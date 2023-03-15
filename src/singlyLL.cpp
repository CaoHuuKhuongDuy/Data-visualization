#include "singlyLL.h"

Vector2f upStep = Vector2f(0, -2.8125);
Vector2f straightStep = Vector2f(3.75, 0);


// right place (120 + 120 * id, 200)

SinglyLL::SinglyLL(int value, int idx, Font &font) {
    nxt = nullptr;
    id = idx;
    data = value;
    
    m_node.setRadius(14);
    m_node.setOutlineColor(Color::Black);
    m_node.setOutlineThickness(3);
    m_node.setFillColor(Color::White);

    m_text.setFont(font);
    m_text.setString(to_string(data));
    m_text.setCharacterSize(18);
    m_text.setStyle(Text::Bold);
    m_text.setFillColor(Color::Black);
}

void SinglyLL::changePosition(Vector2f pos) {
    position = pos;

    m_node.setPosition(pos);
    // m_node.setOrigin(pos);

    Vector2f justify = (data < 10 ? Vector2f(8, 4) : Vector2f(3, 4));
    m_text.setPosition(pos + justify);
}

void SinglyLL::changeRadius(double radius) {
    m_node.setRadius(radius);
    m_text.setCharacterSize(radius * 1.2);
}


void SinglyLL::changeColor(Color color) {
    m_node.setFillColor(color);
}

void SinglyLL::changeData(int x) {
    data = x;
    m_text.setString(to_string(data));
    Vector2f justify = (data < 10 ? Vector2f(8, 4) : Vector2f(3, 4));
    m_text.setPosition(m_node.getPosition() + justify);
}

bool SinglyLL::rightPlace(Font &font) {
    if (position.x == 120 + 120 * id && position.y == 200) return false;
    float tmp = 1.f;
    if (position.x > 120 + 120 * id) tmp = -1.f;
    if (position.x != 120 + 120 * id) changePosition(position + (straightStep * tmp));
    else changePosition(position + upStep);
    return true;
}

void SinglyLL::draw(RenderWindow &window) {
    window.draw(m_node);
    window.draw(m_text);
}

SinglyLL *createNode(int value, int idx, Vector2f pos, Font &font) {
    SinglyLL *cur = new SinglyLL(value, idx, font);
    cur->changePosition(pos);
    return cur;
}

void deleteLL(SinglyLL *&root) {
    while (root) {
        SinglyLL *tmp = root;
        root = root->nxt;
        delete tmp;
    }
    root = nullptr;
}

void createLL(SinglyLL *&root, int numNode, int valueNewNode[], Font &font) {
    srand(time(nullptr));
    int cnt = 1;
    SinglyLL *cur = root;
    while (cnt <= numNode) {
        SinglyLL *tmp = createNode(valueNewNode[cnt], cnt, Vector2f(120 + 120 * cnt, 200), font);
        if (cnt == 1) {
            root = tmp;
            cur = root;
        }
        else {
            cur->nxt = tmp;
            cur = cur->nxt;
        }
        cnt++;
    }
}

Vector2f SinglyLL::getCenter() {
    return m_node.getOrigin();
}

void drawSGL(RenderWindow &window, SinglyLL *root) {
    while (root) {
        if (root->nxt != nullptr) {
            Arrow arrow;
            Vector2f pointInc = Vector2f(15, 15);
            Vector2f p1 = root->position + pointInc;
            Vector2f p2 = root->nxt->position + pointInc;            
            arrow.create(p1, p2);
            arrow.draw(window);
        }
        root->draw(window);
        root = root->nxt;
    }
}

void insertBefore(SinglyLL *&root, int value, int idx, Font &font, bool last) {
    SinglyLL *tmp = createNode(value, idx, Vector2f(120 + 120 * idx, (last ? 200 : 290)), font);
    tmp->nxt = root;
    root = tmp;
}

void deleteBefore(SinglyLL *&root, int idx) {
    SinglyLL *tmp = root;
    root = root->nxt;
    delete tmp;
}

void changeIndex(SinglyLL *cur, int val = 1) {
    while (cur) {
        cur->id += val;
        cur = cur->nxt;
    }
}

void insertLL(SinglyLL *&root, int value, int idx, int &numNode, Font &font) {
    numNode++;
    if (idx == 1) {
        insertBefore(root, value, idx, font, (numNode == idx));
        changeIndex(root->nxt);
        return;
    }
    SinglyLL *cur = root;
    while (cur && cur->id != idx - 1) cur = cur->nxt;
    insertBefore(cur->nxt, value, idx, font, (numNode == idx));
    changeIndex(cur->nxt->nxt);
}

void deleteNodeLL(SinglyLL *&root, int idx, int &numNode) {
    numNode--;
    if (idx == 1) {
        deleteBefore(root, idx);
        changeIndex(root, -1);
        return;
    }
    SinglyLL *cur = root;
    while (cur && cur->id != idx - 1) cur = cur->nxt;
    deleteBefore(cur->nxt, idx);
    changeIndex(cur->nxt, -1);
}

bool format(SinglyLL *cur, Font &font, bool insert_at_end) {
    int tmp = 0;
    while (cur) {
        if (insert_at_end && !cur->nxt) {
            cur->changeColor(Color::Green);
        }
        tmp += (cur->rightPlace(font));
        if (tmp == 1) cur->changeColor(Color::Green);
        if (tmp == 2) cur->changeColor(Color::Blue);
        cur = cur->nxt;
    }
    return (tmp);
}


void clearColorLL(SinglyLL *cur) {
    while (cur) {
        cur->changeColor(Color::White);
        cur = cur->nxt;
    }
    usleep(1000000);
}