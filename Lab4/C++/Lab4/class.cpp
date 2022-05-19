#include "Header.h"

void LinearFunction::displayFunction() {
    if (A1 != 0 && A0 > 0) cout << "y = " << A1 << "x + " << A0 << endl;
    else if (A1 != 0 && A0 < 0) cout << "y = " << A1 << "x - " << -1 * A0 << endl;
    else if (A1 == 0 && A0 != 0) cout << "y = " << A0 << endl;
    else if (A1 != 0 && A0 == 0) cout << "y = " << A1 << "x" << endl;
    else if (A1 == 0 && A0 == 0) cout << "y = 0" << endl;
}

void QuadraticFucntion::displayFunction() {
    if (B2 != 0 && B1 > 0 && B0 > 0) cout << "y = " << B2 << "x^2 + " << B1 << "x + " << B0 << endl;
    else if (B2 != 0 && B1 > 0 && B0 < 0) cout << "y = " << B2 << "x^2 + " << B1 << "x - " << -1 * B0 << endl;
    else if (B2 != 0 && B1 < 0 && B0>0) cout << "y = " << B2 << "x^2 - " << -1 * B1 << "x + " << B0 << endl;
    else if (B2 != 0 && B1 < 0 && B0 < 0) cout << "y = " << B2 << "x^2 - " << -1 * B1 << "x - " << -1 * B0 << endl;
    else if (B2 == 0 && B1 != 0 && B0 > 0) cout << "y = " << B1 << "x + " << B0 << endl;
    else if (B2 == 0 && B1 != 0 && B0 < 0) cout << "y = " << B1 << "x - " << -1 * B0 << endl;
    else if (B2 != 0 && B1 == 0 && B0 > 0) cout << "y = " << B2 << "x^2 + " << B0 << endl;
    else if (B2 != 0 && B1 == 0 && B0 < 0) cout << "y = " << B2 << "x^2 - " << -1 * B0 << endl;
    else if (B2 != 0 && B1 > 0 && B0 == 0) cout << "y = " << B2 << "x^2 + " << B1 << endl;
    else if (B2 != 0 && B1 < 0 && B0 == 0) cout << "y = " << B2 << "x^2 - " << -1 * B1 << endl;
    else if (B2 != 0 && B1 == 0 && B0 == 0) cout << "y = " << B2 << "x^2" << endl;
    else if (B2 == 0 && B1 != 0 && B0 == 0) cout << "y = " << B1 << "x" << endl;
    else if (B2 == 0 && B1 == 0 && B0 != 0) cout << "y = " << B0 << endl;
    else if (B2 == 0 && B1 == 0 && B0 == 0) cout << "y = 0" << endl;
}