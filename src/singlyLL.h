#ifndef SINGLYLL_H
#define SINGLYLL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <unistd.h>
#include "arrow.h"

using namespace sf;
using namespace std;

class SinglyLL {

    public:
        SinglyLL(int value, int idx, Font &font);
        void changePosition(Vector2f pos);
        void changeColor(Color color);
        void changeRadius(double radius);
        void changeData(int x);
        void draw(RenderWindow &window);
        bool rightPlace(Font &font);
        Vector2f getCenter();
        SinglyLL *nxt;
        int id, data;
        Vector2f position;
    private:
        CircleShape m_node;
        Text m_text;

};

SinglyLL *createNode(int value, int idx, Vector2f pos, Font &font);

void deleteLL(SinglyLL *&root);

void createLL(SinglyLL *&root, int numNode, int valueNewNode[], Font &font);

void drawSGL(RenderWindow &window, SinglyLL *root);

void insertLL(SinglyLL *&root, int value, int idx, int &numNode, Font &font);

void deleteNodeLL(SinglyLL *&root, int idx, int &numNode);

bool format(SinglyLL *cur, Font &font, bool insert_at_end);

void clearColorLL(SinglyLL *cur);

#endif