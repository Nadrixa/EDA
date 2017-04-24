/*Andrés Pascual Contreras & Adrián Muñoz Gámez - A22*/
#include <iostream>
#include "Arbin.h"

using namespace std;

template <class T> Arbin<T> leerArbol(T const& vacio);
void excursionistasAtrapados(Arbin <int> arbol, int &excursionistas, int &grupos);

int main() {
	int numCasos;

	cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		int excursionistas = 0, grupos = 0;
		Arbin <int> arbol = leerArbol(-1);
		try {
			excursionistasAtrapados(arbol, excursionistas, grupos);
		}
		catch (EArbolVacio e) {} //Por si se mete un arbol vacío.
		//Hemos probado con un string que almacenase todo el cout pero parece ser que ese no es el problema.
		//string resultado = to_string(grupos) + " " + to_string(excursionistas);
		cout << grupos << " " << excursionistas << endl;
	}

	return 0;
}

template <class T>
Arbin<T> leerArbol(T const& vacio) {
	T raiz; cin >> raiz;
	if (raiz == vacio) return Arbin<T>();
	Arbin<T> a1 = leerArbol(vacio);
	Arbin<T> a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}

void excursionistasAtrapados(Arbin <int> arbol, int &excursionistas, int &grupos) {
	if (!arbol.esVacio()) {
		int excursionistasIz = 0, excursionistasDr = 0;

		//Si hay excursionistas en este nodo.
		if (arbol.raiz() > 0) {
			excursionistas = excursionistas + arbol.raiz();
			//Por cada grupo de excursionistas, añadimo
			grupos++;
		}

		try {
			//Llamada recursiva para el hijo izquierdo.
			excursionistasAtrapados(arbol.hijoIz(), excursionistasIz, grupos);
		}
		//Si el hijo izquierdo está vacío, los excursionistas izquierda no aumentan.
		catch (EArbolVacio e){
			excursionistasIz = excursionistasIz + 0;
		}

		try {
			//Llamada recursiva para el hijo izquierdo.
			excursionistasAtrapados(arbol.hijoDr(), excursionistasDr, grupos);
		}
		//Si el hijo derecho está vacío, los excursionistas derecha no aumentan.
		catch (EArbolVacio e) {
			excursionistasDr = excursionistasDr + 0;
		}

		//Si los excursionistas del hijo derecho son mayores que los del hijo izquierdo.
		if (excursionistasDr > excursionistasIz) {
			excursionistas = excursionistas + excursionistasDr;
			if (arbol.raiz() > 0) //Si estamos en un nodo con excursionistas, eliminamos un grupo (pues consideramos que en cada nodo con excursionistas se añade un nuevo grupo)
				grupos = grupos - 1;
		}
		//Si los excursionistas del hijo izquierdo son mayores que los del hijo derecho.
		else if (excursionistasDr < excursionistasIz) {
			excursionistas = excursionistas + excursionistasIz;
			if (arbol.raiz() > 0) //Si estamos en un nodo con excursionistas, eliminamos un grupo (pues consideramos que en cada nodo con excursionistas se añade un nuevo grupo)
				grupos = grupos - 1;
		}
		//En el caso de que los excursionistas del hijo izquierdo y derecho sean iguales y distintos de cero, tan solo añadimos uno de ellos a nuestro grupo de excursionistas. (Pues el otro sí o sí va a necesitar un equipo de rescate).
		else if (excursionistasDr == excursionistasIz && excursionistasDr != 0 && excursionistasIz != 0) {
			excursionistas = excursionistas + excursionistasIz;
			if (arbol.raiz() > 0)
			grupos = grupos - 1;
		}
	}
	else {
		throw EArbolVacio();
	}
}