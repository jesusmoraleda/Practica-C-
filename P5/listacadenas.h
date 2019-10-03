//Práctica hecha por: Arantxa Brock Rabines y Jesús Martín Moraleda.
#ifndef listacadenas_h
#define listacadenas_h
#include <string>
#include<iostream>

using namespace std;

const int TAM = 11;
typedef string *tDatos;
typedef struct{
	tDatos datos;
	int cont;
	int capacidad;
}tListaCadenas;


int getTamanno(const tListaCadenas & l); //Devuelve el tamaño de la lista.
string getCadena(const tListaCadenas & l, int pos); //Devuelve una cadena en la posición pos.
void insertar(tListaCadenas & l, const string & s); //Inserta un elemento al final de la lista.
bool buscar(const tListaCadenas & l, const string & s); //Devuelve true si la cadena está en la lista, y false si no.
void eliminar(tListaCadenas & l, int pos); //Elimina el elemento en la posición pos.
void imprimir(const tListaCadenas & l); //Imprime los elementos de la lista.
ostream & operator<<(ostream & salida, const tListaCadenas & l); //Sobrecarga de los elementos de la lista.
void inicializaLista(tListaCadenas & l);
void destruirLista(tListaCadenas & l);
void listaNULL(tListaCadenas & l);
tListaCadenas copiaLista(tListaCadenas & l);

#endif