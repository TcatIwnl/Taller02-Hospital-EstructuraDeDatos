
# Taller 02 — Hospital Marmaja: clasificación y árboles AVL

Proyecto en C++ para la asignatura **Estructura de Datos**, segundo semestre de 2026.

Este proyecto amplía el sistema desarrollado en el Taller 1. Permite cargar pacientes desde un archivo de texto, mantener su orden de llegada mediante una cola FIFO, clasificarlos automáticamente utilizando un árbol binario de decisión y almacenarlos en árboles AVL independientes para cada servicio del hospital.

Los árboles AVL están ordenados por el **ID del paciente**.

## Integrantes

| Nombre | RUT | GitHub | Carrera | Paralelo |
| --- | --- | --- | --- | --- |
| Demian Catalán | 22.241.541-1 | Rippnaikii | Ingeniería Civil en Computación e Informática | C2 |
| Angel Olivares | 22.338.590-7 | TcatIwnl | Ingeniería Civil en Computación e Informática | C1 |
| Jason Tapia | 22.382.028-K | jtapia-code | Ingeniería Civil en Computación e Informática | C1 |

## Estructuras de datos

El sistema utiliza estructuras implementadas manualmente mediante nodos, punteros y memoria dinámica.

### Cola FIFO

Implementada mediante `ColaPacientes` y `NodoCola`.

Los pacientes ingresan respetando el orden del archivo y se procesan siguiendo el principio FIFO (First In, First Out).

### Árbol binario de decisión

Implementado mediante `ArbolDecision` y `NodoPregunta`.

Cada nodo almacena una pregunta o un servicio final. Los punteros `hijoSi` y `hijoNo` permiten recorrer el árbol según las características del paciente.

El árbol incluye construcción dinámica, evaluación de pacientes y recorridos preorden, inorden y postorden.

### Lista enlazada de servicios

Implementada mediante `Hospital`, `NodoSeccion` y `Seccion`.

Permite administrar los ocho servicios disponibles en el hospital y acceder al árbol AVL de cada departamento.

### Árboles AVL

Implementados mediante `ArbolAVL` y `NodoAVL`.

Cada servicio tiene su propio árbol AVL, cuyos pacientes se ordenan utilizando el ID como clave.

Se implementan:

- Inserción ordenada por ID.
- Actualización de alturas.
- Cálculo del factor de balance.
- Rotaciones simples LL y RR.
- Rotaciones dobles LR y RL.
- Rebalanceo automático.
- Búsqueda de pacientes por ID y nombre.
- Recorridos inorden, preorden y postorden.
- Eliminación por ID.
- Rebalanceo después de eliminar.

## Flujo de procesamiento

El programa sigue el siguiente flujo:

`Archivo → Cola FIFO → Árbol de decisión → Servicio → AVL`

1. Se cargan los pacientes desde `pacientes.txt`.
2. Los pacientes válidos ingresan a la cola.
3. Al atender, se retira el primer paciente de la cola.
4. El árbol de decisión evalúa sus características.
5. Se determina automáticamente el servicio correspondiente.
6. El paciente se inserta en el AVL de ese servicio.
7. El programa informa la ruta de clasificación y el resultado.

## Formato del archivo de entrada

El archivo `pacientes.txt` contiene 11 campos separados mediante punto y coma (`;`).

```text
ID;Nombre;Edad;Temperatura;PresionArterial;Dolor;TipoDolor;Trauma;SintomasNeurologicos;RequiereCirugia;DiasHospitalizacion
```

Ejemplo:

```text
001;Juan Perez;25;36.5;120;4;pecho;0;0;0;1
002;Maria Soto;67;39.0;135;9;abdomen;0;0;0;0
003;Pedro Rojas;43;37.2;125;7;abdomen;1;0;1;5
```

El servicio no se indica en el archivo, ya que es determinado por el árbol de decisión.

### Validaciones de entrada

Antes de ingresar un paciente a la cola, el programa comprueba:

- Cantidad correcta de campos.
- ID y nombre no vacíos.
- Edad entre 0 y 120 años.
- Temperatura entre 30.0 y 45.0 °C.
- Temperatura con valor numérico finito.
- Presión arterial entre 40 y 260.
- Dolor entre 0 y 10.
- Tipo de dolor válido: `pecho`, `cabeza`, `abdomen`, `extremidad` u `otro`.
- Trauma con valor 0 o 1.
- Síntomas neurológicos con valor 0 o 1.
- Requiere cirugía con valor 0 o 1.
- Días de hospitalización mayores o iguales a 0.
- Conversiones numéricas completas.
- Identificadores de pacientes no duplicados.

Los registros inválidos se ignoran y se informa al usuario, permitiendo continuar con la carga de los demás pacientes.

Los rangos clínicos son criterios definidos para esta simulación académica.

## Diseño del árbol de decisión

El árbol utiliza las características del paciente para determinar uno de los ocho servicios disponibles.

Las condiciones se evalúan desde la raíz hasta encontrar una hoja. Cuando varias condiciones se cumplen simultáneamente, prevalece la primera que se encuentra según la estructura del árbol.

### Orden de evaluación

1. **Edad menor de 14 años:** Pediatría.
2. **Trauma igual a 1:**
   - Si requiere cirugía: Cirugía.
   - Si no requiere cirugía: Traumatología.
3. **Síntomas neurológicos iguales a 1:** Neurología.
4. **Tipo de dolor igual a `pecho`:** Cardiología.
5. **Temperatura mayor o igual a 38.5 °C o dolor mayor o igual a 8:** Urgencias.
6. **Días de hospitalización mayores o iguales a 2:** Hospitalización.
7. **Si ninguna condición anterior se cumple:** Medicina General.

### Justificación de las decisiones

- **Pediatría:** agrupa inicialmente a pacientes menores de 14 años.
- **Cirugía:** recibe pacientes con trauma y requerimiento quirúrgico.
- **Traumatología:** recibe pacientes con trauma sin requerimiento quirúrgico.
- **Neurología:** considera la presencia de síntomas neurológicos.
- **Cardiología:** considera el dolor de pecho.
- **Urgencias:** considera temperatura elevada o dolor intenso.
- **Hospitalización:** considera los días estimados de permanencia.
- **Medicina General:** recibe a quienes no cumplen las condiciones anteriores.

### Prioridades y condiciones simultáneas

La prioridad depende del orden de las preguntas dentro del árbol.

Por ejemplo:

- Un paciente de 12 años con trauma será clasificado en Pediatría.
- Un paciente con trauma y síntomas neurológicos, sin requerimiento quirúrgico, será clasificado en Traumatología.
- Un paciente con dolor de pecho y temperatura elevada será clasificado en Cardiología.

El programa sigue una sola ruta desde la raíz hasta el servicio final.

### Datos inválidos o insuficientes

Los pacientes deben superar las validaciones del archivo antes de ser clasificados.

Los registros con campos incompletos, valores incorrectos, conversiones inválidas o identificadores duplicados se descartan durante la carga.

El árbol de decisión está diseñado para una simulación académica de estructuras de datos y no constituye un protocolo médico real.

## Casos representativos de clasificación

Los 12 pacientes originales permiten comprobar los ocho servicios.

| ID | Paciente | Servicio esperado |
| --- | --- | --- |
| 001 | Juan Perez | Cardiología |
| 002 | Maria Soto | Urgencias |
| 003 | Pedro Rojas | Cirugía |
| 004 | Ana Torres | Pediatría |
| 005 | Luis Diaz | Traumatología |
| 006 | Sofia Morales | Neurología |
| 007 | Carlos Fuentes | Medicina General |
| 008 | Camila Rojas | Pediatría |
| 009 | Diego Vargas | Hospitalización |
| 010 | Valentina Perez | Cardiología |
| 011 | Jorge Castillo | Urgencias |
| 012 | Daniela Soto | Traumatología |

La clasificación utiliza edad, trauma, requerimiento quirúrgico, síntomas neurológicos, tipo de dolor, temperatura, intensidad del dolor y días estimados de hospitalización.

## Operaciones del programa

El sistema dispone de un menú de consola que permite:

### 1. Atender pacientes

Permite seleccionar una cantidad de pacientes para procesarlos desde la cola FIFO.

Cada paciente se clasifica utilizando el árbol de decisión y se incorpora al AVL del servicio correspondiente.

### 2. Ver departamento

Permite seleccionar un servicio del hospital y consultar los pacientes almacenados en su AVL.

Se puede visualizar:

- Cantidad de pacientes.
- Altura del árbol.
- Recorrido inorden.
- Recorrido preorden.
- Recorrido postorden.
- Alturas y factores de balance de los nodos.

### 3. Buscar paciente

Permite buscar pacientes por ID o nombre dentro de los AVL.

También se contempla la búsqueda por ID entre los pacientes que permanecen en la cola de espera.

### 4. Salir

Finaliza el programa y ejecuta los mecanismos de liberación de memoria.

### Operaciones adicionales del AVL

La clase `ArbolAVL` implementa la eliminación de pacientes por ID y el rebalanceo correspondiente.

Esta funcionalidad existe a nivel de clase, aunque no se encuentra disponible como una opción independiente del menú principal.

## Compilación y ejecución

Se requiere un compilador compatible con C++17.

La terminal debe encontrarse en la carpeta raíz del repositorio, donde está ubicado `Main.cpp`.

### GitHub Codespaces / Linux

Compilar:

```bash
g++ -std=c++17 -Wall -Wextra *.cpp -o hospital
```

Ejecutar:

```bash
./hospital
```

Para comprobar explícitamente si el programa compila:

```bash
if g++ -std=c++17 *.cpp -o hospital; then
    echo "COMPILACION_CODESPACES = TRUE"
else
    echo "COMPILACION_CODESPACES = FALSE"
fi
```

### Windows con PowerShell y G++

Compilar:

```powershell
g++ -std=c++17 *.cpp -o hospital.exe
```

Ejecutar:

```powershell
.\hospital.exe
```

El archivo `pacientes.txt` debe estar en el directorio desde el cual se ejecuta el programa.

## Pruebas reproducibles

El proyecto incorpora archivos de prueba independientes dentro de la carpeta `tests/`.

Cada prueba tiene su propio `main()`, por lo que debe compilarse por separado del programa principal.

### Pruebas del árbol de decisión

Archivo: `tests/prueba_decision.cpp`

Compilar:

```bash
g++ -std=c++17 -I. tests/prueba_decision.cpp ArbolDecision.cpp NodoPregunta.cpp Paciente.cpp Persona.cpp -o prueba_decision
```

Ejecutar en Linux:

```bash
./prueba_decision
```

Estas pruebas comprueban:

- 14 escenarios de clasificación.
- Rutas hacia los ocho servicios.
- Condiciones simultáneas.
- Límites de edad, temperatura, dolor y hospitalización.
- Evaluación de un puntero nulo.
- 100 ciclos de construcción y destrucción del árbol.

### Pruebas básicas del AVL

Archivo: `tests/prueba_avl_base.cpp`

Compilar:

```bash
g++ -std=c++17 -I. tests/prueba_avl_base.cpp ArbolAVL.cpp NodoAVL.cpp Paciente.cpp Persona.cpp -o prueba_avl_base
```

Ejecutar en Linux:

```bash
./prueba_avl_base
```

Estas pruebas comprueban:

- Altura de un árbol vacío.
- Creación y manejo de nodos AVL.
- Rotación simple LL.
- Rotación simple RR.

Las operaciones de rotación doble, inserción y eliminación también forman parte de la implementación de `ArbolAVL`.

## Gestión de memoria

Las estructuras utilizan punteros y memoria dinámica.

- La cola libera los pacientes que permanecen pendientes al finalizar.
- Al atender un paciente, la propiedad de su puntero pasa al AVL del servicio correspondiente.
- El AVL administra la eliminación de sus nodos y pacientes almacenados.
- El árbol de decisión libera recursivamente sus nodos desde la raíz.
- El hospital libera los servicios y las estructuras que administra.

El objetivo es evitar pérdidas de memoria y liberaciones duplicadas durante el funcionamiento normal del sistema.

## Limitaciones y consideraciones

- Los identificadores se comparan como cadenas de texto.
- Se recomienda utilizar IDs con un formato uniforme, como `001`, `002` y `003`.
- La búsqueda por nombre utiliza coincidencia exacta y distingue mayúsculas de minúsculas.
- La interfaz de consola puede presentar diferencias visuales respecto del ejemplo del enunciado.
- Las reglas de clasificación corresponden a una simulación académica y no deben utilizarse para decisiones clínicas reales.