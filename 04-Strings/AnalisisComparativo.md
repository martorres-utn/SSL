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
        
            https://wiki.haskell.org/GHC/Memory_Management

            https://making.pusher.com/memory-profiling-in-haskell/

            Haskell tiene un Garbage Collector que se encarga de liberar la memoria de las variables que ya no estén siendo utilizadas.
            
            Las variables son inmutables así que cada vez que se llama a una función se genera una copia de ese valor para que la función pueda manipularlo.


    1. **Lenguaje C**

        En C un string puede ser reservado de forma estática como un arreglo estático tipo char. 
        
        Un string también puede ser definido como un arreglo char dinámico.

        Al momento de enviarlo como argumento a una función se envía un puntero que apunta al primer elemento del arreglo char.

    e. ¿El tipo tiene mutabilidad o es inmutable?
    
    f. ¿El tipo es un first class citizen?
    
    g. ¿Cuál es la mecánica para ese tipo cuando se lo pasa como argumentos?
    
    h. ¿Y cuando son retornados por una función?

