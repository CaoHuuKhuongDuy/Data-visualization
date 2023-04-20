#include "array.h"

Vector2f firstNodeArray = {440, 425};
Color colorNode = {0, 170, 177};
Color colorDummyNode = {0, 170, 177, 50};
int sizeNode = 60;



ArrayVisualize::ArrayVisualize() {
    clear();
}

void ArrayVisualize::clear() {
    a.clear();
    node.clear();
    t_val.clear();
    idx.clear();
    capacity = r = numNode = 0;
}

bool ArrayVisualize::addMore() {
    return (vectorType || r < capacity);
}

void ArrayVisualize::changeStatus(bool statusArray) {
    vectorType = statusArray;
}

void ArrayVisualize::createNode(int id, int val, Font &font, bool dummy) {
    
    a[id] = val;
    node[id].setSize(Vector2f(sizeNode, sizeNode));
    node[id].setFillColor(dummy ? colorDummyNode : colorNode);
    node[id].setPosition(Vector2f(firstNodeArray.x + (sizeNode + 3) * id, firstNodeArray.y));
    
    t_val[id].setFont(font);
    t_val[id].setString(to_string(val));
    t_val[id].setCharacterSize(18);
    t_val[id].setStyle(Text::Bold);
    t_val[id].setFillColor(Color::White);
    t_val[id].setOutlineColor(Color::Black);
    int justify = (val < 10 ? 5 : -2);
    t_val[id].setPosition(Vector2f(node[id].getPosition()) + Vector2f(20 + justify, 20));

    idx[id].setFont(font);
    idx[id].setString(to_string(id));
    idx[id].setCharacterSize(18);
    idx[id].setStyle(Text::Bold);
    idx[id].setFillColor(Color::Black);
    idx[id].setOutlineColor(Color::Black);
    justify = (id < 10 ? 5 : -2);
    idx[id].setPosition(Vector2f(node[id].getPosition()) + Vector2f(20 + justify, 80));
}

void ArrayVisualize::resize(int oldCap, Font &font) {
    capacity = max(1, min(maximumNode, oldCap * 2));
    a.resize(capacity);
    node.resize(capacity);
    t_val.resize(capacity);
    idx.resize(capacity);
    for (int i = r; i < capacity; i++) 
        createNode(i, 0, font, true);
}

void ArrayVisualize::create(int n, int val[], Font &font) {
    clear();
    capacity = n;
    for (int i = 1; i <= n; i++)
        add(val[i], font);
}


void ArrayVisualize::add(int val, Font &font) {
    if (!addMore()) return;
    r++;
    a.push_back(val);
    node.emplace_back();
    t_val.emplace_back();
    idx.emplace_back();
    numNode++;

    createNode(r - 1, val, font);

    if (r > capacity) resize(capacity, font);
}

void ArrayVisualize::changeColor(Color color, int idx) {
    node[idx].setFillColor(color);
}

void ArrayVisualize::changeData(int idx, int val) {
    a[idx] = val;
    t_val[idx].setString(to_string(a[idx]));
    int justify = (a[idx] < 10 ? 5 : -2);
    t_val[idx].setPosition(Vector2f(node[idx].getPosition()) + Vector2f(20 + justify, 20));
}

void ArrayVisualize::copyData(int idx1, int idx2) {
    changeData(idx1, a[idx2]);
}


int ArrayVisualize::getData(int idx) {
    return (idx >= capacity ? 0 : a[idx]);
}

void ArrayVisualize::del() {
    node[numNode - 1].setFillColor(colorDummyNode);
    numNode--;
    r--;
}

bool ArrayVisualize::draw(RenderWindow &window) {
    for (int i = 0; i < capacity; i++) {
        window.draw(node[i]);
        window.draw(t_val[i]);
        window.draw(idx[i]);
    }
    return (capacity != 0); 
}
