#pragma once
#ifndef STACK_H_
#define STACK_H_

template <class T>
class stack {
private:
	int size;
	node<T> *bottom;
	node<T> *top;
public:
	stack();
	~stack();
	void push(T);
	T pop();
	bool isEmpty();
	void empty();
};

#endif // !STACK_H_


