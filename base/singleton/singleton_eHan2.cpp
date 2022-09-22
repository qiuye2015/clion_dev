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

    static CSingleton *myInstance;
public:
    static CSingleton* getInstance()
    {
        return myInstance;
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
//CSingleton CSingleton::myInstance;
CSingleton* CSingleton::myInstance=new CSingleton;

int main(){
    CSingleton *ct1= CSingleton::getInstance();
    CSingleton *ct2= CSingleton::getInstance();
    CSingleton *ct3= CSingleton::getInstance();
    cout<<"to exit"<<endl;
//    CSingleton::releaseInstance(); // 手动释放
    return 0;
}
