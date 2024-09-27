#include <iostream>
#include "s.h"
using namespace std;

int main(int argc, char *argv[])
{
    int a = 10, b = 20;
    swap(&a, &b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
