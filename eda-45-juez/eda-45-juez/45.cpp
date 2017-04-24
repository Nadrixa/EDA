//Andrés Pascual Contreras & Adrián Muñoz Gámez

#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include <string>
using namespace std;

void numerosAfortunados(int n);

int main() {

	// N: 2 <= N <= 10`6
	int n;

	cin >> n;
	while(n != 0 && n >= 2) {
		numerosAfortunados(n);
		cin >> n;
	}

	return 0;
}

void numerosAfortunados(int n) {
	Queue <int> cola;
	Stack <int> pila;
	int n_inicial = n;
	int m = 2;
	// para guardar los numeros que vayamos sacando de la cola para volverlos a meter
	int aux;
	// para controlar que numeros hay que ir sacando de la cola segun sea m
	int cont = m;
	// variable para controlar cuando se ha terminado cada vuelta
	int ronda = 1;
	//Meter todos los numeros en la cola desde 1 hasta n
	// Ir sacando numeros de m en m, y a cada vuelta comprobar cuantos nums quedan en la cola
	// Si m es mayor que el num de elementos en la cola no dan mas vueltas
	// Sacamos los numeros y los imprimimos
	for(int i = 1; i <= n; i++)
		cola.push_back(i);


	while(m <= cola.size()) {
		
		// Sacamos siempre el primer elemento de la cola
		aux = cola.front();
		cola.pop_front();
		// Si no se salva: no metemos el elemento en ningun sitio
		if(cont == m) {
			cont = 1;
		// Si se salva: metemos el elemento al final de la cola
		}else {
			cola.push_back(aux);
			cont++;
		}

		if(ronda == n) {
			m++;
			n = cola.size();
			ronda = 1;
			cont = m;
		}
		else {
			ronda++;
		}
	}


	while (!cola.empty()) {
		pila.push(cola.front());
		cola.pop_front();
	}

	string mensaje = "";
	mensaje += to_string(n_inicial) + ":";
	
	while (!pila.empty()) {
		mensaje += " " + to_string(pila.top());
		pila.pop();
	}

	cout << mensaje << endl;
}
