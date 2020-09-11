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

### 1. Diseño Léxico
Se proponen las siguientes categorías léxicas para el lenguaje de expresiones:

* Constantes enteras. Ejemplo: 1, 22, 30, 456, 51515, etc.
* Identificadores. Ejemplo: A, B, CONT, DIV, etc.
* Operadores: +, *.

Cada categoría tiene asociada un Lenguaje Regular y cada cadena será reconocida por alguna de las siguientes Gramáticas Regulares.

**Constantes enteras**

  *entero* -> *dígito* | *dígito_sin_0* · *cadena_dígitos*

  *dígito* -> 0|1|2|3|4|5|6|7|8|9

  *dígito_sin_0* -> 1|2|3|4|5|6|7|8|9

  *cadena_dígitos* -> *dígito* | *dígito* · *cadena_dígitos*

**Formalmente**
    
    P:
        A -> B | C · D
        B -> 0|1|2|3|4|5|6|7|8|9
        C -> 1|2|3|4|5|6|7|8|9
        D -> B | B · D

    G1 = ({A, B, C, D}, {0,1,2,3,4,5,6,7,8,9}, A, P)

**Identificadores**

  *identificador* -> *letra* | *letra* · *identificador*

  *letra* -> a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z

**Formalmente**

    P:
        A -> B | B · A
        B -> a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z

    G2 = ({A, B}, {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}, A, P)

**Operadores**
 
 *operador* -> *|+

 **Formalmente**
    
    P:
        A -> + | *
    G3 = ({A}, {+,*}, A, P)

### Diseño Sintáctico

Las expresiones aritméticas pertenecerán a un Lenguaje Independiente de Contexto y serán reconocidas por la siguiente Gramática Independientes de Contexto.

*expresión* -> *término* | *término* + *expresión*

*término* -> *factor* | *factor* * *término*

*factor* -> *identificador* | *entero*

**Formalmente**

    P:
        E -> T | T + E
        T -> F | F * T
        F -> 'identificador' | 'entero'
    GIC = ({E, T, F}, {'identificador', 'entero', +, *}, E, P)

Observación: identificador y entero son los lexemas reconocidos por las GR previamente descriptas.

En nuestra implementación el analizador sintáctico hará derivaciones siguiendo las producciones anteriores para verificar si una cadena de tokens respeta la sintaxis.

A continuación un ejemplo derivando usando cadenas en lugar de tokens para una mejor comprensión.

Ejemplo de derivación para encontrar expresion "A * 3 + 5 * 6"

1. *expresión*
2. *término* + *expresión* 
3. *factor* * *término* + *expresión*
4. *identificador* * *término* + *expresión*
5. A * *término* + *expresión*
6. A * *factor* + *expresión*
7. A * *entero* + *expresión*
8. A * 3 + *expresión*
9. A * 3 + *factor* * *término*
10. A * 3 + *entero* * *término*
11. A * 3 + 5 * *término*
12. A * 3 + 5 * *factor*
13. A * 3 + 5 * *entero*
14. A * 3 + 5 * 6

Observación: intentar alcanzar una cadena como "+ A + 3 *" derivando con las producciones anteriores no será posible.