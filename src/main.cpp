#include "render.h"

const int height = 1400;
const int width = 780;


RenderWindow window(VideoMode(height, width), "Data visualization", Style::Default);



int main() {

    int status = 0;
    // loadFont();
    while (window.isOpen()) {
        
        // Sprite sprite;
        // status = homePage(window);
        status = singleLinkList(window);
        continue;
        switch (status) {
            case -1: return EXIT_SUCCESS;
            case 0: 
                status = homePage(window);
                break;
            case 1:
                status = linkListPage(window);
                break; 
            case 11:
                status = singleLinkList(window);
                break; 
            default: 
                status = 0;
                break;
        }
        window.clear();
    }


    return EXIT_SUCCESS;
}


// #include <SFML/Graphics.hpp>
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "Line Example");

//     sf::VertexArray line(sf::Quads, 4); // create a vertex array with 4 points

//     sf::Vector2f point1(100.f, 100.f); // set the starting point of the line segment
//     sf::Vector2f point2(300.f, 300.f); // set the ending point of the line segment
//     sf::Vector2f point3;
//     float thickness = 8.f; // set the thickness of the line segment
//     float arrowSize = 20.f; // set the size of the arrow triangle

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//             else if (event.type == sf::Event::KeyPressed)
//             {
//                 // increase or decrease the thickness of the line segment using the arrow keys
//                 if (event.key.code == sf::Keyboard::Up)
//                     thickness += 1.f;
//                 else if (event.key.code == sf::Keyboard::Down)
//                     thickness -= 1.f;
//             }
//         }

//         // calculate the unit vector and normal vector of the line segment
//         sf::Vector2f direction = point2 - point1;
//         point3.x = point2.x + 10;
        
//         point3.y = point1.y + direction.y * ((direction.x + 10) / direction.x);     //test

//         float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

//         sf::Vector2f unitDirection = direction / length;

//         sf::Vector2f unitNormal(-unitDirection.y, unitDirection.x);

//         // calculate the points of the line segment rectangle
//         sf::Vector2f p1 = point1 + unitNormal * thickness / 2.f;
//         sf::Vector2f p2 = point1 - unitNormal * thickness / 2.f;
//         sf::Vector2f p3 = point2 - unitNormal * thickness / 2.f;
//         sf::Vector2f p4 = point2 + unitNormal * thickness / 2.f;


//         sf::Vector2f p5 = point3 - unitNormal * thickness / 2.f;
//         sf::Vector2f p6 = point3 + unitNormal * thickness / 2.f;

//         // set the texture coordinates of the line vertices
//         line[0].texCoords = sf::Vector2f(0, 0);
//         line[1].texCoords = sf::Vector2f(0, length);
//         line[2].texCoords = sf::Vector2f(thickness, length);
//         line[3].texCoords = sf::Vector2f(thickness, 0);

//         // set the position and texture coordinates of the line vertices
//         line[0].position = p1;
//         line[1].position = p2;
//         line[2].position = p3;
//         line[3].position = p4;

//         sf::Vector2f mid = (p5 + p6) / 2.f;
//         sf::Vector2f arrowP1 = mid - unitDirection * arrowSize + unitNormal * arrowSize / 2.f;
//         sf::Vector2f arrowP2 = mid - unitDirection * arrowSize - unitNormal * arrowSize / 2.f;
//         sf::Vector2f arrowP3 = mid;

//         // create a vertex array for the arrow triangle
//         sf::VertexArray arrow(sf::Triangles, 3);
//         arrow[0].position = arrowP1;
//         arrow[1].position = arrowP2;
//         arrow[2].position = arrowP3;

//         arrow[0].color = sf::Color::Red;
//         arrow[1].color = sf::Color::Red;
//         arrow[2].color = sf::Color::Red;

//         // point2 = point2 + sf::Vector2f(0, -0.1f);
//         // draw the line segment and arrow triangle
//         window.clear();
//         window.draw(line);
//     //     for (int i = 0; i <= 2; i++)
//     //   cout << arrow[i].position.x << " " << arrow[i].position.y << endl;
//         window.draw(arrow);
//         window.display();
//     }
//     return 0;
// }