#include<iostream>
#include<string>
using namespace std;


struct Hero
{
    /* data */
    string name;
    int age;
    string sex;
};
void exchangeInfo(Hero *h1, Hero *h2){
    // string name = h2->name;
    // h2->name = h1->name;
    // h1->name = name;

    // int age = h2->age;
    // h2->age = h1->age;
    // h1->age = age;

    // string sex = h2->sex;
    // h2->sex = h1->sex;
    // h1->sex = sex;
    Hero temp = *h1;
    *h1 = *h2;
    *h2 = temp;
}

void bubbleSort(Hero h[], int len){
    for(int i = 0; i < len - 1; ++i){
        for(int j = 0; j < len - i - 1; ++j){
            if(h[j].age > h[j+1].age){
                exchangeInfo(&h[j], &h[j+1]);
            }
        }
    }
}

void printInfo(Hero h[], int len){
    for(int i = 0; i < len; ++i){
        cout << "姓名：" << h[i].name << "\t"
        << "年龄：" << h[i].age << "\t"
        << "性别：" << h[i].sex << endl;
    }
}

int main(){
    Hero h[5] = {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"},
    };
    int len = sizeof(h) / sizeof(h[0]);
    cout << "冒泡排序前： " << endl;
    printInfo(h, len);
    cout << "冒泡排序后： " << endl;
    bubbleSort(h, len);
    printInfo(h, len);
    return 0;
}