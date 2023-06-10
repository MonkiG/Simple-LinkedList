#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {};

void LinkedList::insertStart(float data) {
	
    Nodo* newNodo = createNodo(data);
	newNodo->next = head;
	head = newNodo;
};

void LinkedList::insertEnd(float data) {
    try
    {
        Nodo* actual = head;
        Nodo* newNodo = createNodo(data);

        if (!data) {
            throw std::runtime_error("Valor no definido");
        }
        if (actual == nullptr) {
            head = newNodo;
        }
        else {
            while (actual != nullptr) {
                if (actual->next == nullptr) {
                    actual->next = newNodo;
                    return;
                }
                actual = actual->next;
            }
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Error:" << e.what() << std::endl;
    }
};

void LinkedList::insertByPosition(int position, float data) {
	
    int length = getLength();

    if (position > length) {
        insertEnd(data);
        return;
    }

    if (position <= 0) {
        insertStart(data);
        return;
    }

    Nodo* actual = head;
    Nodo* newNodo = createNodo(data);

    for (int i = 0; i < position - 1; i++) {
        actual = actual->next;
    }
    newNodo->next = actual->next;
    actual->next = newNodo;
};

void LinkedList::deleteStart() {

    if (isEmpty()) {
        return;
    }else {
        Nodo* nodeToDelete = head;
        Nodo* firstNode = nodeToDelete->next;
        head = firstNode;
        delete nodeToDelete;
    }

};
void LinkedList::deleteEnd() {
    Nodo* actual = head;
    Nodo* nodoToDelete = nullptr;

    if (isEmpty()) {
        return;
    }

    while (actual != nullptr) {
       if (actual->next->next == nullptr) {
              
           nodoToDelete = actual->next;
           break;
       }
        actual = actual->next;
    }

    if (nodoToDelete != nullptr) {
        actual->next = nullptr;
        delete nodoToDelete;
    }
    
};
void LinkedList::deleteByValue(float value) {
    
    try
    {
        Nodo* actual = head;
        Nodo* nodoToDelete = nullptr;

        if (isEmpty()) {
            return;
        }

        if (actual->data == value) {
            head = actual->next;
            delete actual;
            return;
        }

        while (actual->next != nullptr) {
            if (actual->next->data == value) {

                nodoToDelete = actual->next;
                actual->next = nodoToDelete->next;
                delete nodoToDelete;
                break;
            }
            actual = actual->next;
        }
        throw std::runtime_error("Valor no encontrado en la lista.");
    }
    catch (const std::exception& e)
    {
        std::cout << "Excepción: " << e.what() << std::endl;
    }
};

SearchResult LinkedList::searchByValue(float value) {
    SearchResult result = { NULL, NULL, NULL };
    Nodo* actual = head;
    int position = 0;

    if (isEmpty()) {
        return result;
    }

    while (actual != nullptr)
    {
        if (actual->data == value) {
            result = { true, actual->data, position };
            return result;
        }
        position++;
        actual = actual->next;
    }
    result = { false, NULL, NULL };
    return result;
};

SearchResult LinkedList::searchByPosition(int userPosition) {
    SearchResult result = { NULL, NULL, NULL };
    Nodo* actual = head;
    int position = 0;


    if (!isEmpty()) {
        while (actual != nullptr)
        {
            if (position == userPosition) {
                result = { true, actual->data, position };
                return result;
            }
            position++;
            actual = actual->next;
        }
    }
    
    return result;
};

void LinkedList::showLinkedList() {
    if (isEmpty()) {
        std::cout << "Lista enlazada vacia" << std::endl;
    }else {
        std::cout << "Datos de la lista enlazada: " << std::endl;
        std::cout << "[ ";
        iterateLinkedList();
        std::cout << "]";
    }
}

int LinkedList::getLength() {
   
    int tamaño = iterateLinkedList();
    return tamaño;
}

int LinkedList::iterateLinkedList() {
    Nodo* actual = head;
    int tamaño = 0;
    while (actual != nullptr) {
        std::cout << "[" << actual->data << "]" << " ";
        tamaño++;
        actual = actual->next;
    }
    return tamaño;
}

Nodo* LinkedList::createNodo(float data) {
    Nodo* newNodo = new Nodo;
    newNodo->data = data;
    newNodo->next = nullptr;
    return newNodo;
}

bool LinkedList::isEmpty() {
    return head == nullptr;
}