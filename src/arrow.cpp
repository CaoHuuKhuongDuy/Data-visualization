#include "arrow.h"

Arrow::Arrow() {
    line = VertexArray(Quads, 4);
    arrow = VertexArray (Triangles, 3);
}

void Arrow::create(Vector2f startPoint, Vector2f endPoint) {
    point1 = startPoint;
    point2 = endPoint;
    float thickness = 5.f; // set the thickness of the line segment
    float arrowSize = 20.f; // set the size of the arrow triangle
    Vector2f direction = point2 - point1;
    Vector2f point3;
    point3.x = point2.x + 10;
    
    point3.y = point1.y + direction.y * ((direction.x + 10) / direction.x);     //test

    float length = sqrt(direction.x * direction.x + direction.y * direction.y);

    Vector2f unitDirection = direction / length;

    Vector2f unitNormal(-unitDirection.y, unitDirection.x);

    // calculate the points of the line segment rectangle
    Vector2f p1 = point1 + unitNormal * thickness / 2.f;
    Vector2f p2 = point1 - unitNormal * thickness / 2.f;
    Vector2f p3 = point2 - unitNormal * thickness / 2.f;
    Vector2f p4 = point2 + unitNormal * thickness / 2.f;


    Vector2f p5 = point3 - unitNormal * thickness / 2.f;
    Vector2f p6 = point3 + unitNormal * thickness / 2.f;

    // set the texture coordinates of the line vertices
    line[0].texCoords = Vector2f(0, 0);
    line[1].texCoords = Vector2f(0, length);
    line[2].texCoords = Vector2f(thickness, length);
    line[3].texCoords = Vector2f(thickness, 0);

    // set the position and texture coordinates of the line vertices
    line[0].position = p1;
    line[1].position = p2;
    line[2].position = p3;
    line[3].position = p4;

    for (int i = 0; i <= 3; i++)
      line[i].color = Color::Black;
    Vector2f mid = (p5 + p6) / 2.f;
    Vector2f arrowP1 = mid - unitDirection * arrowSize + unitNormal * arrowSize / 2.f;
    Vector2f arrowP2 = mid - unitDirection * arrowSize - unitNormal * arrowSize / 2.f;
    Vector2f arrowP3 = mid;

    // create a vertex array for the arrow triangle
    arrow[0].position = arrowP1;
    arrow[1].position = arrowP2;
    arrow[2].position = arrowP3;

    arrow[0].color = Color::Black;
    arrow[1].color = Color::Black;
    arrow[2].color = Color::Black;
}

void Arrow::draw(RenderWindow &window) {
    window.draw(line);
    window.draw(arrow);
}