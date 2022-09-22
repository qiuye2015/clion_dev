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

    static CSingleton *myInstance;


public:
    static CSingleton * getInstance()
    {   if (nullptr==myInstance){ // new add
            // lock();
            if (nullptr == myInstance)
            {
                myInstance = new CSingleton();
            }
            return myInstance;
            // ulock();
        }
    }

private:
    // 定义一个内部类
    class CGarbo{
    public:
        CGarbo(){};
        ~CGarbo()
        {
            if (nullptr != myInstance)
            {
                delete myInstance;
                myInstance = nullptr;
            }
        }
    };
    // 定义一个内部类的静态对象
    // 当该对象销毁时，顺带就释放myInstance指向的堆区资源
    static CGarbo m_garbo;
};
CSingleton * CSingleton::myInstance = nullptr;
CSingleton::CGarbo CSingleton::m_garbo;

int main(){
    CSingleton *ct1= CSingleton::getInstance();
    CSingleton *ct2= CSingleton::getInstance();
    CSingleton *ct3= CSingleton::getInstance();
    cout<<"to exit"<<endl;
    return 0;
}
