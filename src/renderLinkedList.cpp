#include "renderLinkedList.h"

string styleName[4] = {"", "Singly Linked List", "Doubly Linked List", "Circular Linked List"};

void createAnimationLL(RenderWindow &window, Sprite *&p_randomButton, Sprite *&p_inputButton) {
    if (createProcess == 3) {
        Vector2f posRandomButton = Vector2f(220, 700);
        Vector2f posInputButton = Vector2f(360, 700);
        displayText(window, "Size = " + to_string(numNode), Vector2f(240, 660), 18);
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
        if (numNode == 0) cout << "sdsdssd";
        cur = rootSGL;
        createProcess--;
    }
    
}

void insertAnimationLL() {
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

void deleteAnimationLL() {
    if (deleteProcess == 5 && cur && cur->id < deleteIdx) goAndColor(cur);
    else {
        if (deleteProcess == 5) {
            if (deleteIdx == 1 || deleteIdx == numNode) deleteProcess--;
            else {
                cur->changePosition(cur->position + Vector2f(0, 6));
                if (cur->position.y == firstPosY + 90) deleteProcess--;
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

void updateAnimationLL() {
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

void searchAnimationLL() {
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
    displayText(window, "Linked List", Vector2f(800, 10), 50);


    Sprite singlyLinkList = addSprite(window, "singlyLinkList.png", 450, 300, Vector2f(200, 220));
    Sprite doublyLinkList = addSprite(window, "doublyLinkList.png", 400, 340, Vector2f(760, 160));
    Sprite circularLinkList = addSprite(window, "circular_singlyLinkList.png", 400, 300, Vector2f(1200, 210));

    displayText(window, "Singly Linked List", Vector2f(330, 430), 20);
    displayText(window, "Doubly Linked List", Vector2f(860, 430), 20);
    displayText(window, "Circular Linked List", Vector2f(1310, 430), 20);

    Sprite backButton = addSprite(window, "backButton.png", 150, 70, posBackButton, backButtonDark);     

    window.display();
    return statuslinkListPage(window, singlyLinkList, doublyLinkList, 
                              circularLinkList, backButton);

}


int LinkList(RenderWindow &window, int styleLL) {
    window.clear(Color::White);
    displayText(window, styleName[styleLL], Vector2f(750, 10), 50);
    font.loadFromFile("../media/font/arial.ttf");

    Vector2f posCreateButton = Vector2f(100, 700);
    Vector2f posAddButton = Vector2f(100, 750);
    Vector2f posDeleteButton = Vector2f(100, 800);
    Vector2f posUpdateButton = Vector2f(100, 850);
    Vector2f posSearchButton = Vector2f(100, 900);  

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
            input = displayTextBox(window, "v[" + to_string(noTextBox + 1) + "] = ", posCreateButton + Vector2f((noTextBox == 9 ? 0 : 10), 0));
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


    if (createProcess) createAnimationLL(window, p_randomButton, p_inputButton);
    if (addProcess) insertAnimationLL();
    if (deleteProcess) deleteAnimationLL();
    if (updateProcess) updateAnimationLL();
    if (searchProcess) searchAnimationLL();

    drawLL(window, rootSGL, (styleLL == 2), (styleLL == 3));
    window.display();
    
    // remake = false;
    return statusLinkList(window, backButton,createButton, addButton, deleteButton, updateButton, searchButton, input, 
                          styleLL + 10, p_randomButton, p_inputButton);
}