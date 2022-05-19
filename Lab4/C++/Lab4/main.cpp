#include "Header.h"

int main() {
    srand(time(NULL));
    int n, m;
    cout << "Enter amount of the linear functions: "; cin >> n;
    cout << "Enter amount of the quadratic functions: "; cin >> m;

    vector<LinearFunction> linear;
    vector<QuadraticFucntion> quadratic;

    cout << "\nLinear functions:" << endl;
    for (int i = 0; i < n; i++)
    {
        double a1 = (double)(rand() % 40 - 20) / 2,
            a0 = (double)(rand() % 40 - 20) / 2;
        LinearFunction LFunction(a1, a0);
        linear.push_back(LFunction);
        cout << i + 1 << ") ";
        LFunction.displayFunction();
    }

    cout << "\nQuadratic functions:" << endl;
    for (int i = 0; i < m; i++)
    {
        double b2 = (double)(rand() % 40 - 20) / 2,
            b1 = (double)(rand() % 40 - 20) / 2,
            b0 = (double)(rand() % 40 - 20) / 2;
        QuadraticFucntion QFunction(b2, b1, b0);
        quadratic.push_back(QFunction);
        cout << i + 1 << ") ";
        QFunction.displayFunction();
    }

    cout << "\nNew linear functions:" << endl;
    for (int i = 0; i < n; i++)
    {
        linear[i].increase(3);
        cout << i + 1 << ") ";
        linear[i].displayFunction();
    }

    cout << "\nNew quadratic functions:" << endl;
    for (int i = 0; i < m; i++)
    {
        quadratic[i].decrease(2);
        cout << i + 1 << ") ";
        quadratic[i].displayFunction();
    }

    double x;
    cout << "\nEnter x: "; cin >> x;

    double maxLinear = linear[0].getValue(x);
    int posLinear = 0;

    cout << "\nValues of the linear functions:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ") y = " << linear[i].getValue(x) << endl;
        if (linear[i].getValue(x) > maxLinear) {
            maxLinear = linear[i].getValue(x);
            posLinear = i;
        }
    }

    double maxQuadratic = quadratic[0].getValue(x);
    int posQuadratic = 0;

    cout << "\nValues of the quadratic functions:" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << ") y = " << quadratic[i].getValue(x) << endl;
        if (quadratic[i].getValue(x) > maxQuadratic) {
            maxQuadratic = quadratic[i].getValue(x);
            posQuadratic = i;
        }
    }

    if (maxLinear >= maxQuadratic) {
        cout << "The maximum value has function ";
        linear[posLinear].displayFunction();
        cout << "Value of this function is " << linear[posLinear].getValue(x) << endl;
    }
    else {
        cout << "The maximum value has function ";
        quadratic[posQuadratic].displayFunction();
        cout << "Value of this function is " << quadratic[posQuadratic].getValue(x) << endl;
    }

    cout << endl;

    system("pause");
}