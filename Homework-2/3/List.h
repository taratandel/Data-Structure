/* 
 * File:   List.h
 * Author: Tara Tandel <Tara.tandel at Tara.home>
 *
 * Created on October 22, 2014, 11:42 PM
 */

#ifndef LIST_H
#define	LIST_H

#include <stdexcept>

template<class T>
class List {
private:

	class Node {
	public:
		Node(T object);
		Node(const Node &orig);

		Node* getNext();
		void setNext(Node* next);
		T& getObject();
	private:
		T object;
		Node* next;
	};

	int size;
	Node* start;

public:
	List();
	List(const List &orig);

	void push_back(T object);
	void push_front(T object);
	void pop_front();
	void pop_back();
	T& front();
	T& back();
	T& at(int index);
	T& operator[](int index);
	int getSize();


	virtual ~List();
};


#endif	/* LIST_H */

template<class T>
List<T>::Node::Node(T object)
{
	this->object = object;
	this->next = NULL;
}

template<class T>
List<T>::Node::Node(const Node& orig)
{
	this->next = orig.next;
	this->object = orig.next;
}

template<class T>
typename List<T>::Node *List<T>::Node::getNext()
{
	return next;
}

template<class T>
void List<T>::Node::setNext(Node* next)
{
	this->next = next;
}

template<class T>
T& List<T>::Node::getObject()
{
	return object;
}

template<class T>
List<T>::List()
{
	start = NULL;
	size = 0;
}

template<class T>
List<T>::List(const List& orig)
{
	for (int i = 0; i < orig.size; i++) {
		push_back(orig[i]);
	}
}

template<class T>
T& List<T>::front()
{
	if (start == NULL) {
		throw(new std::invalid_argument("List is empty"));
	}
	return start->getObject();
}

template<class T>
T& List<T>::back()
{
	Node* inner_start = start;

	if (inner_start == NULL) {
		throw(new std::invalid_argument("List is empty"));
	}

	while (inner_start->getNext() != NULL) {
		inner_start = inner_start->getNext();
	}

	return inner_start->getObject();
}

template<class T>
void List<T>::push_front(T object)
{
	size++;
	Node* new_node = new Node(object);
	new_node->setNext(start);
	start = new_node;
}

template<class T>
void List<T>::push_back(T object)
{
	size++;
	Node* inner_start = start;

	if (inner_start == NULL) {
		start = new Node(object);
		return;
	}

	while (inner_start->getNext() != NULL) {
		inner_start = inner_start->getNext();
	}

	Node* new_node = new Node(object);
	inner_start->setNext(new_node);
}

template<class T>
void List<T>::pop_front()
{
	if (start == NULL) {
		return;
	}

	size--;

	Node* inner_start = start;
	start = start->getNext();
	delete (inner_start);
}

template<class T>
void List<T>::pop_back()
{
	Node* inner_start = start;

}

template<class T>
T& List<T>::at(int index)
{
	int i = 0;
	Node* inner_start = start;

	if (index >= size) {
		throw(new std::invalid_argument("No such index"));
	}

	while (i < index) {
		i++;
		inner_start = inner_start->getNext();
	}

	return inner_start->getObject();
}

template<class T>
T& List<T>::operator [](int index)
{
	return at(index);
}

template<class T>
int List<T>::getSize()
{
	return size;
}

template<class T>
List<T>::~List()
{
	while (start != NULL) {
		Node* inner_start = start;
		start = start->getNext();
		delete inner_start;
	}
}