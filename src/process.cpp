#include "process.h"


Event event;

int hoverMouse(Sprite sprite) {
    FloatRect bounds_sprite = sprite.getGlobalBounds();
    return (bounds_sprite.contains(Vector2f(event.mouseMove.x, event.mouseMove.y))); 
}

bool Press(Sprite sprite) {
    FloatRect bounds_sprite = sprite.getGlobalBounds();
    return (bounds_sprite.contains(Vector2f(event.mouseButton.x, event.mouseButton.y)));
}

int statusHomePage(RenderWindow &window, Sprite linkList, Sprite Stack) {
    int state = 0;
    while (window.pollEvent(event)) {

        switch (event.type) {
   
            case Event::Closed:  
                window.close(); 
                state = -1;
                break;

            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left) {

                    if (Press(linkList)) state = 1;
                    else if (Press(Stack)) state = 2;
                }
                break;
    
        }
    }
    return state;
}



int statuslinkListPage(RenderWindow &window, Sprite sLinkList, Sprite dLinkList, Sprite cLinkList,
                       Sprite backButton) {
                        
    int state = 1;
    backButtonDark = hoverMouse(backButton);
    while (window.pollEvent(event)) {
        state = 1;
        switch (event.type) {
 
            case Event::Closed:
                window.close();
                state = -1;
                break;
            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left) {
                  if (Press(backButton)) state = 0; 
                  if (Press(sLinkList)) state = 11;
                  if (Press(dLinkList)) state = 12;
                  if (Press(cLinkList)) state = 13;
                }
                break;
        }
    }
    return state;
}

void initPressState(int x, bool resetCreateProcess = true) {
    numTextBox = x;
    noTextBox = 0;
    userText = "";
    displayNote = false;
    if (resetCreateProcess) createProcess = 0;
}

int statusLinkList(RenderWindow &window, Sprite backButton, Sprite createButton, Sprite addButton, Sprite deleteButton, Sprite updateButton, 
                  Sprite searchButton, textBox &input, int originState, Sprite *randomButton, Sprite *inputButton, Sprite *closeButton) {
    int state = originState;
    backButtonDark = hoverMouse(backButton);
    createButtonDark = hoverMouse(createButton);
    randomButtonDark = (randomButton && hoverMouse(*randomButton));
    inputButtonDark = (inputButton && hoverMouse(*inputButton));
    addButtonDark = hoverMouse(addButton);
    deleteButtonDark = hoverMouse(deleteButton);
    updateButtonDark = hoverMouse(updateButton);
    searchButtonDark = hoverMouse(searchButton);
    while (window.pollEvent(event)) {
        state = originState;
        switch (event.type) {

            case Event::Closed:
                window.close();
                state = -1;
                break;
            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left) {
                    if (numTextBox != 0) input.click(window, event);
                    if (Press(backButton)) state = 1;
                    else if (Press(createButton)) initPressState(1);
                    else if (randomButton && Press(*randomButton)) {
                        initPressState(11, false);
                        createProcess -= 2;
                    }
                    else if (inputButton && Press(*inputButton)) {
                        initPressState(12, false);
                        createProcess--;
                    }
                    else if (Press(addButton)) initPressState(2);
                    else if (Press(deleteButton)) initPressState(3);
                    else if (Press(updateButton)) initPressState(4); 
                    else if (Press(searchButton)) initPressState(5);
                    else initPressState(0); 
                    if (closeButton && Press(*closeButton)) nameCodeId = 0;
                }
                break;
            case Event::TextEntered:
                if (numTextBox != 0) {
                    input.handleInput(window, event);
                }
            
        }
    }
    return state;
}