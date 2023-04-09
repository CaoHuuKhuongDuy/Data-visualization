#ifndef highlight_h
#define highlight_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include "staticFile.h"
using namespace std;
using namespace sf;

class Highlight {
    public:
        Highlight();
        void makeHighlight(int Line, Color color = Color(255, 255, 0, 150));
        void line(int x);
        void draw(RenderWindow &window);
        bool display;
    private:
        RectangleShape highLight;
};

void highlightInsertCode(Highlight &highlight);
void highlightDeleteCode(Highlight &highlight);
void highlightUpdateCode(Highlight &highlight);
void highlightSearchCode(Highlight &highlight);

void highlightPeekCode(Highlight &highlight);
void highlightPushCode(Highlight &highlight);
void highlightPopCode(Highlight &highlight);

#endif