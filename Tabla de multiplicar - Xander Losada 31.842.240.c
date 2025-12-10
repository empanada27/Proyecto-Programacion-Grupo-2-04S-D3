#include <stdio.h>

int main () {

    
    int numero;
    int limite = 10;

    printf("---  Generador de Tabla de Multiplicar ---\n");
    
    printf("Ingrese el numero de la tabla que desea generar: ");
    
    if (scanf("%d", &numero) != 1) {
        printf("Error de entrada. Debe ingresar un número entero válido.\n");
    }
    printf("\nTabla de multiplicar del %d hasta %d:\n", numero, limite);
    printf("--------------------------------\n");

    for (int i = 1; i <= limite; i++) {
        
        int resultado = numero * i;
        
        printf("%3d x %2d = %5d\n", numero, i, resultado);
    }
    
    printf("--------------------------------\n");

  return 0;

}
