//Pr�ctica hecha por: Arantxa Brock Rabines y Jes�s Mart�n Moraleda.
#ifndef clavevalor_h
#define clavevalor_h
#include "listacadenas.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

const int MAXPAL = 150;

typedef struct{
	string clave; //palabras que leemos de los archivos
	tListaCadenas valor; //struct con contador y array en el que estan los archivos en los que aparece la palabra de arriba
}tRegistroIndicePalabras;

typedef tRegistroIndicePalabras *tIndices;
typedef struct{
	tIndices registro;
	int cont;
	int capacidad;
}tIndicePalabras;


int getTamanno(const tIndicePalabras & l); //Devuelve el tama�o de la tabla.
tRegistroIndicePalabras getRegistro(const tIndicePalabras & l, int pos); //Devuelve el registro en la posici�n pos.
bool esta(const tIndicePalabras & l, const string & s, int & pos); //Devuelve true si la palabra es una clave en la tabla, y false en caso contrario.
tListaCadenas buscar(const tIndicePalabras & l, const string & s, const int & pos); //Dada una clave que est� en la tabla devuelve la lista de cadenas asociada a esa clave.
void insertar(tIndicePalabras & idx, const string & palabra, const string & nombreArchivo); //Si palabra es ya una clave de la tabla, a�ade
																							//nombreArchivo a la lista de archivos correspondiente.Si no, crea un registro nuevo con esa informaci�n.
void imprimir(const tIndicePalabras & idx); //Imprime la tabla.
ostream & operator<<(ostream & salida, const tIndicePalabras & idx); //Sobrecarga de la tabla.
void inicializaLista(tIndicePalabras & l);
void destruirLista(tIndicePalabras & l);
void listaNULL(tIndicePalabras & l);
tIndicePalabras copiaLista(tIndicePalabras & l);

#endif