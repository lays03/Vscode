#include "Circle.h"

//设置圆心
void Circle::setCenter(Point center){
    m_center = center;
}
//获取圆心
Point Circle::getCenter(){
    return m_center;
}
//设置半径
void Circle::setr(int r){
    m_r = r;
}
//获取半径
int Circle::getr(){
    return m_r;
}
