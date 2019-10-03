//Práctica hecha por: Arantxa Brock Rabines y Jesús Martín Moraleda.
#ifndef matriz_h
#define matriz_h
#include <iostream>
#include <cmath>
#include "listacadenas.h"
using namespace std;

const double C = 0.85;
const int MAX_TAM = 50;

typedef struct{
	double datos[MAX_TAM][MAX_TAM];
	int x,y;
}tMatriz;

typedef struct{
	double vector[MAX_TAM];
	int tam;
}tVector;


tMatriz matrizConstante(double x, int n); //Crea una matriz de  n * n, en la que todos los valores iniciales son x.
tVector operator*(const tMatriz & m, const tVector & v); //Multiplica una matriz por un vector.
tMatriz operator*(double x, const tMatriz & m); //Obtiene la matriz que se obtiene multiplicando cada elemento de m por x.
tMatriz operator+(const tMatriz & m1, const tMatriz & m2); //Suma dos matrices.
tMatriz desdeEnlacesAMatriz(const tMatriz & L); //Devuelve la matriz M obtenida de L como en la introducción de la sección 4.
tVector normaliza(const tVector & v); //Devuelve un vector proporcional a v con la primera componente igual a 1.0.
tVector vectorPropio(const tMatriz & M); //M es una matriz tal que todas sus columnas suman 1, devuelve un vector v con la 
										//primera componente igual a 1 tal que M ∙ v ≃ v
tMatriz inicMatriz(const int tamaño, const double valor); //Inicializa la matriz L.
ostream & operator<<(ostream & salida, const tMatriz & L); //Sobrecarga de la matriz L.
ostream & operator<<(ostream & salida, const tVector & v); //Sobrecarga del vector v.
tVector operator/(const tVector & v, const tVector & v1); //Divide los vectores v y v1.
void rellenaCeros(tMatriz & M); //Cada vez que se lee un nuevo archivo se rellena con ceros la matriz M.
bool proximos(const tVector &v1, const tVector &v2, double potencia); //Encuentra el vector que cumpla la condicion de (1- v1/v2 < 10^-5).
void ordenar(tVector &v, tListaCadenas & archivo); //Ordena de mayor a menor la relevancia con la que aparece la clave en el archivo.
double getVector(const tVector &v, int pos);


#endif