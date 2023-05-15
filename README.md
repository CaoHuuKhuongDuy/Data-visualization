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
| Method Name                            | Usage                                                                                      |
|--------------------------------------- |--------------------------------------------------------------------------------------------|
| `SinglyLL(int, int, Font&)`            | Constructor to create a new node with the given value, index, and fon                      |
| `void changePosition(Vector2f)`        | Method to update the position of the node.                                                 |
| `void changeColor(Color)`              | Method to update the color of the node.                                                    |
| `void changeRadius(double)`            | Method to update the radius of the node.                                                   |
| `void changeData(int)`                 | Method to update the data of the node.                                                     |
| `void changeDes(string, bool = false)` | Method to update the description of the node.                                              |
| `void draw(RenderWindow&)`             | Method to draw the node on the given RenderWindow.                                         |
| `bool rightPlace(Font&)`               | Method to check if the node is in the correct position according to the font.              |
| `string getDes()`                      | Method to get the description of the node.                                                 |
| `Vector2f getCenter()`                 | Method to get the center position of the node.                                             |

| Property                              | Usage
----------------------------------------|-------------------------------------------------------------------------------------------------|
| `SinglyLL *nxt`                       | Pointer to the next node in the list.                                                           |
| `int id`                              | Unique ID of the node.                                                                          |
| `int data`                            | Data value stored in the node.                                                                  |
| `Vector2f position`                   | Position of the node.                                                                           |
| `CircleShape m_node`                  | Circle shape object representing the node.                                                      |
| `Text m_text`                         | Text object representing the data value of the node.                                            |
| `Text description`                    | Text object representing the description of the node.                                           |

### Function

There are some functions that are called from renderLinkedList.cpp to process user request.

| Function signature                      | Description                                                                                                     |
|-----------------------------------------|-----------------------------------------------------------------------------------------------------------------|
| `SinglyLL *createNode()`                | Creates a new SinglyLL node with the given value, index, position, and font.                                    |
| `void deleteLL()`                       | Deletes all nodes in the SinglyLL linked list starting from the root node. Updates both root and tail pointers. |
| `void createLL()`                       | Creates a new SinglyLL linked list with the given number of nodes, values, and font.                            |
| `void drawReturnLine()`                 | Draws an arrow to indicate that the linked list is circular.                                                    |
| `void drawLL()`                         | Draws the SinglyLL linked list on the given window.                                                             |
| `void insertBefore()`                   | Inserts a new node with the given value and index before the root node.                                         |
| `void deleteBefore()`                   | Deletes the node before the node with the given index.                                                          |
| `void changeIndex()`                    | Increases the index of all nodes starting from the given node.                                                  |
| `void insertLL()`                       | Inserts a new node with the given value and index into the SinglyLL linked list.                                |
| `void deleteNodeLL()`                   | Deletes the node with the given index from the SinglyLL linked list.                                            |
| `bool format()`                         | Moving the nodes to their designated positions based (create the motion effect)                                 |
| `void clearColorLL()`                   | Remove all effects from the nodes                                                                               |

## stack.h
This file is used to handle various operations related to Stack.
### Class StackVisualize 
The StackVisualize class provides functionality to visualize and manipulate a stack data structure.

| Method                                              | Usage                                                 |
|-----------------------------------------------------|-------------------------------------------------------|
| `int size()`                                        | Returns the size of the stack                         |
| `void create(int n, int val[], Font &font)`         | Creates the stack with specified size and values      |
| `void push(int x, Font &font, bool Create = false)` | Pushes an element onto the stack                      |
| `void pop()`                                        | Pops the top element from the stack                   |
| `void clear()`                                      | Clears the stack                                      |
| `void changeColor(Color color)`                     | Changes the color of the stack visualization          |
| `int format(int type = 1)`                          | Formats the visualization style of the stack          |
| `void changePosition(Vector2f pos)`                 | Changes the position of the stack visualization       |
| `void draw(RenderWindow &window)`                   | Draws the stack visualization on the specified window |

| Property                    | Usage                                                      |
|-----------------------------|------------------------------------------------------------|
| `RectangleShape node[12]`   | Array of RectangleShape objects representing stack nodes   |
| `Text t_val[12]`            | Array of Text objects representing node values             |
| `int l`                     | Integer variable representing the left index of the stack  |
| `int r`                     | Integer variable representing the right index of the stack |
| `int a[12]`                 | Array of integers representing the stack elements          |

## queue.h
This file is used to handle various operation related to Queue.
### Class QueueVisualize
The QueueVisualize class provides functionality to visualize and manipulate a queue data structure.
| Method                                                            | Usage                                                     |
|-------------------------------------------------------------------|-----------------------------------------------------------|
| `QueueVisualize()`                                                | Constructor for creating a `QueueVisualize` object        |
| `int size()`                                                      | Returns the size of the queue                             |
| `void create(int n, int val[], Font &font)`                       | Creates the queue with specified size and values          |
| `void enqueue(int val, Font &font, bool Create = false)`          | Adds an element to the back of the queue                  |
| `void dequeue()`                                                  | Removes the front element from the queue                  |
| `void clear()`                                                    | Clears the queue                                          |
| `void changeColor(Color color, int peekPos)`                      | Changes the color of the queue visualization              |
| `bool format(int type = 1)`                                       | Formats the visualization style of the queue              |
| `void changePosition(int id, Vector2f pos, bool status = true)`   | Changes the position of a node in the queue               |
| `void draw(RenderWindow &window)`                                 | Draws the queue visualization on the specified window     |

|Property                                                           |                                                           |
|-------------------------------------------------------------------|-----------------------------------------------------------|
| `int l`                                                           | Integer variable representing the left index of the queue |
| `vector<int> a`                                                   | Vector of integers representing the queue elements        |
| `vector<Text> t_val`                                              | Vector of Text objects representing node values           |
| `vector<RectangleShape> node`                                     | Vector of RectangleShape objects representing queue nodes |
## array.h
This file is used to handle various operation related to Array (static and dynamic).
### Class ArrayVisualize 
The ArrayVisualize class facilitates visualizing and manipulating arrays, offering functionality for adding, deleting, resizing, and modifying element values.
| Method                                                             | Usage                                                           |
|--------------------------------------------------------------------|-----------------------------------------------------------------|
| `ArrayVisualize()`                                                 | Constructor for creating an `ArrayVisualize` object             |
| `void clear()`                                                     | Clears the array                                                |
| `void create(int n, int val[], Font &font)`                        | Creates the array with specified size and values                |
| `void createNode(int id, int val, Font &font, bool dummy = false)` | Creates a node in the array with the specified ID and value     |
| `void resize(int n, Font &font)`                                   | Resizes the array to the specified size                         |
| `void add(int x, Font &font)`                                      | Adds an element to the array                                    |
| `void changeColor(Color color, int idx)`                           | Changes the color of the array element at the specified index   |
| `void changeData(int id, int val)`                                 | Changes the value of the array element with the specified ID    |
| `void copyData(int idx1, int idx2)`                                | Copies the value from one array element to another              |
| `void changeStatus(bool statusArray)`                              | Changes the status of the array                                 |
| `bool addMore()`                                                   | Checks if more elements can be added to the array               |
| `bool full()`                                                      | Checks if the array is full                                     |
| `int getData(int idx)`                                             | Returns the value of the array element at the specified index   |
| `void del()`                                                       | Deletes an element from the array                               |
| `bool draw(RenderWindow &window)`                                  | Draws the array visualization on the specified window           |

| Property                            | Usage                                                                       |
|-------------------------------------|-----------------------------------------------------------------------------|
| `vector<int> a`                     | Vector of integers representing the array elements                          |
| `vector<RectangleShape> node`       | Vector of RectangleShape objects representing array nodes                   |
| `vector<Text> t_val, idx`           | Vectors of Text objects representing node values and indices                |
| `int r`                             | Integer variable representing the right index of the array                  |
| `int capacity`                      | Integer variable representing the capacity of the array                     |
| `bool vectorType`                   | Boolean variable indicating the type of vector used for array visualization |


