# Calculadora Infija.

## 1. Objetivos

* Experimentar el diseño de la especificación de lenguajes a nivel léxico y
sintáctico.
* Experimentar la implementación manual del nivel léxico y sintáctico de
lenguajes.

## 2. Temas

* Especificación del nivel Léxico y Sintáctico.
* Implementación del nivel Léxico y Sintáctico.
* Implementación de Scanner
* Implementación de Parser.
  
## 3. Problema

Análisis de expresiones aritméticas infijas simples que incluya:

* Números naturales con representación literal en base 10.
* Identificadores de variables.
* Adición.
* Multiplicación.

Ejemplos de expresiones correctas:

        A+2*3
        2*A+3
        A
        2
Ejemplos de expresiones incorrectas:

        +
        42+
        +A

## 4. Solución
Especificar e implementar los niveles léxicos y sintácticos del lenguaje.

## 5. Restricciones
* El scanner y el parser deben estar lógicamente separados.
* El parser se comunica con el scanner con la operación GetNextToken, el
scanner toma los caracteres de stdin con getchar.

### Crédito Extra
Estructurar la solución con separación física entre scanner
y parser.

## 6. Tareas
1. Diseñar el nivel léxico del lenguaje.
2. Diseñar el nivel sintáctico del lenguaje.
3. Implementar el scanner.
4. Implementar el parser.
5. Probar.
7. Productos

        DD-CalcInfManual
        46
        Productos
        |-- Calc.md
        |-- Makefile
        |-- Scanner.h // Opcional
        |-- Parser.h // Opcional
        |-- Parser.c // Opcional
        |-- Scanner.c // Opcional
        `-- Calc.c

## Solución propuesta

### Diseño Léxico
Se proponen las siguientes categorías léxicas para el lenguaje de expresiones:

* Constantes enteras. Ejemplo: 1, 22, 30, 456, 51515, etc.
* Identificadores. Ejemplo: A, B, CONT, DIV, etc.
* Operadores: +, *.

Estas categorías formarán parte de un Lenguaje Regular y serán reconocidas por una serie de Gramáticas Regulares que se detalla a continuación.

**Constantes enteras**

  *entero* -> *dígito* | *dígito_sin_0* · *cadena_dígitos*

  *dígito* -> 0|1|2|3|4|5|6|7|8|9

  *dígito_sin_0* -> 1|2|3|4|5|6|7|8|9

  *cadena_dígitos* -> *dígito* | *dígito* · *cadena_dígitos*

Formalmente:
    
    P:
        A -> B | C · D
        B -> 0|1|2|3|4|5|6|7|8|9
        C -> 1|2|3|4|5|6|7|8|9
        D -> B | B · D

    G = ({A, B, C, D}, {0,1,2,3,4,5,6,7,8,9}, A, P)

**Identificadores**

  *identificador* -> *letra* | *letra* · *identificador*

  *letra* -> A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z

**Operadores**
 
 *operador* -> *|+

### Diseño Sintáctico
