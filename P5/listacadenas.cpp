//Práctica hecha por: Arantxa Brock Rabines y Jesús Martín Moraleda.
#include"listacadenas.h"


int getTamanno(const tListaCadenas & l){
	return l.cont;
}

string getCadena(const tListaCadenas & l, int pos){
	return l.datos[pos];
}

void insertar(tListaCadenas & l, const string & s){
	if (l.capacidad <= l.cont){
		l.capacidad = (l.capacidad * 3) / 2 + 1;
		l = copiaLista(l);
	}
	l.datos[l.cont] = s;
	l.cont++;
}

bool buscar(const tListaCadenas & l, const string & s){
	bool encontrado = false;
	int cont = 0;

	while (!encontrado && cont < l.cont){
		if (l.datos[cont] == s)
			encontrado = true;
		else cont++;
	}
	return encontrado;
}

void eliminar(tListaCadenas & l, int pos){
	for (int i = pos; i < l.cont - 1; i++){
		l.datos[i] = l.datos[i + 1];
	}
	l.cont--;
}

void imprimir(const tListaCadenas & l){
	for (int i = 0; i < l.cont; i++){
		cout << l.datos[i] << endl;
	}
}

ostream & operator<<(ostream & salida, const tListaCadenas & l){
	salida << "[";

	for (int i = 0; i < l.cont; i++){
		salida << l.datos[i];
		if (i != l.cont - 1)
			salida << ", ";
	}
	salida << "]";

	return salida;
}
void inicializaLista(tListaCadenas & l){
	l.datos = new string[TAM];
	l.cont = 0;
	l.capacidad = TAM;
}

void listaNULL(tListaCadenas & l){
	l.datos = NULL;
}

void destruirLista(tListaCadenas & l){
	delete [] l.datos;
}
tListaCadenas copiaLista(tListaCadenas & l){
	tListaCadenas newlist;

	newlist.capacidad = l.capacidad;
	newlist.cont = l.cont;
	newlist.datos = new string[newlist.capacidad];
	for (int i = 0; i < newlist.cont; i++){
		newlist.datos[i] = l.datos[i];
	}
	return newlist;
}