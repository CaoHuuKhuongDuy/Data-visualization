#include "renderLinkedList.h"

string styleName[4] = {"", "Singly Linked List", "Doubly Linked List", "Circular Linked List"};

Highlight highlight;

int numFrame = 0;

int loopCodeStatus = -1;

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
        cur = rootSGL;
        createProcess--;
        oldP = nullptr;
    }   
}


// if (insert_at_end) insertFrame = 3 + (insertIdx - 1);
// else insertFrame = 33 + (insertIdx - 1);

void insertAnimationLL() {
    nameCodeId = (insertIdx != 1) + 1;
    if (loopCodeStatus == 1) {
        highlightInsertCode(highlight);
        usleep(600000);
        loopCodeStatus = 0;
        return;
    }
    numFrame++;
    highlightInsertCode(highlight);
    if (cur && cur->id < insertIdx) {
        goAndColor(cur, "pre");
        loopCodeStatus = ((cur && cur->id < insertIdx) ? 1 : -1);
    }
    else {
        loopCodeStatus = -1;
        if (addProcess == 3) {
            if (cur) cur->changeDes(to_string(cur->id + 1) + "/aft", true);
            insertLL(rootSGL, insertValue, insertIdx, numNode, font);
            usleep(500000);
            firstTimeAdd = true;
            addProcess--;
        }
        else if (addProcess == 2) {
            if (firstTimeAdd) usleep(500000);
            firstTimeAdd = false;
            if (!format(rootSGL, font, insert_at_end)) addProcess--;
        }
        else {
            clearColorLL(rootSGL);
            highlight.display = false;
            addProcess--;
            insertIdx = -1;
            cur = rootSGL;
            oldP = nullptr;
            insert_at_end = false;
            numFrame = 0;
        }
    }
}

void deleteAnimationLL() {
    nameCodeId = (deleteIdx != 1) + 3;
    numFrame++;
    // highlightDeleteCode(highlight);
    if (deleteProcess == 5 && cur && cur->id < deleteIdx) goAndColor(cur, "pre");
    else {
        // cout << numFrame << endl;
        if (deleteProcess == 5) {
            cur->changeDes("del");
            cur->changeColor(Color::Blue);
            if (deleteIdx == 1 || deleteIdx == numNode) deleteProcess--;
            else {
                if (cur->nxt) cur->nxt->changeDes("aft");
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
            if (!format(rootSGL, font, insert_at_end, true)) {
                deleteProcess--;
            }
        }
        else {
            clearColorLL(rootSGL);
            deleteProcess--;
            deleteIdx = -1;
            radiusAnimation = 13;
            numFrame = 0;
            loopCodeStatus = -1;
            highlight.display = false;
            oldP = nullptr;
        }
    }
}


void updateAnimationLL() {
    nameCodeId = 5;
    if (loopCodeStatus == 1) {
        highlightUpdateCode(highlight);
        usleep(600000);
        loopCodeStatus = 0;
        return;
    }
    numFrame++;
    highlightUpdateCode(highlight);
    if (cur && cur->id < updateIdx) {
        goAndColor(cur, "pre");
        loopCodeStatus = 1;
    }
    else {
        loopCodeStatus = -1;
        if (updateProcess == 3) {
            usleep(600000);
            if (oldP) oldP->changeDes("", true);
            cur->changeColor(Color::Green);
            cur->changeDes("pre");
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
            highlight.display = false;
            updateProcess--;
            oldP = nullptr;
            cur = rootSGL;
            numFrame = 0;
        }
    }
}

void searchAnimationLL() {
    nameCodeId = 6;
    if (loopCodeStatus == 4 || loopCodeStatus == 5) {
        usleep(1000000);
        numFrame++;
        highlightSearchCode(highlight);
        loopCodeStatus = -1;
        return;
    }
    if (!cur) {
        usleep(500000);
        searchProcess--;
        clearColorLL(rootSGL);
        highlight.display = false;
        cur = rootSGL;
        oldP = nullptr;
        numFrame = 0;
        return;
    }

    if (loopCodeStatus == 1) {
        highlightSearchCode(highlight);
        usleep(600000);
        loopCodeStatus = 0;
        return;
    }
    numFrame++;
    highlightSearchCode(highlight);
    if (cur) {
        loopCodeStatus = 1;
        if (cur->data == searchValue) {
            goAndColor(cur, "pre", searchValue);
            cur = nullptr;
            loopCodeStatus = 5;
        }
        else {
            goAndColor(cur, "pre", searchValue);
            if (!cur) loopCodeStatus = 4;
        }
        
    }
}

int linkListPage(RenderWindow &window) {

    window.clear(Color::White);
    displayText(window, "Linked List", Vector2f(800, 10), 50);
    numNode = 5;
    createProcess = 1;
    initValueNode();

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

void insertCode(RenderWindow &window, string fileName, Sprite *&p_closeButton) {
    addSprite(window, fileName, 600, 300, Vector2f(1400, 700));
    p_closeButton = new Sprite(addSprite(window, "closeButton.png", 25, 25, Vector2f(1895, 700)));

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

    Sprite *p_closeButton = nullptr, *p_randomButton = nullptr, *p_inputButton = nullptr;


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

    if (nameCodeId != 0) insertCode(window, nameCodeLL[nameCodeId], p_closeButton);

    drawLL(window, rootSGL, (styleLL == 2), (styleLL == 3));
    
    highlight.draw(window);

    window.display();

    return statusLinkList(window, backButton,createButton, addButton, deleteButton, updateButton, searchButton, input, 
                          styleLL + 10, p_randomButton, p_inputButton, p_closeButton);
}