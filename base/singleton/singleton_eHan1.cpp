#include <iostream>
using namespace std;
// 饿汉式: 线程安全
class CSingleton
{
private:
    CSingleton(){ cout << "单例对象创建！" << endl; };
    CSingleton(const CSingleton &);
    CSingleton& operator=(const CSingleton &);
    ~CSingleton(){ cout << "单例对象销毁！" << endl; };

    static CSingleton myInstance; // 单例对象在这里！
public:
    static CSingleton* getInstance()
    {
        return &myInstance;
    }
};
CSingleton CSingleton::myInstance;

int main(){
    CSingleton *ct1= CSingleton::getInstance();
    CSingleton *ct2= CSingleton::getInstance();
    CSingleton *ct3= CSingleton::getInstance();
    cout<<"to exit"<<endl;
    return 0;
}
