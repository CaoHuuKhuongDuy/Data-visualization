# This is makefile for SFML C++

path = ..\sfml
INCLUDE = "$(path)\include"
LIBRARY = "$(path)\lib"
SFML_INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system -lcomdlg32
#=======================================================================================#

all: compile link run
compile:
	g++ -c main.cpp render.cpp process.cpp linkedList.cpp textBox.cpp staticFile.cpp arrow.cpp renderLinkedList.cpp highlight.cpp fileDialog.cpp renderStack.cpp stack.cpp renderQueue.cpp queue.cpp renderArray.cpp array.cpp -I $(INCLUDE)
link:
	g++ main.o render.o process.o linkedList.o textBox.o staticFile.o arrow.o renderLinkedList.o highlight.o fileDialog.o renderStack.o stack.o renderQueue.o queue.o renderArray.o array.o -o Data_Visualization.exe -L $(LIBRARY) $(SFMLFLAGS) $(SFML_INCLUDE)
run:
	./Data_Visualization.exe