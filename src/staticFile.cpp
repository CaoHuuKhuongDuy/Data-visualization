#include "staticFile.h"
#include <iostream>

int valueNewNode[11];
int numNode = 5;
int insertIdx = -1, insertValue;
int updateIdx = -1, updateValue; 
int deleteIdx = -1;
int searchValue = -1;
int createProcess = 1;
int peekProcess = 0;
int popProcess = 0;
int pushProcess = 0;
int addProcess = 0;
int deleteProcess = 0; 
int searchProcess = 0;
int dequeueProcess = 0;
int enqueueProcess = 0;
int updateProcess = 0;
int noTextBox = 0;
int maximumNode = 0;
bool displayNote = false;

int nameCodeId = 0;
string nameCodeLL[] = {"", "insertAtHeadS.png", "insertAtHeadD.png", "insertAtHeadC.png", "insertAtTailS.png", "insertAtTailD.png", 
    "insertAtTailC.png", "insertCodeSC.png", "insertCodeD.png", "deleteAtHeadS.png", "deleteAtHeadD.png", "deleteAtHeadC.png", "deleteAtTailSC.png",
    "deleteAtTailD.png", "deletingCodeSC.png", "deletingCodeD.png", "updatingCodeLL.png", "searchingCodeLL.png", "insertFirstNodeSD.png", "insertFirstNodeC.png"};
string nameCodeStack[] = {"", "peekCodeStack.png", "pushCodeStack.png", "popCodeStack.png"};


void initValueNode() {
    for (int i = 1; i <= 10; i++)
      valueNewNode[i] = rand() % 100;
}

void resizeSprite(Sprite &sprite, double height, double width) {
    
    Vector2f targetSize(height, width); 

    sprite.setScale(
        targetSize.x / sprite.getLocalBounds().width, 
        targetSize.y / sprite.getLocalBounds().height);
}


Texture loadTexture(Texture &texture, string fileName) {
    texture.loadFromFile(fileName);
    return texture;
}