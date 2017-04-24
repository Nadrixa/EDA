/*Andrés Pascual Contreras & Adrián Muñoz Gámez - A22*/
#include <iostream>
#include "List.h"

using namespace std;

void ordenaListas(const List <int> &lista1, const List <int> &lista2);

int main() {
	int num_casos;
	int numero_lista;
	char espacios;


	cin >> num_casos;
	cin.get(espacios);
	for (int i = 0; i < num_casos; i++) { //n: numero de casos, m1: longitud caso1, m2: longitud caso2 -> O(n*(m1+m2)).
		List <int> lista1;
		List <int> lista2;
		cin.get(espacios);
		//Primera lista.
		while (espacios != '\n') { //n: longitud caso -> O(n).
			cin.putback(espacios);
			cin >> numero_lista;
			lista1.push_back(numero_lista);
			cin.get(espacios);
		}
		cin.get(espacios);
		//Segunda lista.
		while (espacios != '\n') { //n: longitud caso -> O(n).
			cin.putback(espacios);
			cin >> numero_lista;
			lista2.push_back(numero_lista);
			cin.get(espacios);
		}
		//Llamada a función.
		ordenaListas(lista1, lista2);
	}
	return 0;
}

void ordenaListas(const List<int> &lista1, const List<int> &lista2) {
	List <int> resultado;
	List <int>::ConstIterator it1 = lista1.cbegin();
	List <int>::ConstIterator it2 = lista2.cbegin();
	int aux1, aux2;

	while (it1 != lista1.cend() && it2 != lista2.cend()){ //n:Longitud lista más corta -> O(n).
		aux1 = it1.elem();
		aux2 = it2.elem();
		if (aux1 <= aux2) {
			resultado.push_back(aux1);
			it1.next();
		}
		else {
			resultado.push_back(aux2);
			it2.next();
		}
	}
	//Solo se va a ejecutar uno de los dos. Metemos todos los elementos de la lista que no esté vacía en el resultado.
	while (it1 != lista1.cend()) {//n: longitud lista más corta, m: elementos ya recorridos -> O(n-m).
		resultado.push_back(it1.elem());
		it1.next();
	}
	while (it2 != lista2.cend()) {//n: longitud lista más corta, m: elementos ya recorridos -> O(n-m).
		resultado.push_back(it2.elem());
		it2.next();
	}

	List <int>::ConstIterator itResultado = resultado.cbegin();

	while (itResultado != resultado.cend()) { //n: longitud lista -> O(n).
		cout << " " << itResultado.elem();
		itResultado.next();
	}
	cout << endl;
}
