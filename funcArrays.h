#ifndef FUNCARRAYS_H_INCLUDED
#define FUNCARRAYS_H_INCLUDED
#include "funcArrays.c"


// 1.1
void insPosicion(int *vec, int *ce, int val, int pos, int max);
//ej 1.2
void insOrdenado(int *vec, int *ce, int val, int max);
//1.3
void elimPosicion(int *vec, int *ce, int pos);
//1.4
void elimPrimerAp(int *vec, int *ce, int elem);
//1.5
void elimRepetidos(int *vec, int *ce, int elem);
//ej 1.6
int esPalindromo(char *cad);
// 1.7
int valCadena (char *cad);
//1.8
int contPal (char *cad, char *dest);
//1.9
void normalizarCad(char *cad);
//1.10
char* desofuscar(char *cad);
//1.11
void cargaCadenas(char *cad1, char *cad2, char matriz[][2][MAXLENGHT]);


//otras funciones
void mostrarvec(int *v, int ce);
void elimSaltoLinea(char *cad);
size_t contarCad(const char *cad);
char* concatenar(char *cad1, const char *cad2);
char* copiarStr(char *cad1, const char *cad2);
int compararStr(const char *cad1, const char *cad2);
char* charstr(char *cad1, int x);
char* charstrr(char *cad1, int x);


#endif // FUNCARRAYS_H_INCLUDED
