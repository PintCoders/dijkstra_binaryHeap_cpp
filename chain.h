/** 
  * Assignment 5 for CSE231 Data Structures
  *
  * 2012. 10. 8
	*
	*	FILE: 				chain.h
	* DESCRIPTION: 	Template class chain, this class contain 
	*								the declaration and definition of the class 
	*								where is implement chain ADT.
	*
	* AUTHOR:				Vicente Adolfo Bolea Sanchez
	* STUDENT NO:		20122901
	* EMAIL:				vicente.bolea@gmail.com
	*/

#ifndef _CHAIN_
#define _CHAIN_

template <class T>
class chain {
	private:
		struct node { /* This struct represent the node of the chain */
			T elem;
			node* link;

			node(const T& e, node* l = NULL): elem(e), link(l) {}
		};
		node *first, *last;			

	public:
		/* Class iterator needed for the dijkstra algorithm */
		class iterator { 
			private:
				node* current;

			public:
				iterator(node* n): current(n) {}

				void operator++ (int) {
					current = current->link;
				}	

				bool operator== (const iterator& it) const {
					return (current == it.current) ? true: false;
				}

				bool operator!= (const iterator& it) const {
					return (current != it.current) ? true: false;
				}

				const T& getValue() const {
					return current->elem;
				}
		};

		chain() { 
			last = first = NULL;
		}

		/* Make sure that we delete all the nodes */
		~chain() {
			for (node* tmp = first; tmp != NULL; ) {
				node* aux = tmp;
				tmp = tmp->link;
				delete aux;
			}
		}

		iterator begin() const { iterator it(first); return it; }
		iterator end() const { iterator it(NULL); return it; }

		/* Push back the given element in the chain */
		void push(const T& elem) {
			if (first == NULL && last == NULL) 
				first = last = new node(elem);

			else if (first == last) {
				first->link = new node(elem);
				last = first->link;

			} else {
				last->link = new node(elem);
				last = last->link;
			}
		}		
};	

#endif
