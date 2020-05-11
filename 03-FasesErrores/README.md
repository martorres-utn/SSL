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

3. Escribir hello3.c, una nueva variante:

        int printf(const char *s, ...);
        
        int main(void){ 
            int i=42; 
            prontf("La respuesta es %d\n")
    
4. Investigar la semántica de la primera línea.
    
    Se declara una función llamada printf que recibe como primer argumento un puntero tipo char constante llamado "s". Los puntos suspensivos indican que la cantidad de argumentos que suceden al primero es variable.

5. Preprocesar hello3.c, no compilar, y generar hello3.i. Buscar diferenciasentre hello3.c y hello3.i.

    hello3.i:

        # 1 "hello3.c"
        # 1 "<built-in>"
        # 1 "<command-line>"
        # 1 "hello3.c"
        int printf(const char *s, ...);

        int main(void){
            int i=42;
            prontf("La respuesta es %d\n");
    
    Es parecido a hello3.c sólo que la instrucción \#include fue reemplazada por los linemarkers que hacen referencia a la biblioteca \<built-in\> y \<command-line\>. Luego aparece el código de nuestro archivo hello3.c

6. Compilar el resultado y generar hello3.s, no ensamblar.

        PS C:\repos\SSL\03-FasesErrores> gcc hello3.i -S -o hello3.s
        hello3.c: In function 'main':
        hello3.c:5:5: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]
            5 |     prontf("La respuesta es %d\n");
            |     ^~~~~~
            |     printf
        hello3.c:5:5: error: expected declaration or statement at end of input
    
    Corregimos: reemplazamos prontf por printf y volvemos a generar hello3.i y a compilarlo.

        PS C:\repos\SSL\03-FasesErrores> gcc hello3.c -E -o hello3.i
        PS C:\repos\SSL\03-FasesErrores> gcc hello3.i -S -o hello3.s
        hello3.c: In function 'main':
        hello3.c:5:5: error: expected declaration or statement at end of input
            5 |     printf("La respuesta es %d\n");
            |     ^~~~~~
    
    Corregimos: cerramos con "}" la función main en hello3.c y volvemos a generar hello3.i y hello3.s.

        int printf(const char *s, ...);

        int main(void){
            int i=42;
            printf("La respuesta es %d\n");
        }

    Volvemos a compilar (esta vez sin errores):

        PS C:\repos\SSL\03-FasesErrores> gcc hello3.c -E -o hello3.i
        PS C:\repos\SSL\03-FasesErrores> gcc hello3.i -S -o hello3.s

    Se generó el archivo hello3.s que contiene código de Assembler

            .file	"hello3.c"
            .text
            .def	___main;	.scl	2;	.type	32;	.endef
            .section .rdata,"dr"
        LC0:
            .ascii "La respuesta es %d\12\0"
            .text
            .globl	_main
            .def	_main;	.scl	2;	.type	32;	.endef
        _main:
        LFB0:
            .cfi_startproc
            pushl	%ebp
            .cfi_def_cfa_offset 8
            .cfi_offset 5, -8
            movl	%esp, %ebp
            .cfi_def_cfa_register 5
            andl	$-16, %esp
            subl	$32, %esp
            call	___main
            movl	$42, 28(%esp)
            movl	$LC0, (%esp)
            call	_printf
            movl	$0, %eax
            leave
            .cfi_restore 5
            .cfi_def_cfa 4, 4
            ret
            .cfi_endproc
        LFE0:
            .ident	"GCC: (MinGW.org GCC Build-20200227-1) 9.2.0"
            .def	_printf;	.scl	2;	.type	32;	.endef

7. Corregir  en  el  nuevo  archivo  hello4.c  y  empezar  de  nuevo, generar hello4.s, no ensamblar.

8. Investigar hello4.s.

    hello4.s contiene código Assembler:

    	.file	"hello4.c"
            .text
            .def	___main;	.scl	2;	.type	32;	.endef
            .section .rdata,"dr"
        LC0:
            .ascii "La respuesta es %d\12\0"
            .text
            .globl	_main
            .def	_main;	.scl	2;	.type	32;	.endef
        _main:
        LFB0:
            .cfi_startproc
            pushl	%ebp
            .cfi_def_cfa_offset 8
            .cfi_offset 5, -8
            movl	%esp, %ebp
            .cfi_def_cfa_register 5
            andl	$-16, %esp
            subl	$32, %esp
            call	___main
            movl	$42, 28(%esp)
            movl	$LC0, (%esp)
            call	_printf
            movl	$0, %eax
            leave
            .cfi_restore 5
            .cfi_def_cfa 4, 4
            ret
            .cfi_endproc
        LFE0:
            .ident	"GCC: (MinGW.org GCC Build-20200227-1) 9.2.0"
            .def	_printf;	.scl	2;	.type	32;	.endef

    *Observaciones*

    * El archivo comienza con .file	"hello4.c" que nos indica el archivo del que provino el código assembler.
    
    * Luego .text indica el comienzo de una sección de código.
    
    * La línea: .section .rdata,"dr" indica la declaración de datos que estarán disponibles en modo sólo lectura para el programa (no pueden ser asignados o sobre-escritos).

    * LC0 (local constant 0) es una directiva de assembler que indica la declaración de una constante, el código que sucede a esta marca LC0 corresponde a la constante del texto "La respuesta es %d\12\0".

    * .globl	_main indica la definición de un símbolo "_main" que es global y accesible desde cualquier otro archivo. 

    * LFB0: Local function begin 0. Indica el comienzo de una función local del programa. Después de esta directiva encontramos las instrucciones de assembler que representan a la función main.

    * A continuación dejo comentarios en las lineas de instrucción de assembler explicando lo que hace cada una.

            LFB0:
                .cfi_startproc
                pushl	%ebp                ; Manda el valor del registro %ebp al stack
                .cfi_def_cfa_offset 8
                .cfi_offset 5, -8
                movl	%esp, %ebp          ; Copia el valor del stack pointer %esp al registro %ebp.
                .cfi_def_cfa_register 5
                andl	$-16, %esp          ; Ejecuta un and binario entre el valor -16 y  el valor en registro %esp y el resultado lo guarda en $esp en los primeros 32 bits.
                subl	$32, %esp           ; Resta 32 al registro %esp
                call	___main             ; Invoca función main
                movl	$42, 28(%esp)       ; Copia el valor 42 en reggistro %esp, la forma en la que está escrito el registro destino: 28(%esp) indica que estamos obteniendo el valor que contiene %esp 28 bytes corridos de la dirección %esp (ni idea qué significa esto).
                movl	$LC0, (%esp)        ; Copia el valor LC0 (la cadena de texto constante) en registro %esp (stack pointer)
                call	_printf             ; Llama a _printf
                movl	$0, %eax            ; copia 0 en %eax que es el registro que contiene el resultado de la función
                leave                       ; Libera el stack frame creado por una instrucción ENTER previa (supongo que está implicita en algun lado del código)
                .cfi_restore 5
                .cfi_def_cfa 4, 4
                ret                         ; Retorno de función, devuelve el control a la función llamadora supongo que a quien haya llamado a la función main.
                .cfi_endproc

9. Ensamblar hello4.s en hello4.o, no vincular.

10. Vincular hello4.o con la biblioteca estándar y generar el ejecutable.

11. Corregir en hello5.c y generar el ejecutable.

12. Ejecutar y analizar el resultado.

13. Corregir en hello6.c y empezar de nuevo.

14. Escribir hello7.c, una nueva variante:

        int main(void){ 
            int i=42;    
            printf("La respuesta es %d\n", i);
        }

15. Explicar porqué funciona.