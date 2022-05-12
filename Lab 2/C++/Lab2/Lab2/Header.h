#pragma once
#include <iostream>
#include <vector>

using namespace std;

class TPoint {
private:
    float x;
    float y;
    float z;
    float v1;
    float v2;
    float v3;
public:
    TPoint(float, float, float, float, float, float);
    void setX(float X) { x = X; }
    void setY(float Y) { y = Y; }
    void setZ(float Z) { z = Z; }
    void setV1(float V1) { v1 = V1; }
    void setV2(float V2) { v2 = V2; }
    void setV3(float V3) { v3 = V3; }
    void setCoordinates(float, float, float);
    void setCoordinatesOfVelocity(float, float, float);
    float getX() { return x; }
    float getY() { return y; }
    float getZ() { return z; }
    float getV1() { return v1; }
    float getV2() { return v2; }
    float getV3() { return v3; }
    void changePosition(float);
    bool is_first_octant();
};

bool is_there_first_octant(vector <TPoint>, int);