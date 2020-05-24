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

size_t GetLength(const char * stringValue);
size_t GetLength2(const char * stringValue);

bool isEmpty(const char * stringValue);
bool isEmpty2(const char * stringValue);

char * concatTwoStringsDynamic(const char * stringA, const char * stringB);
void concatTwoStringsStatic(const char * stringA, const char * stringB, char * result);

char * PowerDynamic(const char * string, unsigned int power);
void PowerStatic(const char * string, unsigned int power, char * result);