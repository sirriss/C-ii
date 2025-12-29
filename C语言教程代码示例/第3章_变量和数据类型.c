// 第3章：变量与数据类型
// 编译命令: gcc-14 变量和数据类型.c -o variables
// 运行命令: ./variables

#include <stdio.h>

int main() {
    // 声明并初始化变量
    int age = 25;                    // 整数
    float height = 1.75;            // 浮点数
    char grade = 'A';               // 字符
    double pi = 3.1415926;          // 双精度浮点数
    
    // 使用变量
    printf("年龄: %d\n", age);
    printf("身高: %.2f 米\n", height);
    printf("成绩: %c\n", grade);
    printf("圆周率: %lf\n", pi);
    
    // 使用sizeof查看内存占用
    printf("\n数据类型在M1下的内存占用:\n");
    printf("char: %lu 字节\n", sizeof(char));
    printf("int: %lu 字节\n", sizeof(int));
    printf("float: %lu 字节\n", sizeof(float));
    printf("double: %lu 字节\n", sizeof(double));
    printf("long: %lu 字节\n", sizeof(long));
    
    return 0;
}
