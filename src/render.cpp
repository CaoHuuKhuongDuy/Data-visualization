#include "render.h"

using namespace sf;



Sprite homePage(RenderWindow &window) {

    Texture t_background;
    t_background.loadFromFile("../media/img/homePage.jpg", IntRect(0, 0, 2500, 2500));
    t_background.setSmooth(true);
    Sprite background;
    background.setTexture(t_background);
    window.draw(background);

    Font f_title;
    f_title.loadFromFile("../media/font/arial.ttf");
    Text title;
    title.setFont(f_title);
    title.setString("Data Structure Visualization");
    title.setFillColor(Color::Black);
    title.setStyle(Text::Bold);
    title.setCharacterSize(50);
    title.setPosition(400, 20);
    window.draw(title);

    window.display();
    return background;
}
