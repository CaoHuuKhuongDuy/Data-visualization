#ifndef highlight_h
#define highlight_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
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

void highlightPeekQueue(Highlight &highlight, int peekPos);
void highlightEnqueue(Highlight &highlight);
void highlightDequeue(Highlight &highlight);

void highlightAccessArray(Highlight &highlight);
void highlightAddArray(Highlight &highlight, bool statusArray);
void highlightDeleteArray(Highlight &highlight);
void highlightUpdateArray(Highlight &highlight);
void highlightSearchArray(Highlight &higlight, int correctStatus = -1);

#endif