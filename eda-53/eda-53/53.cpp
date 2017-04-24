/*Andrés Pascual Contreras & Adrián Muñoz Gámez - A22*/
#include <iostream>
#include "Arbin.h"

using namespace std;

template <class T> Arbin<T> leerArbol(T const& vacio);
template <class T> T elementoMinimo(Arbin<T> arbol);


int main() {
	bool ok = true;
	char tipoArbol;

	cin.get(tipoArbol);
	while (cin) { //Mientras el cin no sea erróneo.
		if (tipoArbol == 'N') {
			int min;
			Arbin<int> arbol = leerArbol(-1);
			min = elementoMinimo(arbol);
			cout << min << endl;
		}
		else if (tipoArbol == 'P') {
			string min;
			string almohadilla = "#";
			Arbin <string> arbol = leerArbol(almohadilla);
			min = elementoMinimo(arbol);
			cout << min << endl;
		}
		cin.get(tipoArbol);
	}

	return 0;
}


/*int main() {
	bool ok = true;
	char tipoArbol;

	cin.get(tipoArbol);
	while (cin) { //Mientras el cin no sea erróneo.
		if (tipoArbol == 'N') {
			int min;
			Arbin<int> arbol = leerArbol(-1);
			try {
				min = elementoMinimo(arbol);
			}
			catch (EArbolVacio e) {
				min = -1;
			}

			cout << min << endl;
		}
		else if (tipoArbol == 'P') {
			string min;
			string almohadilla = "#";
			Arbin <string> arbol = leerArbol(almohadilla);
			try {
				min = elementoMinimo(arbol);
			}
			catch (EArbolVacio e) {
				min = "#";
			}

			cout << min << endl;
		}
		cin.get(tipoArbol);
	}

	return 0;
}*/

template <class T>
Arbin<T> leerArbol(T const& vacio) {
	T raiz; cin >> raiz;
	if (raiz == vacio) return Arbin<T>();
	Arbin<T> a1 = leerArbol(vacio);
	Arbin<T> a2 = leerArbol(vacio);
	return Arbin<T>(a1, raiz, a2);
}

/*
PRIMERA SOLUCIÓN CON PARÁMETRO DE ENTRADA/SALIDA -> No necesitamos valor mínimo predefinido.
*/
/*
template <class T> void elementoMinimo(Arbin<T> arbol, T &minimo) {
	//Si el arbol no está vacío.
	if (!arbol.esVacio()) {
		//Si el elemento del arbol es menor.
		if (arbol.raiz() < minimo) {
			//Asignamos el elemento del arbol al mínimo.
			minimo = arbol.raiz();
		}
		//Se llama recursivamente con el hijo izquierdo.
		elementoMinimo(arbol.hijoIz(), minimo);
		//Se llama recursivamente con el hijo izquierdo.
		elementoMinimo(arbol.hijoDr(), minimo);
	}

}*/

/*
SEGUNDA SOLUCIÓN CON RETURN, COMPROBANDO SI EL HIJO IZQUIERDO Y DERECHO EXISTEN. ENTREGADA Y CORRECT
*/
template <class T> T elementoMinimo(Arbin<T> arbol) {
	//Si el arbol no está vacío.
	if (!arbol.esVacio()) {
		//Si es hoja devolvemos su valor almacenado.
		if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
			return arbol.raiz();
		}
		else {
			T min;
			//Si el hijo izquierdo existe.
			if (!arbol.hijoIz().esVacio()) {
				//igualamos el minimo elemento al hijo izquierdo (al final acabará llegando a una hoja).
				min = elementoMinimo(arbol.hijoIz());
				//Si el minimo es mayor que el elemento del arbol actual.
				if (min > arbol.raiz()) {
					//Asignamos el elemento del arbol actual.
					min = arbol.raiz();
				}
			}
			//Si no existe el hijo izquierdo.
			else {
				//Asignamos como valor el elemento del arbol actual.
				min = arbol.raiz();
			}
			//Si existe el hijo derecho.
			if (!arbol.hijoDr().esVacio()) {
				T aux;
				//Guardamos el elemento al minimo que genera el hijo derecho.
				aux = elementoMinimo(arbol.hijoDr());
				//Si el minimo actual es mayor que el minimo obtenido en la línea anterior.
				if (min > aux)
					//Se asigna el minimo calculado en aux.
					min = aux;
			}	
			//Devuelve el mínimo calculado hasta el momento.
			return min;
		}
	}

}

/*
SOLUCIÓN CON TRY Y CATCH -> JUEZ ARROJA TIME-LIMIT.
*/
/*
template <class T> T elementoMinimo(Arbin<T> arbol) {
	//Si el arbol no está vacío.
	if (!arbol.esVacio()) {
		//Si es hoja devolvemos su valor almacenado.
		if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
			return arbol.raiz();
		}
		else {
			T min;
			//igualamos el minimo elemento al hijo izquierdo (al final acabará llegando a una hoja).
			try {
				min = elementoMinimo(arbol.hijoIz());
				//Si el minimo es mayor que el elemento del arbol actual.
				if (min > arbol.raiz()) {
					//Asignamos el elemento del arbol actual.
					min = arbol.raiz();
				}
			}
			catch (EArbolVacio e) {
				min = arbol.raiz();
			}
			T aux;
			//Guardamos el elemento al minimo que genera el hijo derecho.
			try {
				
				aux = elementoMinimo(arbol.hijoDr());
				//Si el minimo actual es mayor que el minimo obtenido en la línea anterior.
				if (min > aux)
					//Se asigna el minimo calculado en aux.
					min = aux;
				//Devuelve el mínimo calculado hasta el momento.
			}
			catch (EArbolVacio e) {
				aux = -1;
			}

			return min;
		}
	}
	else { //Si el arbol está vacío lanzamos una excepción.
		throw EArbolVacio();
	}
}*/