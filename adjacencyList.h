/** 
  * Assignment 5 for CSE231 Data Structures
  *
  * 2012. 10. 8
	*
	*	FILE:					adjacencyList.h
	* DESCRIPTION: 	This file contains the declaration and 
	*								definition of the ADT adjacency list.
	*								This adjacency list has a vector of chain
	*								which is initializate by the constructor.	
	*
	* AUTHOR:				Vicente Adolfo Bolea Sanchez
	* STUDENT NO:		20122901
	* EMAIL:				vicente.bolea@gmail.com
	*/

#ifndef _ADJACENCY_LIST_
#define _ADJACENCY_LIST_

#include "minheap.h" 	/* Only needed for elemHeap class */
#include "chain.h"		/* Needed since a A.L. is a vector of chain */

//Make names simplers :D
typedef chain<heapElem>::iterator Iterator;

class adjacencyList {
	private:
		chain<heapElem>* vector;

	public:

		adjacencyList	(int _vertices) {
			vector = new chain<heapElem>[_vertices];
		} 

		~adjacencyList	() {
			delete[] vector;
		} 

		/* Build the given chain */
		void insert	(int index, const heapElem& item) {
			vector[index].push(item);

			//For the another vertex
			vector[item.idx].push(heapElem(index, item.dist));
		}
		
		/* return the begin for a given vertice */
		inline Iterator beginAt(int index) const {
			return Iterator (vector[index].begin());
		}

		/* return the end for a given vertice */
		inline Iterator endAt(int index) const {
			return Iterator (vector[index].end());
		}
};

#endif
