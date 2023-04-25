#include "stack.h"


Vector2f Right[3] = {Vector2f(3, 0), Vector2f(7, 0), Vector2f(14, 0)};
Vector2f Down[3] = {Vector2f(0, 2), Vector2f(0, 5), Vector2f(0, 8)};




// 445 - x * 55

// 5 + 55 * x



Vector2f firstNodeStack = {834, 645};

StackVisualize::StackVisualize() {
    l = 1;
    r = 0;
}

int StackVisualize::size() {
    return r - l + 1;
}



void StackVisualize::create(int n, int val[], Font &font) {
    clear();
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
    node[r].setPosition((Create ? Vector2f(firstNodeStack.x, firstNodeStack.y - (r - l) * 55) : Vector2f(540, 200)));

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
    numNode = 0;
}

void StackVisualize::changePosition(Vector2f pos) {
    node[r].setPosition(pos);
    int justify = (a[r] < 10 ? 6 : 0);
    t_val[r].setPosition(pos + Vector2f(92 + justify, 15));
}

int StackVisualize::format(int type) {
    if (r == 0) return 3;
    Vector2f pos = node[r].getPosition();
    int formatProcess;
    if (type == 1) {
        if (pos.x != firstNodeStack.x) formatProcess = 1;
        else if (pos.y != firstNodeStack.y - (r - l) * 55) formatProcess = 2;
        else formatProcess = 3;
    }
    else {
        if (pos.y != 200) formatProcess = 2;
        else if (pos.x != 540 && pos.x != 1128) formatProcess = 1;
        else formatProcess = 3;
    }
    if (formatProcess == 1) {
        Vector2f newPos = pos + Right[speed];
        newPos.x = min((int)newPos.x, (type == 1 ? (int)firstNodeStack.x : 1128));
        changePosition(newPos);
    }
    if (formatProcess == 2) {
        Vector2f newPos = pos + Down[speed] * (float)type;
        if (type == 1) newPos.y = min((int)newPos.y, (int)firstNodeStack.y - (r - l) * 55);
        else newPos.y = max((int)newPos.y, 200);
        changePosition(newPos);
    }
    return formatProcess;
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