#include "queue.h"

Vector2f firstNodeQueue = {640, 425};

QueueVisualize::QueueVisualize() {
    l = 0;
}

void QueueVisualize::clear() {
    a.clear();
    t_val.clear();
    node.clear();
    numNode = 0;
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
    // node[r].setPosition
    node[r].setPosition(Vector2f(firstNodeQueue.x + (r - l) * 70, firstNodeQueue.y));
    // node[r].setPosition((Create ? Vector2f(firstNodeQueue.x, firstNodeQueue.y - (r - l) * 55) : Vector2f(490, 200)));

    t_val[r].setFont(font);
    t_val[r].setString(to_string(val));
    t_val[r].setCharacterSize(18);
    t_val[r].setStyle(Text::Bold);
    t_val[r].setFillColor(Color::Black);
    int justify = (val < 10 ? 6 : 0);
    t_val[r].setPosition(Vector2f(node[r].getPosition()) + Vector2f(15 + justify, 65));
}

void QueueVisualize::dequeue() {
    l++;
    numNode--;
}

void QueueVisualize::draw(RenderWindow &window) {
    for (int i = l; i < a.size(); i++) {
        window.draw(node[i]);
        window.draw(t_val[i]);
    }
}