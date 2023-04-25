#include "renderQueue.h"

QueueVisualize rootQueue;

int peekPos = 0; // false = back, true = front

void createAnimationQueue(RenderWindow &window, Sprite *&p_randomButton, Sprite *&p_inputButton) {
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
        rootQueue.create(numNode, valueNewNode, font);
        createProcess--;
    }
}

void peekAnimationQueue(RenderWindow &window, Sprite *&p_peekFront, Sprite *&p_peekBack) {
    if (peekProcess == 3) {
        Vector2f posPeekFront = Vector2f(220, 805);
        Vector2f posPeekBack = Vector2f(300, 805);
        p_peekFront = new Sprite(addSprite(window, "peekFrontButton.png", 70, 30, posPeekFront, peekFrontDark));
        p_peekBack = new Sprite(addSprite(window, "peekBackButton.png", 70, 30, posPeekBack, peekBackDark));  
        return;
    }
    nameCodeId = 1 + peekPos;
    highlightPeekQueue(highlight, peekPos);
    if (peekProcess == 2) {
        rootQueue.changeColor(Color::Green, peekPos); 
        peekProcess--;
    }
    else {
        usleep(1800000);
        highlight.display = false;
        rootQueue.changeColor(Color::Blue, peekPos);
        peekProcess--;
    }
}

// enqueueFrame = 42 + 14 * (8 - numNode) + 2

bool firstEnqueue = false;

void enqueueAnimationQueue(RenderWindow &window) {
    numFrame++;
    nameCodeId = 3 + (numNode == 1);
    if (enqueueProcess == 3) {
        rootQueue.enqueue(insertValue, font);
        rootQueue.changeColor(Color::Green, 1);
        enqueueProcess--;
        firstEnqueue = true;
        highlightEnqueue(highlight);
        nameCodeId = 3 + (numNode == 1);
        return;
    }
    highlightEnqueue(highlight);
    if (firstEnqueue) usleep(1000000);
    firstEnqueue = false;
    if (enqueueProcess == 2 && !rootQueue.format(-1)) enqueueProcess--;
    else if (enqueueProcess == 1) {
        usleep(1800000);
        rootQueue.changeColor(Color::Blue, 1);
        numFrame = 0;
        enqueueProcess = 0;
        highlight.display = false;
    }
    
}

void dequeueAnimationQueue(RenderWindow &window) {
    numFrame++;
    nameCodeId = 5;
    highlightDequeue(highlight);
    if (dequeueProcess == 2) {
        rootQueue.changeColor(Color::Green, 0);
        if (!rootQueue.format()) dequeueProcess--;    
    }
    else {
        usleep(1000000);
        rootQueue.dequeue();
        numFrame = 0;
        dequeueProcess = 0;
        highlight.display = false;
    }
}

void createBoxQueue(RenderWindow &window) {
    Arrow arrow(0);
    arrow.create(Vector2f(600, 400), Vector2f(1400, 400));
    arrow.draw(window);
    arrow.create(Vector2f(600, 600), Vector2f(1400, 600));
    arrow.draw(window);
}

int Queue(RenderWindow &window) {
    maximumNode = 8;
    window.clear(Color::White);
    displayText(window, "Queue", Vector2f(850, 50), 50);
    font.loadFromFile("../media/font/arial.ttf");
    
    Vector2f posImportButton = Vector2f(100, 700);
    Vector2f posCreateButton = Vector2f(100, 750);
    Vector2f posPeekButton = Vector2f(100, 800);
    Vector2f posEnqueueButton = Vector2f(100, 850);
    Vector2f posDequeueButton = Vector2f(100, 900);

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
            peekProcess = 3;
            numTextBox = 0;
            break;
        case 221:
            peekProcess--;
            numTextBox = 0;
            peekPos = 0;
            break;
        case 222:
            peekProcess--;
            numTextBox = 0;
            peekPos = 1;
            break;
        case 33:
            input = displayTextBox(window, "Value", posEnqueueButton);
            break;
        case 34:
            dequeueProcess = 2;
            numTextBox = 0;
            break;
    }

    Sprite *p_closeButton = nullptr, *p_randomButton = nullptr, *p_inputButton = nullptr;
    Sprite *p_peekFront = nullptr, *p_peekBack = nullptr;

    if (createProcess) createAnimationQueue(window, p_randomButton, p_inputButton);
    if (peekProcess) peekAnimationQueue(window, p_peekFront, p_peekBack);
    if (enqueueProcess) enqueueAnimationQueue(window);
    if (dequeueProcess) dequeueAnimationQueue(window);

    Sprite backButton = addSprite(window, "backButton.png", 150, 70, posBackButton, backButtonDark);     
    Sprite importButton = addSprite(window, "importButton.png", 90, 42, posImportButton, importButtonDark);
    Sprite createButton = addSprite(window, "createButton.png", 90, 42, posCreateButton, createButtonDark);
    Sprite peekButton = addSprite(window, "peekButton.png", 90, 42, posPeekButton, peekButtonDark);
    Sprite enqueueButton = addSprite(window, "enqueueButton.png", 90, 42, posEnqueueButton, enqueueButtonDark);
    Sprite dequeueButton = addSprite(window, "dequeueButton.png", 90, 42, posDequeueButton, dequeueButtonDark);

    createBoxQueue(window);
 
    if (nameCodeId != 0) insertCode(window, nameCodeQueue[nameCodeId], p_closeButton);

    rootQueue.draw(window);
    highlight.draw(window);
    drawSpeedBox(window);


    window.display();
    return statusQueue(window, backButton, importButton, createButton, peekButton, enqueueButton, dequeueButton, input, p_randomButton, p_inputButton, p_closeButton, p_peekFront, p_peekBack);
}