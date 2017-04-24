/* Andr�s Pascual Contreras & Adri�n Mu�oz G�mez*/
#include <iostream>
#include "List.h"

using namespace std;

int main() {
	int num;
	bool ok = true;

	while (ok) {
		List<int> lista;
		cin >> num;

		//PEDAZO DE �APA.
		if (!cin) ok = false;
		
		while (num != 0) { //n: longitud del caso -> O(n)
			lista.push_back(num);
			cin >> num;
		}

		if (!lista.empty()) {
			lista.invertirNodos(); //Coste en List.h
			lista.mostrarLista(); //Coste en List.h
		}
		else {
			cout << endl;
		}
	}

	return 0;
}