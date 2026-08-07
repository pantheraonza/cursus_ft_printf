*Este proyecto ha sido creado como parte del currículo de 42 por criredon.*


Bloque	Estado
1 — %c, %%	✅
2 — %s con NULL	✅
3 — %d, %i	✅
4 — %u	✅
5 — %x, %X	⬜
6 — %p	⬜
7 — integración final	⬜




























# ft_printf

---

## 1. Descripción General - ¿Cuál es el objetivo del proyecto ft_printf?

El proyecto `ft_printf` es la reimplementación desde cero de la función `printf()` de la librería estándar de C. El objetivo es entender cómo funciona y porqué se ejecuta sin conocer la cantidad de argumentos que va a recibir - entender las **funciones variádicas** (funciones que aceptan un número desconocido de argumentos en tiempo de compilación). 

El resultado final es una librería estática, `libftprintf.a`, que contiene una única función:

```c
int ft_printf(const char *, ...);
```

En la función recreada se implementan de forma obligatoria las conversiones `c s p d i u x X %`, y de forma bonus, la gestión de cualquier combinación de flags (`-`, `0`, `#`, ` `, `+`), el ancho mínimo de campo y la precisión de las conversiones.

---

## 2. Instrucciones - ¿Cómo se utiliza la función ft_printf?

### 2.1 Compilación, instalación y ejecución

| Comando | Efecto |
|---|---|
| `make` | Compila `libft` (con su propio Makefile) y después `libftprintf.a`, dejándola en la raíz del repositorio |
| `make bonus` | Añade a la librería las conversiones con flags y el ancho mínimo, compiladas desde archivos `_bonus.c` / `_bonus.h` independientes |
| `make clean` | Elimina los archivos objeto (`.o`) | 
| `make fclean` | Elimina objetos y la librería `.a` |
| `make re` | Equivale a `fclean` + `all` |

Para usar la librería en un programa de prueba propio:

```
cc main.c libftprintf.a -o test
./test
```

### 2.2 Ejemplos de uso
 
```c
ft_printf("Hola %s, tienes %d años\n", "Cris", 22);
// -> Hola Cris, tienes 22 años
 
ft_printf("En hex: %x | En HEX: %X | Puntero: %p\n", 255, 255, &var);
// -> En hex: ff | En HEX: FF | Puntero: 0x7ffee3a1c
 
ft_printf("[%5d][%-5d][%05d]\n", 42, 42, 42);
// -> [   42][42   ][00042]
```

---
 
## 3. Recursos
 
### 3.1 Referencias clásicas consultadas

La implementación de este proyecto se basa en la especificación oficial del proyecto de 42 y cuenta con el respaldo de referencias confiables para el lenguaje C. 

- Manuales de Programación de Linux: man 3 printf, man 3 stdarg.
- Especificaciones POSIX-Open Group: printf, stdarg.h
- Libros: El Lenguaje de Programación C de Brian Kernighan & Dennis Ritchie, Introducción a Algoritmos de Thomas Cormen, Code Complete de Steve McConnell y Crafting Interpreters de Robert Nystrom.

### 3.2 Tutoriales y repositorios consultados

Se revisaron tutoriales y repositorios de otros programadores con experiencia, para contrastar decisiones técnicas y recursos empleados, además de obtener testers que permitieran verificar la funcionalidad del programa.

Tutoriales de programadores que considero referentes:
- https://suspectedoceano.notion.site/
- https://parzibyte.me/blog/2020/12/30/struct-c/

Proyectos incluyendo el bonus:
- https://github.com/42-alberto/printf (42Madrid)
- https://github.com/dmsosa/42-printf (42Madrid)
- https://github.com/VniiD/Printf (42SaoPaulo)
- https://github.com/librity/ft_printf (42SaoPaulo)
- https://github.com/mcombeau/ft_printf (42Paris)

Proyectos sin bonus:
- https://github.com/mapena-z/ft_printf (42Madrid)
- https://github.com/vittoric/ft_printf (42Madrid)
- https://github.com/lrcouto/ft_printf (42SaoPaulo)
- https://github.com/Laendrun/42-ft_printf (42Switzerland)

Testers:
- https://github.com/cacharle/ft_printf_test
- https://github.com/paulo-santana/ft_printf_tester

### 3.3 Uso de IA — declaración de transparencia
 
La Inteligencia Artificial se utilizó como tutor de aprendizaje durante el desarrollo de este proyecto. Todas las implementaciones fueron escritas manualmente, revisadas, probadas y comprendidas antes de ser añadidas al repositorio. Se utilizaron herramientas de IA como Claude, ChatGPT y Gemini para:

- Explicar desde cero conceptos del lenguaje C. 
- Comparar arquitecturas posibles antes de decidir cuál implementar.
- Identificar riesgos técnicos antes de escribir el código.
- Identificar casos límite y escenarios de prueba.
- Explicar errores de compilación y comportamientos indefinidos.
- Ayudar parcialmente en la redacción de la documentación del proyecto (README.md).

El código final, así como la lógica algorítmica, las decisiones de diseño y la implementación de las pruebas para casos límite, fueron realizados íntegramente por el autor.

---
 
## 4. Ejecución del Proyecto
 
### 4.1. ¿Cuál es prototipo y comportamiento de `printf`? ¿Cómo es su flujo de proceso?

Para que printf 

4.2.1. Entradas:
- Cadena de formato (const char *format): puntero a la cadena estática que contiene los literales y especificadores de conversión (%d, %s, %f, etc.)
- Argumentos variádicos (...): lista variable de argumentos (va_list) ubicados en la pila de ejecución (stack), correspondientes a los especificadores de formato.

4.2.2. Extracción de los argumentos Resolución de argumentos variádicos:
- 

4.2.X. Salidas:
- Valor de retorno (int): retorna el número total de caracteres escritos en el caso de éxito o un valor negativo si ocurre un error de escritura.
- Efecto secundario/errores : modifica el bufer interno stdout...... y si pongo muchos %%%%?!?! que pasa o solo uno %%% 

a. empaquetado de los datos: texto fijo y las variables se los entrega a la funcion
b. analisis del texto y su traduccion: si encuentra letras normales, las anota para imprimirlas, si encuentra un simbolo especial %, se detiene  y activa
c. se guarda en el buffer
d. 

cómo combina diferentes tipos de variables en una sola linea?




### 4.4 ¿Cuáles las decisiones técnicas esenciales para ejecutar el proyecto?


La decisión central del proyecto es: **struct de flags + tabla de despacho (punteros a función) + conversión numérica en dos pasadas sin `malloc`**, frente a las alternativas evaluadas:
 
| Alternativa descartada | Motivo del descarte |
|---|---|
| Cadena de `if/else` para elegir conversión | Supera el límite de 25 líneas por función en cuanto se combinan flags |
| Impresión directa carácter a carácter, sin buffer | Físicamente imposible de cumplir cuando hay ancho mínimo: no se puede "borrar" lo ya escrito con `write`, así que hay que medir antes de imprimir el primer carácter |
| Lista enlazada con un nodo por carácter | Genera un `malloc`/`free` por cada espacio de padding — coste innecesario para el mismo resultado |
| Variables sueltas en vez de struct | Rompe el límite de 4 parámetros de la Norma en cuanto se combinan flags + ancho + precisión + tipo |
 
La combinación elegida cumple la Norma sin trucos, minimiza las llamadas a `malloc` y a `write`, y aísla cada responsabilidad (leer formato / convertir dato / aplicar padding) en una función distinta y corta.
 
### 4.2 Fundamentos necesarios
 
| **Punteros a función** | La Norma prohíbe `switch`, `case` y el operador ternario | Permiten construir una tabla de despacho: un array donde cada casilla es una función, indexada por la letra de conversión, sin necesidad de comparar con `if` uno por uno |
| **Recursión** | Convertir un número a texto exige procesar los dígitos en orden inverso al que se calculan | Al dividir por la base, el primer resto obtenido es el dígito *menos* significativo; la recursión permite "esperar" a que la llamada más profunda imprima primero el dígito más significativo |
| **Aritmética de bases (10 y 16)** | `%d/%i/%u` usan base 10, `%x/%X/%p` usan base 16 | División entera y resto (`/` y `%`) sobre la base correspondiente, mapeando cada resto a un carácter mediante indexación en `"0123456789abcdef"` |
| **Manejo de signo y `unsigned`** | `ft_atoi("--5")` y el caso de `INT_MIN` ya enseñaron que el signo es la fuente más común de bugs | Un número negativo debe tratarse aparte antes de aplicar `%`, porque el resto de una división con dividendo negativo no se comporta de forma intuitiva |


| Fundamento | Explicación | Porqué hace falta |
|---|---|---|
| Funciones variádicas (`va_list`, `va_start`, `va_arg`, `va_end`) | Mecanismo del lenguaje C que permite a una función aceptar un número de argumentos no determinado en tiempo de compilación. `va_start` inicializa el acceso a la lista de argumentos adicionales a partir del último parámetro fijo; `va_arg` recupera secuencialmente cada argumento, interpretándolo según el tipo indicado; `va_end` libera el estado asociado | Sin este mecanismo, C no permite declarar una función con un número variable de argumentos, requisito explícito del proyecto |
| `struct` | Tipo de dato semejante a una tabla definido por el usuario y que agrupa varias variables, potencialmente de tipos distintos (como flags, ancho, precisión y tipo de conversión), bajo un único identificador accesible como una sola unidad | La Norma limita a 4 el número de parámetros por función y utilizar `struct` es una forma de manejar más de 4 paŕametros sin infringir esa restricción. Si se solventara el proyecto con un función del tipo `handle`, se necesitarían mucho más parámetros para completar la conversión, como por ejemplo: el tipo de conversión, el acceso al argumento a imprimir, el ancho, la precisión, el flag de alineación à la izquierda, y el flag de relleno con ceros. El `struct` tammbién es esencial para construir una tabla de despacho, recurso de lo que se habla a continuación. |
| Punteros a función | Variable cuyo valor almacenado es la dirección de memoria de una función, lo que permite invocarla indirectamente a través del puntero, incluyendo su uso como elemento de un array indexado | La Norma prohíbe el uso de  `switch`, `case` y el operador ternario; los punteros a función permiten construir una tabla de despacho que selecciona la función correspondiente sin comparaciones condicionales explícitas |
| Recursión | Técnica en la que una función se invoca a sí misma para resolver una subinstancia del mismo problema, delegando en la pila de llamadas el orden de ejecución | La conversión de un número a su representación en una base determinada produce los dígitos en orden inverso al que deben imprimirse; la recursión permite diferir la impresión hasta que la llamada más profunda resuelve el dígito de mayor peso |
| Aritmética de bases (10 y 16) | Conjunto de operaciones de división entera y resto que permiten descomponer un valor numérico en los dígitos correspondientes a una base determinada, mapeando cada resto a su carácter mediante una tabla de correspondencia | Las conversiones `%d/%i/%u` requieren base 10 y `%x/%X/%p` requieren base 16; ambas comparten el mismo procedimiento de descomposición, variando únicamente la base y el alfabeto de dígitos |
| Manejo de signo y tipos sin signo | Tratamiento explícito del signo antes de aplicar operaciones aritméticas, y conversión controlada entre tipos con y sin signo para evitar comportamiento indefinido | El resto de una división con dividendo negativo no produce el resultado esperado si el signo no se aísla previamente; además, `INT_MIN` no tiene un equivalente positivo representable en `int`, lo que exige un tratamiento diferenciado |


### 4.3 Artefactos necesarios
 
| Artefacto | Por qué hace falta | Descripción |
|---|---|---|
| `t_format` (struct) | Agrupar flags/ancho/precisión/conversión en un solo parámetro | Ficha rellenada por el Lector, consultada por el Traductor y el Maquetador |
| Array de punteros a función (dispatch table) | Sustituto legal del `switch` prohibido | Indexado por la letra de conversión (o por una resta desde el carácter base), apunta directo a la función correspondiente |
| Bucle de parseo con estado (FSM informal) | Leer flags, ancho y precisión en el orden correcto antes de llegar a la letra de conversión | Recorre el formato carácter a carácter, avanzando el puntero según en qué "fase" del `%...` se encuentra |
| Funciones de conteo + impresión recursiva (*Two-Pass Measure-then-Print*) | Saber el ancho del número **antes** de decidir cuántos espacios de padding poner, sin usar `malloc` | Una función cuenta dígitos dividiendo hasta llegar a 0; otra los imprime recursivamente usando `ft_putchar_fd` de libft |
| Reutilización directa de libft | Evitar reescribir trabajo ya hecho y probado | `ft_strlen`, `ft_strchr`, `ft_isdigit`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_calloc` |
| Funciones autorizadas por el subject | Límite explícito impuesto por el enunciado | `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end` — cualquier otra función del sistema está prohibida salvo que provenga de la propia libft |
 

 
### 4.5 Riesgos del proyecto y cómo se han mitigado
 
| Riesgo | Mitigación |
|---|---|
| Overflow al convertir `INT_MIN` (no tiene equivalente positivo representable en `int`) | Tratar el signo como caso especial antes de negar, o trabajar internamente en un tipo sin signo tras aislar el signo |
| El resto (`%`) de una división con dividendo negativo no da el resultado intuitivo | Aislar el signo y trabajar siempre con la magnitud positiva antes de la recursión |
| `%p` sobre un puntero `NULL`: el `printf` real de glibc imprime `(nil)`, no `0x0` | Verificar explícitamente este caso contra el `printf` real antes de dar el proyecto por cerrado — el subject exige comparación directa con el original |
| `%s` con un puntero `NULL` como argumento | Comprobar el puntero antes de medir su longitud, para evitar un `segfault` — el subject califica con 0 cualquier terminación inesperada |
| `%%` no debe consumir ningún argumento de la lista variádica | La entrada de la tabla de despacho para `%` no debe llamar a `va_arg` |
| Uso de variables globales como atajo para contar caracteres totales | Prohibido por la Norma; el conteo se propaga como valor de retorno entre funciones, nunca como estado global |
| Fuga de memoria si se usa `malloc` sin disciplina | Minimizado por diseño: los números no usan `malloc` en absoluto; solo se reserva memoria donde es estrictamente necesario, y siempre con su `free` correspondiente |
| Incumplir la Norma por funciones demasiado largas al combinar flags | Descomposición en funciones estáticas pequeñas, cada una con una única responsabilidad, siguiendo el mismo patrón ya aplicado en libft Parte 2 |
| `write()` puede fallar o escribir menos bytes de los pedidos | Comprobar el valor de retorno de cada `write` en los puntos críticos |


### 4.6 Casos de prueba y comparación con los resultados de la función original

printf("%05.2d\n", 3);
 
---
 
## 5. Conclusión
 
`ft_printf` no enseña, en el fondo, a "imprimir cosas en pantalla" — enseña a diseñar código que crece sin romperse. La Norma, al prohibir `switch` y limitar los parámetros, empuja hacia patrones que cualquier programador de C profesional usaría de todas formas: tablas de despacho y agrupación de datos relacionados en estructuras. El aprendizaje más valioso de este proyecto no es la sintaxis de `va_arg`, sino la disciplina de **separar responsabilidades antes de escribir la primera línea de código** — la diferencia entre un proyecto que sobrevive al bonus y uno que hay que reescribir desde cero al llegar a él.
 


















































































































































































In order to fullfil the objectives of printf project,


** Qué es el proyecto
El proyecto de libftprintf

** OBJECTIVES
- Utilizar un numero variable de argumentos.
- Entender las funcciones variádiicas en C.

** REQUISITOS
- Tener un código bien estructurado y extensible.
- Reaprovechar las funciones de libft.h
- Cumplir la Norma.
- No terminar funciones de forma inesperada (segfault, bus error, double free, etc).
- Asegurar que no existen leaks de memoria, liberando toda la memoria utilizada de manera

** Estrategia para solucionar el reto
- Utilizar las opcion de struct y array de punteros es una solución más compleja que hacer recursiones sobre el string
