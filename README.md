
Leer una línea de un descriptor de archivo es
demasiado tedioso.

Este proyecto no solo te permitirá añadir una función bastante práctica a tu colección,
también te hará aprender el increíble concepto de las variables estáticas en C

que es una varianle estatica

El programa debe compilar con el indicador (flag) -D BUFFER_SIZE=n
Este indicador se utilizará para determinar el tamaño del buffer de las lecturas de la función
read() en el get_next_line(). Este parámetro será modificado por las personas
que hagan la evaluación y por Moulinette para probar tu programa.

Se debería poder compilar este proyecto con y sin el indicador -D
BUFFER_SIZE, junto a los indicadores habituales. Se puede elegir el
valor por defecto que se prefiera.

El programa se compilará de la siguiente forma (se utiliza como ejemplo un tamaño
de buffer de 42):
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c.



Se considera que get_next_line() tiene un comportamiento indeterminado si el
archivo al que apunta el descriptor de archivo ha cambiado desde la última vez que
se llamó, siempre que read() no haya llegado al final del archivo.
• Se considera que get_next_line() tiene un comportamiento indeterminado cuando
lo que se lee es un archivo binario. Sin embargo, es posible implementar alguna
manera lógica de sortear este problema, si se desea.

¿Funciona correctamente get_next_line si el BUFFER_SIZE es 9999? ¿Y
si es 1? ¿Qué tal con 10000000? ¿Sabes por qué?