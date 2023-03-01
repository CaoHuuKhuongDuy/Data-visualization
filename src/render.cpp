#include "render.h"
#include "process.h"
#include "button.h"

using namespace sf;

const string imgSource = "../media/img/";


void resizeSprite(Sprite &sprite, double height, double width) {
    
    Vector2f targetSize(height, width); 

    sprite.setScale(
        targetSize.x / sprite.getLocalBounds().width, 
        targetSize.y / sprite.getLocalBounds().height);
}

Sprite addSprite(RenderWindow &window, string fileName, double sz1, double sz2, int x, int y) {
    
    fileName = imgSource + fileName;
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
    displayText(window, "Linked list", 550, 10, 50);

    Font font;
    font.loadFromFile("../media/font/arial.ttf");


    Sprite returnButton = addSprite(window, "homeButton.png", 150, 80, 10, 10);
    // Button returnButton(Vector2f(10, 10), Vector2f(100, 50), sf::Color::Black, font, "Home", 30, Color::White);

    // returnButton.draw(window);
    
    window.display();

    return statuslinkListPage(window, returnButton);

}