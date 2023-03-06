#include "render.h"
#include "process.h"
#include "node.h"
#include "textBox.h"
#include <vector>


const string imgSource = "../media/img/";

const int numNode = 10;
const Vector2f posBackButton = Vector2f(10, 10); 


bool backButtonDark = false;
bool createButtonDark = false;
bool addButtonDark = false;
bool deleteButtonDark = false;
bool updateButtonDark = false;
bool searchButtonDark = false;
int numTextBox = 0;

Font font;
Texture t_submitButton;

void loadStatic() {
    font.loadFromFile("../media/font/arial.ttf");
    // Texture t_submitButton;
    cout << (t_submitButton.loadFromFile("../media/img/submitButton.png")) << endl;
    t_submitButton.setSmooth(true);
}

void resizeSprite(Sprite &sprite, double height, double width) {
    
    Vector2f targetSize(height, width); 

    sprite.setScale(
        targetSize.x / sprite.getLocalBounds().width, 
        targetSize.y / sprite.getLocalBounds().height);
}

Sprite addSprite(RenderWindow &window, string fileName, double sz1, double sz2, Vector2f pos, bool dark = false, bool display = true) {
    
    fileName = imgSource + fileName;
    if (dark) fileName.insert(fileName.size() - 4, "_dark", 5);
    Texture texture;
    texture.loadFromFile(fileName);
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
    title.setFont(font);
    title.setString(content);
    title.setFillColor(Color::Black);
    title.setStyle(Text::Bold);
    title.setCharacterSize(sz);
    title.setPosition(x, y);
    window.draw(title);

}

void drawCircle(RenderWindow &window, Node &node, int radius, Vector2f pos, string text) {
    node.init(pos, 14, "12");
    node.draw(window);
}


void displayTextBox(RenderWindow &window, Vector2f pos) {
    
    textBox input(pos + Vector2f(100, 8));
    input.draw(window);
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
                              circularLinkList, backButton, backButtonDark);

}



int singleLinkList(RenderWindow &window) {

    window.clear(Color::White);
    displayText(window, "Singly Linked List", 500, 10, 50);

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
            displayTextBox(window, posCreateButton);
            break;
        case 2:
            displayTextBox(window, posAddButton);
            break;
        case 3:
            displayTextBox(window, posDeleteButton);
            break;
        case 4:
            displayTextBox(window, posUpdateButton);
            break;
        case 5:
            displayTextBox(window, posSearchButton);
            break;
    }
    

    vector <Node> node(numNode);
    for (int i = 0; i < 10; i++) 
        drawCircle(window, node[i], 14, Vector2f(120 + 150 * i, 300), "12");
    
    window.display();
    return statusSingleLinkList(window, backButton, backButtonDark, createButton, createButtonDark, addButton, addButtonDark, 
                                deleteButton, deleteButtonDark, updateButton, updateButtonDark, searchButton, searchButtonDark, numTextBox);

}