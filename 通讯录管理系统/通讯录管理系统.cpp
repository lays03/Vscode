#include <iostream>
#include <string>

using namespace std;
const int maxn = 1001;

struct Person{
    string name; //姓名
    int sex; //性别
    int age; //年龄
    string phone; //联系电话
    string address; //家庭住址
};

struct Addressbooks{
    struct Person p[maxn];
    int size;
};

//退出通讯录
void Exit(){
    cout << "欢迎下次使用" << endl;
}

//添加联系人
void Add(Addressbooks *abs){
    if(abs->size > maxn){
        cout << "此通讯录已满，无法添加！" << endl;
    }
    else{
        string name; //姓名
        int sex; //性别
        int age; //年龄
        string phone; //联系电话
        string address; //家庭住址
        cout << "请输入*姓名*：";
        cin >> name;    
        abs->p[abs->size].name = name;

        cout << "请输入*性别*：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        while(1){
            cin >> sex;
            if(sex == 1 || sex ==2){
                abs->p[abs->size].sex = sex;
                break;
            }
            else{
                cout << "输入有误，请重新输入！" << endl;
            }
        }
        cout << "请输入*年龄*：";
        cin >> age;    
        abs->p[abs->size].age = age;

        cout << "请输入*联系电话*：";
        cin >> phone;    
        abs->p[abs->size].phone = phone;

        cout << "请输入*家庭住址*：";
        cin >> address;    
        abs->p[abs->size].address = address;

        cout << "添加成功！" << endl;

        cout << "添加的条目为：" << endl;
        cout << "姓名：" << abs->p[abs->size].name << endl
        << "性别：" << abs->p[abs->size].sex << endl
        << "年龄：" << abs->p[abs->size].age << endl
        << "联系电话：" << abs->p[abs->size].phone << endl
        << "家庭住址：" << abs->p[abs->size].address << endl;

        abs->size++;
        system("pause"); //请按任意键继续
        system("cls"); //清屏
    }
}

void Show(Addressbooks *abs){
    if(abs->size == 0) cout << "记录为空" << endl;
    else{
        cout << "共有" << abs->size << "个条目" << endl;
        cout << "通讯录信息：" << endl;
        for(int i = 0; i < abs->size; ++i){
            cout << i + 1 << ". 姓名：" << abs->p[i].name << "\t"
            << "性别：" << (abs->p[i].sex == 1 ? "男" : "女") << "\t"
            << "年龄：" << abs->p[i].age << "\t"
            << "联系电话：" << abs->p[i].phone << "\t\t"
            << "家庭住址：" << abs->p[i].address << endl;
        }
    }
    
    system("pause"); //请按任意键继续
    system("cls"); //清屏
}

//查找联系人，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
int isExist(Addressbooks *abs, string name){
    for(int i = 0; i < abs->size; ++i){
        if(abs->p[i].name == name){
            return i;
        }
    }
    return -1;
}

//删除联系人
void Delete(Addressbooks *abs){
    cout << "请输入您要删除的联系人：" << endl;
    string name;
    cin >> name;
    int res = isExist(abs, name);
    if(res == -1){
        cout << "查无此人" << endl;
        system("pause");
        system("cls");
    }
    else{
        //如果删除的是最后一个人
        if(res == abs->size - 1){
            abs->size--;
            cout << "删除成功√" << endl;
            system("pause");
            system("cls");
        }
        else{
            for(int i = res; i + 1 < abs->size - 1 ; ++i){
            abs->p[i] = abs->p[i + 1];
            }
            abs->p[abs->size - 2] = abs->p[abs->size - 1];
            abs->size--;
            cout << "删除成功√" << endl;
            system("pause");
            system("cls");
        }
        
    }
}

void Search(Addressbooks *abs){
    cout << "请输入您要查找的联系人姓名：";
    string name;
    cin >> name;
    int res = isExist(abs, name);
    if(res == -1){
        cout << "查无此人" << endl;
        system("pause");
        system("cls");
    }
    else{
        cout << "查找成功√，该联系人详细信息为：" << endl;
        cout <<"姓名：" << abs->p[res].name << "\t"
            << "性别：" << (abs->p[res].sex == 1 ? "男" : "女") << "\t"
            << "年龄：" << abs->p[res].age << "\t"
            << "联系电话：" << abs->p[res].phone << "\t\t"
            << "家庭住址：" << abs->p[res].address << endl;
        system("pause");
        system("cls");
    }

}

//修改联系人
void Modify(Addressbooks *abs){
    cout << "请输入您要查找的联系人姓名：";
    string name;
    cin >> name;
    int res = isExist(abs, name);
    if(res == -1){
        cout << "查无此人" << endl;
        system("pause");
        system("cls");
    }
    else{
        cout << "查找成功√，原信息为：" << endl;
        cout <<"姓名：" << abs->p[res].name << "\t"
            << "性别：" << (abs->p[res].sex == 1 ? "男" : "女") << "\t"
            << "年龄：" << abs->p[res].age << "\t"
            << "联系电话：" << abs->p[res].phone << "\t\t"
            << "家庭住址：" << abs->p[res].address << endl;
        while(1){
            cout << "请输入对应的数字进行修改，或者输入\"0\"退出修改" << endl;
            cout << "*** 1. 姓名   2. 性别   3. 年龄   4.电话号码   5.家庭住址   0.退出修改 ***" << endl;
            int choice;
            cin >> choice; 
            switch(choice){
                case 1:
                {
                    string name;
                    cout << "请输入修改后的姓名：";
                    cin >> name;
                    abs->p[res].name = name;
                    cout << "修改成功√，修改后的姓名为：" << abs->p[res].name << endl;
                    system("pause");
                    system("cls");
                }
                    break;
                case 2:
                {
                    int sex;
                    cout << "请输入修改后的性别：";
                    cin >> sex;
                    abs->p[res].sex = sex;
                    cout << "修改成功√，修改后的姓名为：" << abs->p[res].sex << endl;
                    system("pause");
                    system("cls");
                }
                    break;
                case 3:
                {
                    int age;
                    cout << "请输入修改后的年龄：";
                    cin >> age;
                    abs->p[res].age = age;
                    cout << "修改成功√，修改后的年龄为：" << abs->p[res].age << endl;
                    system("pause");
                    system("cls");
                }
                    break;
                case 4:
                {
                    string phone;
                    cout << "请输入修改后的电话号码：";
                    cin >> phone;
                    abs->p[res].phone = phone;
                    cout << "修改成功√，修改后的电话号码为：" << abs->p[res].phone << endl;
                    system("pause");
                    system("cls");
                }
                    break;
                case 5:
                {
                    string address;
                    cout << "请输入修改后的家庭住址：";
                    cin >> address;
                    abs->p[res].address = address;
                    cout << "修改成功√，修改后的家庭住址为：" << abs->p[res].address << endl;
                    system("pause");
                    system("cls");
                }
                    break;
                case 0:
                    cout << "退出修改成功√" << endl;
                    system("pause");
                    system("cls");
                    return;
                    break;
                default:
                    break;
            }
        }
        
    }
}

//清空通讯录
void Clear(Addressbooks *abs){
    abs->size = 0;
    cout << "通讯录已清空" << endl;
    system("pause");
    system("cls");
}
//显示目录
void showMenu(){
    cout << "*****************************" << endl;
    cout << "***** " << "\t" << "1、添加联系人" << " \t" << "*****" << endl;
    cout << "***** " << "\t" << "2、显示联系人" << " \t" << "*****" << endl;
    cout << "***** " << "\t" << "3、删除联系人" << " \t" << "*****" << endl;
    cout << "***** " << "\t" << "4、查找联系人" << " \t" << "*****" << endl;
    cout << "***** " << "\t" << "5、修改联系人" << " \t" << "*****" << endl;
    cout << "***** " << "\t" << "6、清空联系人" << " \t" << "*****" << endl;
    cout << "***** " << "\t" << "0、退出通讯录" << " \t" << "*****" << endl;
    cout << "*****************************" << endl;
    
    
}

int main(int argc, char *argv[]){
    Addressbooks abs;
    abs.size = 0; 
    while(1){
        showMenu();
        string choice;
        cout << "请输入操作对应的数字：";
        cin >> choice;
        if(choice != "0" && choice != "1" && choice != "2" && choice !="3" 
            && choice != "4" && choice != "5" && choice != "6"){
            cout << "输入有误，请重新输入！" << endl;
            continue;
        }
        switch(stoi(choice)){
            case 0: //退出通讯录
                Exit();
                return 0;
                break;
            case 1: //添加联系人
                Add(&abs);
                break;
            case 2: //显示联系人
                Show(&abs);
                break;
            case 3: //删除联系人
                Delete(&abs);
                break;
            case 4: //查找联系人
                Search(&abs);
                break;
            case 5: //修改联系人
                Modify(&abs);
                break;
            case 6: //清空联系人
            {
                cout << "确认清空？ (1 === 确认     其他 === 退出)" << endl;
                string temp;
                cin >> temp;
                if(temp == "1"){
                    Clear(&abs);
                }
                else continue;
            }
                
                break;
            default:
                continue;
        }
    }

}
