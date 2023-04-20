#ifndef LOAD_STATICFILE_H
#define LOAD_STATICFILE_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

extern int valueNewNode[30], maximumNode;
extern bool backButtonDark, createButtonDark, addButtonDark, deleteButtonDark, canAdd;
extern bool randomButtonDark, inputButtonDark, peekFrontDark, peekBackDark;
extern bool importButtonDark, peekButtonDark, pushButtonDark, popButtonDark;
extern bool enqueueButtonDark, dequeueButtonDark, accessButtonDark;
extern bool updateButtonDark, searchButtonDark, displayNote;
extern int numTextBox, noTextBox, numNode, insertIdx, insertValue, searchValue, updateIdx, accessIndex, updateValue;
extern int createProcess, addProcess, deleteProcess, searchProcess, updateProcess; 
extern int peekProcess, popProcess, pushProcess, enqueueProcess, dequeueProcess, accessProcess;
extern int deleteIdx;
extern bool remake;
extern string userText, notice;
extern bool statusArray;

extern int nameCodeId;
extern string nameCodeLL[];
extern string nameCodeStack[];
extern string nameCodeQueue[];

extern int numFrame, loopCodeStatus;
extern bool insert_at_end, delete_at_end;
extern int styleLL;

void initValueNode();
void resizeSprite(Sprite &sprite, double height, double width);
Texture loadTexture(Texture &texture, string fileName);


#endif