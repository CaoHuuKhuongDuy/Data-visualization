#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "staticFile.h"

using namespace sf;
using namespace std;

class textBox {
private:
    RectangleShape chatbox;
    Text text, note;
    Sprite submitButton;
public:
    textBox(Vector2f posChatBox, Texture &t_submitButton, Font &font);
    textBox();
    void handleInput(RenderWindow &window, Event event);
    void click(RenderWindow &winndow, Event event);
    void submit();
    void draw(RenderWindow &window);
};

#endif