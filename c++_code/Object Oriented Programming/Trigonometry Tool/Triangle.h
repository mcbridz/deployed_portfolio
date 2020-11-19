/*
  * @brief Assignment 2
   * @author Zachary McBride
  */
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"


class Triangle
{
private:

    //private member information enumerated
    Point vertexA;
    Point vertexB;
    Point vertexC;
    Point verticies[3];

public:
    //constructors

    //Construct triangle using the three Points as the verticies
    Triangle (Point p1, Point p2, Point p3);
    //Construct triangle from array of three verticies
    Triangle (Point vertices[3]);


    //member function declarations

    /**
     * @brief getPoint Takes value expected to be 0, 1, 2 (throw
     * an exception or do anything you want if a bad index comes
     * in).
     * @param number Takes value expected to be 0, 1, or 2.
     * @return Returns corresponding vertex from triangle.
     */
    Point getPoint(const int number);
    /**
     * @brief setPoint Takes value expected to be 0, 1, 2 (throw
     * an exception or do anything you want if a bad index
     * comes in) and a Point. Stores that point as the indicated vertex.
     * @param number Takes value expected to be 0, 1, 2
     * @param p Point to be set.
     */
    void setPoint(int number, Point p);
    /**
     * @brief getPerimeter – calculate and return value.
     * @return Perimeter value
     */
    double getPerimeter();
    /**
     * @brief getArea calculate and return value.
     * @return <Double> area value
     */
    double getArea();
    /**
     * @brief getAngle Finds the angle at the given vertex of the
     * triangle
     * @param number Takes value expected to be 0, 1,  or 2.
     */
    double getAngle(int number);
    /**
     * @brief translate  Move the triangle by the given amount in
     * x and y dimensions. Do so by moving the vertices.
     * @param xShift X attribute shift
     * @param yShift Y attribute shift
     */
    void translate(double xShift, double yShift);
    /**
     * @brief contains Return true if indicated Point is within the triangle
     * @param p Point to be tested to see if it is within the triangle
     * @return If the point is within the triangle, returns true
     */
    bool contains(const Point& p);
    /**
     * @brief sideLength Returns side length for different uses
     * @param side Takes value expected to be 0, 1, or 2.
     * @return <double> side length
     */
    double sideLength(char side);
    /**
     * @brief vertexCheck Checks to make sure vertex input is 0<=x<=2
     * @param input Vertex integer input to be evaluated.
     */
    void vertexCheck(int input);
};

#endif // TRIANGLE_H
