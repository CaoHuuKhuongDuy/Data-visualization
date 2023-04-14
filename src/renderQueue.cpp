#include "renderQueue.h"

QueueVisualize rootQueue;

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

void createBoxQueue(RenderWindow &window) {
    Arrow arrow(0);
    arrow.create(Vector2f(600, 400), Vector2f(1400, 400));
    arrow.draw(window);
    arrow.create(Vector2f(600, 600), Vector2f(1400, 600));
    arrow.draw(window);
}

int Queue(RenderWindow &window) {
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
            peekProcess = 2;
            numTextBox = 0;
            break;
        case 33:
            input = displayTextBox(window, "Value", posEnqueueButton);
            break;
        case 34:
            popProcess = 2;
            numTextBox = 0;
            break;
    }

    Sprite *p_closeButton = nullptr, *p_randomButton = nullptr, *p_inputButton = nullptr;

    if (createProcess) createAnimationQueue(window, p_randomButton, p_inputButton);
    // Vector2f posSearchButton = Vector2f(100, 900);

    Sprite backButton = addSprite(window, "backButton.png", 150, 70, posBackButton, backButtonDark);     
    Sprite importButton = addSprite(window, "importButton.png", 90, 42, posImportButton, importButtonDark);
    Sprite createButton = addSprite(window, "createButton.png", 90, 42, posCreateButton, createButtonDark);
    Sprite peekButton = addSprite(window, "peekButton.png", 90, 42, posPeekButton, peekButtonDark);
    Sprite enqueueButton = addSprite(window, "enqueueButton.png", 90, 42, posEnqueueButton, enqueueButtonDark);
    Sprite dequeueButton = addSprite(window, "dequeueButton.png", 90, 42, posDequeueButton, dequeueButtonDark);

    createBoxQueue(window);

    rootQueue.clear();
    
    for (int i = 1; i <= 8; i++) 
        rootQueue.enqueue(i, font);

    rootQueue.draw(window);

    window.display();
    return statusQueue(window, backButton, importButton, createButton, peekButton, enqueueButton, dequeueButton, input, p_randomButton, p_inputButton, p_closeButton);
}