#include "renderArray.h"

ArrayVisualize rootArray;

bool canAdd = false;

int curId = -1;

Color colorNodeArray = {0, 170, 177};
Color colorPeekNode = {248, 210, 16};
Color changeValueColor = colorPeekNode;

void createAnimationArray(RenderWindow &window, Sprite *&p_randomButton, Sprite *&p_inputButton) {
    if (createProcess == 3) {
        Vector2f posRandomButton = Vector2f(220, 650);
        Vector2f posInputButton = Vector2f(360, 650);
        displayText(window, "Size = " + to_string(numNode), Vector2f(240, 610), 18);
        p_randomButton = new Sprite(addSprite(window, "randomButton.png", 120, 42, posRandomButton, randomButtonDark));
        p_inputButton = new Sprite(addSprite(window, "inputButton.png", 120, 42, posInputButton, inputButtonDark));    
    }
    if (createProcess == 1) {
        rootArray.changeStatus(statusArray);
        if (numTextBox == 111) {
            for (int i = 1; i <= numNode; i++)
              valueNewNode[i] = rand() % 100;
        }
        rootArray.create(numNode, valueNewNode, font);
        createProcess--;
    }
}

void accessAnimationArray(RenderWindow &window) {
    nameCodeId = 1;
    highlightAccessArray(highlight);
    if (accessProcess == 2) {
        rootArray.changeColor(colorPeekNode, accessIndex);
        accessProcess--;
    }
    else if (accessProcess == 1) {
        usleep(1800000);
        rootArray.changeColor(colorNodeArray, accessIndex);
        highlight.display = false;
        accessProcess = 0;
    }
}

void addAnimationArray(RenderWindow &window, Sprite *&p_headButton, Sprite *&p_tailButton, Sprite *&p_specifyButton) {
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
    nameCodeId = (statusArray ? 3 : 2);
    if (numFrame == 0) {
        if (!rootArray.full()) numFrame = 1;
        highlightAddArray(highlight, statusArray);
        if (!rootArray.full()) numFrame = 0;
        numFrame++;
        return;
    }
    if (addProcess == 3) {
        usleep(600000);
        rootArray.add(rootArray.getData(numNode), font);
        rootArray.changeColor(colorPeekNode, numNode - 1);
        highlightAddArray(highlight, statusArray);
        addProcess--;
        return;
    }
    if (loopCodeStatus == 1) {
        highlightAddArray(highlight, statusArray);
        usleep(600000);
        loopCodeStatus = (curId <= insertIdx ? -1 : 0);
        return;
    }
    if (curId == -1) curId = numNode - 1;
    if (curId == insertIdx) numFrame++;
    highlightAddArray(highlight, statusArray);
    numFrame++;
    if (curId > insertIdx) {
        if (curId != numNode - 1) rootArray.changeColor(colorNodeArray, curId + 1);
        rootArray.changeColor(Color::Red, curId);
        rootArray.changeColor(Color::Green, curId - 1);
        rootArray.copyData(curId, curId - 1);
        curId--;
        usleep(900000);
        loopCodeStatus = 1;
    }
    else {
        if (addProcess == 2)  {
            usleep(900000);
            if (curId < numNode - 1) rootArray.changeColor(colorNodeArray, curId +  1);
            rootArray.changeColor(changeValueColor, curId);
            rootArray.changeData(curId, insertValue);
            addProcess--;
            
        }
        else if (addProcess == 1) {
            usleep(1000000);
            rootArray.changeColor(colorNodeArray, curId);
            highlight.display = false;
            curId = -1;
            addProcess--;
            numFrame = 0;
            loopCodeStatus = -1;
        }
    }
}

void deleteAnimationArray(RenderWindow &window, Sprite *&p_headButton, Sprite *&p_tailButton, Sprite *&p_specifyButton) {
    if (deleteProcess == 4) {
        Vector2f posHead = Vector2f(220, 805);
        Vector2f posTail = Vector2f(320, 805);
        Vector2f posSpecify = Vector2f(420, 805);
        p_headButton = new Sprite(addSprite(window, "headButton.png", 90, 35, posHead, headButtonDark));
        p_tailButton = new Sprite(addSprite(window, "tailButton.png", 90, 35, posTail, tailButtonDark));
        p_specifyButton = new Sprite(addSprite(window, "specifyIndexButton.png", 90, 35, posSpecify, specifyButtonDark));
        if (displayNote) displayText(window, notice, posSpecify + Vector2f(100, 10), 12, Color::Red, false);
        return;
    }
    if (deleteProcess == 3) return;
    nameCodeId = 4;
    if (loopCodeStatus == 1) {
        highlightDeleteArray(highlight);
        usleep(600000);
        loopCodeStatus = (curId > numNode - 2 ? -1 : 0);
        return;
    }
    if (curId == -1) curId = deleteIdx;
    if (curId == numNode - 1) numFrame = 1;
    highlightDeleteArray(highlight);
    numFrame++;
    if (curId <= numNode - 2) {
        if (curId != deleteIdx) rootArray.changeColor(colorNodeArray, curId - 1);
        rootArray.changeColor(Color::Red, curId);
        rootArray.changeColor(Color::Green, curId + 1);
        rootArray.copyData(curId, curId + 1);
        usleep(900000);
        loopCodeStatus = 1;
        curId++;
    }
    else {
        if (deleteProcess == 2) {
            usleep(600000);
            rootArray.del();
            deleteProcess--;
        }
        else {
            usleep(900000);
            rootArray.changeColor(colorNodeArray, curId - 1);
            deleteProcess = 0;
            curId = -1;
            highlight.display = false;
            numFrame = 0;
            loopCodeStatus = -1;
        }
    }
}

void updateAnimationArray(RenderWindow &window) {
    nameCodeId = 5;
    highlightUpdateArray(highlight);
    if (updateProcess == 3) {
        rootArray.changeColor(Color::Red, updateIdx);
        updateProcess--;
    }
    else if (updateProcess == 2) {
        usleep(900000);
        rootArray.changeColor(changeValueColor, updateIdx);
        rootArray.changeData(updateIdx, updateValue);
        updateProcess--;
    }
    else {
        usleep(900000);
        rootArray.changeColor(colorNodeArray, updateIdx);
        updateProcess = 0;
        highlight.display = false;
    }
}

void searchAnimationArray(RenderWindow &window) {
    nameCodeId = 6;
    if (loopCodeStatus == 1) {
        highlightSearchArray(highlight, rootArray.getData(curId - 1) == searchValue);
        usleep(600000);
        loopCodeStatus = (curId == numNode ? -1 : 0);
        return;
    }
    if (curId == -1) curId = 0;
    if (numNode != 0) highlightSearchArray(highlight);
    numFrame++;
    if (curId < numNode) {
        if (curId != 0 && rootArray.getData(curId - 1) != searchValue) rootArray.changeColor(colorNodeArray, curId - 1);
        rootArray.changeColor((rootArray.getData(curId) != searchValue ? colorPeekNode : Color::Red) , curId);
        usleep(900000);
        curId++;
        loopCodeStatus = 1;
    }
    else {
        usleep(900000);
        for (int i = 0; i < numNode; i++) 
          rootArray.changeColor(colorNodeArray, i);
        searchProcess = 0;
        curId = -1;
        highlight.display = false;
        numFrame = 0;
        loopCodeStatus = -1;
    }
}

int arrayHomePage(RenderWindow &window) {
    window.clear(Color::White);
    displayText(window, "Array", Vector2f(850, 50), 50); 

    Sprite staticArray = addSprite(window, "staticArray.png", 400, 280, Vector2f(400, 200));
    Sprite dynamicArray = addSprite(window, "vector.png", 450, 300, Vector2f(1040, 340));

    displayText(window, "Static Array", Vector2f(565, 530), 20);
    displayText(window, "Dynamic Array (Vector)", Vector2f(1080, 530), 20);

    Sprite backButton = addSprite(window, "backButton.png", 150, 70, posBackButton, backButtonDark);     

    window.display();
    return statusArrayPage(window, staticArray, dynamicArray, backButton);
}

int Array(RenderWindow &window) {
    window.clear(Color::White);
    displayText(window, (statusArray ? "Dynamic Array (Vector)" : "Static Array"), Vector2f(750, 50), 50);
    font.loadFromFile("../media/font/arial.ttf");

    Vector2f posImportButton = Vector2f(100, 600);
    Vector2f posCreateButton = Vector2f(100, 650);
    Vector2f posAccessButton = Vector2f(100, 700);
    Vector2f posAddButton = Vector2f(100, 750);
    Vector2f posDeleteButton = Vector2f(100, 800);
    Vector2f posUpdateButton = Vector2f(100, 850);
    Vector2f posSearchButton = Vector2f(100, 900);

    Sprite backButton = addSprite(window, "backButton.png", 150, 70, posBackButton, backButtonDark);     
    Sprite importButton = addSprite(window, "importButton.png", 90, 42, posImportButton, importButtonDark);
    Sprite createButton = addSprite(window, "createButton.png", 90, 42, posCreateButton, createButtonDark);
    Sprite accessButton = addSprite(window, "accessButton.png", 90, 42, posAccessButton, accessButtonDark);
    Sprite addButton = addSprite(window, "addButton.png", 90, 42, posAddButton, addButtonDark);
    Sprite deleteButton = addSprite(window, "deleteButton.png", 90, 42, posDeleteButton, deleteButtonDark);
    Sprite updateButton = addSprite(window, "updateButton.png", 90, 42, posUpdateButton, updateButtonDark);
    Sprite searchButton = addSprite(window, "searchButton.png", 90, 42, posSearchButton, searchButtonDark);

    Sprite *p_closeButton = nullptr, *p_randomButton = nullptr, *p_inputButton = nullptr;
    Sprite *p_headButton = nullptr, *p_tailButton = nullptr, *p_specifyButton = nullptr;

    switch (numTextBox) {
        case 11:
            input = displayTextBox(window, " Size", posCreateButton);
            break;
        case 112:
            input = displayTextBox(window, "v[" + to_string(noTextBox) + "] = ", posCreateButton + Vector2f((noTextBox == 9 ? 0 : 10), 0));
            break;
        case 113:
            import(window, valueNewNode, numNode);
            createProcess = 1;
            numTextBox = 0;
            break;
        case 42:
            input = displayTextBox(window, "Index", posAccessButton);
            break;
        case 43:
            if (addProcess == 0) {
                addProcess = 5;
                numTextBox = 0;
            }
            else input = displayTextBox(window, ((noTextBox == 0) ? "Index" : "Value"), posAddButton);
            break;
        case 44:
            if (deleteProcess == 0) {
                deleteProcess = 4;
                numTextBox = 0;
            }
            else input = displayTextBox(window, "Index", posDeleteButton);
            break;
        case 45:
            input = displayTextBox(window, ((noTextBox == 0) ? "Index" : "Value"), posUpdateButton);
            break;
        case 46:
            input = displayTextBox(window, "Value", posSearchButton);
            break;
    }

    if (createProcess) createAnimationArray(window, p_randomButton, p_inputButton);
    if (accessProcess) accessAnimationArray(window);
    if (addProcess) addAnimationArray(window, p_headButton, p_tailButton, p_specifyButton);
    if (deleteProcess) deleteAnimationArray(window, p_headButton, p_tailButton, p_specifyButton);
    if (updateProcess) updateAnimationArray(window);
    if (searchProcess) searchAnimationArray(window);
    
    
    if (rootArray.draw(window)) displayText(window, "Index: ", Vector2f(370, 500), 20);
    if (nameCodeId != 0) insertCode(window, nameCodeArray[nameCodeId], p_closeButton);
    highlight.draw(window);
    drawSpeedBox(window);
    window.display();

    canAdd = rootArray.addMore();
    return statusArray_SD(window, backButton, importButton, createButton, accessButton, addButton, deleteButton, updateButton, 
                            searchButton, input, p_randomButton, p_inputButton, p_closeButton, p_headButton, p_tailButton, p_specifyButton);
}