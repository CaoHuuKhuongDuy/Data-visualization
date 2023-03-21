#include "arrow.h"

Arrow::Arrow(int num) {
    line = VertexArray(Quads, 4);
    arrow1 = VertexArray(Triangles, 3);
    arrow2 = VertexArray(Triangles, 3); 
    numArrow = num;
}

void Arrow::createLine(Vector2f startPoint, Vector2f endPoint, bool change) {
    point1 = startPoint;
    point2 = endPoint;
    float thickness = 5.f;
    Vector2f direction = point2 - point1;
    if (change) {
        Vector2f direction2;
        direction2 = direction * 0.8f;
        Vector2f tmp = point2;
        point2 = direction2 + point1;
        if (numArrow == 2) {
            direction2 = direction2 * -1.f;
            point1 = direction2 + tmp;
        }
    }
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    Vector2f unitDirection = direction / length;
    Vector2f unitNormal(-unitDirection.y, unitDirection.x);
    Vector2f p1 = point1 + unitNormal * thickness / 2.f;
    Vector2f p2 = point1 - unitNormal * thickness / 2.f;
    Vector2f p3 = point2 - unitNormal * thickness / 2.f;
    Vector2f p4 = point2 + unitNormal * thickness / 2.f;
    
    line[0].texCoords = Vector2f(0, 0);
    line[1].texCoords = Vector2f(0, length);
    line[2].texCoords = Vector2f(thickness, length);
    line[3].texCoords = Vector2f(thickness, 0);

    line[0].position = p1;
    line[1].position = p2;
    line[2].position = p3;
    line[3].position = p4;

    for (int i = 0; i <= 3; i++)
      line[i].color = Color::Black;
}

void Arrow::createArrow(VertexArray &arrow) {
    float thickness = 5.f; // set the thickness of the line segment
    float arrowSize = 20.f; // set the size of the arrow triangle
    Vector2f direction = point2 - point1;
    Vector2f direction2;


    Vector2f tmp = point2;
    direction2 = direction * 1.085f;
    Vector2f point3 = direction2 + point1;

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
    Vector2f mid = (p5 + p6) / 2.f;

    Vector2f arrowP1 = mid - unitDirection * arrowSize + unitNormal * arrowSize / 2.f;
    Vector2f arrowP2 = mid - unitDirection * arrowSize - unitNormal * arrowSize / 2.f;
    Vector2f arrowP3 = mid;

    arrow[0].position = arrowP1;
    arrow[1].position = arrowP2;
    arrow[2].position = arrowP3;

    for (int i = 0; i <= 2; i++)
      arrow[i].color = Color::Black;
}

void Arrow::create(Vector2f startPoint, Vector2f endPoint, bool change) {
    createLine(startPoint, endPoint, change);
    if (numArrow >= 1) createArrow(arrow1);
    if (numArrow == 2) {
        swap(point1, point2);
        createArrow(arrow2);
    }

}

void Arrow::draw(RenderWindow &window) {
    window.draw(line);
    window.draw(arrow1);
    if (numArrow == 2) window.draw(arrow2);
}