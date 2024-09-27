#include <iostream>
#include "Circle.h"
#include "point.h"

void isInCircle(Circle &c, Point &p){
    int m_x = c.getCenter().getx();
    int m_y = c.getCenter().gety();
    int m_r = c.getr();
    cout << "该圆的圆心坐标为：" << "(" << m_x << ", " << m_y << ")" << "   ";
    cout << "该圆的半径为：" << m_r << endl;
    int dis = (p.getx() - m_x) * (p.getx() - m_x) + (p.gety() - m_y) * (p.gety() - m_y);
    if(dis > m_r * m_r){
        cout << "该点坐标为：(" << p.getx() << ", " << p.gety() << ")，在圆外" << endl;
    }
    else if(dis < m_r * m_r){
        cout << "该点坐标为：(" << p.getx() << ", " << p.gety() << ")，在圆内" << endl;
    }
    else {
        cout << "该点坐标为：(" << p.getx() << ", " << p.gety() << ")，在圆上" << endl;
    } 
}

int main(){
    Point p;
    p.setx(0);
    p.sety(0);

    Point p1;
    p1.setx(1);
    p1.sety(1);

    Point p2;
    p2.setx(2);
    p2.sety(0);

    Point p3;
    p3.setx(2);
    p3.sety(2);

    Circle c;
    c.setCenter(p);
    c.setr(2);

    isInCircle(c, p1);
    isInCircle(c, p2);
    isInCircle(c, p3);

    return 0;
}