#include "Figures.h"

void Figure::SetColor(const Color& color) {
	_color = color;
}

void Circle::Move(const Point& delta) {
    _center.x += delta.x;
    _center.y += delta.y;
};

void Circle::Rotate(const Point& pt, double angle)
{
    std::cout << "Rotate circle" << std::endl;
}

void Circle::Draw() {
    std::cout << "It's a circle" << std::endl;
}

void Line::Move(const Point& delta) {
    _p1.x += delta.x;
    _p1.y += delta.y;
    _p2.x += delta.x;
    _p2.y += delta.y;
};

void Line::Rotate(const Point& pt, double angle)
{
    std::cout << "Line circle" << std::endl;
}

void Line::Draw() {
    std::cout << "It's a line" << std::endl;
}

void Rectangle::Move(const Point& delta)
{
    _leftTop.x += delta.x;
    _leftTop.y += delta.y;
    _rightBottom.x += delta.x;
    _rightBottom.y += delta.y;
}

void Rectangle::Rotate(const Point& pt, double angle)
{
    std::cout << "Rectangle circle" << std::endl;
}

void Rectangle::Draw()
{
    std::cout << "It's a rect" << std::endl;
}