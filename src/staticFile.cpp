#include "staticFile.h"
#include <iostream>

int numNode = 5;
int insertIdx = -1, insertValue;
int updateIdx = -1, updateValue; 
int deleteIdx = -1;
int searchValue = -1;
int addProcess = 0;
int deleteProcess = 0; 
int searchProcess = 0;
int updateProcess = 0;
bool remake = true, secondTextBox = false;
bool displayNote = false;
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