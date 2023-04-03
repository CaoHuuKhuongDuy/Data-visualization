#include "highLight.h"

Highlight::Highlight() {
    display = false;
}

void Highlight::makeHighlight(int Line, Color color) {
    display = true;
    highLight.setSize(sf::Vector2f(480, 35));
    highLight.setFillColor(color);
    line(Line);
}

void Highlight::line(int x) {
    highLight.setPosition(1400, 714 + (x - 1) * 42);
}

void Highlight::draw(RenderWindow &window) {
    if (display) window.draw(highLight);
}


bool highLightLoop(Highlight &highlight) {
    if (numFrame != 1 && loopCodeStatus != 0 && loopCodeStatus != 1) return false;
    if (numFrame == 1 && loopCodeStatus == -1) highlight.makeHighlight(1);
    else if (loopCodeStatus != -1) highlight.makeHighlight(loopCodeStatus == 1 ? 2 : 3);
    return true;
}

void highlightInsertCode(Highlight &highlight) {
    if (nameCodeId == 1) {
        if (numFrame <= 11) highlight.makeHighlight(1);
        else if (numFrame <= 22) highlight.makeHighlight(2);
        else highlight.makeHighlight(3);
        if (numFrame == 33) highlight.display = false;
        return;
    }
    if (highLightLoop(highlight)) return;
    if (numFrame - insertIdx <= 8) highlight.makeHighlight(4);
    else if (numFrame - insertIdx <= 16) highlight.makeHighlight(5);
    else if (numFrame - insertIdx <= 24) highlight.makeHighlight(6);
    else highlight.makeHighlight(7);
}

void highlightUpdateCode(Highlight &highlight) {
    if (highLightLoop(highlight)) return;
    highlight.makeHighlight(4);
}

void highlightSearchCode(Highlight &highlight) {
    if (highLightLoop(highlight)) return;
    cout << loopCodeStatus << endl;
    highlight.makeHighlight(loopCodeStatus);
}