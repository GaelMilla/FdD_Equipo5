# Sistema autónomo APAH y su importancia para el proyecto YAKUMET

## Introducción
Nuestro proyecto consiste en un sistema capaz de monitorear el agua y detectar metales pesados, con el objetivo de alertar a la población que viva en zonas cercanas a ríos y cuyo tratamiento de esa misma agua sea pobre o nulo (consultar `README.md` principal).

Sin embargo, pese a tener la idea, nos vimos atrapados en un problema al querer llevarlo a la práctica. Así nos surgió la duda:

> **¿Cómo trabajaría el sistema en conjunto?**

Ya sabemos que vamos a utilizar sensores de **pH**, **conductividad eléctrica** y un sensor que pueda detectar el **oxígeno disuelto**.  
Por lo tanto, buscamos información sobre proyectos similares en fuentes confiables.

Es así como en *Science Direct* encontramos:

**APAH: An autonomous IoT driven real-time monitoring system for industrial wastewater**  
O traducido al español:  
**APAH: Un sistema autónomo de monitoreo en tiempo real impulsado por IoT para aguas residuales industriales**

---

## ¿Qué es el sistema APAH?
El sistema **APAH** es un sistema autónomo basado en **IoT** para la monitorización en tiempo real de aguas residuales industriales.  
Integra múltiples sensores (pH, oxígeno disuelto, conductividad eléctrica, sólidos disueltos totales, turbidez y temperatura) y utiliza una arquitectura en capas (sensado, procesamiento y aplicación).  
Incluye una app móvil (APAH) desarrollada en **Android Studio**, conectada a **Firebase**, y emplea analítica predictiva con *machine learning* para mejorar la gestión.  

Su objetivo es garantizar el **cumplimiento ambiental**, **prevenir contaminación** mediante alarmas y válvulas automáticas, y **optimizar los procesos de tratamiento**.

---

## Arquitectura de tres capas del sistema APAH
La arquitectura del sistema se organiza en tres capas que permiten la monitorización en tiempo real y la gestión eficiente:

### 1. Capa de sensores
- Captura parámetros clave de calidad de agua:
  - Sensor de pH
  - Sensor de DO (Oxígeno disuelto)
  - Sensor de Conductividad (EC)
  - Sensor de TDS (Sólidos disueltos totales)
  - Sensor de Turbidez
  - Sensor de Temperatura
- Los sensores están conectados a un **NodeMCU ESP8266**, que recoge y transmite los datos.

### 2. Capa de borde (*Edge Layer*)
- Procesa y transmite los datos recopilados.
- Tecnologías: **GSM, GPRS, Wi-Fi**.
- Almacenamiento en la nube: **Firebase** y **ThingSpeak**.

### 3. Capa de aplicación
- Presenta datos a los usuarios finales.
- Incluye la app móvil **APAH** en Android.
- Funcionalidades:
  - Visualización en tiempo real.
  - Recepción de alertas.
  - Control remoto del sistema.
- Analítica predictiva con **Machine Learning** para detectar tendencias y anticipar problemas.

---

## Sensores empleados en el sistema APAH
A continuación se detallan los sensores utilizados y su relevancia:

- **Sensor de pH**  
  - Rango: 0–14 pH  
  - Importancia: indica acidez/ alcalinidad.

- **Sensor de Oxígeno Disuelto (DO)**  
  - Rango: 0–20 mg/L  
  - Importancia: esencial para organismos acuáticos y procesos biológicos.

- **Sensor de Conductividad (EC)**  
  - Rango: 0–1000 µS/cm  
  - Importancia: refleja concentración de sales o metales disueltos.

- **Sensor de Sólidos Disueltos Totales (TDS)**  
  - Rango: 0–1000 mg/L  
  - Importancia: altos niveles indican baja calidad del agua.

- **Sensor de Turbidez**  
  - Rango: 0–1000 NTU  
  - Importancia: mide partículas suspendidas que afectan la claridad.

- **Sensor de Temperatura**  
  - Rango: -55 °C a 125 °C  
  - Importancia: afecta reacciones químicas y solubilidad de gases.

---

## Parámetros y fórmulas
![Tabla de parámetros y fórmulas](img/tabla.png)

![Fórmulas WQI](Recursos/Imágenes/APAH imagenes/formula1.jpg)

---

## Ejemplo de funcionamiento del sistema APAH
![Flujo de funcionamiento](img/flujo.png)

1. El **sensor detecta anomalía** (ej. pH fuera de rango).  
2. El **ESP8266 procesa la señal** y la compara con límites definidos.  
3. Si hay riesgo:
   - Activa la **válvula automática** (interrumpe flujo).  
   - Dispara **alarma sonora** en la planta.  
   - Envía **alerta y datos en vivo** a la app APAH.  

---

## Conclusión
La documentación del sistema **APAH** constituye un valioso referente para nuestro proyecto, ya que proporciona una guía práctica sobre cómo estructurar un sistema de análisis de datos de calidad del agua en tiempo real.  

Sin embargo, nuestro desarrollo no busca replicar ni plagiar dicho sistema, sino **adaptar sus principios a un contexto distinto**, enfocado en la detección de **metales pesados en ríos**, mediante sensores diferentes y en condiciones geográficas particulares.  

De esta manera, aprovechamos la experiencia de APAH como base conceptual y metodológica, pero orientamos nuestra propuesta hacia un propósito específico y diferenciado, evitando conflictos de propiedad intelectual y garantizando la originalidad de nuestro trabajo.

---

## Referencias
1. Chavhan N, Bhattad R, Khot S, Patil S, Pawar A, Pawar T, et al. APAH: An autonomous IoT driven real-time monitoring system for Industrial wastewater. *Digital Chemical Engineering*. 2025;14:100217. https://doi.org/10.1016/j.dche.2025.100217
