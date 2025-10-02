# Equipo 05 - Fundamentos de Diseño 2025-2  
### Carrera de Ingeniería Ambiental e Informática
**UNIVERSIDAD PERUANA CAYETANO HEREDIA**

---

## 🌍 Descripción del Equipo  
Somos el **Equipo 05** del curso **Fundamentos de Diseño 2025-2**, conformado por estudiantes de la carrera de Ingeniería Ambiental e Informática.  
Nuestro objetivo es aplicar la metodología de diseño para generar soluciones innovadoras con impacto social, tecnológico y ambiental.

---
Nos interesa trabajar en los siguientes **Objetivos de Desarollo Sostenible(ODS):**

**ODS  3: Salud y bienestar**

<p align="center">
  <img width="384" height="315" alt="aaaa1" src="/Recursos/Imágenes/ods3 imagen.png" />
</p>

**ODS  6: Agua limpia y saneamiento**

<p align="center">
  <img width="384" height="315" alt="aaaa1" src="/Recursos/Imágenes/ods 6.jpg" />
</p>

## MIEMBROS DEL EQUIPO

Aldana Porras Leonela Angela

Ancco Quispe Juan Carlos.

Lombardi Quispe Joseph Manuel.

Milla Fasabi Gael Valentino.

Turpo Cayo Ruth Carina



---

## 📸 Fotografía del Equipo  
<p align="center">
  <img width="1536" height="1024" alt="aaaa1" src="/Recursos/Imágenes/grupo 5.jpg" />

</p>

---

## 👥 Integrantes del Equipo

| Foto | Nombre | Rol | Intereses | Correo Electronico |
|------|--------|-----|-----------|--------------------|
| <img src="/Recursos/Imágenes/aldana.jpg" width="90"/> | **Leonela Ángela Aldana Porras** | Cordinadora General y de investigacion | Liderazgo, innovación social, sostenibilidad | leonela.aldana@upch.pe|
| <img src="/Recursos/Imágenes/j ancco.jpg" width="90"/> | **Juan Carlos Ancco Quispe** | Cordinador de Electrónica y Hardware | Robótica, electrónica aplicada, sensores ambientales | juan.ancco@upch.pe
| <img src="/Recursos/Imágenes/lombardi.jpg" width="90"/> | **Joseph Manuel Lombardi Quispe** | Coordinador de programación y plataforma IoT | Programación en Python y C++, análisis de datos ambientales | joseph.lombardi@upch.pe
| <img src="/Recursos/Imágenes/turpo.jpg" width="90"/> | **Ruth Carina Turpo Cayo** | Coordinadora de Diseño y prototipado | Diseño de prototipos, creatividad aplicada, innovación tecnológica, impresión 3D | ruth.turpo@upch.pe
| <img src="/Recursos/Imágenes/milla.jpg" width="90"/> | **Gael Valentino Milla Fasabi** | Coordinador de Comunicación y Redacción Técnica | Programación, análisis de datos, simulación | gael.milla@upch.pe

---


## INTRODUCCIÓN A LA PROBLEMÁTICA

El acceso a agua potable de calidad constituye un derecho fundamental y un requisito esencial para la salud pública. Sin embargo, en diversos contextos, la contaminación por metales pesados representa una amenaza creciente para la seguridad hídrica y el bienestar de las poblaciones. Elementos como el plomo, el mercurio, el arsénico y el cadmio, aun en concentraciones bajas, son altamente tóxicos y tienden a bioacumularse en los organismos vivos, generando efectos adversos a nivel neurológico, renal, inmunológico y reproductivo (World Health Organization [WHO], 2022).
En el Perú, la problemática se intensifica debido a la cercanía de las fuentes de agua a actividades extractivas como la minería, que liberan efluentes ácidos y residuos con metales pesados a los ríos y lagunas. Casos como los reportados en Junín —con la contaminación del río Chacote y otros afluentes— ponen en evidencia la vulnerabilidad de las comunidades que dependen directamente de estos recursos hídricos para su consumo diario (Ministerio del Ambiente, 2020). La Organización Mundial de la Salud recomienda que el agua potable esté libre de metales pesados por encima de los valores máximos permisibles, estableciendo límites estrictos: por ejemplo, 0.01 mg/L para el plomo y 0.006 mg/L para el mercurio, debido a su elevada toxicidad incluso en niveles mínimos.
Frente a esta situación, surge la necesidad de desarrollar soluciones tecnológicas accesibles y confiables que permitan **detectar de manera temprana la presencia de metales pesados en aguas destinadas al consumo humano.** La creación de dispositivos portátiles de detección no solo facilita el monitoreo en tiempo real, sino que también representa un aporte significativo a la prevención de riesgos en salud, la gestión ambiental y la garantía del derecho a un agua segura.
Estoa problemática está vinculada al ODS 3: Salud y bienestar, y al ODS 6: Agua limpia y saneamiento.

### **ODS 3**: Salud y Bienestar

**Objetivo general**: Garantizar una vida sana y promover el bienestar para todos en todas las edades.

Sub objetivo 3:
"Para 2030, implementar sistemas de monitoreo y alerta temprana para detectar metales pesados en el agua y prevenir riesgos en la salud de la población altoandina."

### ODS 6: Agua Limpia y Saneamiento

**Objetivo general**: Garantizar la disponibilidad de agua y su gestión sostenible y el saneamiento para todos.

Sub objetivo 1:
"Para 2030, lograr el acceso universal y equitativo al agua potable a un precio asequible para todos."

### Proyecto tentativo:
Título: Detector colorimétrico IoT de metales pesados en tiempo real para el río Coata (Puno)

Resumen: Desarrollaremos un dispositivo colorimétrico con sensor óptico TCS34725 y ESP32 que analiza muestras de agua del río Coata mediante ciclos automáticos (toma de muestra → dosificación de reactivos → reacción → lectura óptica → envío de datos → enjuague). Los datos se envían en tiempo real a una aplicación móvil/web (Blynk/ThingSpeak/Firebase) para visualización, almacenamiento y alertas cuando se superen umbrales de referencia (ECA/OMS).

Metales objetivo (fase curso): Plomo (Pb) y Arsénico (As) mediante kits colorimétricos.

### Justificacion:
La cuenca del río Coata (Puno) registra reportes sostenidos de contaminación por metales pesados (principalmente plomo y arsénico), con efectos severos sobre la salud (neurotoxicidad, daño renal, mayor riesgo en niñas/niños y gestantes) y sobre los ecosistemas acuáticos. El monitoreo tradicional depende de campañas puntuales de muestreo y análisis de laboratorio: es costoso, espaciado en el tiempo y hace invisible la variabilidad diaria de la calidad del agua.

Frente a ello, proponemos un dispositivo colorimétrico IoT de bajo costo que realiza ciclos automáticos de toma de muestra, reacción y lectura óptica, enviando los resultados en tiempo real a una aplicación móvil/web. Esta solución:

Alinea ODS 3 (Salud y Bienestar): reduce la exposición de la población a sustancias químicas peligrosas mediante alertas tempranas cuando los valores superen umbrales de referencia (ECA/OMS).

Alinea ODS 6 (Agua limpia y saneamiento): mejora la vigilancia de la calidad del agua y apoya la gestión sostenible del recurso hídrico con datos continuos y trazables.


---

### Referencias:

Ministerio del Ambiente. (2020). Informe nacional de la calidad del agua superficial en el Perú. Lima: MINAM. Recuperado de https://www.gob.pe/minam

World Health Organization. (2022). Guidelines for drinking-water quality: Fourth edition incorporating the first and second addenda. Geneva: WHO. https://www.who.int/publications/i/item/9789240045064

Muqui. (2021). La contaminación ambiental de la cuenca del río Coata y los desafíos de la mesa de diálogo en Puno. https://muqui.org/la-contaminacion-ambiental-de-la-cuenca-del-rio-coata-y-los-desafios-de-la-mesa-de-dialogo-en-puno/

Organismo de Evaluación y Fiscalización Ambiental (OEFA). (2021). Informe técnico sobre contaminantes frecuentes en la cuenca del río Coata. https://repositorio.oefa.gob.pe/items/66a28285-1f97-4c5a-a98b-05fafa1010ea

Vallejo-Cárdenas, J., & Pérez-Llanos, A. (2022). Variación de la calidad del agua del río Coata según el ICA-Perú por fuentes contaminantes. Revista de la Facultad de Ciencias de la Salud, Universidad Nacional Federico Villarreal, 19(2), 103-112. https://revistas.unfv.edu.pe/RCV/article/view/1189)

## 📌 Resumen Final  
Este README resume quiénes somos, qué nos motiva a cumplir nuestro objetivo y en qué ODS queremos enfocar nuestro trabajo durante el desarrollo del curso.
