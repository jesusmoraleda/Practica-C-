//Práctica hecha por: Arantxa Brock Rabines y Jesús Martín Moraleda.
#include "clavevalor.h"
#include "indices.h"
#include "listacadenas.h"
#include "matriz.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(){
	tIndicePalabras idx = nuevoIndice();
	tListaCadenas totales = nuevaListaCadenas();
	tMatriz L = inicMatriz(1, 0.0);
	string nombreArchivo = pedirArchivo();

	cout << endl;
	cout << "Cargando..." << endl;
	cout << endl;
	crearTabla(idx, totales, nombreArchivo, L);
	cout << "Tabla indice creada." << endl;
	cout << endl;
	cout << idx;
	cout << "Matriz L: " << endl << L << endl;
	cout << "Totales: " << endl << totales << endl;
	cout << endl;

	tMatriz M = desdeEnlacesAMatriz(L);

	cout << "C: " << C << endl;
	cout << endl;
	cout << "Matriz M: " << endl << M << endl;

	tVector v = vectorPropio(M);

	cout << "Vector v: " << endl << v << endl;
	cout << endl;

	string palabra = pedirPalabra();

	while (palabra != "fin"){
		tListaCadenas archivos;
		int pos = 0;
		tListaCadenas arch_aux;
		tVector vec_aux;
		//arch_aux.cont = 0;
		inicializaLista(arch_aux);
		vec_aux.tam = 0;
		if (esta(idx, palabra, pos)){
			archivos = buscar(idx, palabra, pos);//archivos en los que esta la palabra
		
			for (int i = 0; i < totales.cont; i++){
				arch_aux.datos[i] = getCadena(archivos, i);
				arch_aux.cont++;
				vec_aux.vector[i] = getVector(v, i);
				vec_aux.tam++;
			}
			
			ordenar(vec_aux, arch_aux);

			for (int i = totales.cont - 1; i >= 0; i--){
				if (buscar(archivos, totales.datos[i])){
					cout << totales.datos[i] << " " << "(" << vec_aux.vector[i] << ")" << endl;
				}
			}
		}
		else
			cout << "La palabra no esta en la tabla" << endl;
		
		
		cout << endl;
		palabra = pedirPalabra();
	}
	for (int i = 0; i < idx.cont; i++){
		destruirLista(idx);
		destruirLista(idx.registro[i].valor);
	}
	system("pause");
	return 0;
} // main

