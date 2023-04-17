#ifndef QUEUE
#define QUEUE

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <time.h>
#include <unistd.h>
#include "staticFile.h"

using namespace std;
using namespace sf;

class QueueVisualize {
    public:
        QueueVisualize();
        int size();
        void create(int n, int val[], Font &font);
        void enqueue(int val, Font &font, bool Create = false);
        void dequeue();
        void clear();
        void changeColor(Color color, int peekPos);
        bool format(int type = 1);
        void changePosition(int id, Vector2f pos, bool status = true);
        void draw(RenderWindow &window);
    private:
        int l;
        vector <int> a;
        vector <Text> t_val;
        vector <RectangleShape> node;
};

#endif