#pragma once
#include <iostream>
#include "Point.h"
using namespace std;
class Circle{
private:
    int m_r;
    Point m_center; //在类中，可以让另一个类 作为本类中的成员
public:
    //设置圆心
    void setCenter(Point center);
    //获取圆心
    Point getCenter();
    //设置半径
    void setr(int r);
    //获取半径
    int getr();
};