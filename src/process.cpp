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

void initState(int _numNode, int _maximumNode) {
    numNode = _numNode;
    maximumNode = _maximumNode;
    nameCodeId = 0;
    pushProcess = 0;
    peekProcess = 0;
    popProcess = 0;
    enqueueProcess = 0;
    dequeueProcess = 0;
    initValueNode();
}

int statusHomePage(RenderWindow &window, Sprite linkList, Sprite Stack, Sprite Queue, Sprite Array) {
    int state = 0;
    while (window.pollEvent(event)) {

        switch (event.type) {
   
            case Event::Closed:  
                window.close(); 
                state = -1;
                break;

            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left) {
                    createProcess = 1;
                    if (Press(linkList)) state = 1;
                    else if (Press(Stack)) {
                        state = 2;
                        initState(3, 6);
                    }
                    else if (Press(Queue)) {
                        state = 3;
                        initState(3, 8);
                    }
                    else if (Press(Array)) {
                        state = 4;
                        initState(4, 6);
                    }
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
    numTextBox = (numTextBox == x ? 0 : x);
    noTextBox = 0;
    userText = "";
    displayNote = false;
    if (resetCreateProcess) createProcess = 0;
}

int statusLinkList(RenderWindow &window, Sprite backButton, Sprite importButton,Sprite createButton, Sprite addButton, Sprite deleteButton, 
                  Sprite updateButton, Sprite searchButton, textBox &input, int originState, Sprite *randomButton, Sprite *inputButton, Sprite *closeButton) {
    int state = originState;
    backButtonDark = hoverMouse(backButton);
    importButtonDark = hoverMouse(importButton);
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
                    else if (Press(importButton)) initPressState(113);
                    else if (Press(createButton)) initPressState(11);
                    else if (randomButton && Press(*randomButton)) {
                        initPressState(111, false);
                        createProcess -= 2;
                    }
                    else if (inputButton && Press(*inputButton)) {
                        initPressState(112, false);
                        createProcess--;
                    }
                    else if (Press(addButton)) initPressState(12);
                    else if (Press(deleteButton)) initPressState(13);
                    else if (Press(updateButton)) initPressState(14); 
                    else if (Press(searchButton)) initPressState(15);
                    // else initPressState(0); 
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


int statusStack(RenderWindow &window, Sprite backButton, Sprite importButton, Sprite createButton, Sprite peekButton,
                Sprite pushButton, Sprite popButton, textBox &input, Sprite *randomButton, Sprite *inputButton, Sprite *closeButton) {
    int state = 2;
    backButtonDark = hoverMouse(backButton);
    importButtonDark = hoverMouse(importButton);
    createButtonDark = hoverMouse(createButton);
    randomButtonDark = (randomButton && hoverMouse(*randomButton));
    inputButtonDark = (inputButton && hoverMouse(*inputButton));
    peekButtonDark = hoverMouse(peekButton);
    pushButtonDark = hoverMouse(pushButton);
    popButtonDark = hoverMouse(popButton);

    while (window.pollEvent(event)) {
        switch (event.type) {
            case Event::Closed:
                window.close();
                state = -1;
                break;
            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left) {
                    if (Press(backButton)) state = 0;
                    else if (Press(importButton)) initPressState(113);
                    else if (Press(createButton)) initPressState(11);
                    else if (randomButton && Press(*randomButton)) {
                        initPressState(111, false);
                        createProcess -= 2;
                    }
                    else if (inputButton && Press(*inputButton)) {
                        initPressState(112, false);
                        createProcess--;
                    }
                    else if (Press(peekButton)) initPressState(22);
                    else if (Press(pushButton)) initPressState(23);
                    else if (Press(popButton)) initPressState(24); 
                    if (closeButton && Press(*closeButton)) nameCodeId = 0;
                }   
                break;
            case Event::TextEntered:
                if (numTextBox != 0) {
                    input.handleInput(window, event);
                }
                break;
        } 
    }
    return state;
}

int statusQueue(RenderWindow &window, Sprite backButton, Sprite importButton, Sprite createButton, Sprite peekButton,
                Sprite enqueueButton, Sprite dequeueButton, textBox &input, Sprite *randomButton, Sprite *inputButton, Sprite *closeButton) {
    int state = 3;
    backButtonDark = hoverMouse(backButton);
    importButtonDark = hoverMouse(importButton);
    createButtonDark = hoverMouse(createButton);
    randomButtonDark = (randomButton && hoverMouse(*randomButton));
    inputButtonDark = (inputButton && hoverMouse(*inputButton));
    peekButtonDark = hoverMouse(peekButton);
    enqueueButtonDark = hoverMouse(enqueueButton);
    dequeueButtonDark = hoverMouse(dequeueButton);

    while (window.pollEvent(event)) {
        switch (event.type) {
            case Event::Closed:
                window.close();
                state = -1;
                break;
            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left) {
                    if (Press(backButton)) state = 0;
                    else if (Press(importButton)) initPressState(113);
                    else if (Press(createButton)) initPressState(11);
                    else if (randomButton && Press(*randomButton)) {
                        initPressState(111, false);
                        createProcess -= 2;
                    }
                    else if (inputButton && Press(*inputButton)) {
                        initPressState(112, false);
                        createProcess--;
                    }
                    else if (Press(peekButton)) initPressState(22);
                    else if (Press(enqueueButton)) initPressState(33);
                    else if (Press(dequeueButton)) initPressState(34); 
                    if (closeButton && Press(*closeButton)) nameCodeId = 0;
                }   
                break;
            case Event::TextEntered:
                if (numTextBox != 0) {
                    input.handleInput(window, event);
                }
                break;
        } 
    }
    return state;
}
