/*Andrés Pascual Contreras & Adrián Muñoz Gámez*/
#include <iostream>
#include "Arbin.h"

using namespace std;

template <class T> Arbin<T> leerArbol(T const& vacio);
void aguasLimpias(Arbin<int> arbol, int &tramosNavegables, int &caudales);
int main() {
	int numCasos;
	char espacios;
	cin >> numCasos;
	cin.get(espacios);

	for (int i = 0; i < numCasos; i++) { //n: número de casos -> O(n).
			int tramosNavegables = 0, caudales = 0;
			cin.putback(espacios);
			Arbin <int> arbol = leerArbol(-1);
			try {
				aguasLimpias(arbol, tramosNavegables, caudales);
			}
			catch (EArbolVacio e) {}
			cout << tramosNavegables << endl;		
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

void aguasLimpias(Arbin<int> arbol, int &tramosNavegables, int &caudales) {
	if (!arbol.esVacio()) {
		//Si es hoja y la raíz es 0 sumamos 1 a los caudales.
		if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
			if (arbol.raiz() == 0)
				caudales = caudales + 1;
			else //Si no es 0 la raíz, no sumamos nada.
				caudales = caudales + 0;
		}
		else {
			int caudalesIzquierdo = 0;
			int caudalesDerecho = 0;

			try { //Si hijoIz existe, llama recursivamente a la función.
				aguasLimpias(arbol.hijoIz(), tramosNavegables, caudalesIzquierdo);
				//Comprueba el caudal del hijo izquierdo.
				if (caudalesIzquierdo >= 3)
					tramosNavegables++;
			}
			catch (EArbolVacio e) { // Si el arbol no existe, no se suma al caudal.
				caudales = caudales + 0;
			}

			try { //Si hijoDr existe, llama recursivamente a la función.
				aguasLimpias(arbol.hijoDr(), tramosNavegables, caudalesDerecho);
				//Comprueba el caudal del hijo derecho.
				if (caudalesDerecho >= 3)
					tramosNavegables++;
			}
			catch (EArbolVacio e) { // Si el arbol no existe, no se suma al caudal.
				caudales = caudales + 0;
			}

			//Suma el número de caudales.
			caudales = caudalesIzquierdo + caudalesDerecho;

			//Si es un embalse, resta el agua que se queda.
			if (arbol.raiz() > 0) {
				caudales = caudales - arbol.raiz();
				//El caudal no puede ser negativo.
				if (caudales < 0) caudales = 0;
			}
		}
	}
	else {
		throw EArbolVacio();
	}
}

/*
Devuelve el número de caudales que hay al final de la ejecución. Va calculando el número de tramosNavegables (Teníamos que restarle -1)
*/

/*
int aguasLimpias(Arbin<int> arbol, int &tramosNavegables) {
int caudales = 0;
if (!arbol.esVacio()) {
if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
if (arbol.raiz() == 0)
return 1;
else
return 0;
}
else {
caudales = aguasLimpias(arbol.hijoIz(), tramosNavegables) + aguasLimpias(arbol.hijoDr(), tramosNavegables);

if (arbol.raiz() > 0) {
caudales = caudales - arbol.raiz();
if (caudales < 0) caudales = 0;
}

if (caudales >= 3)
tramosNavegables++;


return caudales;

}
}
else {
return 0;
}
}*/

