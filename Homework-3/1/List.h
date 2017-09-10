/* 
 * File:   List.h
 * Author: Tara Tandel <Tara.tandel at Tara.home>
 *
 * Created on October 22, 2014, 11:42 PM
 */

#ifndef LIST_H
#define	LIST_H

#include <stdexcept>
#include <iostream>

template<class T>
class List {
private:

	class Node {
	public:
		Node(const T& object);

		Node* getNext();
		Node* getBack();
		void setNext(Node* next);
		void setBack(Node* back);
		T& getObject();

		//virtual ~Node();
	private:
		T object;
		Node* next;
		Node* back;
	};

	int size;
	Node* start;
	Node* finish;

public:
	List();
	List(const List<T> &orig);
	List<T>& operator=(const List<T> &orig);

	void push_back(const T& object);
	void push_front(const T& object);
	void pop_front();
	void pop_back();
	T& front();
	T& back();
	typename List<T>::Iterator begin();
	typename List<T>::Iterator end();
	T& at(int index) const;
	T& operator[](int index) const;
	int getSize() const;
	template<class V> friend std::ostream& operator<<(std::ostream &os, const List<V>& list);

	virtual ~List();

	class Iterator {
	public:
		Iterator(Node* startNode, Node* start, Node* finish);
		Iterator(const Iterator &orig);

		T& operator*()const;
		Iterator& operator++();
		Iterator operator++(int);
		Iterator& operator--();
		Iterator operator--(int);
		bool operator==(const Iterator &origin);
		bool operator!=(const Iterator &origin);

		//virtual ~Iterator();
	private:
		Node* start;
		Node* current;
		Node* finish;
	};
};


#endif	/* LIST_H */

template<class T>
List<T>::Node::Node(const T& object)
{
	this->object = T(object);
	this->next = NULL;
	this->back = NULL;
}

template<class T>
typename List<T>::Node *List<T>::Node::getNext()
{
	return next;
}

template<class T>
typename List<T>::Node *List<T>::Node::getBack()
{
	return back;
}

template<class T>
void List<T>::Node::setNext(Node* next)
{
	this->next = next;
}

template<class T>
void List<T>::Node::setBack(Node* back)
{
	this->back = back;
}

template<class T>
T& List<T>::Node::getObject()
{
	return object;
}

template<class T>
List<T>::Iterator::Iterator(typename List<T>::Node* startNode, typename List<T>::Node* start, typename List<T>::Node* finish)
{
	this->start = start;
	current = startNode;
	this->finish = finish;
}

template<class T>
List<T>::Iterator::Iterator(const Iterator& orig)
{
	this->finish = orig.finish;
	this->current = orig.current;
	this->start = orig.start;
}

template<class T>
T& List<T>::Iterator::operator *() const
{
	return current->getObject();
}

template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
	if (current->getNext() != NULL) {
		current = current->getNext();
	} else {
		current = start;
	}
	return *this;
}

template<class T>
typename List<T>::Iterator List<T>::Iterator::operator ++(int)
{
	Iterator old = *this;
	if (current->getNext() != NULL) {
		current = current->getNext();
	} else {
		current = start;
	}
	return old;
}

template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator--()
{
	if (current->getBack() != NULL) {
		current = current->getBack();
	} else {
		current = finish;
	}
	return *this;
}

template<class T>
typename List<T>::Iterator List<T>::Iterator::operator --(int)
{
	Iterator old = *this;
	if (current->getBack() != NULL) {
		current = current->getBack();
	} else {
		current = finish;
	}
	return old;
}

template<class T>
bool List<T>::Iterator::operator==(const Iterator &origin)
{
	return current == origin.current;
}

template<class T>
bool List<T>::Iterator::operator!=(const Iterator &origin)
{
	return current != origin.current;
}

template<class T>
List<T>::List()
{
	start = NULL;
	finish = NULL;
	size = 0;
}

template<class T>
List<T>::List(const List<T>& orig)
{
	this->start = NULL;
	this->finish = NULL;
	this->size = 0;

	for (int i = 0; i < orig.size; i++) {
		this->push_back(orig[i]);
	}
}

template<class T>
List<T>& List<T>::operator=(const List<T>& orig)
{
	this->start = NULL;
	this->finish = NULL;
	this->size = 0;

	for (int i = 0; i < orig.size; i++) {
		this->push_back(orig[i]);
	}

	return *this;
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
	if (finish == NULL) {
		throw(new std::invalid_argument("List is empty"));
	}
	return finish->getObject();
}

template<class T>
typename List<T>::Iterator List<T>::begin()
{
	return Iterator(start, start, finish);
}

template<class T>
typename List<T>::Iterator List<T>::end()
{
	return Iterator(finish, start, finish);
}

template<class T>
void List<T>::push_front(const T& object)
{
	size++;

	if (start == NULL) {
		start = new Node(object);
		finish = start;
		return;
	}

	Node* new_node = new Node(object);
	start->setBack(new_node);
	new_node->setNext(start);
	start = new_node;
}

template<class T>
void List<T>::push_back(const T& object)
{
	size++;

	if (start == NULL) {
		start = new Node(object);
		finish = start;
		return;
	}

	Node* new_node = new Node(object);
	finish->setNext(new_node);
	new_node->setBack(finish);
	finish = new_node;
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
	start->setBack(NULL);
	delete (inner_start);

	if (start == NULL)
		finish = NULL;
}

template<class T>
void List<T>::pop_back()
{
	if (finish == NULL) {
		return;
	}

	size--;

	Node* inner_back = finish;
	finish = finish->getBack();
	finish->setNext(NULL);
	delete (inner_back);

	if (finish == NULL)
		start = NULL;

}

template<class T>
T& List<T>::at(int index) const
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
T& List<T>::operator [](int index) const
{
	return at(index);
}

template<class T>
int List<T>::getSize() const
{
	return size;
}

template<class V>
std::ostream& operator<<(std::ostream &os, const List<V>& list)
{
	typename List<V>::Node* inner_start = list.start;
	while (inner_start != NULL) {
		os << "| ";
		os << inner_start->getObject();
		os << " |";
		inner_start = inner_start->getNext();
	}
	return os;
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