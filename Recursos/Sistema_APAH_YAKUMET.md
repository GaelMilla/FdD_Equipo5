**Sistema autónomo APAH y su importancia para el proyecto YAKUMET**

Cómo es sabido, nuestro proyecto consiste en un sistema capaz de
monitorear el agua y detectar metales pesados, con el objetivo de
alertar a la población que viva en zonas cercanas a ríos y cuyo
tratamiento de esa misma agua sea pobre o nulo. La idea es llevarlo a
cabo en Puno para prevenir que la población se siga contaminando con los
metales pesados que deja la minería en aquella zona (consultar
[[README.mp]{.underline}](https://github.com/GaelMilla/FdD_Equipo5/blob/main/README.md)
principal).

Sin embargo, pese a tener la idea, nos vimos atrapados en un problema al
querer llevarlo a la práctica. Así nos surgió la duda **¿Cómo trabajaría
el sistema en conjunto?**

Porque ya sabemos que vamos a utilizar sensores de **pH, conductividad
eléctrica y un sensor que pueda detectar el oxígeno disuelto.**

Por lo que decidimos buscar información, sobre proyectos similares a
nuestra idea, en fuentes confiables.

Es así como en Science Direct encontramos:

**APAH: An autonomous IoT driven real-time monitoring system for
Industrial wastewater**

O traducido al español:**\
\
APAH: Un sistema autónomo de monitoreo en tiempo real impulsado por IoT
para aguas residuales industriales**

![](media/image3.png){width="6.267716535433071in"
height="3.5416666666666665in"}

El sistema **APAH** es un sistema autónomo basado en **IoT** para la
monitorización en tiempo real de aguas residuales industriales (1).
Integra múltiples sensores (pH, oxígeno disuelto, conductividad
eléctrica, sólidos disueltos totales, turbidez y temperatura) y utiliza
una arquitectura en capas (capa de sensado, capa de procesamiento y capa
de aplicación). Incluye una app móvil (APAH) desarrollada en Android
Studio, conectada a Firebase, y emplea analítica predictiva con
**machine learning** para mejorar la gestión. Su objetivo es garantizar
el cumplimiento ambiental, prevenir contaminación mediante alarmas y
válvulas automáticas, y optimizar los procesos de tratamiento.

A continuación, se explica la arquitectura que utiliza el sistema APAH.

**Arquitectura de tres capas del sistema APAH**

El sistema se organiza en una arquitectura de tres capas que permite la
monitorización en tiempo real y la gestión eficiente de la calidad del
agua en aguas residuales industriales. A continuación se describen las
tres capas:

1.  **Capa de sensores**

> Función: Esta capa es responsable de la captura de parámetros clave de
> calidad del agua a través de un conjunto de sensores distribuidos.
>
> Sensores Utilizados:
>
> **Sensor de pH:** Mide la concentración de iones de hidrógeno para
> determinar la acidez o alcalinidad del agua.
>
> **Sensor de DO (Oxígeno Disuelto):** Monitorea el nivel de oxígeno
> disuelto, esencial para los procesos biológicos.
>
> **Sensor de Conductividad (EC):** Evalúa la capacidad del agua para
> conducir electricidad, lo que indica la concentración de iones
> disueltos.
>
> **Sensor de TDS (Sólidos Disueltos Totales):** Mide la concentración
> de sólidos disueltos en el agua.
>
> **Sensor de Turbidez:** Determina la claridad del agua, que puede
> verse afectada por partículas suspendidas.
>
> **Sensor de Temperatura:** Monitorea la temperatura del agua, que
> influye en las reacciones químicas y biológicas.
>
> **Conexión:** Los sensores están conectados a un microcontrolador IoT,
> como el NodeMCU ESP8266, que recoge y transmite los datos.

2.  **Capa de borde (Edge Layer)**

> **Función:** Esta capa se encarga de la transmisión y procesamiento de
> los datos recopilados por los sensores.
>
> **Transmisión de Datos:** Utiliza tecnologías de comunicación como
> GSM, GPRS y Wi-Fi para enviar datos a la nube, asegurando que la
> información se pueda acceder en tiempo real, incluso en áreas con
> conectividad limitada.
>
> **Almacenamiento:** Los datos se almacenan en plataformas en la nube
> como Firebase y ThingSpeak, lo que permite un análisis y visualización
> eficientes.

3.  **Capa de aplicación**

> **Función:** Esta capa es donde los datos procesados se presentan a
> los usuarios finales a través de aplicaciones móviles o web.
>
> **Interfaz de Usuario:** Incluye la aplicación móvil APAH,
> desarrollada en Android Studio, que permite a los operadores
> visualizar datos en tiempo real, recibir alertas y controlar el
> sistema de forma remota.
>
> **Análisis Predictivo:** Integra capacidades de aprendizaje automático
> para analizar datos históricos y predecir tendencias futuras, lo que
> ayuda en la toma de decisiones informadas sobre la gestión del agua.

![](media/image2.png){width="5.411458880139983in"
height="2.7003499562554683in"}

![](media/image5.png){width="5.114583333333333in"
height="3.310064523184602in"}

La arquitectura de tres capas del sistema APAH permite una
monitorización continua y eficaz de la calidad del agua, lo que facilita
la detección temprana de problemas y la intervención rápida para
mantener los estándares ambientales. Esta estructura modular también
permite la escalabilidad y la adaptabilidad del sistema a diferentes
entornos industriales.

Cómo se mencionó previamente, la razón de citar este documento es
analizar cómo trabajan estos sensores y cómo se comunican para luego
enviar la información para ser vista y analizada.

**Sensores empleados en el sistema APAH**

A continuación, se detalla más sobre los sensores que utiliza el sistema
APAH para medir parámetros críticos de calidad del agua en tiempo real,
además de los datos obtenidos en cuatro plantas de tratamiento de aguas
residuales industriales en Maharashtra, India, en efluentes textiles,
lácteos y aguas grises:

1.  **Sensor de pH**

> Función: Mide la concentración de iones de hidrógeno en el agua,
> indicando su acidez o alcalinidad.
>
> Rango de Medición: 0 a 14 pH.
>
> Importancia: Mantener un pH adecuado es crucial para evitar
> condiciones tóxicas para los organismos acuáticos y para la
> efectividad de los procesos de tratamiento.

2.  **Sensor de Oxígeno Disuelto (DO)**

> Función: Monitorea el nivel de oxígeno disuelto en el agua, esencial
> para la supervivencia de organismos acuáticos y para procesos
> biológicos de tratamiento.
>
> Rango de Medición: 0 a 20 mg/L.
>
> Importancia: Niveles adecuados de DO son necesarios para prevenir
> condiciones anaeróbicas que pueden generar gases nocivos como el
> sulfuro de hidrógeno.

3.  **Sensor de Conductividad (EC)**

> Función: Mide la capacidad del agua para conducir electricidad, que
> está relacionada con la concentración de iones disueltos (sales y
> metales).
>
> Rango de Medición: 0 a 1000 µS/cm.
>
> Importancia: Altos niveles de conductividad pueden indicar
> contaminación por sales o metales pesados, afectando la calidad del
> agua.

4.  **Sensor de Sólidos Disueltos Totales (TDS)**

> Función: Cuantifica la concentración de sólidos disueltos en el agua,
> proporcionando un indicador de la pureza del agua.
>
> Rango de Medición: 0 a 1000 mg/L.
>
> Importancia: Altos niveles de TDS pueden hacer que el agua sea
> inadecuada para uso industrial o agrícola.

5.  **Sensor de Turbidez**

> Función: Mide la claridad del agua, que se ve afectada por la
> presencia de partículas suspendidas como sedimentos y materia
> orgánica.
>
> Rango de Medición: 0 a 1000 NTU (Unidades Nefelométricas de
> Turbidez\*).
>
> Importancia: La turbidez alta puede reducir la penetración de luz y
> afectar la fotosíntesis en ecosistemas acuáticos.

6.  **Sensor de Temperatura**

> Función: Monitorea la temperatura del agua, que influye en las
> reacciones químicas y en la solubilidad de gases como el oxígeno.
>
> Rango de Medición: -55 °C a 125 °C.
>
> Importancia: La temperatura óptima es crucial para mantener la salud
> de los organismos acuáticos y la efectividad de los procesos de
> tratamiento.

La información presentada fue extraída directamente del documento.\
\
![](media/image1.png){width="6.267716535433071in"
height="6.347222222222222in"}

Estos sensores trabajan de manera conjunta para proporcionar una imagen
completa de la calidad del agua en tiempo real, lo que permite a los
operadores del sistema APAH tomar decisiones informadas y rápidas para
garantizar el tratamiento efectivo de las aguas residuales y el
cumplimiento de los estándares ambientales.

Gracias a toda la información obtenida, pudimos responder nuestra duda
inicial **¿Cómo trabajaría el sistema en conjunto?**

La siguientes imagen es una tabla que muestra la unidad de cada
parámetro medido por los sensores y la fórmula matemática empleada para
realizar la medición de cada uno de ellos:

![](media/image4.png){width="6.677083333333333in" height="3.09375in"}

Esta imagen muestra las fórmulas empleadas para determinar el índice de
calidad del agua.

(Las imágenes fueron generadas por ChatGPT tras analizar el documento
citado)![](media/image6.png){width="4.906325459317586in"
height="3.2573950131233596in"}

**Ejemplo de cómo opera el sistema APAH:**

1.  Sensor detecta anomalía (ej. pH fuera de rango).

2.  El ESP8266 procesa la señal y la compara con límites definidos.

3.  Si hay riesgo:

    a.  Activa la válvula automática (interrumpe flujo).

    b.  Dispara alarma sonora en la planta.

    c.  Envía alerta y datos en vivo a la app APAH.

**Conclusión:**

La documentación del sistema APAH constituye un valioso referente para
nuestro proyecto, ya que proporciona una guía práctica sobre cómo
estructurar un sistema de análisis de datos de calidad del agua en
tiempo real. Sin embargo, nuestro desarrollo no busca replicar ni
plagiar dicho sistema, sino adaptar sus principios a un contexto
distinto, enfocado específicamente en la detección de metales pesados en
ríos mediante sensores diferentes y bajo condiciones geográficas y
ambientales particulares. De esta manera, aprovechamos la experiencia de
APAH como base conceptual y metodológica, pero orientamos nuestra
propuesta hacia un propósito específico y diferenciado, lo que permite
evitar conflictos de propiedad intelectual y garantizar la originalidad
de nuestro trabajo.

Referencias:

> [1.](https://www.zotero.org/google-docs/?Z50QeT) [Chavhan N, Bhattad
> R, Khot S, Patil S, Pawar A, Pawar T, et al. APAH: An autonomous IoT
> driven real-time monitoring system for Industrial wastewater. Digit
> Chem Eng. 1 de marzo de
> 2025;](https://www.zotero.org/google-docs/?Z50QeT)
> https://doi.org/10.1016/j.dche.2025.100217.
