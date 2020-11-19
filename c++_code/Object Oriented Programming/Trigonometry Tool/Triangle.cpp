/*
  * @brief Assignment 2
   * @author Zachary McBride
  */
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include "Triangle.h"
#include "Point.h"

using namespace std;

const double pi = 3.14159265359;
const double error = 10e-13;

//array constructor
Triangle::Triangle(Point verticies[3]){
    vertexA = verticies[0];
    vertexB = verticies[1];
    vertexC = verticies[2];
    if ((sideLength('A') < error) || (sideLength('B') < error) || (sideLength('C') < error)){
        throw invalid_argument("Not A Real Triangle");
    }
    if (round(getAngle(0) + getAngle(1) + getAngle(2)) != 90.0){
        throw invalid_argument("Not A Real Triangle");
    }
    if ((getAngle(0) == 0.0) || (getAngle(1) == 0.0) || (getAngle(2) == 0.0)){
        throw invalid_argument("Not A Real Triangle");
    }
}
//full constructor
Triangle::Triangle(Point p1, Point p2, Point p3){
    vertexA = p1;
    vertexB = p2;
    vertexC = p3;
    if ((sideLength('A') < error) || (sideLength('B') < error) || (sideLength('C') < error)){
        throw invalid_argument("Not A Real Triangle");
    }
    if (round(getAngle(0) + getAngle(1) + getAngle(2)) != 180.0){
        throw invalid_argument("Not A Real Triangle");
    }
    if ((getAngle(0) == 0.0) || (getAngle(1) == 0.0) || (getAngle(2) == 0.0)){
        throw invalid_argument("Not A Real Triangle");
    }
}

//member functions
void Triangle::vertexCheck(int input){
    if ((input <0) || (input >2)){
        throw invalid_argument("Not A Valid Vertex");
    }
}
double Triangle::sideLength(char side){
    double sideLength;
    if (side == 'A'){
        sideLength = vertexC.distanceTo(vertexB);
    } else if (side == 'B'){
        sideLength = vertexA.distanceTo(vertexC);
    } else if (side == 'C'){
        sideLength = vertexB.distanceTo(vertexA);
    } else {
        sideLength = 0;
    }
    return sideLength;
}
double Triangle::getPerimeter(){
    double sideA = sideLength('A');
    double sideB = sideLength('B');
    double sideC = sideLength('C');
    return sideA + sideB + sideC;
}
double Triangle::getArea(){
    double area;
    double semiPerimeter = (sideLength('A') + sideLength('B') + sideLength('C')) / 2;
    area = semiPerimeter * ((semiPerimeter - sideLength('A')) * (semiPerimeter - sideLength('B')) * (semiPerimeter - sideLength('C')));
    area = pow(area, 0.5);
    return area;
}
double Triangle::getAngle(int number){
    double theta;
    char first, second, third;
    if (number == 0){
        first = 'A';
        second = 'B';
        third = 'C';
    } else if (number == 1){
        first = 'B';
        second = 'C';
        third = 'A';
    } else if (number == 2){
        first = 'C';
        second = 'A';
        third = 'B';
    } else {
        vertexCheck(number);
    }
    double firstFirst = sideLength(first);
    double secondSecond = sideLength(second);
    double thirdThird = sideLength(third);
    theta = (pow(secondSecond, 2) + pow(thirdThird, 2) - pow(firstFirst, 2)) / ( 2 * secondSecond * thirdThird);
    theta = acos(theta);
    theta = (theta * 180) / pi;
    return theta;
}
Point Triangle::getPoint(const int number){
    vertexCheck(number);
    Point output;
    if (number == 0){
        output = vertexA;
    } else if (number == 1){
        output = vertexB;
    } else {
        output = vertexC;
    }
    return output;
}
void Triangle::setPoint(int number, Point p){
    vertexCheck(number);
    if (number == 0){
        vertexA = p;
    } else if (number == 1){
        vertexB = p;
    } else {
        vertexC = p;
    }
}
void Triangle::translate(double xShift, double yShift){
    vertexA.setX(vertexA.getX() + xShift);
    vertexA.setY(vertexA.getY() + yShift);
    vertexB.setX(vertexB.getX() + xShift);
    vertexB.setY(vertexB.getY() + yShift);
    vertexC.setX(vertexC.getX() + xShift);
    vertexC.setY(vertexC.getY() + yShift);
}
bool Triangle::contains(const Point& p){
    bool output = false;
    double originalArea = getArea();
    double areaOne;
    double semiP1 = ((p.distanceTo(vertexA) + p.distanceTo(vertexB) + vertexB.distanceTo(vertexA)) / 2);
    areaOne = semiP1 * ((semiP1 - p.distanceTo(vertexA)) * (semiP1 - p.distanceTo(vertexB)) * (semiP1 - vertexB.distanceTo(vertexA)));
    areaOne = pow(areaOne, 0.5);
    double areaTwo;
    double semiP2 = ((p.distanceTo(vertexB) + p.distanceTo(vertexC) + vertexB.distanceTo(vertexC)) / 2);
    areaTwo = semiP2 * ((semiP2 - p.distanceTo(vertexB)) * (semiP2 - p.distanceTo(vertexC)) * (semiP2 - vertexB.distanceTo(vertexC)));
    areaTwo = pow(areaTwo, 0.5);
    double areaThree;
    double semiP3 = ((p.distanceTo(vertexA) + p.distanceTo(vertexC) + vertexA.distanceTo(vertexC)) / 2);
    areaThree = semiP3 * ((semiP3 - p.distanceTo(vertexA)) * (semiP3 - p.distanceTo(vertexC)) * (semiP3 - vertexA.distanceTo(vertexC)));
    areaThree = pow(areaThree, 0.5);
    double pArea = areaOne + areaTwo + areaThree;
    double deltaArea = abs(originalArea - pArea);
    if (deltaArea < error){
        output = true;
        return output;
    }
    return output;
}
