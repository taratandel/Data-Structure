// In The Name Of God
// ========================================
// * File Name : GenList.h
// 
// * Creation Date : 05-12-2014
//
// * Last Modified : Tue 09 Dec 2014 07:37:11 PM IRST
//
// * Created By : Tara Tandel (Tara.tandel.94@gmail.com)
// =======================================
#pragma once

#include <stdexcept>
#include <iostream>

template<class T>
class GenList{
public:
	class Node{
	public:
		Node(const T& object);

		Node* getNext() const;
		Node* getBack() const;
		void setNext(Node* next);
		void setBack(Node* back);
		const T& getData() const;
		Node* getLink() const;
		void setData(const T& object);
		void setLink(Node* link);
		int getRef();
		void decRef();
		void incRef();
		void chainRemove();
		
		virtual ~Node();
	private:
		int mRef;
		T mData;
		Node* mLink;
		Node* mNext;
		Node* mBack;
	};


	GenList();
	GenList(const GenList<T> &orig);
	GenList<T>& operator=(const GenList<T> &orig);
	void push_front(const T& object);
	void pop_front();

	Node* find(const T& object) const;
	void list(Node* first) const;
	void list() const;
	void listFrom(Node* first) const;
	void addChild(Node* parent, const T& object);
	void addChild(Node* parent, Node* child);
	void addParent(Node* child, Node* parent);
	void remove(Node* node);

	virtual ~GenList();

private:
	Node* mStart;
	Node* mFinish;

	Node* find(const T& object, Node* first) const;
};

//-----------------List<T>::Node-------------------

template<class T>
GenList<T>::Node::Node(const T& object){
	mRef = 0;
	mData = object;
	mNext = NULL;
	mBack = NULL;
	mLink = NULL;
}

template<class T>
typename GenList<T>::Node *GenList<T>::Node::getNext() const{
	return mNext;
}

template<class T>
typename GenList<T>::Node *GenList<T>::Node::getBack() const{
	return mBack;
}

template<class T>
void GenList<T>::Node::setNext(Node* next){
	mNext = next;
}

template<class T>
void GenList<T>::Node::setBack(Node* back){
	mBack = back;
}

template<class T>
const T& GenList<T>::Node::getData() const{
	return mData;
}

template<class T>
typename GenList<T>::Node* GenList<T>::Node::getLink() const{
	return mLink;
}

template<class T>
void GenList<T>::Node::setData(const T& object){
	mData = object;
}

template<class T>
void GenList<T>::Node::setLink(Node* link){
	link->incRef();
	mLink = link;
}

template<class T>
int GenList<T>::Node::getRef(){
	return mRef;
}

template<class T>
void GenList<T>::Node::decRef(){
	mRef--;
	if(mRef == 0){
		this->chainRemove();
	}
}

template<class T>
void GenList<T>::Node::incRef(){
	mRef++;
}

template<class T>
void GenList<T>::Node::chainRemove(){
	Node* node = this->getNext();
	Node* temp;
	while(node != NULL){
		temp = node;
		node = node->getNext();
		delete temp;
	}
	this->~Node();
}


template<class T>
GenList<T>::Node::~Node(){
	if(mLink != NULL){
		mLink->decRef();
	}
}


//=======================================================
//---------------------GenList<T>------------------------

template<class T>
GenList<T>::GenList(){
	mStart = NULL;
}

template<class T>
GenList<T>::GenList(const GenList<T>& orig){
	// TODO Implement list copying
}

template<class T>
GenList<T>& GenList<T>::operator=(const GenList<T>& orig){
	// TODO Implement list assignment
}

template<class T>
void GenList<T>::push_front(const T& object){
	if(mStart == NULL){
		mStart = new Node(object);
		mFinish = mStart;
		return;
	}

	Node* new_node = new Node(object);
	new_node->setNext(mStart);
	mStart->setBack(new_node);
	mStart = new_node;
}

template<class T>
void GenList<T>::pop_front(){
	if(mStart == NULL){
		return;
	}

	Node* inner_start = mStart;
	mStart = mStart->getNext();
	mStart->setBack(NULL);
	
	delete inner_start;
}


template<class T>
typename GenList<T>::Node* GenList<T>::find(const T& object) const{
	return find(object, mStart);	
}

template<class T>
typename GenList<T>::Node* GenList<T>::find(const T& object, Node* first) const{
	Node* start = first;
	while(start != NULL){
		if(start->getData() == object)
			return start;
		if(start->getLink() == NULL || find(object, start->getLink()) == NULL)
			start = start->getNext();
		else 
			return find(object, start->getLink());
	}
	return NULL;
}

template<class T>
void GenList<T>::list() const{
	list(mStart);
}

template<class T>
void GenList<T>::list(Node* first) const{
	Node* start = first;
	while(start != NULL){
		std::cout << start->getData() << " " << start->getRef() << std::endl;
		if(start->getLink() != NULL){
			std::cout << ">>>>>" << std::endl;
			list(start->getLink());
			std::cout << "<<<<<" << std::endl;
		}
		start = start->getNext();
	}
}

template<class T>
void GenList<T>::listFrom(Node* first) const{
	if(first->getLink())
		list(first->getLink());
}

template<class T>
void GenList<T>::addChild(Node* parent, const T& object){
	if(!parent->getLink()){
		parent->setLink(new Node(object));
	}else{
		Node* start = parent->getLink();	
		while(start->getNext() != NULL){
			start = start->getNext();
		}
		start->setNext(new Node(object));
		start->getNext()->setBack(start);
	}

}

template<class T>
void GenList<T>::addChild(Node* parent, Node* child){
	if(!parent->getLink()){
		parent->setLink(child);
	}else{
		Node* start = parent->getLink();	
		while(start->getNext() != NULL){
			start = start->getNext();
		}
		start->setNext(child);
		start->getNext()->setBack(start);
	}
}

template<class T>
void GenList<T>::addParent(Node* child, Node* parent){
	parent->setLink(child);
}

template<class T>
void GenList<T>::remove(Node* node){
	if(mStart == node)
		mStart = node->getNext();
	if(mFinish == node)
		mFinish = node->getBack();
	if(node && node->getNext()){
		node->getNext()->setBack(node->getBack());
	}
	if(node && node->getBack()){
		node->getBack()->setNext(node->getNext());
	}
	delete node;
}

template<class T>
GenList<T>::~GenList(){
	while (mStart != NULL) {
		Node* inner_start = mStart;
		mStart = mStart->getNext();
		delete inner_start;
	}
}
