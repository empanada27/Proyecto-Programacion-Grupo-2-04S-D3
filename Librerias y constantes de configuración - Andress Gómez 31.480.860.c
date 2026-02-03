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

// 2. Menu de usuario 

int main() {
    Producto inventario[MAX_PRODUCTOS];
    int numProductos = cargar(inventario);
    int opcion;

    do {
        printf("\n--- INVENTARIO CONVENIENCIA ---");
        printf("\n1. Registrar producto\n2. Aumentar stock\n3. Disminuir stock");
        printf("\n4. Buscar por nombre\n5. Valor total (Recursivo)\n6. Guardar y Salir");
        printf("\nSeleccione: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: registrar(inventario, &numProductos); break;
            case 2: modificarStock(inventario, numProductos, 1); break;
            case 3: modificarStock(inventario, numProductos, 0); break;
            case 4: buscar(inventario, numProductos); break;
            case 5: 
                printf("\nValor total: $%.2f\n", calcularValorTotal(inventario, numProductos, 0)); 
                break;
            case 6: guardar(inventario, numProductos); break;
        }
    } while(opcion != 6);

    return 0;
}

    // 3. Registrar
void registrar(Producto inv[], int *n) {
    if (*n >= MAX_PRODUCTOS) {
        printf("Inventario lleno.\n");
        return;
    }
    printf("Nombre: ");
    scanf("%s", inv[*n].nombre);
    printf("Cantidad: ");
    scanf("%d", &inv[*n].cantidad);
    printf("Precio: ");
    scanf("%f", &inv[*n].precio);
    (*n)++;
}

// 4. Modificar Stock
void modificarStock(Producto inv[], int n, int aumentar) {
    char nombre[50];
    int cant;
    printf("Nombre del producto: ");
    scanf("%s", nombre);
    for(int i = 0; i < n; i++) {
        if(strcmp(inv[i].nombre, nombre) == 0) {
            printf("Cantidad: ");
            scanf("%d", &cant);
            if(aumentar) inv[i].cantidad += cant;
            else inv[i].cantidad -= cant;
            return;
        }
    }
    printf("No encontrado.\n");
}
// 5. Buscar
void buscar(Producto inv[], int n) {
    char nombre[50];
    printf("Nombre a buscar: ");
    scanf("%s", nombre);
    for(int i = 0; i < n; i++) {
        if(strcmp(inv[i].nombre, nombre) == 0) {
            printf("Producto: %s | Cantidad: %d | Precio: %.2f\n", inv[i].nombre, inv[i].cantidad, inv[i].precio);
            return;
        }
    }
    printf("No encontrado.\n");
}


