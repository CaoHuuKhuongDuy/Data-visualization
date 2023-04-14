#ifndef ARROW_H
#define ARROW_H

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "staticFile.h"

using namespace std;
using namespace sf;

class Arrow {
    public:
        Arrow(int num = 1);
        void create(Vector2f startPoint, Vector2f endPoint, bool change = true);
        void createLine(Vector2f startPoint, Vector2f endPoint, bool change = true);
        void createArrow(VertexArray &arrow);
        void draw(RenderWindow &window);
    private:
        int numArrow;
        VertexArray line;
        VertexArray arrow1, arrow2;
        Vector2f point1, point2;
};

#endif