/*Andrés Pascual Contreras & Adrián Muñoz Gámez - A22*/
#include <iostream>
#include "Arbin.h"

using namespace std;

template <class T> Arbin<T> leerArbol(T const& vacio);
bool arbolGenealogico(Arbin <int> arbol);

int main() {
	int num_casos;

	cin >> num_casos;

	for (int i = 0; i < num_casos; i++) {
		int genealogico;
		Arbin <int> arbol = leerArbol(-1);
		try {
			genealogico = arbolGenealogico(arbol);
			if (!genealogico) {
				cout << "NO";
			}
			else {
				cout << "SI " << arbol.talla();
			}
			cout << endl;
		}
		catch (EArbolVacio e) {
		}


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

bool arbolGenealogico(Arbin <int> arbol) {
	bool genealogico;

	if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
		genealogico = true;
		return genealogico;
	}
	else {
		try {
			genealogico = arbolGenealogico(arbol.hijoIz());
			if (genealogico) {
				if (arbol.raiz() - arbol.hijoIz().raiz() < 18) {
					genealogico = false;
				}
			}
		}
		catch (EArbolVacio e) {}
		try {
			if (genealogico) {
				genealogico = arbolGenealogico(arbol.hijoDr());
				if (genealogico) {
					if (arbol.raiz() - arbol.hijoDr().raiz() < 18) {
						genealogico = false;
					}
					if (arbol.hijoIz().raiz() - arbol.hijoDr().raiz() < 2) {
						genealogico = false;
					}
				}
			}
		}
		catch (EArbolVacio e) {}
		return genealogico;
	}
}