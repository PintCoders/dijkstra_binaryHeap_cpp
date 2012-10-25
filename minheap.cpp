#include "minheap.h"

MinHeap::MinHeap() {
	array = new heapElem[2];
	capacity = 1;
	length = 0;
}

MinHeap::~MinHeap() {
	delete[] array;
}

/*
		If the capacity is not enought, double and
		push the given element in the last position
		after that increasyKey from this last position
		it will positionate the given element in the appropiate
		position
*/
void MinHeap::Push (const heapElem& e)
{
	//In case there is not space for the next element to be allocated
	if ( (length+1) >= capacity)
		if (length == 1)
			resize(4);
		else
			resize(capacity * 2);
	
	array[++length] = e;	
	map[e.idx] = length;
	increaseKey (length);
}

/* returns the root of the bheap */
const heapElem& MinHeap::Top () {
	return array[1];
}

/* deletes the root of the bheap */
void MinHeap::Pop () 
{
	array[1] = array[length];
	length--;
	decreaseKey (1);
}

/*
		For the given element update, and than depends if
		the new element is higher(key) or smaller increase or
		decrease the key
*/
void MinHeap::Modify (const heapElem& e) 
{
	if (e.dist > array[ map[e.idx]].dist) {
		array[ map[e.idx]] = e;
		decreaseKey( map[e.idx]);

	} else {
		array[ map[e.idx]] = e;
		increaseKey( map[e.idx]);
	}
}

/*
		For a given root positionate in the appropiate
		position of the binary heap going to leaf nodes
*/
void MinHeap::decreaseKey (int i)
{
	int largest = i;
	int left = leftChild(i), right = rightChild(i);

	if (left <= length && array[left].dist < array[largest].dist)
		largest = left;	
	if (right <= length && array[right].dist < array[largest].dist)
		largest = right;	

	if (largest != i) {
		swap (i, largest); 	
		decreaseKey (largest);
	}
}

/*
		For a given element positionate in the appropiate
		position of the binary heap going to the top
*/
void MinHeap::increaseKey (int i) 
{
	if (i != 1 && array[i].dist < array[parent(i)].dist) {
		swap (i, parent(i));
		increaseKey (parent(i));
	}
}

/*
		Just create another array with the given size,
		copy the original array to the new one,
		and delete the original array.
*/
void MinHeap::resize (int _length) 
{
	heapElem* tmp = new heapElem[_length];
	for (int i = 1; i <= length; i++) {
		tmp[i] = array[i];
	}

	delete[] array;
	array = tmp;
	capacity = _length;
}

/*
		The important point of this function is that
		I also swap the value of the "map" array, As result 
		"map" array is always update since 
		the only operation which modify the heap is swap
*/
inline void MinHeap::swap(int i, int j) {
	int map_aux = map [array[j].idx];
	map[ array[j].idx] = map[ array[i].idx];
	map[ array[i].idx] = map_aux;

	heapElem& aux = array[j];
	array[j] = array[i];
	array[i] = aux;
}

inline int MinHeap::parent (int i) {
	return ((int) i/2);			/*A weird implementation of floor */
}

inline int MinHeap::leftChild (int i) {
	return 2*i;
}

inline int MinHeap::rightChild (int i) {
	return 2*i + 1;
}
