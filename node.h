#pragma once
#ifndef NODE_H_
#define NODE_H_

template <class T>
struct node {
	T data;
	node<T> *next = nullptr;
	node<T> *prev = nullptr;
};

#endif // !NODE_H_


