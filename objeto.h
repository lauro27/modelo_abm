#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ABIERTO 0
#define OCUPADO 1
#define BORRADO -1

#define TRUE 1
#define FALSE 0

typedef struct
{
    int estado;
    char nombre[50];
    char proveedor[50];
    char codigo[50];
    float precio;
    char fecha[50];
}eObjeto;

eObjeto pedirObjeto();

void inicializarObjetos(eObjeto[], int);

void mostrarObjeto(eObjeto);

void cargarArray(eObjeto[], int);

void mostrarArray(eObjeto[], int);

void construirArray(eObjeto[], int);

int insertarObjeto(eObjeto[], int);

int indexDisponible(eObjeto[], int);

int existeObjeto(eObjeto, eObjeto[]);

int borrarObjeto(eObjeto[], int);

int editarObjeto(eObjeto[], int);

void mostrarError(char[]);
