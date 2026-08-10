*Este proyecto ha sido creado como parte del currículo de 42 por criredon.*

# ft_printf

---

## 1. Descripción general — ¿Cuál es el objetivo del proyecto ft_printf?

El proyecto `ft_printf` es la reimplementación desde cero de la función `printf()`. El objetivo es entender cómo funciona y por qué puede ejecutarse sin conocer de antemano la cantidad de argumentos que va a recibir; es decir, comprender las **funciones variádicas** (funciones que aceptan un número de argumentos no determinado en tiempo de compilación).

En la función recreada se implementan de forma obligatoria las conversiones `c s p d i u x X %`. El resultado final es una librería estática, `libftprintf.a`, que contiene una única función pública:

```c
int ft_printf(const char *, ...);
```

---

## 2. Instrucciones — ¿Cómo se utiliza la función ft_printf?

### 2.1 Compilación y ejecución

| Comando | Efecto |
|---|---|
| `make` | Compila `libft` (con su propio Makefile) y después `libftprintf.a`, dejándola en la raíz del repositorio |
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

ft_printf("Char: %c | Sin signo: %u | Porcentaje: %%\n", 'A', 4000000000U);
// -> Char: A | Sin signo: 4000000000 | Porcentaje: %
```

---

## 3. Recursos

### 3.1 Referencias clásicas consultadas

La implementación se basa en la especificación oficial del proyecto de 42 y cuenta con el respaldo de referencias confiables:

- Manuales de programación de Linux: `man 3 printf`, `man 3 stdarg`.
- Especificaciones POSIX / Open Group: `printf`, `stdarg.h`.
- Libros: *El Lenguaje de Programación C* de Brian Kernighan y Dennis Ritchie, *Introducción a los Algoritmos* de Thomas Cormen, *Code Complete* de Steve McConnell y *Crafting Interpreters* de Robert Nystrom.

### 3.2 Tutoriales y repositorios consultados

Se revisaron tutoriales y repositorios de otros programadores con experiencia, para contrastar decisiones técnicas y recursos empleados, además de obtener testers que permitieran verificar la funcionalidad del programa.

Tutoriales y proyectos de referencia:
- https://suspectedoceano.notion.site/
- https://github.com/VniiD/Printf (42 São Paulo)
- https://github.com/lrcouto/ft_printf (42 São Paulo)
- https://github.com/mapena-z/ft_printf (42 Madrid)
- https://github.com/vittoric/ft_printf (42 Madrid)
- https://github.com/mcombeau/ft_printf (42 Paris)
- https://github.com/Laendrun/42-ft_printf (42 Switzerland)

### 3.3 Uso de IA — declaración de transparencia

La inteligencia artificial se utilizó como tutor de aprendizaje durante el desarrollo de este proyecto. Todas las implementaciones fueron escritas manualmente, revisadas, probadas y comprendidas antes de ser añadidas al repositorio. Se emplearon herramientas como Claude, ChatGPT y Gemini para:

- Explicar desde cero conceptos del lenguaje C.
- Comparar arquitecturas posibles antes de decidir cuál implementar.
- Identificar riesgos técnicos antes de escribir el código.
- Identificar casos límite y escenarios de prueba.
- Explicar errores de compilación y comportamientos indefinidos.
- Ayudar parcialmente en la redacción de la documentación (README.md).

El código final, la lógica algorítmica, las decisiones de diseño y la implementación de las pruebas para casos límite fueron realizados íntegramente por la autora.

---

## 4. Ejecución, estructura y decisiones técnicas

### 4.1 ¿Qué arquitectura se eligió y por qué?

Se evaluaron dos enfoques: **(A)** recorrido lineal con despacho condicional y **(B)** despacho mediante punteros a función. Se eligió la opción A por su simplicidad y su escritura inmediata, sin necesidad de memoria intermedia. Es extensible a nuevas conversiones —el dispatcher crece con una rama por cada una—, aunque abordar los requisitos de bonus exigiría modificaciones de mayor calado.

Con el **recorrido lineal y despacho condicional**, `ft_printf` recorre el formato carácter a carácter: ante un `%` consulta el carácter siguiente y `ft_dispatch` decide, con una cadena de `if`, qué función de impresión llamar. Cada responsabilidad se aísla en una función distinta y corta.

Todas las conversiones numéricas (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`) se apoyan en un **único** motor recursivo:

```c
int ft_print_nbr(unsigned long n, char *base)
```

- Recibe el número **ya positivo** (el signo lo gestiona quien llama) como `unsigned long`, para cubrir la magnitud de `INT_MIN` y todo el rango de `UINT_MAX`.
- `base` es el alfabeto de símbolos, y **su longitud es la base** (`radix`): `"0123456789"` → base 10, `"0123456789abcdef"` → base 16.
- La cifra se obtiene con `n % radix` y se traduce a carácter con `base[n % radix]`. Esto sustituye al truco decimal `(n % 10) + '0'` y funciona para cualquier base, dígitos y letras incluidos.
- Es el `ft_putnbr` de C04 generalizado: mismo `if (n >= radix)` más recursión sobre `n / radix`, con dos añadidos: devuelve el conteo y propaga `-1`.

Cada conversión solo cambia **qué alfabeto** le pasa al motor.

Además, cada conversión **se procesa y se descarta al instante**: no se acumula ninguna salida en memoria, lo que elimina las llamadas a `malloc` y los riesgos asociados. `ft_printf` no mide una cadena final; cada función de impresión **devuelve cuántos bytes escribió**, y ese conteo se va sumando en un contador. El total sale sin haber guardado nunca el contenido.

### 4.2 ¿Cuál es el flujo del proceso?

`ft_printf` toma como entrada una cadena de formato (`const char *format`) y una lista variable de argumentos (`...`), y produce como salida el texto ya resuelto, escrito directamente en la salida estándar; devuelve el número total de bytes escritos, o `-1` ante un error de escritura. El proceso intermedio recorre el formato de izquierda a derecha: copia los caracteres literales tal cual y, al encontrar un `%`, interpreta el especificador siguiente, recupera el argumento correspondiente con `va_arg` y lo convierte a texto sobre la marcha. No hay ningún búfer intermedio: cada trozo se escribe y se cuenta en el momento, y el flujo termina cerrando la lista de argumentos y devolviendo el total acumulado.

```
ft_printf
  ├── valida format != NULL
  ├── va_start
  ├── ft_scan  ──► recorre el formato con un índice
  │        ├── texto literal  ──► ft_print_char
  │        └── '%' + válido    ──► ft_dispatch
  │                                    ├── c ──► ft_print_char
  │                                    ├── s ──► ft_print_str
  │                                    ├── d/i ─► ft_print_int      ─┐
  │                                    ├── u ──► ft_print_unsigned  ─┤
  │                                    ├── x/X ─► ft_print_hexa     ─┤► ft_print_nbr
  │                                    ├── p ──► ft_print_ptr       ─┘   (motor único)
  │                                    └── % ──► ft_print_char('%')
  └── va_end, devuelve el total
```

Como `ft_printf` no sabe de antemano cuántos ni qué tipos de argumentos recibirá, lo descubre **leyendo el formato**: cada especificador le indica qué tipo recuperar a continuación con `va_arg`. Así, `"%c%d%s"` recupera primero un `int`, luego otro `int` y por último un `char *`, en ese orden. El formato es el guion que dicta, uno a uno, qué tipo sacar de la lista de argumentos; por eso pueden combinarse distintos tipos en una misma línea sin ambigüedad.

### 4.3 ¿Cómo se construyó el proyecto?

El proyecto se levantó en bloques acumulativos, de manera que cada función pudiera compilarse y validarse por separado antes de pasar a la siguiente. El bloque 3 es la bisagra: antes de él, escritura directa; en él se construye el motor numérico; después, todo son variaciones que lo reutilizan.

| Bloque | Conversión | Aporte principal |
|--------|------------|------------------|
| 1 | `%c`, `%%` | Recorrido del formato + escritura y conteo de un carácter |
| 2 | `%s` | Reutiliza `ft_strlen`; caso `NULL` → `(null)` |
| 3 | `%d`, `%i` | **El motor numérico** (`ft_print_nbr`) + signo + `INT_MIN` |
| 4 | `%u` | Reutiliza el motor, sin signo |
| 5 | `%x`, `%X` | Mismo motor, base 16, alfabeto por parámetro |
| 6 | `%p` | `uintptr_t`, prefijo `0x`, caso nulo, motor en base 16 |
| 7 | — | Integración, bordes, norminette, relink, valgrind, tester final |

### 4.4 ¿Cómo está estructurado el proyecto?

El proyecto se organiza en dos archivos fuente, un header y el Makefile, más la `libft` como dependencia. Cada archivo agrupa funciones por afinidad: el recorrido y las conversiones simples en uno, y el motor numérico con sus derivadas en otro.

**`ft_printf.h`** — Cabecera pública. Protege contra doble inclusión, incluye lo
estrictamente necesario (`../libft/libft.h`, `<stdarg.h>`, `<unistd.h>`) y declara
todos los prototipos.

**`ft_printf.c`** — Recorrido del formato y conversiones no numéricas.

| Función | Para qué sirve |
|---|---|
| `ft_printf` | Punto de entrada público. Valida el formato, abre la `va_list`, delega el recorrido y devuelve el total de bytes |
| `ft_scan` | Recorre el formato carácter a carácter; distingue texto literal de conversión y va sumando los bytes escritos |
| `ft_dispatch` | Según el especificador tras `%`, decide qué función de impresión llamar y consume el argumento del tipo correcto |
| `ft_print_char` | Escribe un carácter con `write` y devuelve el conteo |
| `ft_print_str` | Escribe una cadena; resuelve el caso `NULL` imprimiendo `(null)` |

**`ft_printf_nbr.c`** — Motor numérico y todas las conversiones que se apoyan en él.

| Función | Para qué sirve |
|---|---|
| `ft_utils_nbr` | Motor recursivo único: convierte un `unsigned long` a cualquier base según el alfabeto recibido, y cuenta los bytes |
| `ft_print_int` | `%d` / `%i`: gestiona el signo, resuelve `INT_MIN` ensanchando a `long`, y delega las cifras en el motor |
| `ft_print_unsigned` | `%u`: adapta el `unsigned int` y llama al motor en base 10, sin signo |
| `ft_print_hexa` | `%x` / `%X`: llama al motor en base 16 con el alfabeto (minúsculas o mayúsculas) que le pasa el dispatcher |
| `ft_print_ptr` | `%p`: gestiona el puntero nulo, escribe el prefijo `0x` y convierte la dirección con el motor en base 16 |

**`Makefile`** — Compila la `libft`, fusiona `libft.a` dentro de `libftprintf.a` y añade encima los objetos propios. Incluye las reglas `all`, `clean`, `fclean` y `re`.

**`libft/`** — Biblioteca propia reutilizada; de ella se emplea `ft_strlen` para medir cadenas y el alfabeto de las bases.

### 4.5 ¿Qué fundamentos hicieron falta para comprender el proyecto?

Antes de escribir la primera línea, cuatro conceptos del lenguaje C tuvieron que quedar claros: sin ellos, ni el mecanismo variádico ni la conversión numérica se sostienen.

| Fundamento | Explicación | Por qué hace falta |
|---|---|---|
| **Funciones variádicas** (`va_list`, `va_start`, `va_arg`, `va_end`) | Mecanismo de C que permite aceptar un número de argumentos no determinado en compilación: `va_start` abre el acceso a partir del último parámetro fijo, `va_arg` recupera cada argumento según el tipo indicado, y `va_end` cierra el estado | Es el requisito central del proyecto: sin él, C no permite declarar una función de argumentos variables |
| **Recursión** | Una función se invoca a sí misma para resolver una subinstancia del mismo problema, delegando el orden de ejecución en la pila de llamadas | Al dividir por la base, el primer resto es el dígito *menos* significativo; la recursión difiere la impresión hasta que la llamada más profunda resuelve el dígito de mayor peso, corrigiendo el orden |
| **Aritmética de bases (10 y 16)** | División entera y resto sobre una base para descomponer un número en sus dígitos, mapeando cada resto a su carácter mediante indexación en un alfabeto | `%d/%i/%u` usan base 10 y `%x/%X/%p` usan base 16; ambas comparten el procedimiento y solo cambian la base y el alfabeto |
| **Manejo de signo y tipos sin signo** | Aislar el signo antes de las operaciones aritméticas y convertir con cuidado entre tipos con y sin signo para evitar comportamiento indefinido | El resto de una división con dividendo negativo no se comporta de forma intuitiva, y `INT_MIN` no tiene equivalente positivo en `int`; ya en C04 (`ft_atoi`, `ft_putnbr`) el signo fue la fuente de bugs más recurrente |

---

## 5. Conclusión

`ft_printf` no enseña, en el fondo, a "imprimir cosas en pantalla": enseña a diseñar código que crece sin romperse. El aprendizaje más valioso no es la sintaxis de `va_arg`, sino la disciplina de **separar responsabilidades antes de escribir la primera línea de código**.