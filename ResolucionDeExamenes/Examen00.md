# UTN FRBA – SSL – K2051 – Examen #0 – Recuperatorio #0 – 2020-03-301. 

## Parte I

1. **Indique la tarea más representativa para la cual un Ingeniero en Sistemas de Información estácalificado.**

	Un Ingeniero en Sistemas de Información está calificado para analizar un problema relacionado a la producción o procesamiento de información y aplicar una solución mediante el desarrollo o la mejora de un sistema que procesa información. Dicho sistema puede estar constituido por máquinas, personas o métodos.

2. **Defina información.**

	Información es el resultado del procesamiento de un conjunto de datos. La información es suceptible de ser interpretada, tiene un significado y puede ser utilizada para tomar decisiones. Los datos son unidades discretas sin procesar que no representan más que hechos o eventos del mundo de forma aislada.

3. **Indique las asignaturas del área de programación.**

	1. Matemática Discreta
	2. Algoritmos y Estructuras de Datos
	3. Sintaxis y Semántica de los Lenguajes
	4. Paradigmas de Programación
	5. Gestión de Datos

4. **Indique las asignaturas del área de sistemas de información.**

	1. Sistemas y Organizaciones
	2. Análisis de Sistemas
	3. Diseño de Sistemas

5. **Indique el paradigma de programación aplicado en primer año de la carrera.**

	Programación estructurada fue el paradigma aplicado durante el primer año de la carrera.

6. **Defina abstracción.**

	La abstracción es la acción de separar características esenciales e importantes de una entidad, dejando de lado detalles de fondo, esto permite reducir la complejidad cuando se intenta modelar o representar la realidad.

## Parte II

1. **Indique diferencias entre secuencia y conjunto.**

	Una secuencia o sucesión es una lista de elementos, numerada en el orden creciente de los números naturales en cambio un conjunto es una colección de objetos de una misma especie, esta colección no implica un orden.

2. **Defina el concepto matemático secuencia.**
	
	Una secuencia o sucesión es una lista de elementos numerables y ordenados, es decir que a cada número en el conjunto de los números naturales le corresponde un elemento de la sucesión. Esta correspondencia puede ser con el mismo conjunto de números naturales o con conjuntos de otro tipo. Puede decirse que una sucesión es una función con dominio N (naturales) y codominio A (cualquier otro conjunto).

3. **Defina función matemática.**

	Una función matemática es una relación entre dos conjuntos cualquiera. Supongamos función F que relaciona conjuntos A y B. 

	Dicha relación es un subconjunto del producto cartesiano A x B y para ser considerado función debe cumplir:

	1. **Existencia**: Todo elemento del conjunto A debe relacionarse con alguno del conjunto B.
	2. **Unicidad**: Un mismo elemento del conjunto A no puede relacionarse con dos elementos distintos del conjunto B.

4. **Defina grafo.**

	Definición informal: es un conjunto de puntos o nodos unidos por arcos o aristas.
	
	Definición formal: es una terna G = (V; A; r) siendo:

	* **V**: un conjunto de vértices no vacío.
	* **A**: un conjunto de aristas.
	* **r**: una función de incidencia r: A -> V\'\' y V\'\' es un conjunto formado por subconjuntos de 1 o 2 elementos de V.

5. **Defina partición de un conjunto.**
	
	Sea un conjunto no vacío A, la partición de A es otro conjunto P constituido a su vez por otros conjuntos: P = { A1, A2, ... , An}. P es partición si y sólo si cumple lo siguiente:
	
	1. Para todo i: Ai no es vacío. Esto significa que todos los elementos dentro de P no son vacíos.
	2. Para todo i distinto de j se verifica que: Ai intersección con Aj es vacío. Esto significa que para cualquier par de elementos dentro de P, la intersección entre ellos no posee elementos (no hay elementos en común).
	3. La unión de todos los elementos Ai es igual al conjunto original A.

6. **Sea X={a,b} indique P(X)**
	
	P(X) = { {}, {a}, {b}, {a, b} }

7. **Defina Lenguaje Formal.**

	Un lenguaje formal es un conjunto L que está incluido dentro de V\*. Siendo V\* el conjunto de todas las palabras de cualquier longitud que pueden formarse con el alfabeto V. Es decir que L es un subconjunto de V\*.

8. **Defina autómata finito.**

	Un autómata finito es una máquina virtual que es capaz de reconocer un lenguaje L. Formalmente es una quintupla formada por:

	A = (Q; V; r; q0; F)

	* **Q**: Conjunto finito de estados.
	* **V**: Alfabeto.
	* **r**: función de transición: Q x V -> Q.
	* **q0**: estado inicial
	* **F**: Conjunto de estados finales. Este conjunto no puede ser vacío y debe estar incluido dentro de Q.

## Parte III

1. **Defina algoritmo.**

	Es un conjunto finito de pasos y reglas lógicas que deben cumplirse de forma precisa para resolver un problema.

2. **Defina programación estructurada.**

	Es un paradigma que permite la creación de un programa a través de la combinación de módulos. Esto permite descomponer un problema cualquiera en piezas más pequeñas que simplifican su resolución.

3. **Indique las tres estructuras de control de flujo de ejecución de la programación estructurada**
	
	Las estructuras de control de flujo de ejecución en la programación estructurada son:

	* **Estructuras Secuenciales:** Son acciones que se ejecutan en secuencia en el orden natural en el que fueron escritas en el texto que representa el programa. Las instrucciones de entrada, salida y asignación son ejemplo de estructuras secuenciales.

	* **Estructuras de Selección o Decisión:** Evalúan el valor de verdad de una proposición lógica (o de varias) y toman una ruta de acción u otra. Son capaces de reemplazar la ejecución de un bloque de instrucciones por otro.

	* **Estructuras de Repetición:** Se basan en el valor de verdad de una proposición lógica (o de varias), en caso de que se cumplan permiten ejecutar un bloque de instrucciones mientras esa proposición siga siendo verdadera, la repetición se interrumpe si la condición resulta falsa. También existen variaciones de esta estructura que permiten repetir una cantidad finita de veces una instrucción (apoyandose en una variable contador y en un valor límite).

4. **Indique las diferencias entre parámetro y argumento.**

	Un parámetro es la variable en la enumeración de entradas o salidas de un módulo. Por ejemplo:

		int mayor(int valorA, int valorB);

	Un argumento es el valor que está siendo enviado al módulo al momento de ser invocado:

		int valorMayor = mayor(15, 42); //argumentos 15 y 42

5. **Explique las dos formas de transferencia de argumentos.**

	Los argumentos pueden ser pasados a un módulo de las siguientes formas:

	* **Por Valor:** Cuando un módulo recibe un argumento por valor antes de comenzar a ejecutar su correspondiente bloque de instrucciones, realiza una copia de ese valor recibido. Las instrucciones del módulo trabajarán con esa copia del valor sin afectar el argumento enviado en el contexto exterior (el contexto que lo invocó).

	* **Por Referencia:** Cuando un módulo recibe un argumento por referencia no realiza una copia del valor recibido sino que trabaja directamente con el valor original. Las instrucciones del módulo trabajarán con ese valor original afectándolo. Si el conjunto de instrucciones del módulo lo modifica de alguna forma, ese cambio podrá verse en el contexto en el que se invocó el módulo.

6. **Explique las diferencias entre parámetros de entrada, de salida y de entrada/salida.**
	
	Los parámetros de entrada son los valores que procesa un módulo para generar un resultado.

	Los parámetros de salida son valores que recibe un módulo para depositar en ellos un resultado. Se utilizan cuando un módulo produce más de 1 resultado.

	Los parámetros de entrada/salida son una combinación de los dos anteriores. Son valores que un módulo recibe para procesarlos y también depositar en ellos los resultados.

7. **Defina tipo de dato abstracto.**

	Un Tipo da Dato Abstracto puede ser definido como una clase de objetos cuyo comportamiento lógico está definido por un conjunto de valores y un conjunto de operaciones.

	La definición de un Tipo de Dato Abstracto sólo menciona las operaciones posibles de realizar pero no especifica cómo son implementadas. Tampoco especifica cómo se organizarán los datos en memoria ni qué algoritmos se utilizarán para realizar las operaciones. 

	Se puede decir que un Tipo de Dato Abstracto está definido por su comportamiento desde el punto de vista del usuario, el usuario no sabe cómo está implementado internamente, cómo se procesa una operación para ese tipo, al usuario sólo le interesa cómo se comporta.

	Ejemplos de Tipo de Dato Abstracto: Pila, Cola, Lista.

8. **Indique las diferencias entre una pila y una cola**

	En una pila los últimos elementos agregados son los primeros en salir, como consecuencia de esto al ser vaciada los elementos son devueltos en el orden inverso en el que fueron agregados.
	
	En cambio en una cola los primeros elementos agregados son los primeros en salir, esto quiere decir que se respeta el orden cronológico en el que se fueron agregando.

9. **Defina archivo.**
	
	Es una estructura de datos que permite almacenamiento físico en disco. Permite operaciones de asignación, apertura, creación, cierre, lectura, grabación, obtención de cantidad de elementos, posición del puntero en un archivo, acceso a una posición determinada de un archivo, acceso al final del archivo.
	
	Pueden ser de dos tipos:

	* **Archivos de texto:** Secuencia de líneas compuestas por caracteres de un alfabeto, algunos caracteres especiales se utilizan para separar con espacios o crear saltos de línea.

	* **Archivos binarios:** Secuencia de bloques de bytes. Para su lectura se debe contar con la definición del bloque a través de un struct, por eso el tamaño del struct es un argumento utilizado en el proceso de lectura de un archivo binario.

10. **Diseñe un algoritmo que dado un arreglo de naturales a y su longitud n calcule el promedio.**

		unsigned int CalcularPromedio (unsigned int a[], unsigned int n)
		{
		    double suma = 0;
		    for(unsigned int ind = 0; ind < n; ind++)
		    {
		        suma += a[ind];
		    }

		    return (suma / n);
		}
