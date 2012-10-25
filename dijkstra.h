/** 
  * Assignment 5 for CSE231 Data Structures
  *
  * 2012. 10. 8
	*
	*	FILE:					dijkstra.h
	* DESCRIPTION: 	Class Dijkstra, this class contain 
	*								the declaration and definition of the class 
	*								where is implement Dijkstra ADT.
	*								This class solve the dijstra's algorithm
	*								using a binary heap implementation
	*
	* AUTHOR:				Vicente Adolfo Bolea Sanchez
	* STUDENT NO:		20122901
	* EMAIL:				vicente.bolea@gmail.com
	*/

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "adjacencyList.h"
#include <iostream>
#include <fstream>

using namespace std;

class Dijkstra {
public:
	Dijkstra();
	~Dijkstra();
	
	void ReadGraph(const char* file);
	
	void FindPath(const int v0, const int v1);
	
private:
	int vertices, edges;
	
	//Data structures
	adjacencyList* al;
	MinHeap heap;	

	//Arrays
	float* dist;
	int* previous;
	bool* visited;

	//privated methods
	void dumpFile(std::fstream&, int, int);
	void print_result(const int, const int);

};

#endif
