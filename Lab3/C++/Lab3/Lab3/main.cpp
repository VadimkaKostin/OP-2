#include "Header.h"

int main() {
    Circle C1;
    Circle C2(3, -1, 7);
    Circle C3(C2);

    cout << "Circle 1:\n\tRadius = " << C1.getR() << "\n\tCoordinates (" << C1.getX() << ";" << C1.getY() << ")" << endl;
    cout << "\nCircle 2:\n\tRadius = " << C2.getR() << "\n\tCoordinates (" << C2.getX() << ";" << C2.getY() << ")" << endl;
    cout << "\nCircle 3:\n\tRadius = " << C3.getR() << "\n\tCoordinates (" << C3.getX() << ";" << C3.getY() << ")" << endl;

    ++C1;
    C2++;
    C3 = C3 * 3;

    cout << "\n=========Changing operations=========" << endl;

    cout << "\nCircle 1:\n\tRadius = " << C1.getR() << "\n\tCoordinates (" << C1.getX() << ";" << C1.getY() << ")" << endl;
    cout << "\nCircle 2:\n\tRadius = " << C2.getR() << "\n\tCoordinates (" << C2.getX() << ";" << C2.getY() << ")" << endl;
    cout << "\nCircle 3:\n\tRadius = " << C3.getR() << "\n\tCoordinates (" << C3.getX() << ";" << C3.getY() << ")" << endl;

    double length1 = C1.circumference(),
        length2 = C2.circumference(),
        length3 = C3.circumference();

    cout << "\nCircle 1 length = " << length1 << endl;
    cout << "Circle 2 length = " << length2 << endl;
    cout << "Circle 3 length = " << length3 << endl;

    if (length1 >= length2 && length1 >= length3) cout << "\nThe first circle has the longest circumference" << endl;
    else if (length2 >= length3) cout << "\nThe second circle has the longest circumference" << endl;
    else cout << "\nThe third circle has the longest circumference" << endl;

    system("pause");
}