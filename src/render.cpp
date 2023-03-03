#include "render.h"
#include "process.h"
#include "node.h"
#include <vector>


const string imgSource = "../media/img/";

const int numNode = 10;

bool backButtonDark = false;

void resizeSprite(Sprite &sprite, double height, double width) {
    
    Vector2f targetSize(height, width); 

    sprite.setScale(
        targetSize.x / sprite.getLocalBounds().width, 
        targetSize.y / sprite.getLocalBounds().height);
}

Sprite addSprite(RenderWindow &window, string fileName, double sz1, double sz2, int x, int y, bool dark = false) {
    
    fileName = imgSource + fileName;
    if (dark) fileName.insert(fileName.size() - 4, "_dark", 5);
    Texture texture;
    texture.loadFromFile(fileName);
    texture.setSmooth(true);
    Sprite sprite;
    sprite.setTexture(texture);
    resizeSprite(sprite, sz1, sz2);
    sprite.setPosition(Vector2f(x, y));
    window.draw(sprite);
    return sprite;
}

void displayText(RenderWindow &window, string content, int x, int y, int sz) {

    Font f_title;
    f_title.loadFromFile("../media/font/arial.ttf");
    Text title;
    title.setFont(f_title);
    title.setString(content);
    title.setFillColor(Color::Black);
    title.setStyle(Text::Bold);
    title.setCharacterSize(sz);
    title.setPosition(x, y);
    window.draw(title);

}   

int homePage(RenderWindow &window) {

    window.clear(Color::White);

    // Texture
    Sprite linkList = addSprite(window, "Linked-list.png", 400, 300, 50, 100);
    Sprite Stack = addSprite(window, "stack.png", 400, 300, 500, 100);
    
    displayText(window, "Data visualization", 500, 10, 50);
    
    window.display();
    return statusHomePage(window, linkList, Stack);

}

int linkListPage(RenderWindow &window) {

    window.clear(Color::White);
    displayText(window, "Linked List", 550, 10, 50);


    Sprite singlyLinkList = addSprite(window, "singlyLinkList.png", 450, 300, 20, 220);
    Sprite doublyLinkList = addSprite(window, "doublyLinkList.png", 400, 340, 520, 160);
    Sprite circularLinkList = addSprite(window, "circular_singlyLinkList.png", 400, 300, 930, 210);

    displayText(window, "Singly Linked List", 135, 430, 20);
    displayText(window, "Doubly Linked List", 620, 430, 20);
    displayText(window, "Circular Linked List", 1050, 430, 20);

    Sprite returnButton = addSprite(window, "backButton.png", 150, 70, 10, 10, backButtonDark);     

    window.display();
    return statuslinkListPage(window, singlyLinkList, doublyLinkList, 
                              circularLinkList, returnButton, backButtonDark);

}

void drawCircle(RenderWindow &window, Node &node, int radius, Vector2f pos, string text, Font font) 
{
    node.init(pos, 14, "12", font);
    node.draw(window);
}

int singleLinkList(RenderWindow &window) {

    window.clear(Color::White);
    displayText(window, "Singly Linked List", 500, 10, 50);

    Sprite returnButton = addSprite(window, "backButton.png", 150, 70, 10, 10, backButtonDark);     
    
    Font font;
    font.loadFromFile("../media/font/arial.ttf");

    vector <Node> node(numNode);
    for (int i = 0; i < 10; i++) 
        drawCircle(window, node[i], 14, Vector2f(120 + 150 * i, 300), "12", font);
    
    window.display();
    return statusSingleLinkList(window, returnButton, backButtonDark);

}