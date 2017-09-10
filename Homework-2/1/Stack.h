/* 
 * File:   Stack.h
 * Author: Tara Tandel <Tara.tandel at Tara.home>
 *
 * Created on October 22, 2014, 5:41 PM
 */

#ifndef STACK_H
#define	STACK_H

#include <stdexcept>

template<class T>
class Stack {
public:
	Stack();
	Stack(const Stack& orig);

	void push(T object);
	T pop();
	T top();
	int size();
	bool empty();

	virtual ~Stack();
private:
	static const int MAX = 1000 * 100;
	T backend[MAX];
	int pointer;
};

template<class T>
Stack<T>::Stack()
{
	pointer = 0;
}

template<class T>
Stack<T>::Stack(const Stack& orig)
{
	for (int i = 0; i < pointer; i++) {
		backend = orig.backend[i];
	}
}

template<class T>
T Stack<T>::pop()
{
	if (pointer > 0) {
		pointer--;
		return backend[pointer];
	} else {
		throw(new std::invalid_argument("Stack is empty"));
	}
}

template<class T>
void Stack<T>::push(T object)
{
	if (pointer < MAX) {
		backend[pointer] = object;
		pointer++;
	} else {
		throw(new std::invalid_argument("Stack is full"));
	}
}

template<class T>
T Stack<T>::top()
{
	return backend[pointer - 1];
}

template<class T>
int Stack<T>::size()
{
	return pointer;
}

template<class T>
bool Stack<T>::empty()
{
	return(pointer == 0);
}

template<class T>
Stack<T>::~Stack()
{
}

#endif	/* STACK_H */

