#pragma once
#include <iostream>
#define pi 3.14f

using namespace std;

class Circle {
private:
    int R;
    int X;
    int Y;
public:
    Circle();
    Circle(int R, int X, int Y);
    Circle(Circle&);
    int getR() { return R; }
    int getX() { return X; }
    int getY() { return Y; }
    double circumference();
    Circle operator++();
    Circle operator++(int);
    Circle operator*(int);
};