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
            case 0: 
                status = homePage(window);
                break;
            case 1:
                status = linkListPage(window);
                break; 
            // case 11:
                // status = 
            default: 
                status = 0;
                break;
        }
        window.clear();
    }


    return EXIT_SUCCESS;
}