#include "renderLinkedList.h"
#include "render.h"

const int height = 1920;
const int width = 1080;


RenderWindow window(VideoMode(height, width), "Data visualization", Style::Close);



int main() {

    int status = 0;
    initValueNode();
    while (window.isOpen()) {
        
        // Sprite sprite;
        // status = homePage(window);
        // status = singleLinkList(window);
        // status = LinkList(window, 3);
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
                status = LinkList(window);
                break; 
            case 12:
                status = LinkList(window, 2);
                break;
            case 13:
                status = LinkList(window, 3);
                break;
            default: 
                status = 0;
                break;
        }
        window.clear();
    }


    return EXIT_SUCCESS;
}