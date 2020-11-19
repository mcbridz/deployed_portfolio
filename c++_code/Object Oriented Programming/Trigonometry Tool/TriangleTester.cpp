/*
  * @brief Assignment 2
   * @author Zachary McBride
  */
//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "Point.h"
#include "Triangle.h"
#include <math.h>

const double error = 10e-13;

TEST_CASE("Get Point"){
    Point test(1, 1);
    Point vertexA(-1, -1);
    Point vertexB(-2, -2);
    Point vertexC(-2, -1);
    Triangle testTriangle(vertexA, vertexB, vertexC);
    Point reflect = testTriangle.getPoint(0);
    REQUIRE (Approx(reflect.getX()) == -1);
    REQUIRE (Approx(reflect.getY()) == -1);
}
TEST_CASE("Set Point"){
    Point test(1, 1);
    Point vertexA(-1, -1);
    Point vertexB(-2, -2);
    Point vertexC(-2, -1);
    Triangle testTriangle(vertexA, vertexB, vertexC);
    testTriangle.setPoint(0, test);
    Point reflect = testTriangle.getPoint(0);
    REQUIRE (Approx(reflect.getX()) == test.getX());
    REQUIRE (Approx(reflect.getY()) == test.getY());
}
TEST_CASE("Get Area"){
    Point vertexA(0, 0);
    Point vertexB(2, 0);
    Point vertexC(0, 2);
    Triangle testTriangle(vertexA, vertexB, vertexC);
    double base = vertexB.getX();
    double height = vertexC.getY();
    double manualArea = base * (height / 2);
    REQUIRE ((manualArea - testTriangle.getArea()) <= error);
}
TEST_CASE("Get Angle"){
    Point vertexA(0,0);
    Point vertexB((1/pow(2, 0.5)), 0);
    Point vertexC(1/pow(2, 0.5), 1/pow(2, 0.5));
    Triangle t1(vertexA, vertexB, vertexC);
    REQUIRE(Approx(t1.getAngle(0)) == 45.0);
    REQUIRE(Approx(t1.getAngle(1)) == 90.0);
    REQUIRE(Approx(t1.getAngle(2)) == 45.0);
}
TEST_CASE("Translate"){
    Point vertexA(0, 0);
    Point vertexB(2, 0);
    Point vertexC(0, 2);
    Triangle testTriangle(vertexA, vertexB, vertexC);
    testTriangle.translate(-2, -2);
    Point reflectedA = testTriangle.getPoint(0);
    double reflectedAX = reflectedA.getX();
    double reflectedAY = reflectedA.getY();
    REQUIRE(Approx(reflectedAX) == -2);
    REQUIRE(Approx(reflectedAY) == -2);
    Point reflectedB = testTriangle.getPoint(1);
    double reflectedBX = reflectedB.getX();
    double reflectedBY = reflectedB.getY();
    REQUIRE(Approx(reflectedBX) == 0);
    REQUIRE(Approx(reflectedBY) == -2);
    Point reflectedC = testTriangle.getPoint(2);
    double reflectedCX = reflectedC.getX();
    double reflectedCY = reflectedC.getY();
    REQUIRE(Approx(reflectedCX) == -2);
    REQUIRE(Approx(reflectedCY) == 0);
}
TEST_CASE("Get Perimeter"){
    Point A(2, 0);
    Point B(-2, 0);
    Point C(0, (2 * pow(3, 0.5)));
    Triangle t1(A, B, C);
    double test = A.distanceTo(B) + B.distanceTo(C) + C.distanceTo(A);
    REQUIRE(Approx(t1.getPerimeter()) == test);
}
/*TEST_CASE("Equilateral Triangle") {
    Point A(2, 0);
    Point B(-2, 0);
    Point C(0, (2 * pow(3, 0.5)));
    Triangle t1(A, B, C);
    double length = t1.sideLength('A');
    REQUIRE (length == Approx(t1.sideLength('B')));
    REQUIRE (length == Approx(t1.sideLength('C')));
    REQUIRE (t1.getAngle(0) == Approx(t1.getAngle(1)));
    REQUIRE (t1.getAngle(0) == Approx(t1.getAngle(2)));
    Point inside(0, 1);
    REQUIRE (t1.contains(inside) == true);
    REQUIRE (t1.getPerimeter() == Approx((t1.sideLength('A') + t1.sideLength('B') + t1.sideLength('C'))));
}*/
TEST_CASE("Contains"){
    Point A(2, 0);
    Point B(-2, 0);
    Point C(0, (2 * pow(3, 0.5)));
    Triangle t1(A, B, C);
    Point check(0,1);
    REQUIRE(t1.contains(check) == true);
    Point secondCheck(25, 25);
    REQUIRE(t1.contains(secondCheck) == false);
}
TEST_CASE("Constructor"){
    Point A(2, 0);
    Point B(-2, 0);
    Point C(0, (2 * pow(3, 0.5)));
    Triangle t1(A, B, C);
    REQUIRE(t1.getPoint(0).isSameAs(A));
    REQUIRE(t1.getPoint(1).isSameAs(B));
    REQUIRE(t1.getPoint(2).isSameAs(C));
    Point errorPoint(1, 0);
    CHECK_THROWS_AS(Triangle(A, B, errorPoint), std::invalid_argument);
    Point tester[3] = {A, B, errorPoint};
    CHECK_THROWS_AS(Triangle(tester), std::invalid_argument);
}
TEST_CASE("Vertex Input Check"){
    Point A(2, 0);
    Point B(-2, 0);
    Point C(0, (2 * pow(3, 0.5)));
    Triangle t1(A, B, C);
    Point test(0, 0);
    CHECK_THROWS_AS(t1.getPoint(3), std::invalid_argument);
    CHECK_THROWS_AS(t1.getPoint(-1), std::invalid_argument);
    CHECK_THROWS_AS(t1.setPoint(3, test), std::invalid_argument);
    CHECK_THROWS_AS(t1.setPoint(-1, test), std::invalid_argument);
    CHECK_THROWS_AS(t1.getAngle(3), std::invalid_argument);
    CHECK_THROWS_AS(t1.getAngle(-1), std::invalid_argument);
}
