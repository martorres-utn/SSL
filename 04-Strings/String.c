#include "String.h"

/*
    Si no encuentra caracter nulo '\0' estamos en problemas.
*/
size_t GetLength(const char * stringValue)
{
    size_t index = 0;
    while(stringValue[index] != '\0')
    {
        index++;
    }
    return index;
}

/*
    Avanzo incrementando la dirección del puntero.
*/
size_t GetLength2(const char * stringValue)
{
    const char * start = stringValue;
    while(*stringValue != '\0')
        stringValue++;
    return stringValue - start;
}

/*
    Si la cadena está vacía tiene longitud 0 es decir no posee ningun caracter salvo el caracter nulo.
*/
bool isEmpty(const char * stringValue)
{
    return GetLength(stringValue) == 0;
}

/*
    Si el primer char de una cadena es char nulo \0 considero que la cadena está vacía.
*/
bool isEmpty2(const char * stringValue)
{
    return stringValue[0] == '\0';
}

/*
    Concatena dos strings y devuelve un puntero a un nuevo string que es el resultado de los dos concatenados.
    El nuevo string fue reservado de forma dinámica.
*/
char * concatTwoStringsDynamic(const char * stringA, const char * stringB)
{
    size_t lengthA = GetLength(stringA);
    size_t lengthB = GetLength(stringB);
    size_t lengthAB = lengthA + lengthB;

    char * result = (char*) malloc((lengthAB + 1) * sizeof(char));
            
    for(size_t index = 0; index < lengthAB; index++)
    {
        if(index < lengthA)
            result[index] = stringA[index];
        else
            result[index] = stringB[index - lengthA];
    }

    result[lengthAB] = '\0';

    return result;
}

/*
    Concatena dos strings depositandolos en un array char pre-existente.
    La longitud del array destino debe ser mayor o igual que la suma de las longitudes de los strings a concatenar.
*/
void concatTwoStringsStatic(const char * stringA, const char * stringB, char * result)
{
    size_t lengthA = GetLength(stringA);
    size_t lengthB = GetLength(stringB);
    size_t lengthAB = lengthA + lengthB;
            
    for(size_t index = 0; index < lengthAB; index++)
    {
        if(index < lengthA)
            result[index] = stringA[index];
        else
            result[index] = stringB[index - lengthA];
    }

    result[lengthAB] = '\0';
}

int main(void){
    char sampleString[20] = "String de prueba";
    char emptyString[20] = "";

    size_t length1 = GetLength("Pepito");
    size_t length2 = GetLength(sampleString);
    size_t length3 = GetLength("");
    size_t length4 = GetLength2("hola mundo");
    size_t length5 = GetLength2(sampleString);
    size_t length6 = GetLength2(emptyString);
    size_t length7 = GetLength2("");

    bool empty1 = isEmpty("");
    bool empty2 = isEmpty2(emptyString);

    char * concatResult1 = concatTwoStringsDynamic("string de ", "prueba");
    char * concatResult2 = concatTwoStringsDynamic(sampleString, emptyString);
    char concatResult3[100];
    
    concatTwoStringsStatic("hola 1 2 3 probando!", "chau nos vimos", concatResult3);

    size_t lengthResult1 = GetLength(concatResult1);
    size_t lengthResult2 = GetLength(concatResult2);
    size_t lengthResult3 = GetLength(concatResult3);

    printf("Strings: \"%s\", \"%s\", \"%s\", \"%s\" \"%s\"\n", sampleString, emptyString, concatResult1, concatResult2, concatResult3);
    
    free(concatResult1);
    free(concatResult2);
}