#ifndef ARRAY_H
#define ARRAY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <time.h>
#include <unistd.h>
#include "staticFile.h"

class ArrayVisualize {
    public:
        ArrayVisualize();
        void clear();
        void create(int n, int val[], Font &font);
        void createNode(int id, int val, Font &font, bool dummy = false);
        void resize(int n, Font &font);
        void add(int x, Font &font);
        void changeColor(Color color, int idx);
        void changeData(int id, int val);
        void copyData(int idx1, int idx2);
        void changeStatus(bool statusArray);
        bool addMore();
        bool full();
        int getData(int idx);
        void del();
        bool draw(RenderWindow &window);
    private:
        vector <int> a;
        vector <RectangleShape> node;
        vector <Text> t_val, idx;
        int r, capacity;
        bool vectorType;
};

#endif 