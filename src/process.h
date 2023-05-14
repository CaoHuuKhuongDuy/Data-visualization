#ifndef PROCESS_H
#define PROCESS_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "staticFile.h"
#include "textBox.h"

using namespace sf;
using namespace std;


int statusHomePage(RenderWindow &window, Sprite linkList, Sprite Stack, Sprite Queue, Sprite Array);

int statuslinkListPage(RenderWindow &window, Sprite sLinkList, Sprite dLinkList, Sprite cLinkList, Sprite backButton);


int statusLinkList(RenderWindow &window, Sprite backButton, Sprite importButton, Sprite createButton, Sprite addButton, 
                  Sprite deleteButton, Sprite updateButton, Sprite searchButton, textBox &input, int originState, 
                  Sprite *randomButton = nullptr, Sprite *inputButton = nullptr, Sprite *closeButton = nullptr, 
                  Sprite *headButton = nullptr, Sprite *tailButton = nullptr, Sprite *specifyButton =  nullptr);


int statusStack(RenderWindow &window, Sprite backButton, Sprite importButton, Sprite createButton, Sprite peekButton,
                Sprite pushButton, Sprite popButton, textBox &input, Sprite *randomButton = nullptr, 
                Sprite *inputButton = nullptr, Sprite *closeButton = nullptr);


int statusQueue(RenderWindow &window, Sprite backButton, Sprite importButton, Sprite createButton, Sprite peekButton,
                Sprite enqueueButton, Sprite dequeueButton, textBox &input, Sprite *randomButton, 
                Sprite *inputButton, Sprite *closeButton, Sprite *peekFrontButton, Sprite *peekBackButton);

int statusArrayPage(RenderWindow &window, Sprite staticArray, Sprite dynamicArray, Sprite backButton);

int statusArray_SD(RenderWindow &window, Sprite backButton, Sprite importButton, Sprite createButton, Sprite accessButton, 
                    Sprite addButton, Sprite deleteButton, Sprite updateButton, Sprite searchButton, textBox &input, 
                    Sprite *randomButton = nullptr, Sprite *inputButton = nullptr, Sprite *closeButton = nullptr, 
                    Sprite *headButton = nullptr, Sprite *tailButton = nullptr, Sprite *specifyButton = nullptr);


#endif