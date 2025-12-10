/*Nombre del Estudiante: Cesar Castrillo CI:31970219
Materia: Lenguajes de Programación 1 
Evaluación: 2
Fecha: 14/11/2025
Descripción: Modularidad y Recursividad*/

#include <stdio.h>

//funciones
float promedioVentas(float ventas[], int n);
float buscarMayor(float ventas[], int n);
float buscarMenor(float ventas[], int n);
int contarSuperiores(float ventas[], int n, float monto);

int main() {
    int cantidad_Dias;
    float monto_referencia;
    
    printf("Bienvenido al programada de Registro y Análisis de Ventas empleado de TecnoStore!! ");
    printf("Ingrese solo números (nada de letras) y en caso de usar decimales utilice el punto(.)");

    // Para registrar cuantos días de ventas
    printf("¿Cuántos días de ventas deseas registrar? \n");
    scanf("%d", &cantidad_Dias);

    float ventas[cantidad_Dias];
    
    for (int i = 0; i < cantidad_Dias; i++) {
        printf("Ingrese el monto vendido del dia %d: $", i + 1);
        scanf("%f", &ventas[i]);
    }

    // para mostrar los montos ingresados
    printf("Ventas registradas:\n");
    for (int i = 0; i < cantidad_Dias; i++) {
        printf(" Día %d: $%.2f\n", i + 1, ventas[i]);
    }

    // Para calcular el total de ventas
    float totalVentas = 0;
    for (int i = 0; i < cantidad_Dias; i++) {
        totalVentas += ventas[i];
    }

    // Para mostrar los datos
    printf("Total vendido: $%.2f\n", totalVentas);
    printf("Promedio de ventas: $%.2f\n", promedioVentas(ventas, cantidad_Dias));
    printf("Venta más alta: $%.2f\n", buscarMayor(ventas, cantidad_Dias));
    printf("Venta más baja: $%.2f\n", buscarMenor(ventas, cantidad_Dias));

    // pars pedir el monto de referencia 
    printf("Ingrese un monto de referencia para contar días con ventas superiores: $");
    scanf("%f", &monto_referencia);

    int diasExcedidos = contarSuperiores(ventas, cantidad_Dias, monto_referencia);
    printf("Número de días con ventas mayores a $%.2f: %d\n", monto_referencia, diasExcedidos);

    return 0;
}

// Función que calcula el promedio de ventas
float promedioVentas(float ventas[], int n) {
    float suma = 0;
    for (int i = 0; i < n; i++)
        suma += ventas[i];
    return suma / n;
}

// Función que encuentra la mayor venta
float buscarMayor(float ventas[], int n) {
    float mayor = ventas[0];
    for (int i = 1; i < n; i++)
        if (ventas[i] > mayor)
            mayor = ventas[i];
    return mayor;
}

// Función que encuentra la menor venta
float buscarMenor(float ventas[], int n) {
    float menor = ventas[0];
    for (int i = 1; i < n; i++)
        if (ventas[i] < menor)
            menor = ventas[i];
    return menor;
}

// Función recursiva que cuenta los días que superan el monto
int contarSuperiores(float ventas[], int n, float monto) {
    if (n == 0)
        return 0;

    int cuenta = contarSuperiores(ventas, n - 1, monto);

    if (ventas[n - 1] > monto)
        cuenta++;

    return cuenta;
    return 0;
}
    