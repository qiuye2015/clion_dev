#include "stdio.h"
#pragma pack(1) /*1字节对齐*/
struct test
{
    int a;
    char b;
    int c;
    short d;
};//16
#pragma pack()/*还原默认对齐*/

struct test1
{
    int a;
    char b;
    int c;
    short d;
}__attribute__ ((packed));

struct test2
{
    int a;
    char b;
    int c;
    short d;
}__attribute__ ((aligned (32)));
struct test3
{
    char a;
    char b;
};

int main(){
    printf("the size of struct test is %zu\n",sizeof(struct test));
    printf("the size of struct test is %zu\n",sizeof(struct test1));
    printf("the size of struct test is %zu\n",sizeof(struct test2));
    printf("the size of struct test is %zu\n",sizeof(struct test3));
}