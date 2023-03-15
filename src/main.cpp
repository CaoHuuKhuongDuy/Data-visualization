#include "renderLinkedList.h"
#include "render.h"

const int height = 1400;
const int width = 780;


RenderWindow window(VideoMode(height, width), "Data visualization", Style::Close);



int main() {

    int status = 0;
    initValueNode();
    while (window.isOpen()) {
        
        // Sprite sprite;
        // status = homePage(window);
        // status = singleLinkList(window);
        // continue;
        switch (status) {
            case -1: return EXIT_SUCCESS;
            case 0: 
                status = homePage(window);
                break;
            case 1:
                status = linkListPage(window);
                break; 
            case 11:
                status = singleLinkList(window);
                break; 
            case 12:
                status = singleLinkList(window, 2);
                break;
            default: 
                status = 0;
                break;
        }
        window.clear();
    }


    return EXIT_SUCCESS;
}