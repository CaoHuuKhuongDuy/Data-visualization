#include "node.h"
#include "render.h"


void Node::init(Vector2f position, int radius, string textString, Font &font) {
    m_node.setPosition(position);
    m_node.setRadius(radius);
    m_node.setOutlineColor(Color::Black);
    m_node.setOutlineThickness(3);

    m_text.setFont(font);
    m_text.setString(textString);
    m_text.setCharacterSize(20);
    m_text.setStyle(Text::Bold);
    m_text.setFillColor(Color::Black);
    m_text.setPosition(position + Vector2f(1, 4));
}

void Node::draw(RenderWindow& window) {
    window.draw(m_node);
    window.draw(m_text);
}

