#include "button.h"

Button::Button(Vector2f position, Vector2f size, Color color, Font& font, string textString, int textSize, Color textColor) {
    m_button.setPosition(position);
    m_button.setSize(size);
    m_button.setFillColor(color);

    m_text.setFont(font);
    m_text.setString(textString);
    m_text.setCharacterSize(textSize);
    m_text.setFillColor(textColor);
    m_text.setPosition(position + sf::Vector2f(size.x / 2 - m_text.getLocalBounds().width / 2, size.y / 2 - m_text.getLocalBounds().height / 2 - 5));
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(m_button);
    window.draw(m_text);
}

bool Button::isClicked(sf::RenderWindow& window) {
    sf::FloatRect buttonBounds = m_button.getGlobalBounds();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (buttonBounds.contains(mousePosition.x, mousePosition.y)) {
        return true;
    }

    return false;
}