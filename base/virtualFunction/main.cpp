#include <iostream>

using namespace std;

class Base {
public:
    virtual void f() {
        cout << "Base::f" << endl;
    }

    virtual void g() {
        cout << "Base::g" << endl;
    }

    virtual void h() {
        cout << "Base::h" << endl;
    }
};

using Func = void (*)(void);
// typedef void(*Fun)(void);

int main() {
    Base b;
    Func pFun = nullptr;
//cout<<"虚函数表地址："<<(&b)<<endl;
    cout << "虚函数表地址：" << (int *) (&b) << endl;
    cout << "虚函数表--第一个虚函数地址：" << (int *) *(int *) (&b) << endl;
    pFun = (Func) *((int *) *(int *) (&b));
    pFun();
//   32位系统用int, 64位系统用long long
//    auto p1 = (Func) *((int *) *(int *) (&b) + 0);
//    auto p2 = (Func) *((int *) *(int *) (&b) + 2);
//    auto p3 = (Func) *((int *) *(int *) (&b) + 4);
    auto p1 = (Func) *((long long *) *(long long *) (&b) + 0);
    auto p2 = (Func) *((long long *) *(long long *) (&b) + 1);
    auto p3 = (Func) *((long long *) *(long long *) (&b) + 2);
    p1();
    p2();
    p3();
}
