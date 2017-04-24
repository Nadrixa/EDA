/*Andrés Pascual Contreras & Adrián Muñoz Gámez*/
#include <iostream>
#include "Arbin.h"

using namespace std;

void calculaAtributos(Arbin <char> arbol, int &nodo, int &hojas, int &maxAltura, int alturaNodo);
template <class T> Arbin<T> leerArbol(T const& vacio);
void pintaArbol(Arbin <char> arbol, string espacios, string &resultado);

int main() {
	int numCasos;
	char espacios;

	cin >> numCasos;
	cin.get(espacios);

	for (int i = 0; i < numCasos; i++) { //n: número de casos -> O(n).
			int nodo = 0, hojas = 0, maxAltura = 0;
			Arbin <char> arbol = leerArbol('.');
			calculaAtributos(arbol, nodo, hojas, maxAltura, maxAltura);
			cout << nodo << " " << hojas << " " << maxAltura << endl;
	}

	return 0;
}

void calculaAtributos(Arbin <char> arbol, int &nodo, int &hojas, int &maxAltura, int alturaNodo) {
	//Si el arbol existe.
	if (!arbol.esVacio()) {
		nodo++; //Incrementamos el número de nodos.
		alturaNodo++; //Incrementamos su altura.
		if (alturaNodo > maxAltura) //Si la altura en la que estamos es mayor a la máxima anteriormente guardada.
			maxAltura = alturaNodo; 
		if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) //Si no tiene hijos.
			hojas++; //Incrementamos el número de hojas.
		else {
			//Llama conb el hijo izquierdo.
			calculaAtributos(arbol.hijoIz(), nodo, hojas, maxAltura, alturaNodo);
			//Llama con el hijo derecho.
			calculaAtributos(arbol.hijoDr(), nodo, hojas, maxAltura, alturaNodo);
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

/*Función que se usó para depurar y ver cómo era el árbol.*/
void pintaArbol(Arbin <char> arbol, string espacios, string &resultado) {
	espacios = espacios + "    ";
	if (!arbol.esVacio()) {
		resultado = resultado + espacios + arbol.raiz() + "\n";
		pintaArbol(arbol.hijoIz(), espacios, resultado);
		pintaArbol(arbol.hijoDr(), espacios, resultado);
	}
}
