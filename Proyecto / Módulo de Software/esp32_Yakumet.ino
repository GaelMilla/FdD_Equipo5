#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <HTTPClient.h>

//  Definición de pines 

// DS18B20 – temperatura del agua
#define DS18B20_PIN   4  

// Turbidez
#define TURBID_PIN   33    

// TDS / conductividad
#define TDS_PIN      32      

// pH 
#define PH_OUT_PIN   34      // Salida OUT del módulo de pH
#define PH_REF_PIN   35      // Salida REF del módulo de pH

//  Parámetros del ADC del ESP32 

const float ADC_VREF = 3.3;    // Tensión de referencia del ADC
const int   ADC_MAX  = 4095;   // Resolución de 12 bits (0–4095)

// DS18B20 – temperatura 

OneWire oneWire(DS18B20_PIN);
DallasTemperature ds18b20(&oneWire);

// TDS – conductividad 

const float TDS_CAL_FACTOR = 10.10f;   // Factor de calibración empírico del equipo

//  Turbidez – NTU 
// Calibración lineal empírica:

const float V_LIMPIA = 1.5f;
const float V_TURBIA = 0.90f;


const float PH_SLOPE  = -35.50f;   
const float PH_OFFSET =  5.92f;   

//  WIFI + THINGSPEAK 

const char* ssid     = "Redmi Note 14 Pro 5G";
const char* password = "11111111";

String writeAPIKey = "GPWVHE1AR3EQL7Z8";
String server = "http://api.thingspeak.com/update";


void setup() {
  Serial.begin(115200);
  delay(1000);

  analogReadResolution(12); 

  ds18b20.begin();

  Serial.println("Sistema de monitoreo de calidad de agua – inicializado.");

  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.println("\nWiFi conectado!");
}

//                    Funciones de lectura de sensores

float leerTemperaturaAgua() {
  ds18b20.requestTemperatures();
  float tC = ds18b20.getTempCByIndex(0);
  if (tC == DEVICE_DISCONNECTED_C) {
    return -1.0f;  
  }
  return tC;
}

// Turbidez: devuelve ADC, voltaje (V) y turbidez estimada (NTU)
void leerTurbidez(int &adc, float &volt, float &ntu) {
  const int N = 50;      // número de muestras para promediado
  long suma = 0;

  for (int i = 0; i < N; i++) {
    suma += analogRead(TURBID_PIN);
    delay(5);
  }

  adc  = suma / N;
  volt = adc * (ADC_VREF / ADC_MAX);

  if (volt > V_LIMPIA) volt = V_LIMPIA;
  if (volt < V_TURBIA) volt = V_TURBIA;

  ntu = (V_LIMPIA - volt) * (3000.0f / (V_LIMPIA - V_TURBIA));
}

// TDS / conductividad: devuelve ADC, voltaje (V) y TDS calibrado (ppm)
void leerTDS(float tempAguaC, int &adc, float &volt, float &tds_ppm) {
  const int N = 20;
  long suma = 0;

  for (int i = 0; i < N; i++) {
    suma += analogRead(TDS_PIN);
    delay(5);
  }

  adc  = suma / N;
  volt = adc * (ADC_VREF / ADC_MAX);

  if (tempAguaC < -0.5f) {
    tempAguaC = 25.0f;
  }

  float compensationCoeff = 1.0f + 0.02f * (tempAguaC - 25.0f);
  float vComp = volt / compensationCoeff;

  float tds_raw = (133.42f * vComp * vComp * vComp
                - 255.86f * vComp * vComp
                + 857.39f * vComp) * 0.5f;

  tds_ppm = tds_raw * TDS_CAL_FACTOR;
}

// pH: lectura diferencial entre OUT y REF del módulo de pH
void leerPH(int &adcOut, int &adcRef, float &vReal, float &pH) {
  const int N = 40;
  long sumaOut = 0;
  long sumaRef = 0;

  for (int i = 0; i < N; i++) {
    sumaOut += analogRead(PH_OUT_PIN);
    sumaRef += analogRead(PH_REF_PIN);
    delay(5);
  }

  adcOut = sumaOut / N;
  adcRef = sumaRef / N;

  float vOut = adcOut * (ADC_VREF / ADC_MAX);
  float vRef = adcRef * (ADC_VREF / ADC_MAX);

  vReal = (vOut - vRef) / 3.0f;

  pH = PH_SLOPE * vReal + PH_OFFSET;
}


//                               Loop

void loop() {

  // 1. Temperatura del agua
  float tempAgua = leerTemperaturaAgua();

  // 2. Turbidez
  int   adc_turb = 0;
  float v_turb   = 0.0f;
  float ntu      = 0.0f;
  leerTurbidez(adc_turb, v_turb, ntu);

  // 3. TDS / conductividad (ppm)
  int   adc_tds  = 0;
  float v_tds    = 0.0f;
  float tds_ppm  = 0.0f;
  leerTDS(tempAgua, adc_tds, v_tds, tds_ppm);

  // 4. pH
  int   adc_ph_out = 0;
  int   adc_ph_ref = 0;
  float vreal_ph   = 0.0f;
  float pH         = 0.0f;
  leerPH(adc_ph_out, adc_ph_ref, vreal_ph, pH);


  // THINGSPEAK

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url =
      server +
      "?api_key=" + writeAPIKey +
      "&field1=" + String(pH, 2) +
      "&field2=" + String(ntu, 1) +
      "&field3=" + String(tds_ppm, 1) +
      "&field4=" + String(tempAgua, 2);

    http.begin(url);
    int code = http.GET();
    Serial.print("ThingSpeak HTTP code: ");
    Serial.println(code);
    http.end();
  }

  delay(10000);   // periodo de actualización (10 segundos)
}
