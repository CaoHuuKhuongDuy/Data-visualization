#include "renderLinkedList.h"

string styleName[4] = {"", "Singly Linked List", "Doubly Linked List", "Circular Linked List"};

void createAnimationSGL(RenderWindow &window, Sprite *&p_randomButton, Sprite *&p_inputButton) {
    if (createProcess == 3) {
        
        Vector2f posRandomButton = Vector2f(220, 500);
        Vector2f posInputButton = Vector2f(360, 500);
        displayText(window, "Size = " + to_string(numNode), Vector2f(240, 460), 18);
        p_randomButton = new Sprite(addSprite(window, "randomButton.png", 120, 42, posRandomButton, randomButtonDark));
        p_inputButton = new Sprite(addSprite(window, "inputButton.png", 120, 42, posInputButton, inputButtonDark));    
    }
    if (createProcess == 1) {
        deleteLL(rootSGL);
        if (numTextBox == 11) {
            for (int i = 1; i <= numNode; i++)
              valueNewNode[i] = rand() % 100;
        }
        createLL(rootSGL, numNode, valueNewNode, font);
        cur = rootSGL;
        createProcess--;
    }
    
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

int linkListPage(RenderWindow &window) {

    window.clear(Color::White);
    displayText(window, "Linked List", Vector2f(550, 10), 50);


    Sprite singlyLinkList = addSprite(window, "singlyLinkList.png", 450, 300, Vector2f(20, 220));
    Sprite doublyLinkList = addSprite(window, "doublyLinkList.png", 400, 340, Vector2f(520, 160));
    Sprite circularLinkList = addSprite(window, "circular_singlyLinkList.png", 400, 300, Vector2f(930, 210));

    displayText(window, "Singly Linked List", Vector2f(135, 430), 20);
    displayText(window, "Doubly Linked List", Vector2f(620, 430), 20);
    displayText(window, "Circular Linked List", Vector2f(1050, 430), 20);

    Sprite backButton = addSprite(window, "backButton.png", 150, 70, posBackButton, backButtonDark);     

    window.display();
    return statuslinkListPage(window, singlyLinkList, doublyLinkList, 
                              circularLinkList, backButton);

}


int singleLinkList(RenderWindow &window, int styleLL) {
    window.clear(Color::White);
    displayText(window, styleName[styleLL], Vector2f(500, 10), 50);
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

    Sprite *p_randomButton = nullptr, *p_inputButton = nullptr;



    switch (numTextBox) {
        case 1: 
            input = displayTextBox(window, " Size", posCreateButton);
            break;
        case 12:
            input = displayTextBox(window, "v[" + to_string(noTextBox + 1) + "] = ", posCreateButton);
            break;
        case 2:
            input = displayTextBox(window, ((noTextBox == 0) ? "Index" : "Value"), posAddButton);
            break;
        case 3:
            input = displayTextBox(window, "Index", posDeleteButton);
            break;
        case 4:
            input = displayTextBox(window, ((noTextBox == 0) ? "Index" : "Value"), posUpdateButton);
            break;
        case 5:
            input = displayTextBox(window, "Value", posSearchButton);
            break;      
    }


    if (createProcess) createAnimationSGL(window, p_randomButton, p_inputButton);
    if (addProcess) insertAnimationSGL();
    if (deleteProcess) deleteAnimationSGL();
    if (updateProcess) updateAnimationSGL();
    if (searchProcess) searchAnimationSGL();

    drawLL(window, rootSGL, (styleLL == 2));
    window.display();
    
    // remake = false;
    return statusLinkList(window, backButton,createButton, addButton, deleteButton, updateButton, searchButton, input, 
                          styleLL + 10, p_randomButton, p_inputButton);
}