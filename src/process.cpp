#include "process.h"

Event event;


bool Press(Sprite sprite) {
    FloatRect bounds_sprite = sprite.getGlobalBounds();
    if (bounds_sprite.contains(Vector2f(event.mouseButton.x, event.mouseButton.y))) return true;
    return false;
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
                    cout << state << endl;
                }
                break;
    
        }
    }
    return state;
}
