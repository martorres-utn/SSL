#include "String.h"
#include <assert.h>
#include <string.h>

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