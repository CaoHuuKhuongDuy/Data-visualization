#ifndef RENDER_H
#define RENDER_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "staticFile.h"
#include "process.h"
#include "arrow.h"
#include "singlyLL.h"

using namespace sf;
using namespace std;


void resizeSprite(Sprite &sprite, double height, double width);

int homePage(RenderWindow &window);

int linkListPage(RenderWindow &window);

int singleLinkList(RenderWindow &window);

#endif