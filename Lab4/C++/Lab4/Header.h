#pragma once
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;

class TFunction {
public:
    virtual void increase(double) = 0;
    virtual void decrease(double) = 0;
    virtual double getValue(double) = 0;
    virtual void displayFunction() = 0;
};

class LinearFunction :public TFunction {
private:
    double A1;
    double A0;
public:
    LinearFunction() : A1(1), A0(1) {}
    LinearFunction(double A1, double A0) {
        this->A1 = A1;
        this->A0 = A0;
    }
    void increase(double number) {
        A1 += number;
        A0 += number;
    }
    void decrease(double number) {
        A1 -= number;
        A0 -= number;
    }
    double getValue(double x) {
        double y = A1 * x + A0;
        return y;
    }
    void displayFunction();
};

class QuadraticFucntion :public TFunction {
private:
    double B2;
    double B1;
    double B0;
public:
    QuadraticFucntion() : B2(1), B1(1), B0(1) {}
    QuadraticFucntion(double B2, double B1, double B0) {
        this->B2 = B2;
        this->B1 = B1;
        this->B0 = B0;
    }
    void increase(double number) {
        B2 += number;
        B1 += number;
        B0 += number;
    }
    void decrease(double number) {
        B2 -= number;
        B1 -= number;
        B0 -= number;
    }
    double getValue(double x) {
        double y = B2 * pow(x, 2) + B1 * x + B0;
        return y;
    }
    void displayFunction();
};