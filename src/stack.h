#ifndef STACK
#define STACK

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <unistd.h>
#include "staticFile.h"

using namespace std;
using namespace sf;

class StackVisualize {
    public:
        StackVisualize();
        int size();
        void create(int n, int val[], Font &font);
        void push(int x, Font &font, bool Create = false);
        void pop();
        void clear();
        void changeColor(Color color);
        int format(int type = 1);
        void changePosition(Vector2f pos);
        void draw(RenderWindow &window);
    private:
        RectangleShape node[12];
        Text t_val[12];
        int l, r;
        int a[12];
};

#endif