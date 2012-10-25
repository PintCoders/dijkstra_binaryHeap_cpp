#include "dijkstra.h"

Dijkstra::Dijkstra() { }

/* This destructor will liberate all the dynamic memory */
Dijkstra::~Dijkstra() {
	delete[] dist;
	delete[] visited;
	delete[] previous;
	delete al;
}

/*
		This method will open the given file
		and create the dynamic elements of the class
		after that will call "dumpFile" function to
		recursively fill the adjacency list.
*/
void Dijkstra::ReadGraph (const char* file)
{
	fstream my_file;

	/* 	since last time I got penalty for using c++ standard
			exceptions I will comment exceptions */

	//my_file.exceptions (fstream::failbit | fstream::badbit);
	//try {
		my_file.open (file, fstream::in);

		//Asignate the number of vertices and edges
		my_file >> vertices;
		my_file >> edges;

		//create the dynamic elements
		dist = new float [vertices];
		visited = new bool [vertices];
		previous = new int [vertices];
		al = new adjacencyList (vertices);

		//Create the binary heap
		dumpFile (my_file, 0, vertices);

	//}	catch (fstream::failure& e) {
	//	cout<< "Exception: reading file : "<< e.what() << endl;

	//} catch (bad_alloc& e) {
	//	cout<< "Exception: allocating memory: " << e.what() << endl;
	//}

	my_file.close ();
}

/*
	 This method is the Dijsktra's algorithm adapted to be 
	 used with a binary heap. 
 */
void Dijkstra::FindPath (const int v0, const int v1) 
{	
	float max_float = std::numeric_limits<float>::max();	

	//Fill the heap with all vertices dist "inf"
	for (int i = 0; i < vertices; i++) {
		heap.Push(heapElem(i, max_float));
		visited[i] = false;
		dist[i] = max_float;
	}

	//Modify v0 to has dist = 0
	heap.Modify(heapElem(v0, 0));

	while (1) {
		heapElem v = heap.Top();	
		heap.Pop();
		visited[v.idx] = true;
		if (v.idx == v1) break;

		//for all adjancent vertex of v:
		for (Iterator it = al->beginAt(v.idx); it != al->endAt(v.idx); it++) {
			heapElem w = it.getValue();
			float alt = v.dist + w.dist;

			/* If is not visited and the way to reach w going throught
				 v is shorter or dist[w] is never been updated, update */
			if (visited[w.idx] == false && alt < dist[w.idx]) {
				heap.Modify(heapElem(w.idx, alt));
				previous[w.idx] = v.idx;
				dist[w.idx] = alt;
			}
		}
	}			
	print_result(v0, v1);
}

/*
	 This function read recursively the file and
	 create the nodes of the binary heap
 */
void Dijkstra::dumpFile(std::fstream& f, int i, int _max)
{
	if (i <= _max) {
		int index, pointing, weight;

		f >> index;
		f >> pointing;
		f >> weight;

		al->insert(index, heapElem(pointing, weight));

		dumpFile(f, ++i, _max);
	}
}

/* 
	 This method creates an array with the 
	 shortes route from v0 to v1 and print out on 
	 the standart output */
void Dijkstra::print_result(const int v0, const int v1) 
{
	int aux[100], ii=0;
	for (int i = v1; i != v0; i = previous[i]) {
		aux[ii] = i;
		ii++;
	}
	aux[ii] = v0;
	for (int i = ii; i > 0; i--)
		cout << aux[i] <<",";
	cout << aux[0] << endl;
}
