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

extern int firstPosX;
extern int firstPosY;

class SinglyLL {

    public:
        SinglyLL(int value, int idx, Font &font);
        void changePosition(Vector2f pos);
        void changeColor(Color color);
        void changeRadius(double radius);
        void changeData(int x);
        void changeDes(string s, bool empty = false);
        void draw(RenderWindow &window);
        bool rightPlace(Font &font);
        string getDes();
        Vector2f getCenter();
        SinglyLL *nxt;
        int id, data;
        Vector2f position;
    private:
        CircleShape m_node;
        Text m_text, description;

};

SinglyLL *createNode(int value, int idx, Vector2f pos, Font &font);

void deleteLL(SinglyLL *&root, SinglyLL *&tail);

void createLL(SinglyLL *&root, SinglyLL *&tail, int numNode, int valueNewNode[], Font &font);

void drawLL(RenderWindow &window, SinglyLL *root, SinglyLL *tail, bool doublyLL = false, bool circular = false, bool stack = false);

void insertLL(SinglyLL *&root, SinglyLL *&tail, int value, int idx, int &numNode, Font &font);

void deleteNodeLL(SinglyLL *&root, SinglyLL *&tail, int idx, int &numNode);

bool format(SinglyLL *cur, Font &font, bool insert_at_end, bool deleteProcess = false);

void clearColorLL(SinglyLL *cur);

#endif