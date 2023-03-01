# This is makefile for SFML C++

path = D:\Code\DataVisualizationApplication\sfml
INCLUDE = "$(path)\include"
LIBRARY = "$(path)\lib"
CXXFLAGS =
SFMLFLAGS =
SOURCE = main
SFML_INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system
#=======================================================================================#

all: compile link run
compile:
	g++ -c $(SOURCE).cpp -I $(INCLUDE)
	g++ -c "render.cpp" -o render.o -I $(INCLUDE)
link:
	g++ $(CXXFLAGS) $(SOURCE).o render.o -o main.exe -L $(LIBRARY) $(SFMLFLAGS) $(SFML_INCLUDE)
run:
	./$(SOURCE).exe