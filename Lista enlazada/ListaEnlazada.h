#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <iostream>
#include "Node.h"

class ListaEnlazada
{
	private:
		Node* head;

	public:
		//Constructor
		ListaEnlazada();

		void insertarInicio(int valor);

		void imprimir();
};
#endif