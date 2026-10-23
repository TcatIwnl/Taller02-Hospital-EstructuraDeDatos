# Taller02-Hospital-EstructuraDeDatos

## Diseño del árbol de decisión

Estado: diseño definido; implementación e integración pendientes.

El sistema clasifica automáticamente a los pacientes mediante
un árbol binario de decisión implementado manualmente.

### Orden de evaluación

1. Edad < 14: Pediatría.
2. Trauma == 1:
   - RequiereCirugia == 1: Cirugía.
   - RequiereCirugia == 0: Traumatología.
3. SintomasNeurologicos == 1: Neurología.
4. TipoDolor == "pecho": Cardiología.
5. Temperatura >= 38.5 o Dolor >= 8: Urgencias.
6. DiasHospitalizacion >= 2: Hospitalización.
7. En cualquier otro caso: Medicina General.

### Justificación de las decisiones

- Pediatría: agrupa inicialmente a pacientes menores de 14 años.
- Cirugía: recibe pacientes con trauma que requieren cirugía.
- Traumatología: recibe pacientes con trauma sin requerimiento quirúrgico.
- Neurología: identifica síntomas neurológicos.
- Cardiología: identifica dolor de pecho.
- Urgencias: considera temperatura elevada o dolor intenso.
- Hospitalización: utiliza los días estimados de permanencia.
- Medicina General: recibe casos que no cumplen condiciones anteriores.

### Prioridades y casos simultáneos

Las condiciones se evalúan desde la raíz hacia una hoja.
La primera hoja alcanzada determina el único servicio asignado.

La edad tiene prioridad sobre las condiciones siguientes.
La necesidad de cirugía se evalúa únicamente cuando existe trauma.
Los atributos que no se consultan en una ruta no modifican su resultado.

Este criterio es una simulación académica y no representa
un protocolo médico real.

### Datos inválidos o insuficientes

La clasificación solo se ejecutará para registros que hayan
superado las validaciones de formato y datos clínicos.

Los registros incompletos, con conversiones incorrectas,
rangos inválidos o identificadores duplicados se descartan
durante la carga, sin incorporarse a la cola.

### Casos de prueba representativos

- 001: Cardiología.
- 002: Urgencias.
- 003: Cirugía.
- 004: Pediatría.
- 005: Traumatología.
- 006: Neurología.
- 007: Medicina General.
- 009: Hospitalización.

El árbol deberá construirse mediante NodoPregunta y punteros,
permitiendo recorridos y evaluación de pacientes.
Los resultados anteriores son expectativas de prueba;
la clasificación todavía no está implementada.
