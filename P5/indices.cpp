//Práctica hecha por: Arantxa Brock Rabines y Jesús Martín Moraleda.
#include "indices.h"

#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;


void crearTabla(tIndicePalabras & tabla, tListaCadenas & totales, const string & archivoInicial, tMatriz & L){
	tListaCadenas visitados;
	tListaCadenas no_visitados;
	ifstream archivo;
	char c;
	string cadena;
	bool insert = true;

	//tabla.cont = 0;
	//visitados.cont = 0;
	//no_visitados.cont = 0;
	//totales.cont = 0;
	inicializaLista(tabla);
	inicializaLista(visitados);
	inicializaLista(no_visitados);
	inicializaLista(totales);

	no_visitados.datos[0] = archivoInicial;
	no_visitados.cont++;
	totales.datos[totales.cont] = archivoInicial;
	totales.cont++;
	L = inicMatriz(1, 0.0);
	
	while (no_visitados.cont > 0){	
		visitados.datos[visitados.cont] = no_visitados.datos[no_visitados.cont - 1];
		no_visitados.cont--;
		visitados.cont++;
		
		string arch = visitados.datos[visitados.cont - 1];
		
		archivo.open(arch);
		if (archivo.is_open()){//no pongo else ya que se da por hecho que los archivos existen
			while (!archivo.eof()){
				cadena = "";
				archivo.get(c);
				
				while (!ispunct(c) && !isspace(c)){//bucle para leer una palabra
					cadena += c;
					archivo.get(c);
				}
				
				transform(cadena.begin(), cadena.end(), cadena.begin(), tolower);
				
				if (c == '<'){
					insert = false;
					archivo.get(c);
					
					while (c != '>'){
						cadena += c;
						archivo.get(c);
					}
					
					if (buscar(totales, cadena)){
						int pos1 = buscarPos(totales, cadena);
						int pos2 = buscarPos(totales, arch);
						L.datos[pos1][pos2] = 1.0;
					}
					else{
						insertar(totales, cadena);
						L.x++;
						L.y++;
						int pos = buscarPos(totales, arch);
						L.datos[L.x -1][pos] = 1.0;
						rellenaCeros(L);
					}

					if (!buscar(visitados, cadena)){
						insertar(no_visitados, cadena);
					}
					
					archivo.get(c); //lee el espacio en blanco siguiente al enlace
				}
				else insert = true;
				
				if (insert && cadena != ""){
					insertar(tabla, cadena, arch);
					//ordenar(tabla);
				}
			}
		}
		archivo.close();
	}
	
}

void ordenar(tIndicePalabras & tabla){
	string tmp;
	tListaCadenas aux;
	
	for (int i = 0; i < tabla.cont - 1; i++) {
		// Desde el último hasta el siguiente a i...
		for (int j = (tabla.cont - 1); j > i; j--) {
			if (tabla.registro[j].clave < tabla.registro[j - 1].clave) {
				tmp = tabla.registro[j].clave;
				tabla.registro[j].clave = tabla.registro[j - 1].clave;
				tabla.registro[j - 1].clave = tmp;
				aux = tabla.registro[j].valor;
				tabla.registro[j].valor = tabla.registro[j - 1].valor;
				tabla.registro[j - 1].valor = aux;
			}
		}
	}
}

string pedirArchivo(){
	string archivoInicial;

	cout << "Por favor, introduzca el nombre del fichero raiz a partir del que se creara el indice : ";
	cin >> archivoInicial;

	return archivoInicial;
}

string pedirPalabra(){
	string palabra;
	
	cout << "Introduzca una palabra (fin para terminar): " << endl;
	cin >> palabra;

	return palabra;
}

tIndicePalabras nuevoIndice(){
	tIndicePalabras l;
	l.cont = 0;
	
	return l;
}

tListaCadenas nuevaListaCadenas(){
	tListaCadenas m;
	m.cont = 0;
	
	return m;
}

int buscarPos(const tListaCadenas & totales, const string &archivo){
	bool encontrado = false;
	int pos = 0;
	
	while (!encontrado && pos < totales.cont){
		if (totales.datos[pos] == archivo){
			encontrado = true;
		}
		else pos++;
	}

	return pos;
}