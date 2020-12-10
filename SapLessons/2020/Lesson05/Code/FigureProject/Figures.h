#pragma once

#include <iostream>

struct Point {
    Point(double _x, double _y)
        : x(_x), y(_y) {}

    double x = 0.;
    double y = 0.;
};

struct Color {
    Color(char r, char g, char b, char a)
        : R(r), G(g), B(b), A(a) {}

    char R, G, B, A;
};

class Figure {
public:
    virtual ~Figure() {
        std::cout << "Figure destructor has been called!" << std::endl;
    };

    void SetColor(const Color& color);

    virtual void Move(const Point& pt) = 0;
    virtual void Rotate(const Point& pt, double angle) = 0;
    virtual void Draw() = 0;

protected:
    Color _color = Color(255, 255, 255, 255);
};

class Circle : public Figure {
public:
    Circle(const Point& center, double radius)
        : _center(center), _radius(radius) {}

    ~Circle() {
        std::cout << "Circle destructor has been called!" << std::endl;
    }

    virtual void Move(const Point& delta) override;
    virtual void Rotate(const Point& pt, double angle) override;
    virtual void Draw() override;

private:
    Point _center;
    double _radius;
};

class Line : public Figure {
public:
    Line(const Point& pt1, const Point& pt2)
        :_p1(pt1), _p2(pt2)
    {}

    ~Line() {
        std::cout << "Line destructor has been called!" << std::endl;
    }

    virtual void Move(const Point& delta) override;
    virtual void Rotate(const Point& pt, double angle) override;
    virtual void Draw() override;

private:
    Point _p1, _p2;
};

class Rectangle : public Figure {
public:
    Rectangle(const Point& leftTop, const Point& rightBottom)
        :_leftTop(leftTop), _rightBottom(rightBottom)
    {}

    ~Rectangle() {
        std::cout << "Rectangle destructor has been called!" << std::endl;
    }

    virtual void Move(const Point& delta) override;
    virtual void Rotate(const Point& pt, double angle) override;
    virtual void Draw() override;

private:
    Point _leftTop;
    Point _rightBottom;
};
