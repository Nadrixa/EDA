//Andrés Pascual Contreras & Adrián Muñoz Gámez
#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

void sumaDigitos(int numero);
//Separa en dígitos el número recibido, los mete en la pila.
void gestionaNumero(int numero, Stack <int> &pila);

int main() {
	/*Declaración*/
	int caso_prueba; //No mayor que 10^9

	cin >> caso_prueba;
	//Llenamos el array de casos de prueba.
	while (caso_prueba != -1) {
		sumaDigitos(caso_prueba);
		cin >> caso_prueba;
	}

	return 0;
}

void sumaDigitos(int numero) {
	/*Declaración*/
	Stack <int> pila;
	int resultadoSuma;
	int digito;
	string mensaje_resultado;

		/*Inicialización*/
		resultadoSuma = 0;
		mensaje_resultado = "";

	gestionaNumero(numero, pila);

	while (!pila.empty()) {
		digito = pila.top();
		pila.pop();
		resultadoSuma += digito;
		mensaje_resultado += to_string(digito);
		if (pila.empty())
			mensaje_resultado += " = ";
		else
			mensaje_resultado += " + ";
	}

	mensaje_resultado += to_string(resultadoSuma);
	cout << mensaje_resultado << endl;
	
}

void gestionaNumero(int numero, Stack <int> &pila) {
	if (numero == 0) pila.push(numero);
	while (numero > 0) {
		pila.push(numero % 10);
		numero = numero / 10;
	}
}