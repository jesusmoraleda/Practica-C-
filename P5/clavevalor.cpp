//Práctica hecha por: Arantxa Brock Rabines y Jesús Martín Moraleda.
#include "clavevalor.h"
#include "listacadenas.h"



int getTamanno(const tIndicePalabras & l){
	return l.cont;
}

tRegistroIndicePalabras getRegistro(const tIndicePalabras & l, int pos){
	return l.registro[pos];
}

bool esta(const tIndicePalabras & l, const string & s, int & pos){
	bool encontrado = false;
	int ini = 0;
	int fin = l.cont - 1;
	int mitad = 0;

	while (!encontrado && ini <= fin){
		mitad = (ini + fin) / 2;
		
		if (l.registro[mitad].clave == s){
			encontrado = true;
		}
		else if (s < l.registro[mitad].clave){
			fin = mitad - 1;
		}
		else{
			ini = mitad + 1;
		}
	}
	if (encontrado)
		pos = mitad;
	else
		pos = ini;
	
	return encontrado;
}

tListaCadenas buscar(const tIndicePalabras & l, const string & s,const int & pos){
	return l.registro[pos].valor;
}

void insertar(tIndicePalabras & idx, const string & palabra, const string & nombreArchivo){
	bool encontrado = false;
	int cont = 0;
	int pos = 0;

	if (esta(idx, palabra, pos)){
		if (!buscar(idx.registro[pos].valor, nombreArchivo)){
			insertar(idx.registro[pos].valor, nombreArchivo);
		}
	}
	
	else{
		if (idx.capacidad <= idx.cont){
			idx.capacidad = (idx.capacidad * 3) / 2 + 1;
			idx = copiaLista(idx);
		}
		for (int i = idx.cont - 1; i >= pos; i--){
			idx.registro[i + 1] = idx.registro[i];
		}

		inicializaLista(idx.registro[pos].valor);
		
		idx.registro[pos].clave = palabra;
		//idx.registro[pos].valor.cont = 0;
		idx.registro[pos].valor.datos[0] = nombreArchivo; //en la posicion cero ya que se crea un registro nuevo y el cont valdria basura

		idx.registro[pos].valor.cont++;
		idx.cont++;
	}
}

void imprimir(const tIndicePalabras & idx){
	for (int i = 0; i < idx.cont; i++){
		cout << idx.registro[i].clave << endl;
	}
}

ostream & operator<<(ostream & salida, const tIndicePalabras & idx){
	salida << "Clave | Indice" << endl;
	salida << endl;

	for (int i = 0; i < idx.cont; i++){
		salida << idx.registro[i].clave << ": ";
		salida << idx.registro[i].valor;
		salida << endl;
	}
	salida << endl;

	return salida;
}
void inicializaLista(tIndicePalabras & l){
	l.registro = new tRegistroIndicePalabras[TAM];
	l.cont = 0;
	l.capacidad = TAM;
}
void destruirLista(tIndicePalabras & l){
	delete[] l.registro;
}
void listaNULL(tIndicePalabras & l){
	l.registro = NULL;
}
tIndicePalabras copiaLista(tIndicePalabras & l){
	tIndicePalabras newlist;

	newlist.capacidad = l.capacidad;
	newlist.cont = l.cont;
	newlist.registro = new tRegistroIndicePalabras[newlist.capacidad];
	for (int i = 0; i < newlist.cont; i++){
		newlist.registro[i] = l.registro[i];
	}
	return newlist;
}