#include "iostream"

using namespace std;

class Date {
private:
    int _year;
    int _month;
    int _day;
public:
    Date(int year = 2022, int month = 7, int day = 18) {
        _year = year, _month = month, _day = day;
    }

    //  Date(const Date& date);
    // ~Date();
    friend ostream &operator<<(ostream &_cout, Date &date);

    friend istream &operator>>(istream &_in, Date &date);
//    为什么一定要在类外面用友元去编写，直接让其作为类的成员函数实现不就好了。其实
//    作为类的成员函数实现也是可以的，但是这样会有一个不好的地方，作为类的成员函数，那么就一定会有默认
//    的this指针，那么你就只需要传一个参数就好了，但是，这样你就需要将cout或者是cin写在后面了，像
//    year<<cout;这样，毕竟有一个隐含的this指针，所以需要使用友元来完成
};

ostream &operator<<(ostream &_cout, Date &date) {
    _cout << date._year << "-" << date._month << "-" << date._day;
    return _cout;
}

istream &operator>>(istream &_in, Date &date) {
    _in >> date._year >> date._month >> date._day;
    return _in;
}

int main() {
    Date d;
    cout << d << endl;
    cin >> d;
    cout << d;
}