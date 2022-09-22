#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <memory>
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include <cassert>
#include "assert.h"

using namespace std;

void test();

void print_time() {
    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X");
    cout << "Now is: " << ss.str() << endl;
}

int main() {
    cout << "Hello, CPP!" << endl;
    print_time();
    auto start = chrono::high_resolution_clock::now();
    auto start_time = chrono::steady_clock::now();
    test();
    auto elapsed = chrono::high_resolution_clock::now() - start;
    auto end_time = chrono::steady_clock::now();
    auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
    cout << "Bye!! elapsed: " << chrono::duration_cast<chrono::microseconds>(elapsed).count() << "ms; \nConsumed     : "
         << ms << "ms;" << endl;
    return 0;
}

bool isMatch(string s, string p) {
    // p 可能为空
    if (p.empty()) return s.empty();
    if (p.size()>0 && p[0]=='*') {
        auto zero = isMatch(s, p.substr(1));//匹配0个
        auto mut = !s.empty() && (p[0] == s[0] || p[0] == '?' || p[0]=='*') &&
                   isMatch(s.substr(1), p); // 匹配多个
        cout<<"* "<<s<<" "<<p<<" "<<zero<<mut<<endl;
        return zero || mut;
    }else{
        auto b = !s.empty() && (p[0] == s[0] || p[0] == '?') &&
                 isMatch(s.substr(1), p.substr(1));
        cout<<"-- "<<s<<" "<<p<<" "<<b<<endl;
        return b;
    }
}

void test() {
    string s("adceb");
    string p("*a*b");
    cout<<isMatch(s,p)<<endl;
}























