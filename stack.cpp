#include "node.h"
#include "stack.h"
#include <iostream>

using namespace std;

template <class T>
stack<T>::stack() {
	size = 0;
	top = nullptr;
	bottom = nullptr;
}

template <class T>
stack<T>::~stack() {

}

template <class T>
void stack<T>::push(T data) {
	//Create a new node
	node<T> *newNode = new node<T>;
	node<T> *tmp;

	//set the node's data to data
	newNode->data = data;

	//adjust next and prev pointers in the node
	if (size == 0) { 
		//Only need to adjust top pointer if this is the first node being entered
		bottom = newNode;
		top = newNode;
	}
	else {
		tmp = top;
		top->prev = newNode;
		top = newNode;
		newNode->next = tmp;
	}

	//bottom adjustments will always be the same
	newNode->prev = nullptr;
	top = newNode;

	//increment size
	size++;
}

template <class T>
T stack<T>::pop() {
	T item;
	
	//delete top node
	if (top != nullptr) {
		//save top item of stack
		item = top->data;

		//Create tmp pointers to keep track
		node<T> *newTop = top->next;
		node<T> *tmp = top;
		delete tmp;
		top = newTop;

		//reduce size by 1
		size--;
	}
	else
		item = 0;

	//return top node
	return item;
}

template <class T>
bool stack<T>::isEmpty() {
	return size == 0 ? true : false;
}

template <class T>
void stack<T>::empty() {
	node<T> *newBottom;

	if (size == 0)
		cout << "There is no data in the stack.\n";
	else {
		while (size != 0) {
			node<T> *tmp = bottom;
			newBottom = bottom->prev;
			delete tmp;
			bottom = newBottom;
			size--;
		}
	}
}