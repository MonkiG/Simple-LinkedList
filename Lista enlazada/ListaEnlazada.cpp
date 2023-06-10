#include "ListaEnlazada.h"
#include "Node.h"

ListaEnlazada::ListaEnlazada() : head(nullptr) {};

void ListaEnlazada::insertarInicio(int valor) {
	Node* newNode = new Node;
	std::cout << newNode << std::endl;
	newNode->data = valor;
	newNode->next = head;
	head = newNode;
}

void ListaEnlazada::imprimir() {
	

	Node* current = head;
	while (current != nullptr) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;

}