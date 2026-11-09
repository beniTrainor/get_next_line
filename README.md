*Este proyecto ha sido creado como parte del currículo de 42 por btrainor.*

# get\_next\_line

## Descripción

Este proyecto consiste en implementar una función en C capaz de leer y devolver un archivo de texto línea por línea, utilizando un descriptor de archivo (file descriptor o `fd`).

El objetivo principal es comprender el funcionamiento de las variables estáticas, las operaciones de lectura mediante `read()` y la gestión dinámica de memoria en el heap.

La función `get_next_line` lee el contenido de un descriptor de archivo y devuelve una línea cada vez que se invoca. Para ello, debe conservar entre llamadas los datos que ya ha leído pero que todavía no ha devuelto, permitiendo continuar la lectura desde el punto en el que se quedó.

Su prototipo es el siguiente:
```
char	*get_next_line(int fd);
```

La función devuelve una cadena que contiene la siguiente línea, incluyendo el carácter `\n` cuando está presente. Si se alcanza el final del archivo (`EOF`), puede devolver la última línea aunque no termine en un salto de línea. Devuelve `NULL` cuando no quedan más líneas por leer o cuando se produce un error.

El proyecto está dividido en dos partes:
- **Parte obligatoria:** permite leer líneas de un único descriptor de archivo. Incluye los siguientes archivos:
  - `get_next_line.c`
  - `get_next_line_utils.c`
  - `get_next_line.h`

- **Parte bonus:** permite leer líneas de múltiples descriptores de archivo simultáneamente, manteniendo el contenido pendiente de cada uno de forma independiente mediante un único array estático de punteros. Incluye los siguientes archivos:
  - `get_next_line_bonus.c`
  - `get_next_line_utils_bonus.c`
  - `get_next_line_bonus.h`

### Algoritmo

1. **Lectura:** leer del descriptor de archivo en bloques de tamaño `BUFFER_SIZE`, almacenando los datos en un `stash` hasta encontrar un salto de línea (`\n`) o alcanzar el final del archivo (`EOF`).
2. **Extracción:** extraer del `stash` la primera línea completa, incluyendo el salto de línea si existe.
3. **Actualización:** eliminar del `stash` la línea extraída y conservar el contenido restante para la siguiente llamada.

Este algoritmo permite leer archivos de cualquier longitud sin necesidad de cargar todo su contenido en memoria de antemano. Además, permite gestionar líneas de longitud variable y conservar los datos pendientes entre llamadas.

El buffer de lectura se reserva dinámicamente mediante `malloc`, utilizando memoria del heap en lugar de reservar un espacio fijo en el stack.

Para la parte bonus, el algoritmo es prácticamente el mismo. La principal diferencia está en la gestión de los `stash`. En lugar de utilizar un único puntero `char *stash`, se utiliza un array de punteros a `char`: `char *stash[MAX_FD]`.

De esta forma, cada descriptor de archivo dispone de su propio `stash`, permitiendo gestionar múltiples archivos simultáneamente sin mezclar sus contenidos.

## Instrucciones

Para utilizar la función, es necesario incluir el header `get_next_line.h` en el archivo C donde se quiera implementar:

```c
#include "get_next_line.h"

char *line = get_next_line(fd);
```

Donde `fd` es el descriptor de archivo del que se quiere leer.

Una vez incluido el header, se puede compilar el proyecto utilizando el siguiente comando:

```bash
cc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c
```

Si se desea utilizar un tamaño de buffer diferente al valor predeterminado, se puede definir `BUFFER_SIZE` durante la compilación mediante la flag `-D`:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

Esto permite modificar el tamaño del buffer de lectura sin necesidad de cambiar el código fuente.

Para compilar la parte bonus, se deben utilizar los archivos correspondientes:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```

## Recursos

### Documentación

- `man 2 read`
- `man 2 open`

### Artículos

- [Static variables in C](https://www.geeksforgeeks.org/c/static-variables-in-c/)

### Implementaciones de referencia

- [FelixRodriguezG - ft_get_next_line](https://github.com/FelixRodriguezG/ft_get_next_line)
- [AlBektur - get_next_line](https://github.com/AlBektur/get_next_line)

### Testing

- [Tripouille - gnlTester](https://github.com/Tripouille/gnlTester)

### Uso de IA

ChatGPT se ha utilizado como herramienta de apoyo para resolver dudas sobre casos extremos (*edge cases*), mejorar la organización y refactorización del código, y revisar la redacción y estructura de este README.
