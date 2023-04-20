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
    if (accessProcess == 2) {
        // rootArray.changeColor(Color::Magenta, accessIndex);
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

void addAnimationArray(RenderWindow &window) {
    if (addProcess == 3) {
        rootArray.add(rootArray.getData(numNode), font);
        rootArray.changeColor(colorPeekNode, numNode - 1);
        addProcess--;
        return;
    }
    if (curId == -1) curId = numNode - 1;
    if (curId > insertIdx) {
        if (curId != numNode - 1) rootArray.changeColor(colorNodeArray, curId + 1);
        rootArray.changeColor(Color::Red, curId);
        rootArray.changeColor(Color::Green, curId - 1);
        rootArray.copyData(curId, curId - 1);
        curId--;
        usleep(900000);
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
        }
    }
}

void deleteAnimationArray(RenderWindow &window) {
    if (curId == -1) curId = deleteIdx;
    if (curId <= numNode - 2) {
        if (curId != deleteIdx) rootArray.changeColor(colorNodeArray, curId - 1);
        rootArray.changeColor(Color::Red, curId);
        rootArray.changeColor(Color::Green, curId + 1);
        rootArray.copyData(curId, curId + 1);
        curId++;
        usleep(900000);
    }
    else {
        usleep(900000);
        rootArray.del();
        rootArray.changeColor(colorNodeArray, curId - 1);
        deleteProcess = 0;
        curId = -1;
        highlight.display = false;
    }
}

void updateAnimationArray(RenderWindow &window) {
    if (updateProcess == 2) {
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
    if (curId == -1) curId = 0;
    if (curId < numNode) {
        if (curId != 0 && rootArray.getData(curId - 1) != searchValue) rootArray.changeColor(colorNodeArray, curId - 1);
        rootArray.changeColor((rootArray.getData(curId) != searchValue ? colorPeekNode : Color::Red) , curId);
        curId++;
        usleep(900000);
    }
    else {
        usleep(900000);
        for (int i = 0; i < numNode; i++) 
          rootArray.changeColor(colorNodeArray, i);
        searchProcess = 0;
        curId = -1;
        highlight.display = false;
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
            input = displayTextBox(window, ((noTextBox == 0) ? "Index" : "Value"), posAddButton);
            break;
        case 44:
            input = displayTextBox(window, "Index", posDeleteButton);
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
    if (addProcess) addAnimationArray(window);
    if (deleteProcess) deleteAnimationArray(window);
    if (updateProcess) updateAnimationArray(window);
    if (searchProcess) searchAnimationArray(window);
    
    
    if (rootArray.draw(window)) displayText(window, "Index: ", Vector2f(370, 500), 20);

    window.display();

    canAdd = rootArray.addMore();
    return statusStaticArray(window, backButton, importButton, createButton, accessButton, addButton, deleteButton, updateButton, 
                            searchButton, input, p_randomButton, p_inputButton, p_closeButton);
}