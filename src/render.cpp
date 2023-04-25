#include "render.h"



const string imgSource = "../media/img/";

Vector2f posBackButton = Vector2f(10, 10); 

int loopCodeStatus = -1;
bool backButtonDark = false;
bool importButtonDark = false;
bool createButtonDark = false;
bool randomButtonDark = false;
bool peekButtonDark = false;
bool peekBackDark = false;
bool peekFrontDark = false;
bool popButtonDark = false;
bool pushButtonDark = false;
bool inputButtonDark = false;
bool addButtonDark = false;
bool deleteButtonDark = false;
bool updateButtonDark = false;
bool searchButtonDark = false;
bool dequeueButtonDark = false;
bool enqueueButtonDark = false;
bool accessButtonDark = false;
int numTextBox = 0;
string userText = "", notice = "";
SinglyLL *tmp = nullptr;



//--------------------------------------------------------


bool firstTimeAdd = false;
bool insert_at_end = false;
bool delete_at_end = false;
int radiusAnimation = 13;



Color orange(255, 99, 71);
Font font;
Texture t_submitButton;
textBox input;
SinglyLL *rootSGL = nullptr, *tailSGL = nullptr, *cur = nullptr, *oldP = nullptr;


Highlight highlight;

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

void displayText(RenderWindow &window, string content, Vector2f pos, int sz, Color color) {

    Text title;
    font.loadFromFile("../media/font/arial.ttf");
    title.setFont(font);
    title.setString(content);
    title.setFillColor(color);
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


void goAndColor(SinglyLL *&cur, string des, int specialData) {
    if (oldP) oldP->changeDes("", true);
    oldP = cur;
    cur->changeColor((cur->data == specialData) ? Color::Green : orange);
    if (cur == rootSGL) des = "Head/" + des;
    else if (!cur->nxt) des = "Tail/" + des;
    cur->changeDes(des);
    int delayTime;
    if (speed == 0) delayTime = 1000000;
    if (speed == 1) delayTime = 900000;
    if (speed == 2) delayTime = 100000;
    usleep(delayTime);
    cur = cur->nxt;

}

string getNameSpeedBox(int id) {
    string s = nameSpeedBox[id];
    if (id == speed) s.insert(s.size() - 4, "_picked", 7);
    return s;
}

void drawSpeedBox(RenderWindow &window) {
    for (int i = 0; i < 3; i++)
        speedBox[i] = addSprite(window, getNameSpeedBox(i), 100, 49, Vector2f(800 + i * 100, 850));
}

void insertCode(RenderWindow &window, string fileName, Sprite *&p_closeButton) {
    addSprite(window, fileName, 600, 300, Vector2f(1400, 700));
    p_closeButton = new Sprite(addSprite(window, "closeButton.png", 25, 25, Vector2f(1895, 700)));

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
    return statusHomePage(window, linkList, Stack, Queue, Array);

}