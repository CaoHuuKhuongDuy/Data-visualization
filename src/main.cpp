#include "renderLinkedList.h"
#include "renderStack.h"
#include "renderQueue.h"

const int height = 1920;
const int width = 1080;


RenderWindow window(VideoMode(height, width), "Data visualization", Style::Close);
int styleLL;


int main() {

    int status = 0;
    initValueNode();
    while (window.isOpen()) {
        
        // Sprite sprite;   
        // status = homePage(window);
        // status = LinkList(window);
        // status = LinkList(window, 1);
        // status = Stack(window);
        // status = Queue(window);
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
                styleLL = 1;
                status = LinkList(window);
                break; 
            case 12:
                styleLL = 2;
                status = LinkList(window);
                break;
            case 13:
                styleLL = 3;
                status = LinkList(window);
                break;
            case 2:
                status = Stack(window);
                break;
            case 3:
                status = Queue(window);
                break;
            default: 
                status = 0;
                break;
        }
        window.clear();
    }


    return EXIT_SUCCESS;
}
