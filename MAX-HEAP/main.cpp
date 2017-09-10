#include "MaxHeap.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
	MaxHeap<int> heap;
	
	for(int i = 0; i < 20; i++){
		heap.push(i);
	}

	while(!heap.isEmpty()){
		cout << heap.top() << endl;
		heap.pop();
	}
}
