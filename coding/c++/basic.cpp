#include <iostream>
using namespace std;
int add(int a, int b)
{

    int c;
    cout << "enter number";
    cin >> a >> b;
    c = a + b;
    cout << "sum=" << c;
    return 0;
}

int main()
{

    cout << "hello world";
    int x, y;
    add(x, y);
    return 0;
}