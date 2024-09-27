#include <iostream>
#include <cmath>
using namespace std;

class Point{
private:
    int m_x;
    int m_y;

public:
    void setx(int x){
        m_x = x;
    }
    int getx(){
        return m_x;
    }

    void sety(int y){
        m_y = y;
    }
    int gety(){
        return m_y;
    }
};

class Circle{
private:
    int m_x;
    int m_y;
    int m_r;
public:
    void setx(int x){
        m_x = x;
    }
    int getx(){
        return m_x;
    }

    void sety(int y){
        m_y = y;
    }
    int gety(){
        return m_y;
    }

    void setr(int r){
        m_r = r;
    }
    int getr(){
        return m_r;
    }

    void isInCircle(Point &p){
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
};




int main(){
    Circle c;
    c.setx(0);
    c.sety(0);
    c.setr(2);

    Point p1;
    p1.setx(1);
    p1.sety(1);

    Point p2;
    p2.setx(2);
    p2.sety(0);

    Point p3;
    p3.setx(2);
    p3.sety(2);

    c.isInCircle(p1);
    c.isInCircle(p2);
    c.isInCircle(p3);

    return 0;
}