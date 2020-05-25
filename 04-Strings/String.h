/* 
String.h
martorres-utn 
20200524 

Prototipos de funciones según consigna:

Parte  II—Biblioteca  para  el  Tipo  String:  
Desarrollar  una  biblioteca  con  las siguientes operaciones de strings:
        a.GetLength ó GetLongitud
        b.IsEmpty ó IsVacía
        c.Power ó Potenciar
        d.Una operación a definir libremente.

Notar que en vez de la operación concatenar que propone [MUCH2012] se debe desarrollar Power 
ó Potenciar que repite un string n veces.

La  parte  pública  de  la  biblioteca  se  desarrolla  en  el  header  "String.h",  
el cual  no  debe  incluir  <string.h>.  

El  programa  que  prueba  la  biblioteca, porsupuesto, incluye a "String.h", 
pero sí puede incluir <string.h> para facilitarlas comparaciones.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

/*
    GetLength

        Descripción: Calcula la longitud de una cadena.

        Argumentos:
            1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.
        
        Resultado:
            1. size_t: entero positivo indicando la cantidad de caracteres que componen esa cadena.
        
        Precondiciones:
            1. La cadena enviada como argumento debe finalizar con caracter nulo '\0': en caso contrario el programa no podrá terminar.
*/
size_t GetLength(const char * stringValue);

/*
    GetLength2

        Descripción: Calcula la longitud de una cadena.

        Argumentos:
            1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.
        
        Resultado:
            1. size_t: entero positivo indicando la cantidad de caracteres que componen esa cadena.
        
        Precondiciones:
            1. La cadena enviada como argumento debe finalizar con caracter nulo '\0': en caso contrario el programa no podrá terminar.
*/
size_t GetLength2(const char * stringValue);

/*
    IsEmpty

        Descripción: Comprueba si una cadena está vacía.

        Argumentos:
            1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.
        
        Resultado:
            1. bool: valor bool indicando True si la cadena está vacía y False si la cadena NO está vacía.
        
        Precondiciones:
            1. La cadena enviada como argumento debe finalizar con caracter nulo '\0': en caso contrario el programa no podrá terminar.
*/
bool IsEmpty(const char * stringValue);

/*
    IsEmpty2

        Descripción: Comprueba si una cadena está vacía.

        Argumentos:
            1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.
        
        Resultado:
            1. bool: valor bool indicando True si la cadena está vacía y False si la cadena NO está vacía.
        
        Precondiciones:
            1. No hay precondición. La cadena puede o no contener caracter nulo '\0' indicando el fin de la cadena.
*/
bool IsEmpty2(const char * stringValue);


/*
    ConcatDynamic
        
        Descripción: Concatena dos cadenas y devuelve un puntero a una nueva cadena que es el resultado de las dos cadenas originales concatenadas.
        La nueva cadena es instanciada de forma dinámica.

        Argumentos:
            1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.
        
        Resultado:
            1. bool: valor bool indicando True si la cadena está vacía y False si la cadena NO está vacía.
        
        Precondiciones:
            1. No hay precondición. La cadena puede o no contener caracter nulo '\0' indicando el fin de la cadena.

    
*/
char * ConcatDynamic(const char * stringA, const char * stringB);


/*
    ConcatStatic
        
        Descripción: Concatena dos cadenas y devuelve un puntero a una nueva cadena que es el resultado de las dos cadenas originales concatenadas.
        La nueva cadena es depositada en el tercer argumento. La cadena resultante no es instanciada de forma dinámica.

        Argumentos:
            1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.
        
        Resultado:
            1. bool: valor bool indicando True si la cadena está vacía y False si la cadena NO está vacía.
        
        Precondiciones:
            1. Las cadenas deben finalizar con caracter nulo '\0'.
            2. El tercer argumento (de salida) debe apuntar a un arreglo de char lo suficientemente grande como para contener el resultado de la concatenación de las cadenas originales.
*/
void ConcatStatic(const char * stringA, const char * stringB, char * result);

/*
    PowerDynamic
    
        Argumentos:
            1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.
            2. unsigned int power: valor entero natural al que se quiere potenciar la cadena.
        
        Resultado:
            1. char *: puntero a un arreglo char dinámico conteniendo el resultado de la potencia de la cadena.
        
        Precondiciones:
            1. La cadena original debe finalizar con caracter '\0'.
*/
char * PowerDynamic(const char * string, unsigned int power);

/*
    PowerStatic
    
        Argumentos:
            1. const char * stringValue: puntero const a un arreglo char tratado como una cadena.
            2. unsigned int power: valor entero natural al que se quiere potenciar la cadena.
            3. char * result: puntero a arreglo donde se quiere depositar el resultado de la potencia de la cadena.

        Resultado:
            1. void: la funcion no devuelve un valor por retorno.
        
        Precondiciones:
            1. La cadena original debe finalizar con caracter '\0'.
            2. El tercer argumento (de salida) debe apuntar a un arreglo de char lo suficientemente grande como para contener el resultado de la potencia de la cadena original.
*/
void PowerStatic(const char * string, unsigned int power, char * result);