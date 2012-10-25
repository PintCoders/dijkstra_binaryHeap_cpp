#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>

/** 
  * Assignment 5 for CSE231 Data Structures
  *
  * 2012. 10. 8
	*
	*	FILE:					minheap.h
	* DESCRIPTION: 	Class MinHeap, this class contain 
	*								the declaration and definition of the class 
	*								where is implement binary min-heap ADT.
	*								Also this file contains the class 
	*								heapElem.
	*
	* AUTHOR:				Vicente Adolfo Bolea Sanchez
	* STUDENT NO:		20122901
	* EMAIL:				vicente.bolea@gmail.com
	*/

// Heap element
class heapElem {
public:
	int idx; 				// vertex index
	float dist; 		// shortest path distance

	heapElem(): idx(0), dist(0.0) {}
	heapElem(int i, float d): idx(i), dist(d) {}
	heapElem(const heapElem& h) {
		idx = h.idx;
		dist = h.dist;
	}
};


// MinHeap class
class MinHeap {
public:
	MinHeap();
	~MinHeap();
	
	void Push(const heapElem& e);
	
	const heapElem & Top();
	
	void Pop();
	
	void Modify(const heapElem& e);
	
private:
	heapElem* array;
	int map[1000];	// The size is fixed since is the simpler approach
	int length, capacity;

	//Heap functions
	void decreaseKey (int);
	void increaseKey (int);

	//Array functions
	void resize (int);
	inline void swap (int, int);

	//Heap properties
	inline int parent (int);
	inline int leftChild (int);
	inline int rightChild (int);
};
#endif
