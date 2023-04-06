#include "stack.h"

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
        push(val[i], font);
}

void StackVisualize::push(int val, Font &font) {
    a[++r] = val;
    numNode++;
    node[r].setSize(Vector2f(210, 50));
    node[r].setOutlineColor(Color::Black);
    node[r].setOutlineThickness(5);
    node[r].setFillColor(Color::Red);
    node[r].setPosition(Vector2f(784, 645 - (r - l) * 55));

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

void StackVisualize::changeColor(Color color) {
    node[r].setFillColor(color);
}

void StackVisualize::draw(RenderWindow &window) {
    for (int i = l; i <= r; i++) {
        window.draw(node[i]);
        window.draw(t_val[i]);
    }
}