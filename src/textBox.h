#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
using namespace sf;

class textBox {
public:
    textBox(Vector2f posChatBox);
    // bool submit(RenderWindow &window);
    void draw(RenderWindow &window);
private:
    RectangleShape chatbox;
    Text text;
    Sprite submitButton;
};

#endif