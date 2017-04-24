#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

bool balanceado(string caso);
bool esApertura(char simbolo);
bool esClausura(char simbolo);
bool esPareja(char simboloActual, char simboloPila);

int main() {
	string caso;

	getline(cin, caso);

	while (caso != ".") {
		if (balanceado(caso))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		getline(cin, caso);
	}

	return 0;
}

bool balanceado(string caso) {
	/*Declaración*/
	Stack <char> pila; 
	int contador;
	bool balanceado; 
	char simbolo;

		/*Inicialización*/
		contador = 0;
		balanceado = true;


	while (contador < caso.length() && balanceado) {
		simbolo = caso[contador];
		//Si el simbolo es apertura, lo guardo en la pila.
		if (esApertura(simbolo)) {
			pila.push(simbolo);
		}
		//Si es clausura, como las monjas: 
		else if (esClausura(simbolo)){
			//si la pila no está vacía.
			if (!pila.empty()) {
				//Comprobamos si es la pareja del último símbolo, si lo es, tan solo sacamos el último símbolo de la pila.
				if (esPareja(simbolo, pila.top())) {
					pila.pop();
				}
				//Si no es pareja, deja de estar balanceado.
				else {
					balanceado = false;
				}
			}
			//si la pila está vacía (primer caso).
			else {
				balanceado = false;
			}
		}
		contador++;
	}

	if (!pila.empty()) {
		balanceado = false;
		pila.pop();
	}

	return balanceado; 
}

bool esApertura(char simbolo) {
	bool apertura = false;
	
	if (simbolo == '(' || simbolo == '{' || simbolo == '[')
		apertura = true;

	return apertura;
}

bool esClausura(char simbolo) {
	bool clausura = false;

	if (simbolo == ')' || simbolo == '}' || simbolo == ']')
		clausura = true;

	return clausura;
}

bool esPareja(char simboloActual, char simboloPila) {
	bool pareja = false;

	//SimboloActual es clausura siempre.
	switch (simboloActual) {
	case ')':
		if (simboloPila == '(')
			pareja = true;
		break;
	case ']':
		if (simboloPila == '[')
			pareja = true;
		break;
	case '}':
		if (simboloPila == '{')
			pareja = true;
		break;
	}

	return pareja;
}