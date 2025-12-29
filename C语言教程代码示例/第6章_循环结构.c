// 第6章：循环结构
// 编译命令: gcc-14 循环结构.c -o loops
// 运行命令: ./loops

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // for循环示例：打印1-10
    printf("=== for循环：打印1-10 ===\n");
    for(int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // for循环示例：计算1-100的和
    printf("\n=== 计算1-100的和 ===\n");
    int sum = 0;
    for(int i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("1到100的和: %d\n", sum);
    
    // while循环示例：猜数字游戏
    printf("\n=== 猜数字游戏 ===\n");
    srand(time(NULL));
    int secret = rand() % 100 + 1;
    int guess, attempts = 0;
    
    printf("我想了一个1-100之间的数字\n");
    
    while(1) {
        printf("请输入你的猜测: ");
        scanf("%d", &guess);
        attempts++;
        
        if(guess < secret) {
            printf("太小了！\n");
        } else if(guess > secret) {
            printf("太大了！\n");
        } else {
            printf("恭喜你，猜对了！\n");
            printf("你总共猜了%d次\n", attempts);
            break;
        }
    }
    
    // do-while循环示例：菜单
    printf("\n=== 菜单示例 ===\n");
    int choice;
    do {
        printf("\n菜单:\n");
        printf("1. 开始\n");
        printf("2. 设置\n");
        printf("3. 退出\n");
        printf("请选择: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("开始游戏！\n");
                break;
            case 2:
                printf("进入设置\n");
                break;
            case 3:
                printf("退出\n");
                break;
            default:
                printf("无效选择！\n");
        }
    } while(choice != 3);
    
    // 循环嵌套示例：九九乘法表
    printf("\n=== 九九乘法表 ===\n");
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d×%d=%-2d ", j, i, i * j);
        }
        printf("\n");
    }
    
    return 0;
}
