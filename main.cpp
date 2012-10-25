#include "dijkstra.h"
#include <iostream>
using namespace std;
int main()
{
	Dijkstra ds;
	
	ds.ReadGraph("input.txt");
	
	cout << "Shortest path between 0 and 6 : ";
	
	ds.FindPath(0,6);
	
	return 0;
}
