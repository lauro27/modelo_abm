#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objeto.h"
#define T 10

int main()
{
    system("color 07");

    int opcion;

    eObjeto producto;
    eObjeto lista[T];
    construirArray(lista, T);
    inicializarObjetos(lista, T);
    mostrarArray(lista, T);

    do
    {
        printf("1.ALTA\n2.BAJA\n3.MODIFICACION\n4.MOSTRAR\n5.SALIR\nSeleccion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            insertarObjeto(lista, T);
            break;
        case 2:
            borrarObjeto(lista, T);
            break;
        case 3:
            editarObjeto(lista, T);
            break;
        case 4:
            mostrarArray(lista, T);
            break;
        }
        system("cls");
    }while(opcion != 5);
}
