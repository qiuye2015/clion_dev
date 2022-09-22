
// 将拷贝构造函数和重载赋值运算符设为private来禁止拷贝
#define DISABLE_COPY(Class) \
Class(const Class &); \
Class &operator=(const Class &)

class Widget {
public:
    int *pi;
private:
    DISABLE_COPY(Widget);
};