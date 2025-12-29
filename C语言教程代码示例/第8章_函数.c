// 第8章：函数
// 编译命令: gcc-14 函数.c -o functions
// 运行命令: ./functions

#include <stdio.h>
#include <math.h>

// 函数声明
void say_hello();
int add(int a, int b);
int max(int a, int b);
long long factorial(int n);
int fibonacci(int n);
void swap(int *a, int *b);

int main() {
    // 简单函数调用
    printf("=== 简单函数 ===\n");
    say_hello();
    
    // 带参数的函数
    int result = add(5, 3);
    printf("5 + 3 = %d\n", result);
    
    // 返回值函数
    int maximum = max(10, 20);
    printf("max(10, 20) = %d\n", maximum);
    
    // 递归函数：阶乘
    printf("\n=== 递归：阶乘 ===\n");
    int num = 5;
    printf("%d! = %lld\n", num, factorial(num));
    
    // 递归函数：斐波那契数列
    printf("\n=== 递归：斐波那契数列 ===\n");
    printf("前10项: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    
    // 指针参数函数
    printf("\n=== 指针参数 ===\n");
    int x = 10, y = 20;
    printf("交换前: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("交换后: x = %d, y = %d\n", x, y);
    
    return 0;
}

// 函数定义
void say_hello() {
    printf("Hello from function!\n");
}

int add(int a, int b) {
    return a + b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// 递归计算阶乘
long long factorial(int n) {
    if(n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// 递归计算斐波那契数列
int fibonacci(int n) {
    if(n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// 使用指针交换两个数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
