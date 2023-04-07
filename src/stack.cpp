#include "stack.h"


Vector2f Right = {7, 0};
Vector2f Down = {0, 5};




// 445 - x * 55

// 5 + 55 * x



Vector2f firstNode = {784, 645};

StackVisualize::StackVisualize() {
    l = 1;
    r = 0;
}

int StackVisualize::size() {
    return r - l + 1;
}



void StackVisualize::create(int n, int val[], Font &font) {
    numNode = 0;
    for (int i = 1; i <= n; i++) 
        push(val[i], font, true);
}

void StackVisualize::push(int val, Font &font, bool Create) {
    a[++r] = val;
    numNode++;
    node[r].setSize(Vector2f(210, 50));
    node[r].setOutlineColor(Color::Black);
    node[r].setOutlineThickness(5);
    node[r].setFillColor(Color::Red);
    node[r].setPosition((Create ? Vector2f(firstNode.x, firstNode.y - (r - l) * 55) : Vector2f(490, 200)));

    t_val[r].setFont(font);
    t_val[r].setString(to_string(val));
    t_val[r].setCharacterSize(18);
    t_val[r].setStyle(Text::Bold);
    t_val[r].setFillColor(Color::Black);
    int justify = (val < 10 ? 6 : 0);
    t_val[r].setPosition(Vector2f(node[r].getPosition()) + Vector2f(92 + justify, 15));
}

void StackVisualize::pop() {
    if (r == 0) return;
    numNode--;
    r--;
}

void StackVisualize::clear() {
    r = 0;
}

void StackVisualize::changePosition(Vector2f pos) {
    node[r].setPosition(pos);
    int justify = (a[r] < 10 ? 6 : 0);
    t_val[r].setPosition(pos + Vector2f(92 + justify, 15));
}

bool StackVisualize::format(int type) {
    Vector2f pos = node[r].getPosition();
    int formatProcess;
    if (type == 1) {
        if (pos.x != firstNode.x) formatProcess = 1;
        else if (pos.y != firstNode.y - (r - l) * 55) formatProcess = 2;
        else formatProcess = 3;
    }
    else {
        if (pos.y != 200) formatProcess = 2;
        else if (pos.x != 490) formatProcess = 1;
        else formatProcess = 3;
    }
    if (formatProcess == 1) {
        changePosition(pos + (Right * (float)type));
        // cout << node[r].getPosition().x << endl;
    }
    if (formatProcess == 2) changePosition(pos + Down * (float)type);
    return (formatProcess != 3);
}

void StackVisualize::changeColor(Color color) {
    node[r].setFillColor(color);
}

void StackVisualize::draw(RenderWindow &window) {
    for (int i = l; i <= r; i++) {
        window.draw(node[i]);
        window.draw(t_val[i]);
    }
}