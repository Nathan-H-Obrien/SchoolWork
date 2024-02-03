output: main.o graph.o
	g++ -std=c++11 -o output main.o graph.o 

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

List.o: graph.h graph.cpp
	g++ -std=c++11 -c BST.cpp

clean:
	rm output main.o graph.o