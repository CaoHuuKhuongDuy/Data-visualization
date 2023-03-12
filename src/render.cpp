#include "render.h"



const string imgSource = "../media/img/";

const Vector2f posBackButton = Vector2f(10, 10); 


bool backButtonDark = false;
bool createButtonDark = false;
bool addButtonDark = false;
bool deleteButtonDark = false;
bool updateButtonDark = false;
bool searchButtonDark = false;
bool firstTimeAdd = false;
bool insert_at_end = false;


int numTextBox = 0;
int radiusAnimation = 13;
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


textBox displayTextBox(RenderWindow &window, string nameText, Vector2f pos) {

    font.loadFromFile("../media/font/arial.ttf");
    Texture texture;   
    loadTexture(texture, "../media/img/submitButton.png");
    textBox input(pos + Vector2f(100, 8), texture, nameText, font);
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

void goAndColor(SinglyLL *&cur, int specialData = -1) {
    
    cur->changeColor((cur->data == specialData) ? Color::Green : orange);
    usleep(500000);
    cur = cur->nxt;

}

void insertAnimationSGL() {
    if (cur && cur->id < insertIdx) goAndColor(cur);
    else {
        if (addProcess == 3) {
            insertLL(rootSGL, insertValue, insertIdx, numNode, font);
            usleep(500000);
            firstTimeAdd = true;
            insert_at_end = (insertIdx == numNode); 
            addProcess--;
        }
        else if (addProcess == 2) {
            if (firstTimeAdd) usleep(100000);
            firstTimeAdd = false;
            if (!format(rootSGL, font, insert_at_end)) addProcess--;
        }
        else {
            clearColorLL(rootSGL);
            addProcess--;
            insertIdx = -1;
            cur = rootSGL;
            insert_at_end = false;
        }
    }
}

void deleteAnimationSGL() {
    if (deleteProcess == 5 && cur && cur->id < deleteIdx) goAndColor(cur);
    else {
        if (deleteProcess == 5) {
            if (deleteIdx == 1 || deleteIdx == numNode) deleteProcess--;
            else {
                cur->changePosition(cur->position + Vector2f(0, 6));
                if (cur->position.y == 290) deleteProcess--;
            }
        }
        else if (deleteProcess == 4) {
            cur->changeRadius(radiusAnimation--);
            if (radiusAnimation == 9) deleteProcess--;
            usleep(20000);
        }
        else if (deleteProcess == 3) {
            deleteNodeLL(rootSGL, deleteIdx, numNode);  
            cur = rootSGL;
            deleteProcess--;
        }
        else if (deleteProcess == 2) {
            if (!format(rootSGL, font, insert_at_end)) {
                deleteProcess--;
            }
        }
        else {
            clearColorLL(rootSGL);
            deleteProcess--;
            deleteIdx = -1;
            radiusAnimation = 13;
        }
    }
}

void updateAnimationSGL() {
    if (cur && cur->id < updateIdx) goAndColor(cur);
    else {
        if (updateProcess == 3) {
            usleep(600000);
            cur->changeColor(Color::Green);
            updateProcess--;
        }
        else if (updateProcess == 2) {
            usleep(800000);
            cur->changeData(updateValue);
            cur->changeColor(Color::Cyan);
            updateProcess--;
        }
        else {
            clearColorLL(rootSGL);
            updateProcess--;
            cur = rootSGL;
        }
    }
}

void searchAnimationSGL() {
    if (!cur) {
        usleep(500000);
        searchProcess--;
        clearColorLL(rootSGL);
        cur = rootSGL;
        return;
    }
    if (cur) goAndColor(cur, searchValue);
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
            input = displayTextBox(window, " Size", posCreateButton);
            break;
        case 2:
            input = displayTextBox(window, ((!secondTextBox) ? "Index" : "Value"), posAddButton);
            break;
        case 3:
            input = displayTextBox(window, "Index", posDeleteButton);
            break;
        case 4:
            input = displayTextBox(window, ((!secondTextBox) ? "Index" : "Value"), posUpdateButton);
            break;
        case 5:
            input = displayTextBox(window, "Value", posSearchButton);
            break;      
    }

    if (remake) {
        deleteLL(rootSGL);
        createLL(rootSGL, numNode, font);
        cur = rootSGL;
    }

    if (addProcess) insertAnimationSGL();
    if (deleteProcess) deleteAnimationSGL();
    if (updateProcess) updateAnimationSGL();
    if (searchProcess) searchAnimationSGL();

    drawSGL(window, rootSGL);
    window.display();
    
    remake = false;
    return statusSingleLinkList(window, backButton, createButton, addButton, deleteButton, updateButton, searchButton, input);
}