#include <iostream>
using namespace std;
/*
1. 设计立方体类
2. 求出立方体的表面积和体积
3. 分别用全局函数和成员函数判断两个立方体是否相等
*/

class Cube{
private:
    int m_L;
    int m_W;
    int m_H;

public:
    //设置长宽高、获取长宽高
    void setL(int l){
        m_L = l;
    }
    int getL(){
        return m_L;
    }
    void setW(int w){
        m_W = w;
    }
    int getW(){
        return m_W;
    }
    void setH(int h){
        m_H = h;
    }
    int getH(){
        return m_H;
    }

    //获取立方体的表面积
    int getMianji(){
        return (m_L * m_W + m_L * m_H +m_H * m_W) * 2;
    }

    //获取立方体的体积
    int getTiji(){
        return m_L * m_W * m_H;
    }

    //利用成员函数判断两个立方体是否相等
    bool isSameByClass(Cube &c){
        if(m_L == c.getL() && m_W == c.getW() && m_H == c.getH()){
            return true;
        }
        else return false;
    }
};

//利用全局函数判断两个立方体是否相等
bool isSame(Cube c1, Cube c2){
    if(c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()){
        return true;
    }
    else return false;
}

int main(){
    Cube c1;
    c1.setL(10);
    c1.setW(10);
    c1.setH(10);
    cout << "立方体的表面积为：" << c1.getMianji() << endl;
    cout << "立方体的体积为：" << c1.getTiji() << endl;

    Cube c2;
    c2.setL(10);
    c2.setW(10);
    c2.setH(12);

    //利用全局函数判断
    if(isSame(c1, c2)){
        cout << "(全局函数判断)：立方体c1 和 c2 相等" << endl;
    }
    else{
        cout << "(全局函数判断)：立方体c1 和 c2 不相等" << endl;
    }

    //利用成员函数判断
    if(c1.isSameByClass(c2)){
        cout << "(成员函数判断)：立方体c1 和 c2 相等" << endl;
    }
    else{
        cout << "(成员函数判断)：立方体c1 和 c2 不相等" << endl;
    }

    return 0;
}