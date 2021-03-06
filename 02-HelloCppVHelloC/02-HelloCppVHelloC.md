# Comparación de algoritmo "Hello World"
* **Lenguaje C**

        #include <stdio.h>

        int main(void) {
            printf("Hello, World\n");
        }

* **Lenguaje C++**

        #include <iostream>

        int main() {
            std::cout << "Hello World!";
        }

| Niveles | **Diferencias** <br><br> hello.c vs hello.cpp | **Similitudes** <br><br> hello.c vs hello.cpp |
|---|---|---|
| **Léxico** | 1. La biblioteca standard de C es **stdio.h** y de C++ es **iostream**. <br><br> 2. C no utiliza **namespaces** para englobar definiciones y C++ sí soporta **namespaces**: por ejemplo **"std"**. | 1. Ambos incluyen bibliotecas a través de la palabra clave **"#include"**.<br><br>2. Reconocen la cadena **"main"** como el nombre de la función principal del programa.<br><br>3. Ambos reconocen **"{"** y **"}"** como delimitadores de un bloque de instrucciones.<br><br>4. Reconocen el caracter **";"** como el fin de una linea de instrucción.<br><br> 5. Reconocen las doble comillas **"** como el comienzo o fin de una cadena de caracteres.<br><br> 6. Ambos reconocen **"int"** como un tipo de dato. <br><br> 7. Ambos reconocen **"("** y **")"** como delimitadores de un listado de parámetros o argumentos.|
| **Sintáctico** | 1. Incluir una biblioteca en **C requiere nombrar la extensión .h** y en C++ no es necesario.<br><br>2. Llamar una función o variable dentro de un **namespace** en C++ requiere usar el **namespace** como prefijo concatenado con dos veces dos puntos: **"namespace::"**. Por ejemplo **"std::cout"**. | 1. Ambos requieren encerrar los bloques de instrucciones con **"{"** y **"}"**, a toda llave de apertura **"{"**, le corresponde una llave de cierre **"}"**.<br><br>2. Ambos requieren encerrar cadenas de caracteres entre comillas dobles **"**. A toda apertura de cadena usando **"** le corresponde un cierre usando el mismo símbolo.<br><br> 3. La inclusión de bibliotecas mediante **"#include"** requiere nombrar la biblioteca encerrada entre **"<"** y **">"** o comillas dobles **"**.<br><br> 4. Los argumentos o parámetros se listan encerrados entre **"("** y **")"**. |
| **Semántico** | 1. En C la instrucción que muestra la cadena "Hello world!" envía la cadena como argumento a una función **"printf"** mientras que en C++ la cadena es asignada a una variable **"std::cout"**. | 1. Ambos definen una función principal que retorna un valor entero. |