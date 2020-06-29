#include "String.h"
#include <assert.h>
#include <string.h>

/*
    Tests
*/

void TestGetLength()
{
    assert(0 == GetLength(""));
    assert(1 == GetLength("a"));
    assert(3 == GetLength("abc"));
    char stringValue[10] = "Hola mundo";
    assert(10 == GetLength(stringValue));
}

void TestGetLength2()
{
    assert(0 == GetLength2(""));
    assert(1 == GetLength2("a"));
    assert(3 == GetLength2("abc"));
    char stringValue[10] = "Hola mundo";
    assert(10 == GetLength2(stringValue));
}

void TestIsEmpty()
{
    assert(true == IsEmpty(""));
    assert(false == IsEmpty("a"));
    assert(false == IsEmpty("abc"));
    char stringValue[10] = "Hola mundo";
    assert(false == IsEmpty(stringValue));
}

void TestIsEmpty2()
{
    assert(true == IsEmpty2(""));
    assert(false == IsEmpty2("a"));
    assert(false == IsEmpty2("abc"));
    char stringValue[10] = "Hola mundo";
    assert(false == IsEmpty2(stringValue));
}

void TestPower1()
{
    //pruebo Power1 con cadena constante no vacía
    char * result1 = Power1("abc", 3);
    assert(0 == strcmp(result1, "abcabcabc"));

    //pruebo Power1 con cadena constante vacía
    char * result2 = Power1("", 3);
    assert(0 == strcmp(result2, ""));
    
    //pruebo Power1 con cadena del stack no vacía
    char string1[20] = "hola";
    char * result3 = Power1(string1, 3);
    assert(0 == strcmp(result3, "holaholahola"));
    
    //pruebo Power1 con cadena del stack vacía
    char string2[20] = "";
    char * result4 = Power1(string2, 3);
    assert(0 == strcmp(result4, ""));

    //pruebo Power1 con cadena elevada a la 0
    char string3[20] = "hola";
    char * result5 = Power1(string3, 0);
    assert(0 == strcmp(result5, ""));

    //libero memoria del heap
    free(result1);
    free(result2);
    free(result3);
    free(result4);
    free(result5);
}

void TestPower2()
{
    //pruebo Power2 con cadena constante no vacía
    char result1[20];
    Power2("abc", 3, result1);
    assert(0 == strcmp(result1, "abcabcabc"));

    //pruebo Power2 con cadena constante vacía
    char result2[20];
    Power2("", 3, result2);
    assert(0 == strcmp(result2, ""));
    
    //pruebo Power2 con cadenas del stack
    char result3[20];
    char string1[20] = "hola";
    Power2(string1, 3, result3);
    assert(0 == strcmp(result3, "holaholahola"));
    
    //pruebo Power2 con cadena del stack vacía
    char result4[20];
    char string2[20] = "";
    Power2(string2, 3, result4);
    assert(0 == strcmp(result4, ""));

    //pruebo Power2 con cadena constante elevada a la 0
    char result5[20];
    char string3[20] = "hola";
    Power2(string3, 0, result5);
    assert(0 == strcmp(result5, ""));
}


void TestPower3()
{
    char stringValue[7] = "ab";
    assert(0 == strcmp("ababab", Power3(stringValue, 3)));
    assert(0 == strcmp("", Power3(stringValue, 0)));
    assert(0 == strcmp("", Power3(stringValue, 3)));
    
    stringValue[0] = 'a';
    stringValue[1] = '\0';
    assert(0 == strcmp("a", Power3(stringValue, 1)));
    assert(0 == strcmp("aaaaaaa", Power3(stringValue, 7)));
}

void TestCompare()
{
    //pruebo compare con dos constantes literales no vacías
    assert(0 == Compare("abc", "abc", 0));

    //pruebo compare con constantes literales: String Vacío vs String NO Vacío
    assert(0 > Compare("", "abc", 0));
    
    //pruebo compare con constantes literales: String Vacío vs String Vacío
    assert(0 == Compare("", "", 0));
    
    //pruebo compare con strings del stack no vacíos
    char string1[5] = "abc";
    char string2[5] = "abd";
    assert(0 > Compare(string1, string2, 0));
    assert(0 < Compare(string2, string1, 0));

    //pruebo compare con string stack no vacío vs string stack vacío
    char string3[5] = "";
    assert(0 < Compare(string2, string3, 0));
}

int main(void){
    
    TestGetLength();
    TestGetLength2();

    TestIsEmpty();
    TestIsEmpty2();

    TestPower1();
    TestPower2();
    TestPower3();

    TestCompare();

    printf("La prueba concluyó sin errores\n");
}