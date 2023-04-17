#include "queue.h"

Vector2f firstNodeQueue = {640, 425};
Vector2f Left = {-1, 0};

const double epsilon = 1e-6;

QueueVisualize::QueueVisualize() {
    l = 0;
}

int QueueVisualize::size() {
    return (int)(a.size() - l);
}

void QueueVisualize::create(int n, int val[], Font &font) {
    clear();
    for (int i = 1; i <= n; i++)
        enqueue(val[i], font, true);
}

void QueueVisualize::enqueue(int val, Font &font, bool Create) {
    a.push_back(val);
    t_val.emplace_back();
    node.emplace_back();
    numNode++;

    int r = a.size() - 1;
    node[r].setSize(Vector2f(50, 150));
    node[r].setOutlineColor(Color::Black);
    node[r].setOutlineThickness(5);
    node[r].setFillColor(Color::Blue);
    node[r].setPosition(Vector2f(firstNodeQueue.x + (Create ? ((r - l) * 70) : 700), firstNodeQueue.y));

    t_val[r].setFont(font);
    t_val[r].setString(to_string(val));
    t_val[r].setCharacterSize(18);
    t_val[r].setStyle(Text::Bold);
    t_val[r].setFillColor(Color::Black);
    int justify = (val < 10 ? 6 : 0);
    t_val[r].setPosition(Vector2f(node[r].getPosition()) + Vector2f(15 + justify, 65));
}

void QueueVisualize::dequeue() {
    if (numNode == 0) return;
    numNode--;
    l++;
}

void QueueVisualize::clear() {
    a.clear();
    t_val.clear();
    node.clear();
    numNode = 0;
    l = 0;
}

void QueueVisualize::changeColor(Color color, int peekPos) {
    if (peekPos == 0) node[l].setFillColor(color);
    else node.back().setFillColor(color);
}

bool QueueVisualize::format(int type) {
    if (type == 1) {
        changePosition(l, Left * 3.f);
        for (int i = l + 1; i < a.size(); i++)
            changePosition(i, Left);
        return (node[l].getPosition().x != firstNodeQueue.x - 210);
    }
    int r = a.size() - 1;
    Vector2f pos = node[r].getPosition();
    pos = pos + Left * 5.f;
    pos.x = round(pos.x * 10.0f) / 10.0f;
    changePosition(r, pos, false);
    return (node[r].getPosition().x != firstNodeQueue.x + (r - l) * 70);
}

void QueueVisualize::changePosition(int id, Vector2f pos, bool status) {
    if (status) pos = node[id].getPosition() + pos;
    node[id].setPosition(pos);
    int justify = (a[id] < 10 ? 6 : 0);
    t_val[id].setPosition(Vector2f(node[id].getPosition()) + Vector2f(15 + justify, 65));
}

void QueueVisualize::draw(RenderWindow &window) {   
    for (int i = l; i < a.size(); i++) {
        window.draw(node[i]);
        window.draw(t_val[i]);
    }
}