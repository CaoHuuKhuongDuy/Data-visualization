#include "render.h"



const string imgSource = "../media/img/";

Vector2f posBackButton = Vector2f(10, 10); 


bool backButtonDark = false;
bool createButtonDark = false;
bool randomButtonDark = false;
bool inputButtonDark = false;
bool addButtonDark = false;
bool deleteButtonDark = false;
bool updateButtonDark = false;
bool searchButtonDark = false;
int numTextBox = 0;
string userText = "", notice = "";

//--------------------------------------------------------


bool firstTimeAdd = false;
bool insert_at_end = false;
int radiusAnimation = 13;



Color orange(255, 99, 71);
Font font;
Texture t_submitButton;
textBox input;
SinglyLL *rootSGL = nullptr, *cur = nullptr;

Sprite addSprite(RenderWindow &window, string fileName, double sz1, double sz2, Vector2f pos, bool dark, bool display) {
    
    fileName = imgSource + fileName;
    if (dark) fileName.insert(fileName.size() - 4, "_dark", 5);
    Texture texture;
    loadTexture(texture, fileName);    
    texture.setSmooth(true);
    Sprite sprite;
    sprite.setTexture(texture);
    resizeSprite(sprite, sz1, sz2);
    sprite.setPosition(pos);
    if (display) window.draw(sprite);
    return sprite;
}

void displayText(RenderWindow &window, string content, Vector2f pos, int sz) {

    Text title;
    font.loadFromFile("../media/font/arial.ttf");
    title.setFont(font);
    title.setString(content);
    title.setFillColor(Color::Black);
    title.setStyle(Text::Bold);
    title.setCharacterSize(sz);
    title.setPosition(pos);
    window.draw(title);

}


textBox displayTextBox(RenderWindow &window, string nameText, Vector2f pos) {

    font.loadFromFile("../media/font/arial.ttf");
    Texture texture;   
    loadTexture(texture, "../media/img/submitButton.png");
    textBox input(pos + Vector2f(100, 8), texture, nameText, font);
    input.draw(window);
    return input;
}


void goAndColor(SinglyLL *&cur, int specialData) {
    
    cur->changeColor((cur->data == specialData) ? Color::Green : orange);
    usleep(500000);
    cur = cur->nxt;

}



int homePage(RenderWindow &window) {

    window.clear(Color::White);
    // Sprite background = addSprite(window, "background.jpg", 1800, 800, 0, 0);

    // Texture
    Sprite linkList = addSprite(window, "Linked-list.png", 400, 300, Vector2f(50, 300));
    Sprite Stack = addSprite(window, "stack.png", 400, 300, Vector2f(500, 300));
    Sprite Queue = addSprite(window, "queue.png", 400, 300, Vector2f(1000, 300));
    Sprite Array = addSprite(window, "array.png", 400, 300, Vector2f(1500, 200));
    displayText(window, "Data visualization", Vector2f(700, 10), 50);
    window.display();
    return statusHomePage(window, linkList, Stack);

}