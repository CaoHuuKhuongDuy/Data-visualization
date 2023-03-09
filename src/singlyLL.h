#ifndef SINGLYLL_H
#define SINGLYLL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include "arrow.h"

using namespace sf;
using namespace std;

class SinglyLL {

    public:
        SinglyLL(int value, int idx);
        void changePosition(Vector2f pos, Font &font);
        void draw(RenderWindow &window);
        SinglyLL *nxt;
        int id, data;
        Vector2f position;
    private:
        CircleShape m_node;
        Text m_text;

};

SinglyLL *createNode(int value, int idx, Vector2f pos, Font &font);

void deleteLL(SinglyLL *&root);

void createLL(SinglyLL *&root, int numNode, Font &font);

void drawSGL(RenderWindow &window, SinglyLL *root);

#endif