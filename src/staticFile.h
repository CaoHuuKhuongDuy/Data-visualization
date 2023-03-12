#ifndef LOAD_STATICFILE_H
#define LOAD_STATICFILE_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


extern bool backButtonDark, createButtonDark, addButtonDark, deleteButtonDark;
extern bool updateButtonDark, searchButtonDark, displayNote, secondTextBox;
extern int numTextBox, numNode, insertIdx, insertValue, searchValue, updateIdx, updateValue;
extern int addProcess, deleteProcess, searchProcess, updateProcess; 
extern int deleteIdx;
extern bool remake;
extern string userText, notice;


void resizeSprite(Sprite &sprite, double height, double width);
Texture loadTexture(Texture &texture, string fileName);


#endif