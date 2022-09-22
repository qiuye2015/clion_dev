#include <iostream>

using namespace std;

class CFinal {
private:
    CFinal() {
        cout << "CFinal" << endl;
    }

    ~CFinal() {
        cout << "~CFinal" << endl;
    }

public:
    static CFinal *getInstance() {
        return new(CFinal);
    }

    static void delInstance(CFinal *pInstance) {
        if (pInstance != nullptr) {
            delete pInstance;
            pInstance = nullptr;
        }
    }
};

//class D:public CFinal{
//    D(){
//
//    }
//};


template<typename T>
class Base {
    friend T;
private:
    Base() {
        cout << "Base" << endl;
    }

    ~Base() {
        cout << "~Base" << endl;
    }
};

class B : virtual Base<B> {
public:
    B() {
        cout << "B" << endl;
    }

    ~B() {
        cout << "~B" << endl;
    }
};
//class C:public B{
//public:
//    C(){
//
//    }
//};