#include <assert.h>
#include <string.h>
#include "String.h"

/*
    Implementaciones
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

size_t GetLength2(const char * stringValue)
{
    const char * start = stringValue;
    while(*stringValue != '\0')
        stringValue++;
    return stringValue - start;
}

bool IsEmpty(const char * stringValue)
{
    return GetLength(stringValue) == 0;
}

bool IsEmpty2(const char * stringValue)
{
    return stringValue[0] == '\0';
}

char * ConcatDynamic(const char * stringA, const char * stringB)
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

void ConcatStatic(const char * stringA, const char * stringB, char * result)
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

char * PowerDynamic(const char * string, unsigned int power)
{
    size_t length = GetLength(string);
    size_t newLength = length * power;

    char * result = (char*) malloc((newLength + 1) * sizeof(char));
            
    for(size_t index = 0; index < newLength; index++)
    {
        result[index] = string[index % length];
    }

    result[newLength] = '\0';

    return result;
}

void PowerStatic(const char * string, unsigned int power, char * result)
{   
    size_t length = GetLength(string);
    size_t newLength = length * power;

    for(size_t index = 0; index < newLength; index++)
    {
        result[index] = string[index % length];
    }

    result[newLength] = '\0';
}

int Compare(const char * stringA, const char * stringB, size_t index)
{
    char a = stringA[index];
    char b = stringB[index];

    if(a == b)
    {
        if(a != '\0')
        {
            return Compare(stringA, stringB, index + 1);
        }
        
        return 0;
    }
    else if(a > b)
    {
        return 1;
    }
    
    return -1;
}

/*
    Tests
*/

void TestGetLength()
{
    //pruebo cadena constante longitud 3
    size_t length1 = GetLength("abc");
    assert(length1 == 3);

    //pruebo cadena constante vacía
    size_t length2 = GetLength("");
    assert(length2 == 0);

    //pruebo cadena estática inicializada con constante literal NO vacía
    char staticString[20] = "Hola mundo";
    size_t length3 = GetLength(staticString);
    assert(length3 == 10);

    //pruebo cadena estática inicializada con constante literal vacía
    char staticEmptyString[20] = "";
    size_t length4 = GetLength(staticEmptyString);
    assert(length4 == 0);
}

void TestGetLength2()
{
    //pruebo cadena constante longitud 3
    size_t length1 = GetLength2("abc");
    assert(length1 == 3);

    //pruebo cadena constante vacía
    size_t length2 = GetLength2("");
    assert(length2 == 0);

    //pruebo cadena estática inicializada con constante literal NO vacía
    char staticString1[20] = "Hola mundo";
    size_t length3 = GetLength2(staticString1);
    assert(length3 == 10);

    //pruebo cadena estática inicializada con constante literal vacía
    char staticString2[20] = "";
    size_t length4 = GetLength2(staticString2);
    assert(length4 == 0);
}

void TestIsEmpty()
{
    //pruebo IsEmpty con cadena constante no vacía
    bool result1 = IsEmpty("abc");
    assert(result1 == false);

    //pruebo IsEmpty con cadena constante vacía
    bool result2 = IsEmpty("");
    assert(result2 == true);
    
    //pruebo IsEmpty con cadena estática no vacía
    char staticString1[20] = "Hola mundo";
    bool result3 = IsEmpty(staticString1);
    assert(result3 == false);

    //pruebo IsEmpty con cadena estática vacía
    char staticString2[20] = "";
    bool result4 = IsEmpty(staticString2);
    assert(result4 == true);
}

void TestIsEmpty2()
{
    //pruebo IsEmpty con cadena constante no vacía
    bool result1 = IsEmpty2("abc");
    assert(result1 == false);

    //pruebo IsEmpty con cadena constante vacía
    bool result2 = IsEmpty2("");
    assert(result2 == true);
    
    //pruebo IsEmpty con cadena estática no vacía
    char staticString1[20] = "Hola mundo";
    bool result3 = IsEmpty2(staticString1);
    assert(result3 == false);

    //pruebo IsEmpty con cadena estática vacía
    char staticString2[20] = "";
    bool result4 = IsEmpty2(staticString2);
    assert(result4 == true);
}

void TestPowerStatic()
{
    //pruebo PowerStatic con cadena constante no vacía
    char result1[20];
    PowerStatic("abc", 3, result1);
    assert(strcmp(result1, "abcabcabc") == 0);

    //pruebo PowerStatic con cadena constante vacía
    char result2[20];
    PowerStatic("", 3, result2);
    assert(strcmp(result2, "") == 0);
    
    //pruebo PowerStatic con cadena estática no vacía
    char result3[20];
    char string1[20] = "hola";
    PowerStatic(string1, 3, result3);
    assert(strcmp(result3, "holaholahola") == 0);
    
    //pruebo PowerStatic con cadena estática vacía
    char result4[20];
    char string2[20] = "";
    PowerStatic(string2, 3, result4);
    assert(strcmp(result4, "") == 0);

    //pruebo PowerStatic con cadena constante elevada a la 0
    char result5[20];
    char string3[20] = "hola";
    PowerStatic(string3, 0, result5);
    assert(strcmp(result5, "") == 0);
}

void TestPowerDynamic()
{
    //pruebo PowerStatic con cadena constante no vacía
    char * result1 = PowerDynamic("abc", 3);
    assert(strcmp(result1, "abcabcabc") == 0);

    //pruebo PowerStatic con cadena constante vacía
    char * result2 = PowerDynamic("", 3);
    assert(strcmp(result2, "") == 0);
    
    //pruebo PowerStatic con cadena estática no vacía
    char string1[20] = "hola";
    char * result3 = PowerDynamic(string1, 3);
    assert(strcmp(result3, "holaholahola") == 0);
    
    //pruebo PowerStatic con cadena estática vacía
    char string2[20] = "";
    char * result4 = PowerDynamic(string2, 3);
    assert(strcmp(result4, "") == 0);

    //pruebo PowerStatic con cadena constante elevada a la 0
    char string3[20] = "hola";
    char * result5 = PowerDynamic(string3, 0);
    assert(strcmp(result5, "") == 0);

    //libero memoria dinámica
    free(result1);
    free(result2);
    free(result3);
    free(result4);
    free(result5);
}

void TestCompare()
{
    //pruebo compare con dos constantes literales no vacías
    int result1 = Compare("abc", "abc", 0);
    assert(result1 == 0);
    
    result1 = strcmp("abc", "abc");
    assert(result1 == 0);
    
    //pruebo compare con constantes literales: String Vacío vs String NO Vacío
    int result2 = Compare("", "abc", 0);
    assert(result2 < 0);
    
    result2 = strcmp("", "abc");
    assert(result2 < 0);
    
    //pruebo compare con constantes literales: String Vacío vs String Vacío
    int result3 = Compare("", "", 0);
    assert(result3 == 0);
    
    result3 = strcmp("", "");
    assert(result3 == 0);
    
    //pruebo compare con strings estáticos no vacíos
    char string1[5] = "abc";
    char string2[5] = "abc";
    int result4 = Compare(string1, string2, 0);
    assert(result4 == 0);

    result4 = strcmp(string1, string2);
    assert(result4 == 0);

    //pruebo compare con string estático vs string estático vacío
    char string3[5] = "abc";
    char string4[5] = "";
    int result5 = Compare(string3, string4, 0);
    assert(result5 > 0);
    
    result5 = strcmp(string3, string4);
    assert(result5 > 0);
    
}

int main(void){
    
    TestGetLength();
    TestGetLength2();

    TestIsEmpty();
    TestIsEmpty2();

    TestPowerStatic();
    TestPowerDynamic();

    TestCompare();

    printf("La prueba concluyó sin errores\n");
}