* **Usuario github:** martorres-utn

* **Legajo:** 172.400-9

* **Apellido:** Torres

* **Nombre:** Marcos Emanuel

* **Número y título del trabajo:** TP Nº 3 Fases de la Traducción y Errores

* **Compilador seleccionado:** MinGW

# Secuencia de Pasos

1. Escribir hello2.c que es una variante de hello.c

        #include <stdio.h>

        int/*medio*/main(void){
            int i=42;
            prontf("La respuesta es %d\n");

2. Preprocesar hello2.c, no compilar y generar hello2.i. Analizar su contenido:

        PS C:\repos\SSL\03-FasesErrores> gcc hello2.c -E -o hello2.i
    
    Obtuve un archivo hello2.i que en las primeras lineas tiene un listado de bibliotecas y encabezados .h
    Luego aparecen definiciones de tipos que creo que provienen de la biblioteca standard del compilador MinGW (gcc).
    Al final del archivo está el código de nuestra función main sin el comentario /\*medio/\* que fue reemplazado por un espacio.

    De acuerdo a la documentación de GCC: https://gcc.gnu.org/onlinedocs/gcc-9.2.0/cpp/Preprocessor-Output.html

    El preprocesador toma las siguientes decisiones cuando procesa nuestro código:

    * Reemplaza todas las lineas de directiva por líneas en blanco y reemplaza todos los comentarios con espacios.

    * Los espacios entre tokens son reemplazados por 1 solo, con la excepcion del primer token en una linea no directiva precedido por espacios suficientes como para aparecer en la misma columna en el resultado del preprocesamiento y en el archivo fuente original.

    * En hello2.i aparecen lineas denominadas "linemarkers" con la siguiente estructura
    
            # numero_linea nombre_archivo flags

        Por ejemplo:

            # 1 "hello2.c"
            # 1 "<built-in>"
            # 1 "<command-line>"
            # 1 "hello2.c"
            # 1 "c:\\mingw\\include\\stdio.h" 1 3
            # 38 "c:\\mingw\\include\\stdio.h" 3
        
        La combinación de numero_linea y nombre_archivo significa que la SIGUIENTE línea se originó en el archivo con ese nombre en el número de linea indicado.

        Después de nombre_archivo pueden venir 0 o multiples flags. Si hay multiples flags estos son separados por espacios. Los flags posibles son: '1', '2', '3' o '4'. Significado de los flags:

        * '1' Indica el comienzo de un nuevo archivo.
        
        * '2' Indica el retorno a un archivo después de haber incluido otro.
        
        * '3' Indica que el siguiente texto proviene de un archivo encabezado del sistema por lo que algunos warnings no serán tenidos en cuenta.
        
        * '4' Indica que el siguiente texto deberá ser tratado como si estuviera envuelto en un bloque implícito *extern* de lenguaje "C".

        En algunos casos luego de un "linemarker" aparece código C. Por ejemplo:

            # 210 "c:\\mingw\\include\\stdio.h" 3
            typedef struct _iobuf
            {
                char *_ptr;
                int _cnt;
                char *_base;
                int _flag;
                int _file;
                int _charbuf;
                int _bufsiz;
                char *_tmpfname;
            } FILE;

        Este "linemarker" indica que ese bloque typedef se originó en la línea 210 de c:\mingw\include\stdio.h

        Después de muchas lineas con definiciones de variables globales y tipos de datos de la biblioteca standard encontramos un linemarker apuntando a nuestra función main

            # 3 "hello2.c"
            int main(void){
                int i=42;
                prontf("La respuesta es %d\n");



