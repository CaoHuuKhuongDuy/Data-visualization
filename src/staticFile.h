#ifndef LOAD_STATICFILE_H
#define LOAD_STATICFILE_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

extern int valueNewNode[11];
extern bool backButtonDark, createButtonDark, addButtonDark, deleteButtonDark;
extern bool randomButtonDark, inputButtonDark;
extern bool updateButtonDark, searchButtonDark, displayNote;
extern int numTextBox, noTextBox, numNode, insertIdx, insertValue, searchValue, updateIdx, updateValue;
extern int createProcess, addProcess, deleteProcess, searchProcess, updateProcess; 
extern int deleteIdx;
extern bool remake;
extern string userText, notice;

extern int nameCodeId;
extern string nameCodeLL[20];

extern int numFrame, loopCodeStatus;

void initValueNode();
void resizeSprite(Sprite &sprite, double height, double width);
Texture loadTexture(Texture &texture, string fileName);


#endif