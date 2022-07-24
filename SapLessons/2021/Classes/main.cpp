#include <iostream>
#include <vector>

#include "Figures.h"

void TestFigures()
{
    std::vector<Figure*> figures;
    figures.push_back(new Line(Point(0.0, 0.0), Point(100.0, 0.0)));
    figures.push_back(new Circle(Point(0.0, 0.0), 100.));
    figures.push_back(new Line(Point(-100.0, 25.0), Point(100.0, 0.0)));
    figures.push_back(new Circle(Point(-75.0, 33.0), 1250.));
    figures.push_back(new Rectangle(Point(0, 0), Point(100, -20)));

    Point delta(12, -4);
    Color color(122, 122, 255, 555);
    for (Figure* figure : figures) {
        figure->Move(delta);
        figure->SetColor(color);

        figure->Rotate(Point(0, 0), 23.45f);
    }

    for (Figure* figure : figures) {
        figure->Draw();
    }

    for (Figure* figure : figures) {
        delete figure;
    }
    figures.clear();
}

Circle* TestFigures2()
{
    Circle* circle = new Circle(Point(-75.0, 33.0), 1250.);
    circle->Draw();

    return circle;
}

int main()
{
    TestFigures();
    //Circle* cir = TestFigures2();
    //cir->Draw();
    //delete cir;
}