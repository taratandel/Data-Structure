#pragma once

#include <stdexcept>

template<typename T>
class MaxHeap{
	public:
		MaxHeap(int capacity);
		bool isEmpty();
		const T& top();
		void push(const T& input);
		void pop();
	private:
		T*  mHeap;
		int mHeapSize;
		int mCapacity;
};

template<typename T>
MaxHeap<T>::MaxHeap(int capacity = 10){
	if(capacity < 1) throw std::invalid_argument("Capacity must be >= 1");
	mCapacity = capacity;
	mHeapSize = 0;
	mHeap = new T[capacity + 1];
}

template<typename T>
bool MaxHeap<T>::isEmpty(){
	return (mHeapSize == 0);
}

template<typename T>
const T& MaxHeap<T>::top(){
	return mHeap[1];
}

template<typename T>
void MaxHeap<T>::push(const T& input){
	if(mHeapSize == mCapacity){
		T* newHeap = new T[mCapacity * 2 + 1];
		for(int i = 1; i <= mHeapSize; i++){
			newHeap[i] = mHeap[i];
		}
		mHeap = newHeap;
		mCapacity *= 2;
	}

	int current = ++mHeapSize;
	while(current != 1 && mHeap[current / 2] < input){
		mHeap[current] = mHeap[current / 2];
		current /= 2;
	}
	mHeap[current] = input;
}

template<typename T>
void MaxHeap<T>::pop(){
	if(isEmpty()) throw std::invalid_argument("Heap is empty. Cannot delete.");

	T last = mHeap[mHeapSize];
	mHeapSize--;

	int current = 1;
	int child = 2;
	while(child <= mHeapSize){
		if(child < mHeapSize && mHeap[child] < mHeap[child + 1]) child++;

		if(last >= mHeap[child]) break;

		mHeap[current] = mHeap[child];
		current = child;
		child *= 2;
	}
	mHeap[current] = last;
}
