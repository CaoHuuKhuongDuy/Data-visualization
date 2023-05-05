#include "textBox.h"
#include <iostream>


textBox::textBox(){}

textBox::textBox(Vector2f posChatBox, Texture &t_submitButton, string descrip, Font &t_font) {
    
    description.setFont(t_font);
    description.setString(descrip);
    description.setCharacterSize(18);
    description.setFillColor(Color::Black);
    description.setPosition(posChatBox);

    posChatBox = posChatBox + Vector2f(60, 0);
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
    note.setString(notice);
    note.setCharacterSize(12);
    note.setFillColor(Color::Red);
    note.setPosition(posChatBox + Vector2f(110, 5));
    
    Vector2f posSubmitButton = posChatBox + Vector2f(60, -2);

    submitButton.setTexture(t_submitButton);
    submitButton.setPosition(posSubmitButton);
    resizeSprite(submitButton, 45, 28);

}


void textBox::handleInput(RenderWindow &window, Event event) {

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
    switch (numTextBox) {
        case 11:
            displayNote = (tmp > maximumNode);
            if (displayNote) notice = "Note: The maximum number of vertex allowed is " + to_string(maximumNode);
            break;
        
        case 12:
            displayNote = (noTextBox == 0) && (tmp > numNode || numNode >= 10);
            if (!displayNote) break;
            if (numNode == maximumNode) notice = "Note: The maximum number of vertex allowed is " + to_string(maximumNode);
            else notice = "Note: a valid index between [0.." + to_string(numNode) + "]";
            break;
        case 13:
            displayNote = (tmp >= numNode || numNode == 0);
            if (!displayNote) break;
            if (numNode == 0) notice = "Note: The linked list is empty";
            else notice = "Note: a valid index between [0.." + to_string(numNode - 1) + "]"; 
            break;
        case 14:
            displayNote = (noTextBox == 0) && (tmp >= numNode || numNode == 0); 
            if (!displayNote) break;
            if (numNode == 0) notice = "Note: The linked list is empty";
            else notice = "Note: a valid index between [0.." + to_string(numNode - 1) + "]";
            break;
        case 15:
            break;
        case 23:
            displayNote = (numNode == maximumNode);
            if (!displayNote) break;
            notice = "Note: The maximum number of vertex allowed is" + to_string(maximumNode);
            break;
        case 33:
            displayNote = (numNode == maximumNode);
            if (!displayNote) break;
            notice = "Note: The maximum number of vertex allowed is 8" + to_string(maximumNode);
            break;
        case 42:
            displayNote = (tmp >= numNode);
            if (!displayNote) break;
            if (numNode == 0) notice = "Note: The array is empty";
            else notice = "Note: a valid index between [0.." + to_string(numNode - 1) + "]";
            break;
        case 43:
            displayNote = (noTextBox == 0) && (tmp > numNode || numNode >= maximumNode || !canAdd);
            if (!displayNote) break;
            if (!canAdd) notice = "Note: Array capacity exceeded. You have to create a new array"; 
            else if (numNode == maximumNode) notice = "Note: The maximum number of vertex allowed is " + to_string(maximumNode);
            else notice = "Note: a valid index between [0.." + to_string(numNode) + "]";
            break;
        case 44:
            displayNote = (tmp >= numNode);
            if (!displayNote) break;
            if (numNode == 0) notice = "Note: The array is empty";
            else notice = "Note: a valid index between [0.." + to_string(numNode - 1) + "]";
            break;
        case 45:
            displayNote = (noTextBox == 0) && (tmp >= numNode);
            if (!displayNote) break;
            if (numNode == 0) notice = "Note: The array is empty";
            else notice = "Note: a valid index between [0.." + to_string(numNode - 1) + "]";
            break;
    }
    userText = "";
    if (displayNote) return;
    switch (numTextBox) {
        case 11:
            numNode = tmp;
            createProcess = (tmp != 0 ? 3 : 1);
            break;
        case 112:
            valueNewNode[noTextBox + 1] = tmp;
            (noTextBox += 1) %= numNode;
            if (noTextBox == 0) createProcess--;
            break;
        case 12:
            if (noTextBox == 0) insertIdx = tmp + 1;
            else {
                insertValue = tmp;
                addProcess = 3;
            }
            insert_at_end = (insertIdx == numNode + 1);
            (noTextBox += 1) %= 2;
            break;
        case 13:
            deleteIdx = tmp + 1;
            deleteProcess = 5;
            delete_at_end = (deleteIdx == numNode);
            break;
        case 14:
            if (noTextBox == 0) updateIdx = tmp + 1;
            else {
                updateValue = tmp;
                updateProcess = 3;
            }
            (noTextBox += 1) %= 2;
            break;
        case 15:
            searchValue = tmp;
            searchProcess = 1;
            break;
        case 23:
            pushProcess = 3;
            insertValue = tmp;
            break;
        case 33:
            enqueueProcess = 3;
            insertValue = tmp;
            break;
        case 42:
            accessIndex = tmp;
            accessProcess = 2;
            break;
        case 43:
            if (noTextBox == 0) insertIdx = tmp;
            else {
                insertValue = tmp;
                addProcess = 3;
            }
            (noTextBox += 1) %= 2;
            break;
        case 44:
            deleteIdx = tmp;
            deleteProcess = 2;
            break;
        case 45:
            if (noTextBox == 0) updateIdx = tmp;
            else {
                updateValue = tmp;
                updateProcess = 3;
            }
            (noTextBox += 1) %= 2;
            break;
        case 46:
            searchValue = tmp;
            searchProcess = 1;
            break;
    }
    if (noTextBox == 0) numTextBox = 0;
}

void textBox::draw(RenderWindow &window) {

    window.draw(description);
    window.draw(chatbox);
    window.draw(text);
    if (displayNote) window.draw(note);
    window.draw(submitButton);

}