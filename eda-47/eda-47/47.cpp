/* Andrés Pascual Contreras && Adrián Muñoz Gámez - A22*/
#include <iostream>
#include <sstream>
#include "List.h"


using namespace std;

void duplicarPicos(List <int> &lista);


int main () {

	int num_casos;
	int caso;
	char espacios;
	
	cin >> num_casos;
	cin.get(espacios);
	for(int i = 0; i < num_casos; i++) { //n : num_casos, m: longitud de cada caso -> O(n*m)
		List <int> lista;
		cin.get(espacios);
		while(espacios != '\n') { //n: longitud del caso -> O(n)
			cin.putback(espacios);
			cin >> caso;
			lista.push_back(caso);
			cin.get(espacios);
		}
		duplicarPicos(lista);
	}

	return 0;
}

void duplicarPicos(List <int> &lista) {
	List<int>::Iterator it = lista.begin();
	int sumaParcial = 0;
	int contador = 0;

	while (it != lista.end()) { //n: lista.size() -> O(n)
			if (sumaParcial == it.elem()) {
				lista.insert(it.elem(), it);
				contador++;
			}
			sumaParcial += it.elem();
		it.next();
	}

	it = lista.begin();

	cout << contador << ":";

	while (it != lista.end() ){ //n: lista.size() -> O(n)
		cout << " " << it.elem();
		it.next();
	}
	cout << endl;
}
