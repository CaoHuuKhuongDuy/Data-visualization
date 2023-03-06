#include "textBox.h"
#include "render.h"
#include <iostream>



textBox::textBox(Vector2f posChatBox) {
    chatbox.setSize(Vector2f(50, 25));
    chatbox.setFillColor(Color::White);
    chatbox.setOutlineThickness(2);
    chatbox.setOutlineColor(Color::Black);
    chatbox.setPosition(posChatBox);

    text.setFont(font);
    text.setString("");
    text.setCharacterSize(24);
    text.setFillColor(Color::Black);
    text.setPosition(posChatBox + Vector2f(1, 3));

    Vector2f posSubmitButton = posChatBox + Vector2f(60, -2);

    submitButton.setTexture(t_submitButton);
    submitButton.setPosition(posSubmitButton);
    resizeSprite(submitButton, 45, 28);

}


void textBox::draw(RenderWindow &window) {
    window.draw(chatbox);
    window.draw(text);
    window.draw(submitButton);
    

}