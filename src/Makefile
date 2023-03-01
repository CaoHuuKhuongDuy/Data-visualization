# This is makefile for SFML C++

path = D:\Code\DataVisualizationApplication\sfml
INCLUDE = "$(path)\include"
LIBRARY = "$(path)\lib"
SFML_INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system
#=======================================================================================#

all: compile link run
compile:
	g++ -c main.cpp -I $(INCLUDE)
	g++ -c render.cpp -o render.o -I $(INCLUDE)
	g++ -c process.cpp -o process.o -I $(INCLUDE)
link:
	g++ main.o render.o process.o -o main.exe -L $(LIBRARY) $(SFMLFLAGS) $(SFML_INCLUDE)
run:
	./main.exe