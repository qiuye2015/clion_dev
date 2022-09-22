#include <iostream>
#include <memory> // shared_ptr、unique_ptr、weak_ptr

using namespace std;

class Test : public enable_shared_from_this<Test> {
public:
    ~Test() {
        cout << "Destructor" << endl;
    }

    shared_ptr<Test> GetObject() {
//        shared_ptr<Test> pTest(this);
//        return pTest;
        return shared_from_this();
    }
};

class Child;

class Parent;


class Parent {
private:
    //std::shared_ptr<Child> ChildPtr;
    std::weak_ptr<Child> ChildPtr;
public:
    void setChild(std::shared_ptr<Child> child) {
        this->ChildPtr = child;
    }

    void doSomething() {
        //new shared_ptr
        if (this->ChildPtr.lock()) {

        }
    }

    ~Parent() {
    }
};

class Child {
private:
    std::shared_ptr<Parent> ParentPtr;
public:
    void setPartent(std::shared_ptr<Parent> parent) {
        this->ParentPtr = parent;
    }

    void doSomething() {
        if (this->ParentPtr.use_count()) {

        }
    }

    ~Child() {
    }
};


template<typename T>
class SmartPointer {
private:
    T* _ptr;
    size_t* _count;
public:
    SmartPointer(T* ptr = nullptr) :
            _ptr(ptr) {
        if (_ptr) {
            _count = new size_t(1);
        } else {
            _count = new size_t(0);
        }
    }

    SmartPointer(const SmartPointer& ptr) {
        if (this != &ptr) {
            this->_ptr = ptr._ptr;
            this->_count = ptr._count;
            (*this->_count)++;
        }
    }

    SmartPointer& operator=(const SmartPointer& ptr) {
        if (this->_ptr == ptr._ptr) {
            return *this;
        }

        if (this->_ptr) {
            (*this->_count)--;
            if (this->_count == 0) {
                delete this->_ptr;
                delete this->_count;
            }
        }

        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;
        return *this;
    }

    T& operator*() {
        assert(this->_ptr == nullptr);
        return *(this->_ptr);

    }

    T* operator->() {
        assert(this->_ptr == nullptr);
        return this->_ptr;
    }

    ~SmartPointer() {
        (*this->_count)--;
        if (*this->_count == 0) {
            delete this->_ptr;
            delete this->_count;
        }
    }

    size_t use_count(){
        return *this->_count;
    }
};

int main() {

    {
        shared_ptr<Test> p(new Test());
        cout << "use_count 1: " << p.use_count() << endl;
        shared_ptr<Test> q = p->GetObject();
        cout << "use_count 2: " << p.use_count() << endl;
    }
    { // shared_ptr ---------------------------
        int a = 10;
        std::shared_ptr<int> ptra = std::make_shared<int>(a);
        std::shared_ptr<int> ptra2(ptra); //copy
        std::cout << ptra.use_count() << std::endl; // 2

        int b = 20;
        int *pb = &a;
        //std::shared_ptr<int> ptrb = pb;  //error
        std::shared_ptr<int> ptrb = std::make_shared<int>(b);
        ptra2 = ptrb; //assign
        pb = ptrb.get(); //获取原始指针

        std::cout << ptra.use_count() << std::endl; // 1
        std::cout << ptrb.use_count() << std::endl; // 2
    }
    {// unique_ptr ---------------------------
        std::unique_ptr<int> uptr(new int(10));  //绑定动态对象
        //std::unique_ptr<int> uptr2 = uptr;  //不能賦值
        //std::unique_ptr<int> uptr2(uptr);  //不能拷貝
        std::unique_ptr<int> uptr2 = std::move(uptr); //轉換所有權
        uptr2.release(); //释放所有权

    }
    //超過uptr的作用域，內存釋放

    // 像旁观者那样观测资源的使用情况
    {// unique_ptr ---------------------------
        std::shared_ptr<int> sh_ptr = std::make_shared<int>(10);
        std::cout << sh_ptr.use_count() << std::endl; // 1

        std::weak_ptr<int> wp(sh_ptr);
        std::cout << wp.use_count() << std::endl; // 1

        if (!wp.expired()) {
            std::shared_ptr<int> sh_ptr2 = wp.lock(); //get another shared_ptr
            *sh_ptr = 100;
            std::cout << wp.use_count() << std::endl; // 2
        }
    }

    {
        std::weak_ptr<Parent> wpp;
        std::weak_ptr<Child> wpc;
        {
            std::shared_ptr<Parent> p(new Parent);
            std::shared_ptr<Child> c(new Child);
            p->setChild(c);
            c->setPartent(p);
            wpp = p;
            wpc = c;
            std::cout << p.use_count() << std::endl; // 2
            std::cout << c.use_count() << std::endl; // 1
        }
        std::cout << wpp.use_count() << std::endl;  // 0
        std::cout << wpc.use_count() << std::endl;  // 0
    }
    {
        SmartPointer<int> sp(new int(10));
        SmartPointer<int> sp2(sp);
        SmartPointer<int> sp3(new int(20));
        sp2 = sp3;
        std::cout << sp.use_count() << std::endl;
        std::cout << sp3.use_count() << std::endl;
    }
}


