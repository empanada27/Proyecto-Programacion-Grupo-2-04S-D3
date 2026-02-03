// 1.Librerías y constantes de configuración 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define ARCHIVO "inventario.dat"

// Datos (estructura)

typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

// Prototipos de funciones
void registrar(Producto inv[], int *n);
void modificarStock(Producto inv[], int n, int aumentar);
void buscar(Producto inv[], int n);
void guardar(Producto inv[], int n);
int cargar(Producto inv[]);
float calcularValorTotal(Producto inv[], int n, int indice);