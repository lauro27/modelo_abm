#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objeto.h"


eObjeto pedirObjeto()
{
    eObjeto o;

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(o.nombre);


    printf("Ingrese precio: ");
    fflush(stdin);
    scanf("%f", &o.precio);

    printf("Ingrese proveedor: ");
    fflush(stdin);
    gets(o.proveedor);

    printf("Ingrese codigo de barra: ");
    fflush(stdin);
    gets(o.codigo);

    printf("Ingrese fecha de vencimiento: ");
    fflush(stdin);
    gets(o.fecha);

    o.estado = OCUPADO;

    return o;
}

void inicializarObjetos(eObjeto list[], int tam)
{
    float precio[3]={50,42.95,9.52};
    char nombre[3][50]={"Agua 2Lt","Cap. Espacio","Turron"};
    char proveedor[3][50]={"Coca-Cola","Bagley","Arcor"};

    char codigoDeBarra[3][13]={"77951234","77959876","70"};

    char fechaDeVencimiento[3][50]={"22/10/2020","10/05/2019","15/12/2008"};

    int i;

    for(i=0;i<3;i++)
    {
        strcpy(list[i].codigo,codigoDeBarra[i]);
        strcpy(list[i].nombre,nombre[i]);
        strcpy(list[i].proveedor, proveedor[i]);
        strcpy(list[i].fecha, fechaDeVencimiento[i]);
        list[i].precio=precio[i];
        list[i].estado = OCUPADO;
    }
}

void mostrarObjeto(eObjeto o)
{
    printf("%15s %15s %15s %15s %15f %5d\n", o.nombre, o.proveedor, o.codigo, o.fecha, o.precio, o.estado);
}

void cargarArray(eObjeto list[], int tam)
{
    int i;
    for(i = 0; i<tam; i++)
    {
        list[i] = pedirObjeto();
    }
}

void mostrarArray(eObjeto list[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        if (list[i].estado == OCUPADO)
        {
            mostrarObjeto(list[i]);
        }
    }
    system("pause");
}

void construirArray(eObjeto list[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        list[i].estado = ABIERTO;
        list[i].precio = 0;
        strcpy(list[i].nombre, "");
        strcpy(list[i].proveedor, "");
        strcpy(list[i].fecha, "");
        strcpy(list[i].codigo, "");
    }
}

int insertarObjeto(eObjeto list[], int tam)
{
    int i;
    i = indexDisponible(list, tam);
    if (i != -1)
    {
        list[i] = pedirObjeto();
    }
    else{ mostrarError("FullArray");}
    return i;
}

int indexDisponible(eObjeto list[], int tam)
{
    int i;
    int index = -1;

    for(i = 0; i < tam; i++)
    {
        if (list[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int existeObjeto(eObjeto o, eObjeto list[])
{
    //PASS
}

int borrarObjeto(eObjeto list[], int tam)
{
    int i;
    char codigo[50];
    int found = FALSE;

    printf("ingrese el codigo de barras: ");
    fflush(stdin);
    gets(codigo);

    for(i = 0; i < tam; i++)
    {
        if(strcmp(list[i].codigo, codigo) == 0)
        {
            list[i].estado = ABIERTO;
            found = TRUE;
            break;
        }
    }

    if(found == FALSE)
    {
        mostrarError("CodeNotFound");
    }

    return 0;
}

int editarObjeto(eObjeto list[], int tam)
{
    int i;
    char codigo[50];
    int found = FALSE;

    printf("ingrese el codigo de barras: ");
    fflush(stdin);
    gets(codigo);

    for(i = 0; i < tam; i++)
    {
        if(strcmp(list[i].codigo, codigo) == 0)
        {
            printf("Ingrese el nuevo precio: ");
            scanf("%f", &list[i].precio);
            found = TRUE;
            break;
        }
    }

    if(found == FALSE)
    {
        mostrarError("CodeNotFound");
    }

    return 0;
}

void mostrarError(char error[])
{
    system("cls");
    system("color 47");
    printf("ERROR: %s\n", error);
    system("pause");
    system("color 07");
}
