# Análisis Comparativo

1. Análisis Comparativo del tipo String en Lenguajes de Programación:

    Realizar un análisis comparativo de dato String en el lenguaje C versus un lenguaje de programación a elección. El análisis debe contener, por lo menos,los siguientes ítems:
    
    a. **¿El tipo es parte del lenguaje en algún nivel?**

    1. **Lenguaje Haskell**
        
        Los String son un tipo de dato dentro del lenguaje Haskell.
    
        Es parte de Haskell a nivel léxico, sintáctico y semántico.
    
        **Nivel léxico y sintáctico**: ya que Haskell reconoce como String cualquier cadena de caracteres encerrada entre ".
    
        **Nivel semántico**: ya que para Haskell un String es una lista [Char] y este tipo de datos tiene un conjunto de operadores y funciones pre establecido. 
    
        Adicionalmente al ser una lista [Char] cualquier función u operador aplicable a una lista se podrá aplicar a un String.
    
    2. **Lenguaje C**

        Si tomamos la definición de Tipo de Dato como un conjunto de valores posibles y operaciones que se pueden efectuar sobre esos valores, entonces el tipo String no es un tipo de dato dentro del lenguaje C (al menos no lo es como lo son int y float). 

        Sin embargo el compilador a nivel léxico y sintáctico procesa cadenas literales como arreglos char.

        **Nivel léxico y sintáctico**: el compilador reconoce cadenas encerradas entre ".
        
        **Nivel semántico**: el compilador trata un literal "abc" como un arreglo de char : ['a', 'b', 'c'] y es posible procesarlo como tal.

        **Para poder usar cadenas en C es necesario incluir una biblioteca (string.h) o el usuario debe implementar sus propias funciones para manipular cadenas.**

    b. ¿El tipo es parte de la biblioteca?
    
    1. **Lenguaje Haskell**
        
        En Haskell los String son un tipo de dato intrínseco del lenguaje y no es necesario importar una biblioteca para manipularlos. Existen operadores por defecto que pueden ser aplicados sobre un dato String
        
        Sin embargo existen bibliotecas para agregar más funciones para manipular Strings por ejemplo Data.Strings.
    
    2. **Lenguaje C**

        En las bibliotecas standard de C no se define propiamente un tipo String. Pero se definen funciones que sirven para manipularlos y el compilador transforma cualquier sucesión de caracteres encerrados entre " en un arreglo de char. Dichos arreglos se pueden manipular mediante string.h de la biblioteca standard.

    c. ¿Qué alfabeto usa?
    
    1. **Lenguaje Haskell**
        
        Haskell entiende un String como una lista de Char y un Char como una enumeración de valores Unicode bajo el estandard internacional ISO/IEC 10646 que es una extensión de ISO 8859-1 y que a su vez es una extensión de ASCII.
    
    2. **Lenguaje C**

        En C el alfabeto que se usa para un char es UTF-8 (este es el alfabeto que viene por defecto pero es posible especificar otros).

    d. **¿Cómo se resuelve la alocación de memoria?**
    
    1. **Lenguaje Haskell**: 
        
        Haskell deja muchos residuos en memoria porque los datos son considerados inmutables. La única forma de almacenar resultados de operaciones intermedias es a través de la creación de nuevas variables. Por este motivo es común que un programa en Haskell genere una huella de 1gb de datos por segundo (la gran mayoría serán limpiados posteriormente por el Garbage Collector de Haskell).

        *Fuente*: 
            
        https://wiki.haskell.org/GHC/Memory_Management

    2. **Lenguaje C**

        Las variables pueden ser definidas de forma estática en el segmento de datos de un programa, que es una región especial de la memoria para guardar sólo datos marcados como "static". Esto permite que vivan durante toda la ejecución del programa.
        
        También pueden ser definidas en el "Stack" por una función. El stack es una región especial de memoria de la computadora que almacena variables temporales locales creadas por las funciones. Esto quiere decir que al momento de invocar una función se cargan automáticamente las N variables necesarias para esa función en el Stack y al momento de finalizar la ejecución de esa función el espacio ocupado por esas N variables es liberado. El desarrollador no debe preocuparse por liberar esa memoria (tampoco hay necesidad de un Garbage Collector). Las variables del stack son locales a la función que las haya creado. Es decir que desde una función A no se puede acceder a un conjunto de variables de Stack de una función B.

        También se pueden definir variables en el "Heap" que es otra región de memoria donde se puede reservar espacio para datos en tiempo de ejecución. El Heap permite reservar grandes espacios de memoria (más que el Stack), también es más laxo al permitir acceder esos datos desde cualquier otra función (sólo es necesaria la dirección de memoria) y por otro lado la liberación de memoria no es automática y debe ser ordenada explícitamente por el programa, de lo contrario esa región de memoria no podrá ser utilizada nuevamente.

        Teniendo en cuenta lo anterior y que en C un string es un arreglo de tipo char, dicho arreglo puede ser definido como "static", también puede ser definido en el Stack como una variable local a una función o también puede ser reservado de forma dinámica en el Heap (en cuyo caso se necesita liberar la memoria después de haber utilizado esa cadena). 
        
    e. ¿El tipo tiene mutabilidad o es inmutable?
        
    1. **Lenguaje Haskell**

        En Haskell todos los tipos son inmutables por defecto, incluso los String. Esto asegura la transparencia referencial que lo caracteriza como lenguaje. Como consecuencia, no se puede realizar una asignación destructiva de una variable, no se puede pisar un valor previamente existente y asignar otro. 
        
        Sin embargo es posible crear código que use variables mutables a través del uso de módulos especiales que permiten crear variables mutables, operarlas y asignarlas.

    2. **Lenguaje C**

        En C por defecto las variables creadas son mutables, incluso los String. Para lograr que una variable sea inmutable y sólo pueda leerse el valor que guarda es necesario usar la palabra clave "const" al momento de declararla.

        Por ejemplo, esta cadena "hola" sólo puede ser leida y no puede ser asignada o modificada de ninguna forma:

            const char cadena[10] = "holi";

        Al intentar modificarla en el código obtendremos un error en tiempo de compilación:

            StringTest.c: In function ‘main’:
            StringTest.c:205:16: error: assignment of read-only location ‘cadena[3]’
            205 |     cadena2[3] = 'a';

    f. ¿El tipo es un first class citizen?

    **Definición de "First class Citizen"**

    El concepto de objetos de primera y segunda clase fue introducido por Christopher Strachey en 1960 cuando comparaba números reales y procedimientos en el lenguaje ALGOL.

    Luego se llegó a una definición menos ambigüa a través de Robin Popplestone. Un first class citizen debe cumplir:

     1. **Puede ser enviado como parámetro de una función**.
 
     2. **Puede ser devuelto como resultado de una función**.
 
     3. **Puede ser sujeto de una sentencia de asignación**.
 
     4. **Puede ser testeado mediante la equidad o igualdad**.

    Considerando lo anterior para los tipo "String" en los siguientes lenguajes:

    1. **Lenguaje Haskell**
    
        Un tipo String puede ser enviado como parámetro a una función, también puede ser devuelto como resultado y puede ser sujeto de una asignación de una variable al momento en que la variables es definida. También puede ser testeado en una condición lógica mediante el operador de igualdad "==". Por todo lo anterior se puede concluir que el tipo String en Haskell es un First class Citizen.

    2. **Lenguaje C**

        En C un string es tratado como un arreglo de char con lo cual para ser enviado como argumento a una función en realidad se envía un puntero al primer elemento de ese array, para acceder al resto de los valores hay que computar un desplazamiento con respecto a esa primer posición.

        Para ser devuelto como resultado de una función, dicha función debe optar por dos caminos: 

        Escribir el string resultante en un bloque de memoria facilitado a la función como salida o
        crear una cadena en el Heap en tiempo de ejecución y devolver la dirección de memoria al primer elemento. 
        
        Por ambos caminos la cadena es devuelta como resultado de una función indirectamente.

        Para String y arreglos en general no se pueden asignar valores directamente excepto en el momento de declaración del arreglo.
        
        Ejemplo, compilar el siguiente fragmento:

            char cadena[10] = "hola";

            cadena = "holi";

        Resulta en el siguiente error:

            gcc -c String.c StringTest.c -std=c18 -g 
            StringTest.c: In function ‘main’:
            StringTest.c:203:12: error: assignment to expression with array type
            203 |     cadena = "holi";

        Para saber si un dato tipo String es igual a otro es necesario invocar una función para testear si es igual o no. El operador de igualdad "==" no se comporta de igual manera para los arreglos o Strings como para el resto de los tipos de datos.

        Por ejemplo para comparar cadenas en C se utiliza la función strcmp de la librería estandard.

    g. ¿Cuál es la mecánica para ese tipo cuando se lo pasa como argumentos?
    

    1. **Lenguaje Haskell**

        El tipo String puede ser argumento de una función de forma directa sin necesidad de direcciones de memoria apuntando al comienzo de la cadena, tampoco es necesario computar un desplazamiento de la memoria explícitamente.

    2. **Lenguaje C**

        El tipo String se puede enviar como argumento de una función a través de un puntero señalando el comienzo de la cadena y además la cadena debe finalizar con un caracter nulo de finalización: '\0'.

    h. ¿Y cuando son retornados por una función?

    1. **Lenguaje Haskell**

        El tipo String puede ser devuelto como resultado de una función sin necesidad de punteros o mecanismos de direccionamiento de memoria.

    2. **Lenguaje C**

        El tipo String puede ser devuelto como resultado de una función a través de un puntero señalando el comienzo de un espacio de memoria libre para almacenar el resultado o reservando una un bloque de memoria en el Heap que será escrito por la función y luego devuelto en forma de dirección de memoria apuntando al primer elemento.