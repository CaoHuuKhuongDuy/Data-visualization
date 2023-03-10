#include "render.h"



const string imgSource = "../media/img/";

const Vector2f posBackButton = Vector2f(10, 10); 

// int numNode = 5;

bool backButtonDark = false;
bool createButtonDark = false;
bool addButtonDark = false;
bool deleteButtonDark = false;
bool updateButtonDark = false;
bool searchButtonDark = false;
bool formatProcess = false;
int numTextBox = 0;
string userText = "", notice = "";

Color orange(255, 99, 71);

Font font;
Texture t_submitButton;

textBox input;

SinglyLL *rootSGL = nullptr, *cur = nullptr;


Sprite addSprite(RenderWindow &window, string fileName, double sz1, double sz2, Vector2f pos, bool dark = false, bool display = true) {
    
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

void displayText(RenderWindow &window, string content, int x, int y, int sz) {

    Text title;
    font.loadFromFile("../media/font/arial.ttf");
    title.setFont(font);
    title.setString(content);
    title.setFillColor(Color::Black);
    title.setStyle(Text::Bold);
    title.setCharacterSize(sz);
    title.setPosition(x, y);
    window.draw(title);

}


textBox displayTextBox(RenderWindow &window, Vector2f pos) {

    font.loadFromFile("../media/font/arial.ttf");
    Texture texture;   
    loadTexture(texture, "../media/img/submitButton.png");
    textBox input(pos + Vector2f(100, 8), texture, font);
    input.draw(window);
    return input;
}

int homePage(RenderWindow &window) {

    window.clear(Color::White);
    // Sprite background = addSprite(window, "background.jpg", 1800, 800, 0, 0);

    // Texture
    Sprite linkList = addSprite(window, "Linked-list.png", 400, 300, Vector2f(50, 100));
    Sprite Stack = addSprite(window, "stack.png", 400, 300, Vector2f(500, 100));
    
    displayText(window, "Data visualization", 500, 10, 50);
    Arrow arrow;
    // arrow.create(Vector2f(270, 215), Vector2f(390, 415));
    // arrow.draw(window);
    window.display();
    return statusHomePage(window, linkList, Stack);

}

int linkListPage(RenderWindow &window) {

    window.clear(Color::White);
    displayText(window, "Linked List", 550, 10, 50);


    Sprite singlyLinkList = addSprite(window, "singlyLinkList.png", 450, 300, Vector2f(20, 220));
    Sprite doublyLinkList = addSprite(window, "doublyLinkList.png", 400, 340, Vector2f(520, 160));
    Sprite circularLinkList = addSprite(window, "circular_singlyLinkList.png", 400, 300, Vector2f(930, 210));

    displayText(window, "Singly Linked List", 135, 430, 20);
    displayText(window, "Doubly Linked List", 620, 430, 20);
    displayText(window, "Circular Linked List", 1050, 430, 20);

    Sprite backButton = addSprite(window, "backButton.png", 150, 70, posBackButton, backButtonDark);     

    window.display();
    return statuslinkListPage(window, singlyLinkList, doublyLinkList, 
                              circularLinkList, backButton);

}

void goAndColor(SinglyLL *&cur, int idx) {
    
    cur->changeColor(orange);
    usleep(500000);
    cur = cur->nxt;

}

int singleLinkList(RenderWindow &window) {
    window.clear(Color::White);
    displayText(window, "Singly Linked List", 500, 10, 50);
    font.loadFromFile("../media/font/arial.ttf");


    Vector2f posCreateButton = Vector2f(100, 500);
    Vector2f posAddButton = Vector2f(100, 550);
    Vector2f posDeleteButton = Vector2f(100, 600);
    Vector2f posUpdateButton = Vector2f(100, 650);
    Vector2f posSearchButton = Vector2f(100, 700);  

    Sprite backButton = addSprite(window, "backButton.png", 150, 70, posBackButton, backButtonDark);     
    Sprite createButton = addSprite(window, "createButton.png", 90, 42, posCreateButton, createButtonDark);
    Sprite addButton = addSprite(window, "addButton.png", 90, 42, posAddButton, addButtonDark);
    Sprite deleteButton = addSprite(window, "deleteButton.png", 90, 42, posDeleteButton, deleteButtonDark);
    Sprite updateButton = addSprite(window, "updateButton.png", 90, 42, posUpdateButton, updateButtonDark);
    Sprite searchButton = addSprite(window, "searchButton.png", 90, 42, posSearchButton, searchButtonDark);

    switch (numTextBox) {
        case 1: 
            input = displayTextBox(window, posCreateButton);
            break;
        case 2:
            input = displayTextBox(window, posAddButton);
            break;
        case 3:
            input = displayTextBox(window, posDeleteButton);
            break;
        case 4:
            input = displayTextBox(window, posUpdateButton);
            break;
        case 5:
            input = displayTextBox(window, posSearchButton);
            break;      
    }

    if (remake) {
        deleteLL(rootSGL);
        createLL(rootSGL, numNode, font);
        cur = rootSGL;
    }
    bool firstTime = false;
    bool insert_at_end = false;

    if (insertIdx != -1) {
        if (cur && cur->id < insertIdx) goAndColor(cur, insertIdx);
        else {
            insertLL(rootSGL, insertValue, insertIdx, numNode, font);
            insert_at_end = (insertIdx == numNode); 
            insertIdx = -1;
            usleep(800000);
            firstTime = true;
            cur = rootSGL;
        }
    }

    if (deleteIdx != -1) {
        if (cur && cur->id < deleteIdx) goAndColor(cur, insertIdx);
        else {
            deleteNodeLL(rootSGL, deleteIdx, numNode);
            deleteIdx = -1;
            usleep(800000);
            cur = rootSGL;
        }
    }


    bool tmp = format(rootSGL, font, insert_at_end);
    if (!tmp && formatProcess) clearColorLL(rootSGL);
    formatProcess = tmp;

    
    drawSGL(window, rootSGL);
    window.display();
    if (firstTime) usleep(500000);
    firstTime = false;
    remake = false;
    return statusSingleLinkList(window, backButton, createButton, addButton, deleteButton, updateButton, searchButton, input);
}