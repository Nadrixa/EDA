//Andrés Pascual Contreras & Adrián Muñoz Gámez

/*
- Alumnos de 1 a n colocados en circulo.
- Empezando por el primero, va salvando a uno de cada 2 (2, 4, 6...)
- Cuando llega al final empieza de nuevo... hasta que quede un solo alumno ("afortunado")
- Recibe n y m (m >= 1) ejemplo -> 4 1 -> 4 alumnos, que se cogen de 1 en 1.

*/

#include <iostream>
#include "Queue.h"
using namespace std;

int afortunado(int n, int m);

int main() {
	int n, m;

	cin >> n;
	cin >> m;
	while (n != 0 && m != 0) {
		cout << afortunado(n, m) << endl;
		cin >> n;
		cin >> m;
	}

	return 0;
}

int afortunado(int n, int m) {
	Queue <int> cola;
	int resultado;
	int cont = 0;
	int aux;

	for (int i = 1; i <= n; i++)
		cola.push_back(i);

	while (!cola.empty()) {
		aux = cola.front();
		cola.pop_front();
		cont++;
		if (cont == m) {
			if (cola.empty()) resultado = aux;
			cont = 0;
		}
		else {
			cola.push_back(aux);
		}
	}

	return resultado;
}