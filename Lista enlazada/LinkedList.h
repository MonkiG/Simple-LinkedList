#pragma once

struct Nodo {
	float data;
	Nodo* next;
};

struct SearchResult{
	bool finded;
	float value;
	int position;
};

class LinkedList
{
	private:
		Nodo* head;
		int iterateLinkedList();

	public:
		LinkedList();
		void insertStart(float);
		void insertEnd(float);
		void insertByPosition(int, float);
		void deleteStart();
		void deleteEnd();
		void deleteByValue(float);
		SearchResult searchByValue(float);
		SearchResult searchByPosition(int);
		void showLinkedList();
		int getLength();
		bool isEmpty();
		static Nodo* createNodo(float);
		
};

