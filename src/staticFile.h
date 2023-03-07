#ifndef LOAD_STATICFILE_H
#define LOAD_STATICFILE_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


extern bool backButtonDark, createButtonDark, addButtonDark, deleteButtonDark;
extern bool updateButtonDark, searchButtonDark, displayNote;
extern int numTextBox, numNode;
extern string userText;

void resizeSprite(Sprite &sprite, double height, double width);
Texture loadTexture(Texture &texture, string fileName);


#endif