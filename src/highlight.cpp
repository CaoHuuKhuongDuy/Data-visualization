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
    if (nameCodeId == 18 || nameCodeId == 19) {
        highlight.makeHighlight(numFrame);
        return;
    }
    if (nameCodeId <= 3) {
        if (nameCodeId != 2) highlight.makeHighlight((numFrame + 10) / 11);
        else highlight.makeHighlight((numFrame + 7) /8);
        return;
    }
    if (nameCodeId <= 6) {
        highlight.makeHighlight(numFrame);
        return;
    } 
    if (highLightLoop(highlight)) return;
    if (numFrame - insertIdx <= 8) highlight.makeHighlight(4);
    else if (numFrame - insertIdx <= 16) highlight.makeHighlight(5);
    else if (numFrame - insertIdx <= 24) highlight.makeHighlight(6);
    else highlight.makeHighlight(7);
}

void highlightDeleteCode(Highlight &highlight) {
    if (nameCodeId <= 11) {
        if (delete_at_end) {
            if (numFrame <= 3) highlight.makeHighlight(1);
            else if (numFrame <= 5) highlight.makeHighlight(2);
            else highlight.makeHighlight(3);
            return;
        }
        if (styleLL != 2) highlight.makeHighlight(min(3, (numFrame + 9) / 10));
        else highlight.makeHighlight(min(4, (numFrame + 8) / 9));
        return;
    }
    if (nameCodeId == 13) {
        if (numFrame <= 2) highlight.makeHighlight(1);
        else if (numFrame <= 3) highlight.makeHighlight(2);
        else if (numFrame <= 5) highlight.makeHighlight(3);
        else highlight.makeHighlight(4);
        return;
    }
    if (highLightLoop(highlight)) return;
    if (delete_at_end) {
        if (numFrame - deleteIdx <= 2) highlight.makeHighlight(4);
        else if (numFrame - deleteIdx <= 5) highlight.makeHighlight(5);
        else highlight.makeHighlight(6);
    }
    else if (numFrame - deleteIdx <= 20) highlight.makeHighlight(4);
    else if (numFrame - deleteIdx <= 30) highlight.makeHighlight(5);
    else highlight.makeHighlight(6);
}

void highlightUpdateCode(Highlight &highlight) {
    if (nameCodeId == 20) {
        highlight.makeHighlight(1);
        return;
    }
    if (highLightLoop(highlight)) return;
    highlight.makeHighlight(4);
}

void highlightSearchCode(Highlight &highlight) {
    if (highLightLoop(highlight)) return;
    highlight.makeHighlight(loopCodeStatus);
}


void highlightPeekCode(Highlight &highlight) {
    highlight.makeHighlight((numNode != 0) + 1);
}

void highlightPushCode(Highlight &highlight) {
    int maxFrame = 132 - 11 * (numNode - 1);
    if (numFrame <= 43) highlight.makeHighlight(1);
    else if (maxFrame - numFrame > 2) highlight.makeHighlight(2);
    else highlight.makeHighlight(3);
}

void highlightPopCode(Highlight &highlight) {
    int maxFrame = 133 - 11 * (numNode - 1);
    if (numNode == 0) {
        highlight.makeHighlight(1);
        return;
    }
    if (maxFrame - numFrame > 40) highlight.makeHighlight(2);
    else if (maxFrame - numFrame > 2) highlight.makeHighlight(3);
    else highlight.makeHighlight(4);
}

void highlightPeekQueue(Highlight &highlight, int peekPos) {
    if (numNode == 0) highlight.makeHighlight(1);
    else highlight.makeHighlight(2);
}

void highlightEnqueue(Highlight &highlight) {
    int maxFrame = 44 + 14 * (8 - numNode);
    if (numFrame == 1) highlight.makeHighlight(1);
    else if (maxFrame - numFrame <= 5) highlight.makeHighlight(3);
    else highlight.makeHighlight(2);
}

void highlightDequeue(Highlight &highlight) {
    if (numNode == 0) {
        highlight.makeHighlight(1);
        return;
    }
    if (numFrame <= 20) highlight.makeHighlight(2);
    else if (numFrame <= 65) highlight.makeHighlight(3);
    else highlight.makeHighlight(4);
}