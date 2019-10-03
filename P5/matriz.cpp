//Práctica hecha por: Arantxa Brock Rabines y Jesús Martín Moraleda.
#include "matriz.h"
#include <iomanip>

using namespace std;

tMatriz matrizConstante(double x, int n){
	tMatriz matriz;
	matriz.x = 0;
	
	for (int i = 0; i < n; i++){
		matriz.y = 0;
	
		for (int j = 0; j < n; j++){
			matriz.datos[i][j] = x;
			matriz.y++;
		}
		matriz.x++;
	}

	return matriz;
}

tVector operator*(const tMatriz & m, const tVector & v){
	tVector mul;
	mul.tam = v.tam;
	double aux_suma = 0.0;
	
	for (int i = 0; i < m.x; i++){
		aux_suma = 0.0;
	
		for (int j = 0; j < m.y; j++){
			aux_suma = aux_suma + (m.datos[i][j] * v.vector[j]);
		}
		
		mul.vector[i] = aux_suma;
	}
	
	return mul;
}

tMatriz operator*(double x, const tMatriz & m){
	tMatriz mul;
	mul.x = m.x;
	mul.y = m.y;
	
	for (int i = 0; i < m.x; i++){
		for (int j = 0; j < m.y; j++){
			mul.datos[i][j] = m.datos[i][j] * x;
		}
	}
	
	return mul;
}

tMatriz operator+(const tMatriz & m1, const tMatriz & m2){
	tMatriz suma;
	suma.x = m1.x;
	suma.y = m1.y;
	
	for (int i = 0; i < m1.x; i++){
		for (int j = 0; j < m1.y; j++){
			suma.datos[i][j] = m1.datos[i][j] + m2.datos[i][j];
		}
	}
	
	return suma;
}

tMatriz desdeEnlacesAMatriz(const tMatriz & L){
	double n = L.x;
	double cn = 1 / n;
	double e = 0.0;
	tMatriz M = inicMatriz(n, (1 - C) / n);
	tMatriz CN = inicMatriz(n, cn);
	tMatriz Mprima = inicMatriz(n, 0.0);
	tVector noCeros;
	int nj;
	
	for (int j = 0; j < L.x; j++){
		nj = 0;
		noCeros.tam = 0;
		
		for (int i = 0; i < L.y; i++){//calculo el numero de enlaces que tiene un archivo
			if (L.datos[i][j] != 0){
				noCeros.vector[nj] = i;
				nj++;
				noCeros.tam++;
			}
		}
		if (nj != 0){
			e = (1.0 / nj);
		
			for (int a = 0; a < noCeros.tam; a++){//en funcion del numero de enlaces del archivo calculo Mprima
				int pos = noCeros.vector[a];
				Mprima.datos[pos][j] = e;
			}
		}
		else{
			e = (1.0 / n);
			
			for (int a = 0; a < n; a++){
				Mprima.datos[a][j] = e;
			}
		}
	}

	tMatriz M_aux = inicMatriz(n, 0.0);
	tMatriz M_aux1 = inicMatriz(n, 0.0);
	
	M_aux = (1 - C) * CN;
	M_aux1 = C * Mprima;
	M = M_aux + M_aux1;

	return M;
}

tVector normaliza(const tVector & v){
	tVector n;
	double division = v.vector[0];
	n.tam = v.tam;
	
	for (int i = 0; i < v.tam; i++){
		n.vector[i] = v.vector[i] / division;
	}
	
	return n;
}

tMatriz inicMatriz(const int tamaño, const double valor){
	tMatriz m;
	m.x = tamaño;
	m.y = tamaño;

	for (int i = 0; i < m.x; i++){
		for (int j = 0; j < m.y; j++){
			m.datos[i][j] = valor;
		}
	}

	return m;
}

ostream & operator<<(ostream & salida, const tMatriz & L){
	for (int i = 0; i < L.x; i++){
		for (int j = 0; j < L.y; j++){
			salida << setw(10);
			salida << L.datos[i][j];
			salida << setw(10);
		}
		salida << endl;
	}

	return salida;
}

ostream & operator<<(ostream & salida, const tVector & v){
	for (int i = 0; i < v.tam; i++){
		salida << v.vector[i] << " ";
	}

	return salida;
}

void rellenaCeros(tMatriz & M){
	for (int i = 0; i < M.x; i++){
		for (int j = 0; j < M.y; j++){
			if (M.datos[i][j] != 1.0 && M.datos[i][j] != 0.0)
				M.datos[i][j] = 0.0;
		}
	}
}

tVector vectorPropio(const tMatriz & M){
	tVector v;
	v.tam = M.x;
	
	for (int i = 0; i < M.x; i++){
		v.vector[i] = 1.0;
	}
	
	double potencia = 0.000001;
	tVector w = M * v;
	
	while (!proximos(v, w, potencia)){
		v = w;
		w = M * v;
	}
	
	return normaliza(v);
}

tVector operator/(const tVector & v, const tVector & v1){
	tVector division;
	division.tam = v.tam;

	for (int i = 0; i < v.tam; i++){
		division.vector[i] = v.vector[i] / v1.vector[i];
	}
	
	return division;
}

bool proximos(const tVector &v1, const tVector &v2, double potencia){
	int i = 0;

	while (i < v1.tam && abs(1 - v1.vector[i] / v2.vector[i]) < potencia){
		i++;
	}

	return i == v1.tam;
}

double getVector(const tVector &v, int pos){
	return v.vector[pos];
}

void ordenar(tVector &v, tListaCadenas &totales){
	/*double tmp;
	string aux;
	bool ok = true;
	int i = 0;
	while ((i < v.tam - 1 && ok)){
		ok = false;
		for (int j = v.tam - 1; j > i; j--){
			if (v.vector[j] > v.vector[j - 1]){
				tmp = v.vector[j];
				aux = totales.datos[j];
				v.vector[j] = v.vector[j - 1];
				totales.datos[j] = totales.datos[j - 1];
				v.vector[j - 1] = tmp;
				totales.datos[j - 1] = aux;
				ok = true;
			}
		}
		if (ok){
			i++;
		}

	}*/
	double tmp;
	string txt;
	// Del primero al penúltimo...
	for (int i = 0; i < v.tam - 1; i++) {
		// Desde el último hasta el siguiente a i...
		for (int j = v.tam - 1; j > i; j--) {
			if (v.vector[j] < v.vector[j - 1]) {
				tmp = v.vector[j];
				v.vector[j] = v.vector[j - 1];
				v.vector[j - 1] = tmp;
				txt = totales.datos[j];
				totales.datos[j] = totales.datos[j - 1];
				totales.datos[j - 1] = txt;
			}
		}
	}

}