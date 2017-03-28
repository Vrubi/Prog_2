/*
 * \file point.h
 *
 */


#ifndef POINT_H
#define POINT_H
#include<stdbool.h>

/// Point osztály
/// Szándékosan egyszerû (buta)
class Point {
    int x;
    int y;
public:
    Point(int x = 0, int  y = 0) :x(x), y(y) { }
    int getX() const { return x; }
    int getY() const { return y; }
    bool operator==(const Point& a)const{
        if (a.x==this->x && a.y==this->y)
            return true;
    return false;
    }
};

bool operator==(const Point& a, const Point& b){
    if(a.getX()==b.getX()&& a.getY()==b.getY())
        return true;
    return false;
}

#endif // POINT_H
