#ifndef PROCESS_H
#define PROCESS_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"

using namespace sf;
using namespace std;


int statusHomePage(RenderWindow &window, Sprite linkList, Sprite Stack);

int statuslinkListPage(RenderWindow &window, Sprite sLinkList, Sprite dLinkList, Sprite cLinkList,
                       Sprite returnButton, bool &backButtonDark);


#endif