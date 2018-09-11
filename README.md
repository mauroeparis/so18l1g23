Laboratorio 1 - VGA
===============

## Ejecución del proyecto

### Instalación y ejecución:

```
~ git clone https://bitbucket.org/sistop-famaf/so18l1g23

~ cd so18l1g23/xv6

~ make qemu
```

### Programas de usuario:

- `modeswitch`: toma un argumento {1 o 0} para cambiar al modo gráfico y texto, respectivamente
- `testplot`: No acepta argumentos. Cambia a modo gráfico y plotea la siguiente imagen:

![r2d2](https://i.imgur.com/VnkXtHf.jpg)

## Proceso de desarrollo

### Parte 1

Fue bastante simple luego de aprender a como escribir en la memoria VGA y lo hicimos haciendo store de los caracteres y color directamente en la dirección de memoria 0xB8000 (span de memoria usada por VGA para los monitores policromáticos).

### Parte 2 y 3

Aprender a utilizar el modo gráfico fue lo más difícil y lo que más costo del laboratorio. Cuando pudimos encontrar la forma, lo modularizamos bastante rápido e hicimos la parte 2 y 3 prácticamente juntas. Sigue siendo bastante confuso como funciona verdaderamente pero entendemos que guardando las instrucciones correctas al sistema por medio de `outb()` e `inb()` podemos decirle al sistema que inicie un modo gráfico o de texto.
    La mayor dificultad que encontramos en esta parte, por lo cual la hizo la más difícil, fue el entender qué representa cada valor que pasamos a puertos (nos basamos en la rutina de [osdev](https://files.osdev.org/mirrors/geezer/osd/graphics/modes.c)). Si bien disponíamos de la documentación para analizar cada bit de estos puertos, se hacía tedioso y muchas veces no conocíamos los términos a los que hacía referencia.

### Parte 4

Una vez implementadas las syscalls `modeswitch()` y `plotpixel()`, abrimos una nueva rama para empezar a mostrar imágenes.
Con la paleta de colores de 256 bits cargada, podemos crear arreglos con cifras de colores, para poder plotear en consola los píxeles que deseamos para dibujar la imagen.
Para no utilizar arreglos con muchísimos elementos, decidimos crear una función `plotsquare()` que dibuja cuadrados de 5x5 píxeles.
Se presentó un conflicto al intentar crear arreglos para las imágenes cuando tenían más de 1000 elementos, dentro del `main()`. Esto lo solucionamos instanciando los arreglos como globales al sacarlos del mismo.
Finalmente, en un paso de creatividad, optamos por pensar la imagen como un conjunto de secciones para poder dibujar por partes, a cada parte las hicimos a mano square por square.
