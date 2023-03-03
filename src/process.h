#ifndef PROCESS_H
#define PROCESS_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
// #include "node.h"

using namespace sf;
using namespace std;


int statusHomePage(RenderWindow &window, Sprite linkList, Sprite Stack);

int statuslinkListPage(RenderWindow &window, Sprite sLinkList, Sprite dLinkList, Sprite cLinkList,
                       Sprite backButton, bool &backButtonDark);

int statusSingleLinkList(RenderWindow &window, Sprite backButton, bool &backButtonDark, Sprite createButton,
                        bool &createButtonDark, Sprite addButton, bool &addButtonDark, Sprite deleteButton, bool &deleteButtonDark,
                        Sprite updateButton, bool &updateButtonDark, Sprite searchButton, bool &searchButtonDark);

#endif