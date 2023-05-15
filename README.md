# Data Visualization - Solo Project CSC10002 Documentation 
This is my solo project in the Programming Technique course, also known as CSC10002. Its content is to clone the website https://visualgo.net to present basic 
structures such as Linked List, Stack, Queue, Array.

In this project, I use SFML to create GUI. You can read more about SFML at here: https://www.sfml-dev.org/documentation/2.5.1

## Project Structure 
I have total 11 main header files and 4 header files to render each data structures, which are separated from "render.h". Additionally, there is 
a main file to call all of them. The workflow looks like this:


![workflow](https://github.com/CaoHuuKhuongDuy/Data-visualization/blob/main/media/img/workFlow_rm.png)

The functions in header files are defined in .cpp files with the same name. However, there are some functions in the .cpp files that are not declared in the header files because they are only used within the file itself. Therefore, I will list all the functions that exist in the .cpp files.

## process.h
This file is used to handle all events. 

| Function                                                                                                               | Usage                                                            |
|------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------|
| int statusHomePage(RenderWindow &window, Sprite linkList, Sprite Stack, Sprite Queue, Sprite Array);                   | Handle event from Home Page scene                                |
| int statuslinkListPage(RenderWindow &window, Sprite sLinkList, Sprite dLinkList, Sprite cLinkList, Sprite backButton); | Handle event from Linked List Home Page scene                    |
| int statusArrayPage(RenderWindow &window, Sprite staticArray, Sprite dynamicArray, Sprite backButton);                 | Handle event from Array Home Page scene                          |
| int statusLinkList(RenderWindow &window,..., Sprite *tailButton = nullptr, Sprite *specifyButton =  nullptr);          | Handle event from Linked List Visualization scene                |
| int statusStack(RenderWindow &window,...., Sprite *inputButton = nullptr, Sprite *closeButton = nullptr);              | Handle event from Stack Visualization scene                      |
| int statusQueue(RenderWindow &window,...., Sprite *peekFrontButton, Sprite *peekBackButton);                           | Handle event from Queue Visualization scene                      |
| int statusArray_SD(RenderWindow &window,..., Sprite *tailButton = nullptr, Sprite *specifyButton = nullptr);           | Handle event from Array Visualization scene                      |
| int initState(int state, int _numNode, int _maximumNode);                                                              | Reinitialize some global variables when switching screens        |
| void initPressState(int x, bool resetProcess = true);                                                                  | Reinitialize some global variables when clicking the button      |
| bool hoverMouse(Sprite sprite);                                                                                        | To determine if I am hovering the mouse over the "sprite" or not |
| bool Press(Sprite sprite);                                                                                             | To determine if I have clicked on the "sprite" or not            |
