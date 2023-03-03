#ifndef NODE_H
#define NODE_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Node {
public:
    void init(Vector2f position, int radius, string textString, Font &font);
    void draw(sf::RenderWindow& window);
private:
    CircleShape m_node;
    Text m_text;
};

#endif