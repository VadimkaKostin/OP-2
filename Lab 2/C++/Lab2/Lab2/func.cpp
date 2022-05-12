#include "Header.h"

TPoint::TPoint(float x = 0, float y = 0, float z = 0, float v1 = 0, float v2 = 0, float v3 = 0) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
}

void TPoint::setCoordinates(float X, float Y, float Z) {
    x = X;
    y = Y;
    z = Z;
}

void TPoint::setCoordinatesOfVelocity(float V1, float V2, float V3) {
    v1 = V1;
    v2 = V2;
    v3 = V3;
}

void TPoint::changePosition(float time) {
    x += v1 * time;
    y += v2 * time;
    z += v3 * time;
}

bool TPoint::is_first_octant() {
    return x > 0 && y > 0 && z > 0;
}

bool is_there_first_octant(vector <TPoint> array, int n) {
    for (int i = 0; i < n; i++)
    {
        if (array[i].is_first_octant()) return true;
    }
    return false;
}