#include "Header.h"

int main() {
    int n;
    cout << "Enter the amount of points: "; cin >> n;
    vector <TPoint> Array;
    for (int i = 0; i < n; i++)
    {
        float X, Y, Z, V1, V2, V3;
        cout << "\nPoint #" << i + 1 << endl;
        cout << "Enter coordinates of the point: "; cin >> X >> Y >> Z;
        cout << "Enter the coordinates of the vector of the speed: "; cin >> V1 >> V2 >> V3;
        TPoint point(X, Y, Z, V1, V2, V3);
        Array.push_back(point);
    }

    float t;
    cout << "\nEnter Time: "; cin >> t;
    for (int i = 0; i < n; i++)
    {
        Array[i].changePosition(t);
    }

    if (is_there_first_octant(Array, n)) {
        cout << "\nPoints that reached the first octant:" << endl;
        for (int i = 0; i < n; i++)
        {
            if (Array[i].is_first_octant()) cout << "#" << i + 1 << " ";
        }
        cout << endl;
    }
    else {
        cout << "There are not points which reached first octant!" << endl;
    }
    cout << endl;
    system("pause");
}