#include "String.h"

/*
    Definiciones
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

char * Concat1(const char * stringA, const char * stringB)
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

void Concat2(const char * stringA, const char * stringB, char * result)
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

char * Power1(const char * string, unsigned int power)
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

void Power2(const char * string, unsigned int power, char * result)
{   
    size_t length = GetLength(string);
    size_t newLength = length * power;

    for(size_t index = 0; index < newLength; index++)
    {
        result[index] = string[index % length];
    }

    result[newLength] = '\0';
}

char * Power3(char * stringInOut, unsigned int power)
{   
    size_t initialLength = GetLength(stringInOut);
    size_t newLength = initialLength * power;

    for(size_t index = 0; index < newLength; index++)
    {
        stringInOut[index] = stringInOut[index % initialLength];
    }

    stringInOut[newLength] = '\0';

    return stringInOut;
}

int Compare(const char * stringA, const char * stringB, size_t index)
{
    char a = stringA[index];
    char b = stringB[index];
    int subtraction = a - b;

    if(subtraction == 0)
    {
        if(a != '\0')
        {
            return Compare(stringA, stringB, index + 1);
        }
    }

    return subtraction;
}