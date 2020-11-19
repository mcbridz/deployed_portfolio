#include <iostream>
#include "Point.h"
#include "Triangle.h"

using namespace std;

int main()
{
    cout << "Please input cartesian coodrinates for three points to make a triangle" << endl;
    cout << "Point 1: ";
    double x, y;
    Point A, B, C;
    cin >> x >> y;
    A.setX(x);
    A.setY(y);
    cout << endl << "Point 2: ";
    cin >> x >> y;
    B.setX(x);
    B.setY(y);
    cout << endl << "Point 3: ";
    cin >> x >> y;
    C.setX(x);
    C.setY(y);
    cout << endl;
    Triangle t1(A, B, C);
}
