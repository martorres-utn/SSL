# Especificaciones matemáticas de operaciones con cadenas

1.  **GetLength: V\* -> N**

    Conjunto de salida **V\***: Clausura de Kleene del alfabeto.
    
    Conjunto de llegada **N**: Conjunto de números naturales.

    **Ejemplos**:

        GetLength(abc) -> 3
        GetLength(cba) -> 3
        GetLength(hola) -> 4

2.  **IsEmpty: V\* -> \{V,F\}**

    Conjunto de salida **V\***: Clausura de Kleene del alfabeto.
    
    Conjunto de llegada **{V, F}**: V por Verdadero si la cadena es vacía. F por Falseo si la cadena NO está vacía.

    **Ejemplos**:

        IsEmpty(abc) -> F
        IsEmpty(a) -> F
        IsEmpty() -> V

3.  **Power: V\* x N -> V\***

    Conjunto de salida **V\* x N**: Conjunto resultante del producto cartesiano de Clausura de Kleene del alfabeto y Conjunto de números naturales N. Es decir conjunto de infinitos pares ordenados (V\*, N).
    
    Conjunto de llegada **V\***: Clausura de Kleene del alfabeto.

    **Ejemplos**:

        Power((abc, 2)) -> abcabc
        Power((a, 3)) -> aaa

4. **Compare: V\* x V\* -> {-1, 0, 1}**

    Conjunto de salida **V\* x V\***: Conjunto resultante del producto cartesiano de Clausura de Kleene del alfabeto con sigo mismo. Es decir un conjunto de infinitos pares ordenados (V\*, V\*).

    Conjunto de llegada **{-1, 0, 1}**: -1 si el primer componente (primera cadena) del par ordenado es menor que el segundo. 0 si ambas cadenas son iguales. 1 si la primer cadena es mayor que la segunda.

    **Ejemplos**:

        Compare((abc,abc)) -> 0
        Compare((abc,abd)) -> -1
        Compare((abd,abc)) -> 1

