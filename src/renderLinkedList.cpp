#include "renderLinkedList.h"

string styleName[4] = {"", "Singly Linked List", "Doubly Linked List", "Circular Linked List"};


int numFrame = 0;


void createAnimationLL(RenderWindow &window, Sprite *&p_randomButton, Sprite *&p_inputButton) {
    if (createProcess == 3) {
        Vector2f posRandomButton = Vector2f(220, 700);
        Vector2f posInputButton = Vector2f(360, 700);
        displayText(window, "Size = " + to_string(numNode), Vector2f(240, 660), 18);
        p_randomButton = new Sprite(addSprite(window, "randomButton.png", 120, 42, posRandomButton, randomButtonDark));
        p_inputButton = new Sprite(addSprite(window, "inputButton.png", 120, 42, posInputButton, inputButtonDark));   
    }
    if (createProcess == 1) {
        deleteLL(rootSGL, tailSGL);
        if (numTextBox == 111) {
            for (int i = 1; i <= numNode; i++)
              valueNewNode[i] = rand() % 100;
        }
        createLL(rootSGL, tailSGL, numNode, valueNewNode, font);
        cur = rootSGL;
        createProcess--;
        oldP = nullptr;
    }   
}


// if (insert_at_end) insertFrame = 3 + (insertIdx - 1);
// else insertFrame = 33 + (insertIdx - 1);

void insertAnimationLL(RenderWindow &window, Sprite *&p_headButton, Sprite *&p_tailButton, Sprite *&p_specifyButton) {
    if (addProcess == 5) {
        Vector2f posHead = Vector2f(220, 755);
        Vector2f posTail = Vector2f(320, 755);
        Vector2f posSpecify = Vector2f(420, 755);
        p_headButton = new Sprite(addSprite(window, "headButton.png", 90, 35, posHead, headButtonDark));
        p_tailButton = new Sprite(addSprite(window, "tailButton.png", 90, 35, posTail, tailButtonDark));
        p_specifyButton = new Sprite(addSprite(window, "specifyIndexButton.png", 90, 35, posSpecify, specifyButtonDark));
        if (displayNote) displayText(window, notice, posSpecify + Vector2f(100, 10), 12, Color::Red, false);
        return;
    }
    if (addProcess == 4) return;
    if (insertIdx == 1) {
        nameCodeId = styleLL;
        if (insert_at_end) nameCodeId = (styleLL != 3 ? 18 : 19);
    }
    else if (insert_at_end) {
        nameCodeId = 3 + styleLL;
        if (cur == rootSGL) cur = tailSGL;
    }
    else nameCodeId = (styleLL != 2 ? 7 : 8);
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
            insertLL(rootSGL, tailSGL, insertValue, insertIdx, numNode, font);
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

// if (deleteAtEnd) deleteFrame = 8 + (deleteIdx - 1)
// else deleteFrame = 52 + (deleteIdx - 1)

// 0 : 4 frame
// 1 : 2 frame
// 2 : 1

void deleteAnimationLL(RenderWindow &window, Sprite *&p_headButton, Sprite *&p_tailButton, Sprite *&p_specifyButton) {
    if (deleteProcess == 7) {
        Vector2f posHead = Vector2f(220, 805);
        Vector2f posTail = Vector2f(320, 805);
        Vector2f posSpecify = Vector2f(420, 805);
        p_headButton = new Sprite(addSprite(window, "headButton.png", 90, 35, posHead, headButtonDark));
        p_tailButton = new Sprite(addSprite(window, "tailButton.png", 90, 35, posTail, tailButtonDark));
        p_specifyButton = new Sprite(addSprite(window, "specifyIndexButton.png", 90, 35, posSpecify, specifyButtonDark));
        if (displayNote) displayText(window, notice, posSpecify + Vector2f(100, 10), 12, Color::Red, false);
        return;
    }
    if (deleteProcess == 6) return;
    if (loopCodeStatus == 1) {
        highlightDeleteCode(highlight);
        usleep(600000);
        loopCodeStatus = 0;
        return;
    }
    if (deleteIdx == 1) nameCodeId = 8 + styleLL;
    else if (delete_at_end) {
        if (styleLL != 2) nameCodeId = 12;
        else {
            nameCodeId = 13;
            if (cur == rootSGL) cur = tailSGL;
        }
    }
    else nameCodeId = (styleLL != 2 ? 14 : 15);
    numFrame++;
    highlightDeleteCode(highlight);
    if (deleteProcess == 5 && cur && cur->id < deleteIdx) {
        goAndColor(cur, "pre");
        loopCodeStatus = ((cur && cur->id < deleteIdx) ? 1 : -1);
    }
    else {
        if (deleteProcess == 5) {
            if (numFrame == deleteIdx) usleep(300000);
            cur->changeDes("del");
            cur->changeColor(Color::Blue);

            if (deleteIdx == 1 || delete_at_end) {
                deleteProcess--;
                usleep(800000);
            }
            else {
                if (cur->nxt) cur->nxt->changeDes("aft");
                int tmp = (speed + 1) * 3;
                Vector2f newPos =  cur->position + Vector2f(0, tmp);
                newPos.y =  min((int)newPos.y, firstPosY + 90);
                cur->changePosition(newPos);
                if (cur->position.y == firstPosY + 90) deleteProcess--;
            }
        }
        else if (deleteProcess == 4) {
            if (radiusAnimation == 13) {
                usleep(500000);
            }
            cur->changeRadius(radiusAnimation--);
            if (radiusAnimation == 9) deleteProcess--;
            usleep(100000);
        }
        else if (deleteProcess == 3) {
            deleteNodeLL(rootSGL, tailSGL, deleteIdx, numNode);  
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
            delete_at_end = false;
            radiusAnimation = 13;
            numFrame = 0;
            loopCodeStatus = -1;
            highlight.display = false;
            oldP = nullptr;
            cur = rootSGL;
        }
    }
}


void updateAnimationLL() {
    nameCodeId = 16;
    if (updateIdx == numNode) {
        nameCodeId = 20;
        if (cur == rootSGL) cur = tailSGL;
    }
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
    nameCodeId = 17;
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


int LinkList(RenderWindow &window) {
    window.clear(Color::White);
    displayText(window, styleName[styleLL], Vector2f(750, 10), 50);
    font.loadFromFile("../media/font/arial.ttf");

    Vector2f posImportButton = Vector2f(100, 650);
    Vector2f posCreateButton = Vector2f(100, 700);
    Vector2f posAddButton = Vector2f(100, 750);
    Vector2f posDeleteButton = Vector2f(100, 800);
    Vector2f posUpdateButton = Vector2f(100, 850);
    Vector2f posSearchButton = Vector2f(100, 900);  

    Sprite backButton = addSprite(window, "backButton.png", 150, 70, posBackButton, backButtonDark);     
    Sprite importButton = addSprite(window, "importButton.png", 90, 42, posImportButton, importButtonDark);
    Sprite createButton = addSprite(window, "createButton.png", 90, 42, posCreateButton, createButtonDark);
    Sprite addButton = addSprite(window, "addButton.png", 90, 42, posAddButton, addButtonDark);
    Sprite deleteButton = addSprite(window, "deleteButton.png", 90, 42, posDeleteButton, deleteButtonDark);
    Sprite updateButton = addSprite(window, "updateButton.png", 90, 42, posUpdateButton, updateButtonDark);
    Sprite searchButton = addSprite(window, "searchButton.png", 90, 42, posSearchButton, searchButtonDark);

    Sprite *p_closeButton = nullptr, *p_randomButton = nullptr, *p_inputButton = nullptr;
    Sprite *p_HeadButton = nullptr, *p_tailButton = nullptr, *p_specifyButton = nullptr; 


    switch (numTextBox) {
        case 11: 
            input = displayTextBox(window, " Size", posCreateButton);
            break;
        case 112:
            input = displayTextBox(window, "v[" + to_string(noTextBox + 1) + "] = ", posCreateButton + Vector2f((noTextBox == 9 ? 0 : 10), 0));
            break;
        case 113:
            import(window, valueNewNode, numNode, maximumNode);
            createProcess = 1;
            numTextBox = 0;
            break;
        case 12:
            if (addProcess == 0 || addProcess == 5) {
                addProcess = 5;
                // numTextBox = 0;
            }
            else input = displayTextBox(window, ((noTextBox == 0) ? "Index" : "Value"), posAddButton);
            break;
        case 13:
            if (deleteProcess == 0 || deleteProcess == 7) {
                deleteProcess = 7;
                // numTextBox = 0;
            }
            else input = displayTextBox(window, "Index", posDeleteButton);
            break;
        case 14:
            input = displayTextBox(window, ((noTextBox == 0) ? "Index" : "Value"), posUpdateButton);
            break;
        case 15:
            input = displayTextBox(window, "Value", posSearchButton);
            break;      
    }


    if (createProcess) createAnimationLL(window, p_randomButton, p_inputButton);
    if (addProcess) insertAnimationLL(window, p_HeadButton, p_tailButton, p_specifyButton);
    if (deleteProcess) deleteAnimationLL(window, p_HeadButton, p_tailButton, p_specifyButton);
    if (updateProcess) updateAnimationLL();
    if (searchProcess) searchAnimationLL();

    if (nameCodeId != 0) insertCode(window, nameCodeLL[nameCodeId], p_closeButton, (nameCodeId == 16 || nameCodeId == 17));

    drawLL(window, rootSGL, tailSGL, (styleLL == 2), (styleLL == 3));
    
    highlight.draw(window);
    drawSpeedBox(window);
    window.display();

    return statusLinkList(window, backButton, importButton, createButton, addButton, deleteButton, updateButton, searchButton, input, 
                          styleLL + 10, p_randomButton, p_inputButton, p_closeButton, p_HeadButton, p_tailButton, p_specifyButton);
}