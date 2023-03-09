#ifndef ARROW_H
#define ARROW_H

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

using namespace std;
using namespace sf;

class Arrow {
    public:
        Arrow();
        void create(Vector2f startPoint, Vector2f endPoint);
        void draw(RenderWindow &window);
    private:
        VertexArray line;
        VertexArray arrow;
        Vector2f point1, point2;
};

#endif