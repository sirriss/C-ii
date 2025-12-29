// 第7章：数组
// 编译命令: gcc-14 数组.c -o arrays
// 运行命令: ./arrays

#include <stdio.h>

int main() {
    // 一维数组示例
    printf("=== 一维数组 ===\n");
    int numbers[5] = {10, 20, 30, 40, 50};
    
    printf("数组元素: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // 计算平均值
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += numbers[i];
    }
    printf("平均值: %.2f\n", (float)sum / 5);
    
    // 二维数组示例
    printf("\n=== 二维数组 ===\n");
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    printf("矩阵元素:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // 冒泡排序
    printf("\n=== 冒泡排序 ===\n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("排序前: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 冒泡排序算法
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // 交换
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("排序后: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 字符数组和字符串
    printf("\n=== 字符串处理 ===\n");
    char name[50] = "M1 MacBook Pro";
    printf("字符串: %s\n", name);
    printf("长度: %lu\n", strlen(name));
    
    // 字符串复制
    char greeting[100] = "Hello, ";
    strcat(greeting, name);
    printf("连接后: %s\n", greeting);
    
    return 0;
}
