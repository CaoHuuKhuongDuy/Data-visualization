#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Button {
public:
    Button(Vector2f position, Vector2f size, Color color, Font& font, string textString, int textSize, Color textColor);
    void draw(sf::RenderWindow& window);
    bool isClicked(sf::RenderWindow& window);
private:
    RectangleShape m_button;
    Text m_text;
};

#endif