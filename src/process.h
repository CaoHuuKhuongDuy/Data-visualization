#ifndef PROCESS_H
#define PROCESS_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "staticFile.h"
#include "textBox.h"

using namespace sf;
using namespace std;


int statusHomePage(RenderWindow &window, Sprite linkList, Sprite Stack);

int statuslinkListPage(RenderWindow &window, Sprite sLinkList, Sprite dLinkList, Sprite cLinkList,
                       Sprite backButton);


int statusSingleLinkList(RenderWindow &window, Sprite backButton, Sprite createButton, Sprite addButton, 
                        Sprite deleteButton, Sprite updateButton, Sprite searchButton, textBox &input);

#endif