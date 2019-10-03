//Práctica hecha por: Arantxa Brock Rabines y Jesús Martín Moraleda.
#ifndef indices_h
#define indices_h
#include "clavevalor.h"
#include "listacadenas.h"
#include "matriz.h"
#include <iostream>
#include <string>

using namespace std;

void crearTabla(tIndicePalabras & tabla, tListaCadenas & totales, const string & archivoInicial, tMatriz & L); //Crea la tabla de índices.
void ordenar(tIndicePalabras & tabla); //Ordena la tabla por las claves de menor a mayor
string pedirArchivo(); //Pide el nombre del fichero raíz sobre el que crear la tabla de índices.
string pedirPalabra(); //Pide la palabra a buscar.
tIndicePalabras nuevoIndice(); //Inicializa el contador de IndicePalabras a 0.
tListaCadenas nuevaListaCadenas(); //Inicializa la lista de cadenas a 0.
int buscarPos(const tListaCadenas & totales, const string &archivo); //Busca la posicion para poner el 1 en la matriz L


#endif