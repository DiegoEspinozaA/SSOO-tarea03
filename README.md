# SSOO-tarea03 💻

Se necesita implementar la serie de Fibonnaci y de numeros impares, las 2 para un rango de 50 iteraciones utilizando fork(). Los series deben ejecutarse una en el proceso padre y otra en el proceso hijo.
La ejecucion del programa no puede ser interrumpida por señales como: Ctrl + C, Ctrl + Z o Ctrl + \

## Requisitos ⚙️

Para le ejecución del script se debe contar con alguna de las siguientes opciones:

* Sistema operativo basado en Linux, por ejemplo, Ubuntu.

* Máquina virtual con un sistema basado en Linux.

* Subsistema Linux en Windows.

* Paquete **make** instalado


## Explicación 👨‍🏫

Inicialmente se deben identificar las macros de las señales.

SIGINT -> Ctrl + C

SIGTSTP -> Ctrl + Z

SIGQUIT -> Ctrl + \

Estas deben ser manejadas utilizando una funcion que devuelva "Detencion no permitida" en caso de ser detectadas.

Utilizando fork() se generan los 2 procesos, el proceso padre ejecutara la sucesion de Fibonacci utilizando un codigo bastante generico y el Hijo implementa la sucesion de numeros impares, iniciando en 1 para luego sumar 2 por cada iteracion.

El proceso principal no cede el control inmediatamente y el ciclo for se ejecuta tan rápido que se realiza antes de que se "programe" el segundo proceso. Cuando se ejecuta el codigo se obtienen impresiones no secuenciales dependiendo del sistema, para reducir esto se utilizan una serie de sleep().


## Ejecución ▶

Ejecutar el archivo make para construir el programa. Luego utilice ./main para ejecutarlo.

## Autor ✒️

**Diego Espinoza Apablaza** - 20.479.538-8 - diego.espinozaa@alumnos.uv.cl
