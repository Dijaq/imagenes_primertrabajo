all: 
	g++ -ggdb -o milibreria.so ./main.cpp -std=c++11 -fPIC -shared `pkg-config --cflags --libs opencv`
exec:
	g++ -ggdb proyecto.cpp -o main -std=c++11 -fopenmp `pkg-config --cflags --libs opencv`