// 第9章：指针入门
// 编译命令: gcc-14 指针.c -o pointers
// 运行命令: ./pointers

#include <stdio.h>

int main() {
    // 基本指针操作
    printf("=== 基本指针操作 ===\n");
    int num = 25;
    int *ptr = &num;
    
    printf("num的值: %d\n", num);
    printf("num的地址: %p\n", &num);
    printf("ptr存储的地址: %p\n", ptr);
    printf("ptr指向的值: %d\n", *ptr);
    
    // 通过指针修改值
    *ptr = 50;
    printf("\n修改后 num的值: %d\n", num);
    
    // 指针和数组
    printf("\n=== 指针和数组 ===\n");
    int arr[5] = {10, 20, 30, 40, 50};
    int *arr_ptr = arr;
    
    printf("数组元素: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(arr_ptr + i));
    }
    printf("\n");
    
    // 指针算术运算
    printf("\n=== 指针算术运算 ===\n");
    printf("arr_ptr = %p, *arr_ptr = %d\n", arr_ptr, *arr_ptr);
    arr_ptr++;
    printf("arr_ptr++后: %p, *arr_ptr = %d\n", arr_ptr, *arr_ptr);
    
    // M1 ARM架构下的指针地址特点
    printf("\n=== M1 ARM架构下的指针 ===\n");
    char ch = 'A';
    int n = 100;
    float f = 3.14;
    
    char *ch_ptr = &ch;
    int *n_ptr = &n;
    float *f_ptr = &f;
    
    printf("char指针大小: %lu 字节\n", sizeof(ch_ptr));
    printf("int指针大小: %lu 字节\n", sizeof(n_ptr));
    printf("float指针大小: %lu 字节\n", sizeof(f_ptr));
    printf("所有指针在M1上都是8字节（64位）\n");
    
    // 字符串和指针
    printf("\n=== 字符串和指针 ===\n");
    char str[] = "Hello M1";
    char *str_ptr = str;
    
    printf("字符串: %s\n", str);
    printf("逐个字符: ");
    while(*str_ptr != '\0') {
        printf("%c ", *str_ptr);
        str_ptr++;
    }
    printf("\n");
    
    return 0;
}
