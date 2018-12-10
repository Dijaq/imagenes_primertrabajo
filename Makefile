all: 
	g++ -ggdb proyecto.cpp -o main -std=c++11 `pkg-config --cflags --libs opencv`