#include <stdio.h>

/*
 * 本程序用来复习初阶部分结构体，对于一些简单的代码的练习
 * 郭文峰
 * 2018/12/9
 */
 struct People 
 {
    char *name;
    int  stature;
    char sex;
    char age;
 };

 int main(void)
 {
    
    struct People gerald;
     gerald.name = "Gerald Kwok";
     gerald.stature = 178;
     gerald.sex = 'm';
     gerald.age = 21;

     printf("%s\n%d\n%c\n%d\n", gerald.name, gerald.stature, gerald.sex, gerald.age);
     
     return 0;
 }
