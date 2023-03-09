#include "singlyLL.h"

SinglyLL::SinglyLL(int value, int idx) {
    nxt = nullptr;
    id = idx;
    data = value;
}

void SinglyLL::changePosition(Vector2f pos, Font &font) {
    position = pos;

    m_node.setPosition(pos);
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

void drawSGL(RenderWindow &window, SinglyLL *root) {
    while (root) {
        root->draw(window);
        if (root->nxt != nullptr) {
            Arrow arrow;
            arrow.create(root->position + Vector2f(30, 15), root->nxt->position + Vector2f(-10, 15));
            arrow.draw(window);
        }
        root = root->nxt;
    }
}