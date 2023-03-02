#include "process.h"
#include "button.h"

Event event;

bool hoverMouse(Sprite sprite) {
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
                       Sprite returnButton, bool &backButtonDark) {
                        
    int state = 1;
    backButtonDark = hoverMouse(returnButton);
    while (window.pollEvent(event)) {
        state = 1;
        switch (event.type) {
 
            case Event::Closed:
                window.close();
                state = -1;
                break;
            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left) {
                  if (Press(returnButton)) state = 0; 
                  if (Press(sLinkList)) state = 11;
                  if (Press(dLinkList)) state = 12;
                  if (Press(cLinkList)) state = 13;
                }
                break;
        }
    }
    return state;
}