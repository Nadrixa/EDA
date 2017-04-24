/*Andrés Pascual Contreras & Adrián Muñoz Gámez - A22*/
#include <iostream>
#include "Arbin.h"

using namespace std;

typedef struct{
	bool ok;
	int sumaNodos;
	int numNodos;
}tSolucion;

template <class T> Arbin<T> leerArbol(T const& vacio);
tSolucion arbolesValiosos(Arbin <int> arbol);

int main() {
	int numCasos; 
	
	cin >> numCasos;
	tSolucion sol;

	for (int i = 0; i < numCasos; i++) { //n: número de casos -> O(n).
		Arbin <int> arbol = leerArbol(-1);

		try {
			sol = arbolesValiosos(arbol);
		}
		//Si se mete un arbol vacío se captura la excepción.
		catch (EArbolVacio) {
			sol.numNodos = 0;
			sol.sumaNodos = 0;
			sol.ok = true;
		}

		if (sol.ok) {
			cout << "SI";
		}
		else {
			cout << "NO";
		}

		cout << endl;
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

tSolucion arbolesValiosos(Arbin <int> arbol) {
	//Si el arbol no está vacío.
	if (!arbol.esVacio()) {
		tSolucion sol;
		//Caso base. Es hoja.
		if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
			//Inicializamos los nodos y la raíz.
			sol.numNodos = 1;
			sol.sumaNodos = arbol.raiz();
			if (arbol.raiz() > 0) { //Si la raíz es mayor que 0, (1 en adelante) cumple la propiedad.
				sol.ok = true;
			}
			else {
				sol.ok = false;
			}
			return sol;
		}
		else {
			tSolucion estrIz;
			tSolucion estrDr;
			//Llamada recursiva con el hijo izquierdo.
			try {
				estrIz = arbolesValiosos(arbol.hijoIz());
			}
			//Si el hijo izquierdo no existe.
			catch (EArbolVacio e) {
				estrIz.numNodos = 0;
				estrIz.sumaNodos = 0;
				estrIz.ok = true; // 0 >= 0 -> cumple.
			}

			//Llamada recursiva con el hijo izquierdo.
			try {
				estrDr = arbolesValiosos(arbol.hijoDr());
			}
			//Si el hijo izquierdo no existe.
			catch (EArbolVacio e) {
				estrDr.numNodos = 0;
				estrDr.sumaNodos = 0;
				estrDr.ok = true; // 0 >= 0 -> cumple.
			}

			//Añadimos los valores calculados en los hijos.
			sol.numNodos = estrIz.numNodos + estrDr.numNodos + 1;
			sol.sumaNodos = estrIz.sumaNodos + estrDr.sumaNodos + arbol.raiz();
			//Inicializamos pensando que no cumple la propiedad.
			sol.ok = false;

			//Si la propiedad ha sido cumplida por sus hijos.
			if (estrIz.ok && estrDr.ok) {
				//Comprobamos si este nodo sigue cumpliendo la propiedad.
				if (sol.sumaNodos >= sol.numNodos)
					sol.ok = true;
			}

			return sol;
		}
	}
	else {
		throw EArbolVacio();
	}
}