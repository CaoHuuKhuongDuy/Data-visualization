#include "process.h"
// #include "textBox.h"

// textBox input;


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

int statusSingleLinkList(RenderWindow &window, Sprite backButton, Sprite createButton, Sprite addButton, 
                         Sprite deleteButton, Sprite updateButton, Sprite searchButton, textBox &input) {
    int state = 11;
    backButtonDark = hoverMouse(backButton);
    createButtonDark = hoverMouse(createButton);
    addButtonDark = hoverMouse(addButton);
    deleteButtonDark = hoverMouse(deleteButton);
    updateButtonDark = hoverMouse(updateButton);
    searchButtonDark = hoverMouse(searchButton);
    while (window.pollEvent(event)) {
        state = 11;
        switch (event.type) {

            case Event::Closed:
                window.close();
                state = -1;
                break;
            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left) {
                    if (numTextBox != 0) input.click(window, event);
                    if (Press(backButton)) state = 1;
                    if (Press(createButton)) numTextBox = 1, secondTextBox = 0;
                    if (Press(addButton)) numTextBox = 2, secondTextBox = 0;
                    if (Press(deleteButton)) numTextBox = 3, secondTextBox = 0;
                    if (Press(updateButton)) numTextBox = 4, secondTextBox = 0;
                    if (Press(searchButton)) numTextBox = 5, secondTextBox = 0;
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