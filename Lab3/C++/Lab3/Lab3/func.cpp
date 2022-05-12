#include "Header.h"

Circle::Circle() {
    R = 1;
    X = 0;
    Y = 0;
}

Circle::Circle(int R, int X, int Y) {
    if (R >= 0) {
        this->R = R;
        this->X = X;
        this->Y = Y;
    }
    else cout << "Incorrect value of radius!" << endl;
}

Circle::Circle(Circle& c) {
    R = c.R;
    X = c.X;
    Y = c.Y;
}

double Circle::circumference() {
    return 2 * pi * R;
}

Circle Circle::operator++() {
    X++;
    return *this;
}

Circle Circle::operator++(int) {
    Y++;
    return *this;
}

Circle Circle::operator*(int number) {
    Circle temp(*this);
    temp.R *= number;
    return temp;
}