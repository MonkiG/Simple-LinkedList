#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList myLinkedList;

	
	 myLinkedList.insertEnd(80);
	 /*myLinkedList.insertStart(89.5);
	 myLinkedList.insertEnd(90);
	 myLinkedList.insertEnd(1.5);
	 myLinkedList.deleteByValue(90);*/
	 myLinkedList.insertByPosition(2, 30);
	 SearchResult resultado = myLinkedList.searchByValue(3);
	 SearchResult resultado2 = myLinkedList.searchByValue(80);

	 if (resultado.finded) {
		 std::cout << "Primer resultado: " << resultado.finded << " " << resultado.value << " " << resultado.position << std::endl;
	 }
	 if (resultado2.finded) {
		 std::cout << "Segundo resultado: " << resultado2.finded << " " << resultado2.value << " " << resultado2.position << std::endl;
	 }
	 std::cout << myLinkedList.searchByPosition(1).finded << std::endl;;
	 /*myLinkedList.insertStart(79.5);
	 
	 myLinkedList.insertStart(69.5);
	 myLinkedList.insertStart(59.5);
	 myLinkedList.insertStart(49.5);
	 
	 
	 myLinkedList.showLinkedList(); */
	 /*myLinkedList.deleteEnd();*/
	 /*myLinkedList.deleteStart();*/
	 myLinkedList.showLinkedList();
	/*
	 myLinkedList.deleteStart();
	 
	 myLinkedList.deleteByValue(37.8);
	 myLinkedList.searchByValue(99.5);
	 myLinkedList.searchByPosition(1);
	 */
	  
	return 0;
}


