#include "renderStack.h"

StackVisualize rootStack;



void createAnimationStack(RenderWindow &window, Sprite *&p_randomButton, Sprite *&p_inputButton) {
    if (createProcess == 3) {
        Vector2f posRandomButton = Vector2f(220, 750);
        Vector2f posInputButton = Vector2f(360, 750);
        displayText(window, "Size = " + to_string(numNode), Vector2f(240, 710), 18);
        p_randomButton = new Sprite(addSprite(window, "randomButton.png", 120, 42, posRandomButton, randomButtonDark));
        p_inputButton = new Sprite(addSprite(window, "inputButton.png", 120, 42, posInputButton, inputButtonDark));    
    }
    if (createProcess == 1) {
        if (numTextBox == 111) {
            for (int i = 1; i <= numNode; i++)
              valueNewNode[i] = rand() % 100;
        }
        rootStack.create(numNode, valueNewNode, font);
        createProcess--;
    }   
}

void peekAnimationStack(RenderWindow &window) {
    nameCodeId = 1;
    highlightPeekCode(highlight);
    if (peekProcess == 2) {
        rootStack.changeColor(Color::Yellow);
        peekProcess--;
    }
    else {
        usleep(1800000);
        highlight.display = false;
        rootStack.changeColor(Color::Red);
        peekProcess--;
    }
}

void pushAnimationStack(RenderWindow &window) {
    nameCodeId = 2;
    numFrame++;
    highlightPushCode(highlight);
    if (pushProcess == 3) {
        rootStack.push(insertValue, font);
        rootStack.changeColor(Color::Yellow);
        pushProcess--;
    }
    else if (pushProcess == 2 && rootStack.format() == 3) pushProcess--;
    else if (pushProcess == 1) {
        usleep(1000000);
        numFrame = 0;
        highlight.display = false;
        rootStack.changeColor(Color::Red);
        pushProcess = 0;
    }
}

void popAnimationStack(RenderWindow &window) {
    nameCodeId = 3;
    numFrame++;
    int formatProcess;
    highlightPopCode(highlight);
    if (popProcess == 2) {
        rootStack.changeColor(Color::Yellow);
        formatProcess = rootStack.format(-1);
        if (formatProcess == 3) popProcess--;    
    }
    else {
        usleep(1000000);
        rootStack.pop();
        popProcess--;
        highlight.display = false;
        numFrame = 0;
    }
}

void createBoxStack(RenderWindow &window) {
    Arrow arrow(0);
    arrow.create(Vector2f(780, 365), Vector2f(780, 785));
    arrow.draw(window);
    arrow.create(Vector2f(998, 365), Vector2f(998, 785));
    arrow.draw(window);
    arrow.create(Vector2f(777, 700), Vector2f(1056, 700));
    arrow.draw(window);
}

int Stack(RenderWindow &window) {
    window.clear(Color::White);
    displayText(window, "Stack", Vector2f(850, 50), 50);
    font.loadFromFile("../media/font/arial.ttf");
    
    // initValueNode();
    Vector2f posImportButton = Vector2f(100, 700);
    Vector2f posCreateButton = Vector2f(100, 750);
    Vector2f posPeekButton = Vector2f(100, 800);
    Vector2f posPushButton = Vector2f(100, 850);
    Vector2f posPopButton = Vector2f(100, 900);

    switch (numTextBox) {
        case 11: 
            input = displayTextBox(window, " Size", posCreateButton);
            break;
        case 112:
            input = displayTextBox(window, "v[" + to_string(noTextBox + 1) + "] = ", posCreateButton + Vector2f((noTextBox == 9 ? 0 : 10), 0));
            break;
        case 113:
            import(window, valueNewNode, numNode);
            createProcess = 1;
            numTextBox = 0;
            break;
        case 22:
            peekProcess = 2;
            numTextBox = 0;
            break;
        case 23:
            input = displayTextBox(window, "Value", posPushButton);
            break;
        case 24:
            popProcess = 2;
            numTextBox = 0;
            break;
    }

    Sprite *p_closeButton = nullptr, *p_randomButton = nullptr, *p_inputButton = nullptr;


    // Vector2f posSearchButton = Vector2f(100, 900);  

    Sprite backButton = addSprite(window, "backButton.png", 150, 70, posBackButton, backButtonDark);     
    Sprite importButton = addSprite(window, "importButton.png", 90, 42, posImportButton, importButtonDark);
    Sprite createButton = addSprite(window, "createButton.png", 90, 42, posCreateButton, createButtonDark);
    Sprite peekButton = addSprite(window, "peekButton.png", 90, 42, posPeekButton, peekButtonDark);
    Sprite pushButton = addSprite(window, "pushButton.png", 90, 42, posPushButton, pushButtonDark);
    Sprite popButton = addSprite(window, "popButton.png", 90, 42, posPopButton, popButtonDark);
    
    if (createProcess) createAnimationStack(window, p_randomButton, p_inputButton);
    if (peekProcess) peekAnimationStack(window);
    if (pushProcess) pushAnimationStack(window);
    if (popProcess) popAnimationStack(window); // handle pop when the stack is empty

    createBoxStack(window);

    if (nameCodeId != 0) insertCode(window, nameCodeStack[nameCodeId], p_closeButton);
    
    rootStack.draw(window);
    highlight.draw(window);

    window.display();

    return statusStack(window, backButton, importButton, createButton, peekButton, pushButton, popButton, input, p_randomButton, p_inputButton, p_closeButton);

}