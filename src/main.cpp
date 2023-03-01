#include "render.h"


const int height = 1400;
const int width = 780;


RenderWindow window(VideoMode(height, width), "Data visualization", Style::Default);



int main() {

    int status = 0;

    while (window.isOpen()) {
        
        Sprite sprite;
        switch (status) {
            case -1: return EXIT_SUCCESS;
            // case 0:
            default:
                status = homePage(window);
                break;
            // case 2: 
                
            //     break;
            // default: status = 1;
        }
    }


    return EXIT_SUCCESS;
}


