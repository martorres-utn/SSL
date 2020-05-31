# Sintaxis y Semántica de los Lenguajes


* Curso: K2051.  

* Año de cursada: 2020.

* Legajo: 172.400-9.

* Apellido: Torres.

* Nombre: Marcos Emanuel.

## Título del trabajo: 8 - Operaciones de Strings

## Transcripción del enunciado:

Este trabajo tiene dos partes, una de análisis comparativo y otra de desarrollo.

El  análisis  comparativo  es  sobre  el  tipo  de  dato  String  en  el  lenguaje  deprogramación C versus otro lenguaje de programación a elección; mientras queel desarrollo está basado en los ejercicios 20 y 21 del Capítulo #1 del Volumen#1 de [MUCH2012], que a continuación transcribe:

    Investigue  y  construya,  en  LENGUAJE  C,  la  función  que  realiza  cadaoperación solicitada:
    
    **Ejercicio 20**
    
    a. Calcula la longitud de una cadena;
    
    b. Determina si una cadena dada es vacía.
    
    c. Concatena dos cadenas.

Construya un programa de testeo para cada función del ejercicio anterior.

## **Objetivos**

### Parte I — Análisis Comparativo del tipo String en Lenguajes de Programación:

Realizar un análisis comparativo de dato String en el lenguaje C versus unlenguaje de programación a elección. El análisis debe contener, por lo menos,los siguientes ítems:

    a. ¿El tipo es parte del lenguaje en algún nivel?

    b. ¿El tipo es parte de la biblioteca?
    
    c. ¿Qué alfabeto usa?
    
    d. ¿Cómo se resuelve la alocación de memoria?
    
    e. ¿El tipo tiene mutabilidad o es inmutable?
    
    f. ¿El tipo es un first class citizen?
    
    g. ¿Cuál es la mecánica para ese tipo cuando se los pasa como argumentos?
    
    h. ¿Y cuando son retornados por una función?

Las anteriores preguntas son disparadores para realizar una análisis profundo.

### Parte  II — Biblioteca para el Tipo String:

Desarrollar  una  biblioteca  con  lassiguientes operaciones de strings:

    a. GetLength ó GetLongitud
    
    b. IsEmpty ó IsVacía
    
    c. Power ó Potenciar
    
    d. Una operación a definir libremente.

Notar que en vez de la operación concatenar que propone [MUCH2012] se debe desarrollar Power ó Potenciar que repite un string n veces.

La  parte  pública  de  la  biblioteca  se  desarrolla  en  el  header  "String.h",  el cual  no  debe  incluir  <string.h>.  

El  programa  que  prueba  la  biblioteca,  por supuesto, incluye a "String.h", pero sí puede incluir <string.h> para facilitar las comparaciones.

### **Temas**

    1. Strings.
    
    2. Alocación.  
    
    3. Tipos. 

### **Tareas**

1. Parte I
    
    Escribir el AnálisisComparativo.md con la comparación de strings en C versus otro lenguaje de programación a elección.
    
2. Parte II
    
    a. Para cada operación, escribir en Strings.md la especificación matemática de la operación, con conjuntos de salida y de llegada, y con especificaciónde la operación.
    
    b. Escribir el Makefile.
    
    c. Por cada operación:
    
        1. Escribir las pruebas en StringsTest.c.
        
        2. Escribir los prototipos en String.h.
        
        3. Escribir   en   String.h   comentarios   con   las   precondiciones   y poscondiciones de cada función, arriba de cada prototipo.
        
        4. Escribir las implementaciones en Strings.c.

### **Restricciones**

* Las pruebas deben utilizar assert.

* Los proptotipos deben utilizar const cuando corresponde.

* Por lo menos una operación debe implementarse con recursividad.

* Las  implementaciones  no  deben  utilizar  funciones  estándar,  declaradas  en<string.h>

### **Productos**
    DD-Strings
    |-- readme.md
    |-- AnálisisComparativo.md
    |-- String.md
    |-- Makefile
    |-- StringTest.c
    |-- String.h
    `-- String.c.