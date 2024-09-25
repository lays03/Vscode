#include<iostream>
#include<string>
using namespace std;


struct Student
{
    /* data */
    string name;
    int score;
};

struct Teacher
{
    /* data */
    string name;
    struct Student stu[5];
};

void allocateSpace(Teacher t[], int len){
    string str = "ABCDE";
    for(int i = 0; i < len; ++i){
        t[i].name = "Teacher_";
        t[i].name += str[i];
        for(int j = 0; j < 5; ++j){
            t[i].stu[j].name = "Student_";
            t[i].stu[j].name += str[j];
            t[i].stu[j].score = 60;
        }
    }
}

void printInformation(Teacher t[], int len){
    for(int i = 0; i < len; ++i){
        cout << "老师姓名：" << t[i].name << endl;
        cout << "该老师学生信息为：" << endl;
        for(int j = 0; j < 5; ++j){
            cout << "姓名：" << t[i].stu[j].name << "\t\t" 
            << "分数：" << t[i].stu[j].score << endl;
        }
    }
}

int main(){
    Teacher t[3];
    int len = sizeof(t) / sizeof(t[0]);
    allocateSpace(t, len);
    printInformation(t, len);
    return 0;
}