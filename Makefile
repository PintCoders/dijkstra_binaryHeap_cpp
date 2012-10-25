#To compile this assigment use this makefile
CXX= g++
FLAGS= -Wall -g 

all: main.o dijkstra.o minheap.o
	$(CXX) $^ -o assign_5 $(FLAGS)

main.o: main.cpp
	$(CXX) -c $< $(FLAGS)

dijkstra.o: dijkstra.cpp
	$(CXX) -c $< $(FLAGS)

minheap.o: minheap.cpp
	$(CXX) -c $< $(FLAGS)
