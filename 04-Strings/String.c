#include "String.h"

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
    if(power == 0)
        return "";

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
    if(power == 0)
    {
        result[0] = '\0';
        return;
    }
        
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

    bool empty1 = IsEmpty("");
    bool empty2 = IsEmpty2(emptyString);

    char * concatResult1 = ConcatDynamic("string de ", "prueba");
    char * concatResult2 = ConcatDynamic(sampleString, emptyString);
    char concatResult3[100];
    
    ConcatStatic("hola 1 2 3 probando!", "chau nos vimos", concatResult3);

    size_t lengthResult1 = GetLength(concatResult1);
    size_t lengthResult2 = GetLength(concatResult2);
    size_t lengthResult3 = GetLength(concatResult3);

    char * powerDynamicR1 = PowerDynamic("hola", 3);
    printf("powerDynamicR1: \"%s\"\n", powerDynamicR1);

    char * powerDynamicR2 = PowerDynamic("hola", 1);
    printf("powerDynamicR2: \"%s\"\n", powerDynamicR2);

    char * powerDynamicR3 = PowerDynamic("hola", 0);
    printf("powerDynamicR3: \"%s\"\n", powerDynamicR3);

    char powerStaticR1[100] = "";
    char powerStaticR2[100] = "";
    char powerStaticR3[100] = "";

    PowerStatic("hola", 3, powerStaticR1);
    printf("powerStaticR1: \"%s\"\n", powerStaticR1);

    PowerStatic("hola", 1, powerStaticR2);
    printf("powerStaticR2: \"%s\"\n", powerStaticR2);

    PowerStatic("hola", 0, powerStaticR3);
    printf("powerStaticR3: \"%s\"\n", powerStaticR3);

    printf("Strings: \"%s\", \"%s\", \"%s\", \"%s\" \"%s\"\n", sampleString, emptyString, concatResult1, concatResult2, concatResult3);
    
    char stringA[10] = "Hola";
    char stringB[10] = "Hola";

    if(stringA == stringB)
    {
        printf("ambas cadenas son iguales \n");
    }

    if("Hola" == "Hola")
    {
        printf("Hola es igual a Hola\n");
    }

    int compareR1 = Compare("Hola", "Hola", 0);
    int compareR2 = Compare(powerStaticR1, powerStaticR2, 0);
    int compareR3 = Compare("ABCD", "ABCE", 0);
    int compareR4 = Compare("ABCE", "ABCD", 0);
    int compareR5 = Compare("", "", 0);
    int compareR6 = Compare(powerDynamicR1, powerDynamicR1, 0);

    free(concatResult1);
    free(concatResult2);
    free(powerDynamicR1);
    free(powerDynamicR2);
    free(powerDynamicR3);
}