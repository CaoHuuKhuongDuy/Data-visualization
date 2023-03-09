#include "singlyLL.h"

Vector2f upStep = Vector2f(0, -0.75);
Vector2f straightStep = Vector2f(1, 0);


// right place (120 + 120 * id, 200)

SinglyLL::SinglyLL(int value, int idx) {
    nxt = nullptr;
    id = idx;
    data = value;
}

void SinglyLL::changePosition(Vector2f pos, Font &font) {
    position = pos;

    m_node.setPosition(pos);
    // m_node.setOrigin({-5, 20});
    m_node.setRadius(14);
    m_node.setOutlineColor(Color::Black);
    m_node.setOutlineThickness(3);

    m_text.setFont(font);
    m_text.setString(to_string(data));
    m_text.setCharacterSize(18);
    m_text.setStyle(Text::Bold);
    m_text.setFillColor(Color::Black);
    Vector2f justify = (data < 10 ? Vector2f(8, 4) : Vector2f(3, 4));
    m_text.setPosition(pos + justify);
}

void SinglyLL::rightPlace(Font &font) {
    if (position.x != 120 + 120 * id) changePosition(position + straightStep, font);
    else if (position.y != 200) changePosition(position + upStep, font);
}

void SinglyLL::draw(RenderWindow &window) {
    window.draw(m_node);
    window.draw(m_text);
}

SinglyLL *createNode(int value, int idx, Vector2f pos, Font &font) {
    SinglyLL *cur = new SinglyLL(value, idx);
    cur->changePosition(pos, font);
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

void createLL(SinglyLL *&root, int numNode, Font &font) {
    srand(time(nullptr));
    int cnt = 1;
    SinglyLL *cur = root;
    while (cnt <= numNode) {
        SinglyLL *tmp = createNode(rand() % 100, cnt, Vector2f(120 + 120 * cnt, 200), font);
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

void incIndex(SinglyLL *cur) {
    while (cur) {
        cur->id++;
        cur = cur->nxt;
    }
}

void insertLL(SinglyLL *&root, int value, int idx, int &numNode, Font &font) {
    numNode++;
    if (idx == 1) {
        insertBefore(root, value, idx, font, (numNode == idx));
        incIndex(root->nxt);
        return;
    }
    SinglyLL *cur = root;
    while (cur && cur->id != idx - 1) cur = cur->nxt;
    insertBefore(cur->nxt, value, idx, font, (numNode == idx));
    incIndex(cur->nxt->nxt);
}

void format(SinglyLL *cur, Font &font) {
    while (cur) {
        cur->rightPlace(font);
        cur = cur->nxt;
    }
}
