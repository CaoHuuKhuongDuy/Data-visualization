#ifndef FILEDIALOG
#define FileDIALOG

#include <iostream>
#include <string>
#include <thread>
#include <functional>
#include <Windows.h>
#include <fstream>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

void import(RenderWindow &window, int val[], int &numNode, int maximumNode = 10);


#endif