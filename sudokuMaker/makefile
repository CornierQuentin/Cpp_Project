main : grid_validation.o main.o
	g++ main.o grid_validation.o -o main

grid_validation.o : grid_validation/grid_validation.cpp
	g++ -c grid_validation/grid_validation.cpp

main.o : main.cpp
	g++ -c main.cpp