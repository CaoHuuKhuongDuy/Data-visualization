#ifndef RENDER_H
#define RENDER_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "fileDialog.h"
#include "staticFile.h"
#include "highLight.h"
#include "process.h"
#include "arrow.h"
#include "singlyLL.h"
#include "Stack.h"
#include "Queue.h"
#include "array.h"

using namespace sf;
using namespace std;

extern Vector2f posBackButton;
extern bool firstTimeAdd;
extern int radiusAnimation;
extern Color orange;
extern Font font;
extern Texture t_submitButton;
extern textBox input;
extern SinglyLL *rootSGL, *cur, *oldP, *tailSGL;
extern StackVisualize rootStack;

extern Highlight highlight;

Sprite addSprite(RenderWindow &window, string fileName, double sz1, double sz2, Vector2f pos, bool dark = false, bool display = true);

void displayText(RenderWindow &window, string content, Vector2f pos, int sz, Color color = Color::Black, bool bold = true);

textBox displayTextBox(RenderWindow &window, string nameText, Vector2f pos);

void drawSpeedBox(RenderWindow &window);

void goAndColor(SinglyLL *&cur, string des = "", int specialData = -1);

void insertCode(RenderWindow &window, string fileName, Sprite *&p_closeButton);

void resizeSprite(Sprite &sprite, double height, double width);

int homePage(RenderWindow &window);

#endif