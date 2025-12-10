/*Marcia Padilla
CI:31.488.515
Programa de calificacion*/


#include <stdio.h> 

int main (){
    int nota;    
      // Variable para almacenar la calificación introducida

    /* Mensaje de bienvenida y explicación de la app */
    printf("Bienvenido a la App Calificación,\n"
           "la app que evalúa tu nota en base de 0 a 100.\n"
           "¡Te diremos si aprobaste!\n"
           "Por favor ingresa tu calificación: ");

    /* Lee el número introducido por el usuario.  Si no es un número válido, muestra un error y termina */
    if (scanf("%d", &nota) != 1) {
        printf("Error: favor ingrese números.\n");
        return 1;          // Código de salida 1 indica error
    }

    /* Verifica que la nota esté dentro del rango permitido (0‑100) */
    if (nota < 0 || nota > 100) {
        printf("Error: %d no entra en el rango de 0 a 100.\n", nota);
        return 1;
    }

    /* Decide si aprobó o no según el umbral de 60 puntos */
    if (nota >= 60) {
        printf("FELICIDADES, HAS APROBADO con %d puntos.\n", nota);
    } else {
        printf("Lo sentimos, %d no es suficiente para aprobar la asignatura.\n", nota);
    }

    return 0;              // Código de salida
}