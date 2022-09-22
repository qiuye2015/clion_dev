#include <iostream>
using namespace std;
// 懒汉式: 线程不安全
class CSingleton
{
private:
    CSingleton(){ cout << "单例对象创建！" << endl; };
    CSingleton(const CSingleton &);
    CSingleton& operator=(const CSingleton &);
    ~CSingleton(){ cout << "单例对象销毁！" << endl; };
public:
    static CSingleton * getInstance()
    {   // lock();
        static CSingleton myInstance;
       // unlock();
        return &myInstance;
    }

};
int main(){
    CSingleton *ct1= CSingleton::getInstance();
    CSingleton *ct2= CSingleton::getInstance();
    CSingleton *ct3= CSingleton::getInstance();
    cout<<"to exit"<<endl;
    return 0;
}
