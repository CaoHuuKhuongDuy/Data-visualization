#include "render.h"
// #include "process.h"


const int height = 1400;
const int width = 780;


RenderWindow window(VideoMode(height, width), "My window", Style::Default);



int main() {

    int status = 1;

    while (window.isOpen()) {
        
        Sprite sprite;
        switch (status) {

            case 1:
                sprite = homePage(window);
                break;
            case 2: 
                break;

        }

        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {

                case Event::Closed:  
                    window.close(); 
                    break;

                case Event::MouseButtonPressed:
                    if (event.mouseButton.button == Mouse::Left) {
                        FloatRect bounds = sprite.getGlobalBounds();
                        if (bounds.contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                        {
                            // handle left click on sprite
                            std::cout << "yes";
                        }
                    }
                    break;
        
            }

        }
    }


    return EXIT_SUCCESS;
}


