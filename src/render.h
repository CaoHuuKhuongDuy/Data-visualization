#ifndef RENDER_H
#define RENDER_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

extern Font font;
extern Texture t_submitButton;

void loadStatic();

void resizeSprite(Sprite &sprite, double height, double width);

int homePage(RenderWindow &window);

int linkListPage(RenderWindow &window);

int singleLinkList(RenderWindow &window);

#endif