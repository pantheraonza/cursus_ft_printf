*Este proyecto ha sido creado como parte del currículo de 42 por criredon.*

# ft_printf

---

## A. Descripción General

El proyecto `ft_printf` es la reimplementación desde cero de la función `printf()` de la librería estándar de C. El objetivo no es solo lograr que el programa imprima texto correctamente, sino comprender en profundidad dos mecanismos fundamentales del lenguaje: las **funciones variádicas** (funciones que aceptan un número desconocido de argumentos en tiempo de compilación) y la construcción de **código extensible sin recurrir a `switch`**, estructura prohibida por la Norma de 42.

El resultado final es una librería estática, `libftprintf.a`, que contiene una única función:

```c
int ft_printf(char const *, ...);
```

Se implementan de forma obligatoria las conversiones `c s p d i u x X %`, y de forma bonus, la gestión de cualquier combinación de flags (`-`, `0`, `#`, ` `, `+`) y el ancho mínimo de campo de todas las conversiones.

---

## B. Instrucciones

### B.1 Compilación, instalación y ejecución

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

### B.2 Ejemplos de uso
 
```c
ft_printf("Hola %s, tienes %d años\n", "Cris", 22);
// -> Hola Cris, tienes 22 años
 
ft_printf("En hex: %x | En HEX: %X | Puntero: %p\n", 255, 255, &var);
// -> En hex: ff | En HEX: FF | Puntero: 0x7ffee3a1c
 
ft_printf("[%5d][%-5d][%05d]\n", 42, 42, 42);
// -> [   42][42   ][00042]
```

---
 
## C. Recursos
 
### C.1 Referencias clásicas
 
- Brian W. Kernighan & Dennis M. Ritchie, *El Lenguaje de Programación C*
- Thomas H. Cormen & Otros , *Introducción a los Algoritmos*
- Steve McConnell, *Code Complete*
- Robert Nystrom, *Crafting Interpreters*
 
### C.2 Tutoriales y documentación en español consultados
 
- https://parzibyte.me/blog/2020/12/30/struct-c/
- https://elprofearieloficial.wordpress.com/estructuras-de-datos/estructuras-en-c-struct/

### C.3 Repositorios de GitHub consultados

Fueron consultados repositorios de programadores expertos con el afán de consultar diferentes decisiones técnicas, recursos utilizados y, principalmente, testers para comprobar la funcionalidad del programa desarrollado.

- https://github.com/mapena-z/ft_printf
- https://github.com/vittoric/ft_printf
- https://github.com/VniiD/Printf
- https://github.com/Laendrun/42-ft_printf
- https://github.com/cacharle/ft_printf_test
- https://github.com/paulo-santana/ft_printf_tester

### C.4 Uso de IA — declaración de transparencia
 
La Inteligencia Artificial se utilizó como tutor de aprendizaje durante el desarrollo de este proyecto. Todas las implementaciones fueron escritas manualmente, revisadas, probadas y comprendidas antes de ser añadidas al repositorio. Se utilizaron herramientas de IA como Claude, ChatGPT y Gemini para:

- Explicar desde cero conceptos del lenguaje C. 
- Comparar arquitecturas posibles antes de decidir cuál implementar.
- Identificar riesgos técnicos antes de escribir el código.
- Identificar casos límite y escenarios de prueba.
- Explicar errores de compilación y comportamientos indefinidos.
- Ayudar en la redacción de la documentación del proyecto (README.md).

El código final, así como la lógica algorítmica, las decisiones de diseño y la implementación de las pruebas para casos límite, fueron realizados íntegramente por el autor.

---
 
## D. Ejecución del Proyecto
 
### D.1 ¿Cuál es el objetivo del proyecto ft_printf?
 
Reprogramar `printf()` sin usar la función original, entendiendo *por qué* funciona como funciona — no solo replicando su comportamiento externo. El reto real no es "imprimir cosas": es resolver el problema de **no saber, en tiempo de compilación, cuántos argumentos va a recibir la función**, y resolverlo de forma extensible, porque el enunciado avisa explícitamente de que un enfoque ingenuo se rompe en cuanto llega el bonus.
 
### D.2 Fundamentos necesarios
 
| Fundamento | Por qué hace falta | Explicación |
|---|---|---|
| **Funciones variádicas** (`va_list`, `va_start`, `va_arg`, `va_end`) | Sin esto, C no permite un número variable de argumentos | `va_list` es la "cinta transportadora" de argumentos; `va_start` se posiciona al principio; `va_arg(lista, tipo)` coge el siguiente argumento y lo interpreta como el tipo indicado; `va_end` limpia. El string de formato es la única fuente de verdad sobre cuántos y de qué tipo son |
| **`struct`** | La Norma limita a 4 parámetros por función, y una conversión con flags necesita agrupar 5+ datos relacionados | Agrupa flags, ancho, precisión y tipo de conversión en una sola "ficha de trabajo" que viaja entre las funciones sin romper el límite |
| **Punteros a función** | La Norma prohíbe `switch`, `case` y el operador ternario | Permiten construir una tabla de despacho: un array donde cada casilla es una función, indexada por la letra de conversión, sin necesidad de comparar con `if` uno por uno |
| **Recursión** | Convertir un número a texto exige procesar los dígitos en orden inverso al que se calculan | Al dividir por la base, el primer resto obtenido es el dígito *menos* significativo; la recursión permite "esperar" a que la llamada más profunda imprima primero el dígito más significativo |
| **Aritmética de bases (10 y 16)** | `%d/%i/%u` usan base 10, `%x/%X/%p` usan base 16 | División entera y resto (`/` y `%`) sobre la base correspondiente, mapeando cada resto a un carácter mediante indexación en `"0123456789abcdef"` |
| **Manejo de signo y `unsigned`** | `ft_atoi("--5")` y el caso de `INT_MIN` ya enseñaron que el signo es la fuente más común de bugs | Un número negativo debe tratarse aparte antes de aplicar `%`, porque el resto de una división con dividendo negativo no se comporta de forma intuitiva |
 
### D.3 Artefactos necesarios
 
| Artefacto | Por qué hace falta | Descripción |
|---|---|---|
| `t_format` (struct) | Agrupar flags/ancho/precisión/conversión en un solo parámetro | Ficha rellenada por el Lector, consultada por el Traductor y el Maquetador |
| Array de punteros a función (dispatch table) | Sustituto legal del `switch` prohibido | Indexado por la letra de conversión (o por una resta desde el carácter base), apunta directo a la función correspondiente |
| Bucle de parseo con estado (FSM informal) | Leer flags, ancho y precisión en el orden correcto antes de llegar a la letra de conversión | Recorre el formato carácter a carácter, avanzando el puntero según en qué "fase" del `%...` se encuentra |
| Funciones de conteo + impresión recursiva (*Two-Pass Measure-then-Print*) | Saber el ancho del número **antes** de decidir cuántos espacios de padding poner, sin usar `malloc` | Una función cuenta dígitos dividiendo hasta llegar a 0; otra los imprime recursivamente usando `ft_putchar_fd` de libft |
| Reutilización directa de libft | Evitar reescribir trabajo ya hecho y probado | `ft_strlen`, `ft_strchr`, `ft_isdigit`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_calloc` |
| Funciones autorizadas por el subject | Límite explícito impuesto por el enunciado | `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end` — cualquier otra función del sistema está prohibida salvo que provenga de la propia libft |
 
### D.4 Decisiones técnicas
 
La decisión central del proyecto es: **struct de flags + tabla de despacho (punteros a función) + conversión numérica en dos pasadas sin `malloc`**, frente a las alternativas evaluadas:
 
| Alternativa descartada | Motivo del descarte |
|---|---|
| Cadena de `if/else` para elegir conversión | Supera el límite de 25 líneas por función en cuanto se combinan flags |
| Impresión directa carácter a carácter, sin buffer | Físicamente imposible de cumplir cuando hay ancho mínimo: no se puede "borrar" lo ya escrito con `write`, así que hay que medir antes de imprimir el primer carácter |
| Lista enlazada con un nodo por carácter | Genera un `malloc`/`free` por cada espacio de padding — coste innecesario para el mismo resultado |
| Variables sueltas en vez de struct | Rompe el límite de 4 parámetros de la Norma en cuanto se combinan flags + ancho + precisión + tipo |
 
La combinación elegida cumple la Norma sin trucos, minimiza las llamadas a `malloc` y a `write`, y aísla cada responsabilidad (leer formato / convertir dato / aplicar padding) en una función distinta y corta.
 
### D.5 Riesgos del proyecto y cómo se han mitigado
 
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
 
---
 
## E. Conclusión
 
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
