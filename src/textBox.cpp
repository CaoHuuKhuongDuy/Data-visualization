#include "textBox.h"
#include <iostream>


textBox::textBox(){}

textBox::textBox(Vector2f posChatBox, Texture &t_submitButton, Font &t_font) {
    
    chatbox.setSize(Vector2f(50, 25));
    chatbox.setFillColor(Color::White);
    chatbox.setOutlineThickness(2);
    chatbox.setOutlineColor(Color::Black);
    chatbox.setPosition(posChatBox);

    text.setFont(t_font);
    text.setString(userText);
    text.setCharacterSize(24);
    text.setFillColor(Color::Black);
    text.setPosition(posChatBox + Vector2f(10, 0));

    note.setFont(t_font);
    note.setString("Note: The maximum number of vertex allowed is 10");
    note.setCharacterSize(12);
    note.setFillColor(Color::Red);
    note.setPosition(posChatBox + Vector2f(80, 5));

    Vector2f posSubmitButton = posChatBox + Vector2f(60, -2);

    submitButton.setTexture(t_submitButton);
    submitButton.setPosition(posSubmitButton);
    resizeSprite(submitButton, 45, 28);

}

void textBox::handleInput(RenderWindow &window, Event event) {

    text.setString(userText);
    string tmp;
    char c = static_cast<char>(event.text.unicode);
    if (c == '\r' || c == '\b' || (c >= '0' && c <= '9')) {

        if (c == '\b' && userText.size() > 0) userText.erase(userText.size() - 1);
        else if (c == '\r') submit();
        else if (std::isprint(c) && userText.size() < 2) userText += c;
    }
        
}

void textBox::click(RenderWindow &window, Event event) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::FloatRect submitButtonRect = submitButton.getGlobalBounds();
    if (submitButtonRect.contains(mousePos.x, mousePos.y)) submit();
        
}

void textBox::submit() {
    if (userText.size() == 0) return;
    std::cout << "User entered: " << userText << std::endl;
    int tmp = stoi(userText);
    switch (numTextBox)
    {
    case 1:
        displayNote = (tmp > 10);
        break;
    
    case 2:
        displayNote = (tmp == 0 || tmp > numNode + 1 || numNode >= 10);
        break;
    }
    userText = "";
    if (displayNote) return;

    switch (numTextBox) {
    case 1:
        remake = true;
        numNode = tmp;
        break;
    case 2:
        insertIdx = tmp;
        insertValue = rand() % 100;
        break;
    }
    numTextBox = 0;
}

void textBox::draw(RenderWindow &window) {

    window.draw(chatbox);
    window.draw(text);
    if (displayNote) window.draw(note);
    window.draw(submitButton);

}