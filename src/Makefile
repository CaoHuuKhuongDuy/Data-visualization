# This is makefile for SFML C++

path = D:\Code\DataVisualizationApplication\sfml
INCLUDE = "$(path)\include"
LIBRARY = "$(path)\lib"
SFML_INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system
#=======================================================================================#

all: compile link run
compile:
	g++ -c main.cpp render.cpp process.cpp singlyLL.cpp textBox.cpp staticFile.cpp arrow.cpp renderLinkedList.cpp highlight.cpp -I $(INCLUDE)
link:
	g++ main.o render.o process.o singlyLL.o textBox.o staticFile.o arrow.o renderLinkedList.o highlight.o -o main.exe -L $(LIBRARY) $(SFMLFLAGS) $(SFML_INCLUDE)
run:
	./main.exe