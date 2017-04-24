/*Andrés Pascual Contreras & Adrián Muñoz Gámez - A22*/
#include <iostream>
#include "Arbin.h"

using namespace std; 

template <class T> Arbin<T> leerArbol(T const& vacio);
void calculaFrontera(Arbin <int> arbol, List <int> &lista);

int main() {
	int numCasos;

	cin >> numCasos;

	for (int i = 0; i < numCasos; i++) { //n: número de casos -> O(n).


			int nodo = 0, hojas = 0, maxAltura = 0;
			Arbin <int> arbol = leerArbol(-1);
			List <int> listaFrontera;
			calculaFrontera(arbol, listaFrontera);

			List<int>::ConstIterator it = listaFrontera.cbegin();
			if (!listaFrontera.empty()) { //n: tamaño de la lista -> O(n).
				cout << it.elem();
				it.next();
				while (it != listaFrontera.cend()) {
					cout << " " << it.elem();
					it.next();
				}
			}
			cout << endl;

	}

	return 0;
}

void calculaFrontera(Arbin <int> arbol, List <int> &lista) {
	//Si el arbol no es vacío.
	if (!arbol.esVacio()) {
		//Si es hoja.
		if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
			//Añadimos el elemento a la lista.
			lista.push_back(arbol.raiz());
		}
		else {
			//Llamamos recursivamente con el hijo izquierdo.
			calculaFrontera(arbol.hijoIz(), lista);
			//Llamamos recursivamente con el hijo derecho.
			calculaFrontera(arbol.hijoDr(), lista);
		}
	}
}

template <class T>
Arbin<T> leerArbol(T const& vacio) {
	T raiz; cin >> raiz;
	if (raiz == vacio) return Arbin<T>();
	Arbin<T> a1 = leerArbol(vacio);
	Arbin<T> a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}
