// 第4章：运算符与表达式
// 编译命令: gcc-14 运算符.c -o operators
// 运行命令: ./operators

#include <stdio.h>

int main() {
    int a = 10, b = 3;
    
    // 算术运算符
    printf("=== 算术运算符 ===\n");
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d (整数除法)\n", a / b);
    printf("a %% b = %d (取余)\n", a % b);
    
    // 自增自减
    printf("\n=== 自增自减 ===\n");
    int x = 5;
    printf("x = %d\n", x);
    printf("x++ = %d (先使用，后增加)\n", x++);
    printf("x = %d\n", x);
    
    int y = 5;
    printf("++y = %d (先增加，后使用)\n", ++y);
    printf("y = %d\n", y);
    
    // 关系运算符
    printf("\n=== 关系运算符 ===\n");
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n", a < b);
    
    // 逻辑运算符
    printf("\n=== 逻辑运算符 ===\n");
    printf("a > 0 && b > 0: %d\n", a > 0 && b > 0);
    printf("a > 5 || b > 5: %d\n", a > 5 || b > 5);
    printf("!(a > b): %d\n", !(a > b));
    
    // 赋值运算符
    printf("\n=== 赋值运算符 ===\n");
    int c = 10;
    printf("初始值: c = %d\n", c);
    c += 5;
    printf("c += 5 => c = %d\n", c);
    c *= 2;
    printf("c *= 2 => c = %d\n", c);
    
    return 0;
}
