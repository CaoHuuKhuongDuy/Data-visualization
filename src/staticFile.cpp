#include "staticFile.h"
#include <iostream>

int numNode = 5;
int insertIdx = -1, insertValue; 
bool remake = true;
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