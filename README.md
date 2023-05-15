# Data Visualization - Solo Project CSC10002 Documentation 
This is my solo project in the Programming Technique course, also known as CSC10002. Its content is to clone the website https://visualgo.net to present basic 
structures such as Linked List, Stack, Queue, Array.

In this project, I use SFML to create GUI. You can read more about SFML at here: https://www.sfml-dev.org/documentation/2.5.1

## Project Structure 
I have a total of 11 main header files and 4 header files to render each data structures, which are separated from "render.h". Additionally, there is 
a main file to call all of them. The workflow looks like this:


![workflow](https://github.com/CaoHuuKhuongDuy/Data-visualization/blob/main/media/img/workFlow_rm.png)

The functions in header files are defined in .cpp files with the same name. However, there are some functions in the .cpp files that are not declared in the header files because they are only used within the file itself. Therefore, I will list all the functions that exist in the .cpp files.

## process.h
This file is used to handle all events. 

| Function Name                 | Usage                                                                        |
|-------------------------------|------------------------------------------------------------------------------|
| `int statusHomePage()`        | Handle events from the Home Page scene.                                      |
| `int statuslinkListPage()`    | Handle events from the Linked List Home Page scene.                          |
| `int statusLinkList()`        | Handle events from the Linked List Visualization scene.                      |
| `int statusStack()`           | Handle events from the Stack Visualization scene.                            |
| `int statusQueue()`           | Handle events from the Queue Visualization scene.                            |
| `int statusArrayPage()`       | Handle events from the Array Home Page scene.                                |
| `int statusArray_SD()`        | Handle events from the Array Visualization scene.                            |
| `void initState()`            | Reinitialize some global variables when switching screens.                   |
| `void initPressState()`       | Reinitialize some global variables when clicking a button.                   |
| `bool hoverMouse()`           | Determine if the mouse is hovering over a sprite.                            |
| `bool Press()`                | Determine if a sprite has been clicked.                                      |


## linkedList.h
This file is used to handle various operations related to Linked List.
### Class SinglyLL
SinglyLL is a class that defines a node in a singly linked list, with method to modify the position, color, data,... of the node and draw it on a render window.
| Method Name                    | Usage                                                                                                   |
|-------------------------------- |---------------------------------------------------------------------------------------------------------|
| `SinglyLL(int, int, Font&)`   | Constructor to create a new node with the given value, index, and font.                                  |
| `void changePosition(Vector2f)`     | Method to update the position of the node.                                                         |
| `void changeColor(Color)`           | Method to update the color of the node.                                                            |
| `void changeRadius(double)`         | Method to update the radius of the node.                                                           |
| `void changeData(int)`               | Method to update the data of the node.                                                            |
| `void changeDes(string, bool = false)` | Method to update the description of the node.                                                   |
| `void draw(RenderWindow&)`           | Method to draw the node on the given RenderWindow.                                                |
| `bool rightPlace(Font&)`             | Method to check if the node is in the correct position according to the font.                     |
| `string getDes()`                     | Method to get the description of the node.                                                       |
| `Vector2f getCenter()`                | Method to get the center position of the node.                                                   |
| `SinglyLL *nxt`                       | Pointer to the next node in the list.                                                            |
| `int id`                               | Unique ID of the node.                                                                          |
| `int data`                             | Data value stored in the node.                                                                  |
| `Vector2f position`                    | Position of the node.                                                                           |
| `CircleShape m_node`                   | Circle shape object representing the node.                                                      |
| `Text m_text`                          | Text object representing the data value of the node.                                            |
| `Text description`                     | Text object representing the description of the node.                                           |

### Function

There are some functions that are called from renderLinkedList.cpp to process user request.

| Function signature                                      | Description                                                                                                     |
|---------------------------------------------------------|------------------------------------------------------------------------------------|
| `SinglyLL *createNode()`  | Creates a new SinglyLL node with the given value, index, position, and font.                                   |
| `void deleteLL()`          | Deletes all nodes in the SinglyLL linked list starting from the root node. Updates both root and tail pointers. |
| `void createLL()` | Creates a new SinglyLL linked list with the given number of nodes, values, and font. |
| `void drawReturnLine()` | Draws an arrow to indicate that the linked list is circular. |
| `void drawLL()` | Draws the SinglyLL linked list on the given window. |
| `void insertBefore()` | Inserts a new node with the given value and index before the root node. |
| `void deleteBefore()` | Deletes the node before the node with the given index. |
| `void changeIndex()` | Increases the index of all nodes starting from the given node. |
| `void insertLL()` | Inserts a new node with the given value and index into the SinglyLL linked list. |
| `void deleteNodeLL()` | Deletes the node with the given index from the SinglyLL linked list. |
| `bool format()` | Moving the nodes to their designated positions based (create the motion effect)|
| `void clearColorLL()`| Remove all effects from the nodes|
