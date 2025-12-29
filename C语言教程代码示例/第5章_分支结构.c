// 第5章：分支结构
// 编译命令: gcc-14 分支结构.c -o branches
// 运行命令: ./branches

#include <stdio.h>

int main() {
    // if-else 示例：判断成年
    int age;
    printf("请输入年龄: ");
    scanf("%d", &age);
    
    if(age >= 18) {
        printf("你是成年人\n");
    } else {
        printf("你是未成年人\n");
    }
    
    // if-else if-else 示例：成绩等级
    int score;
    printf("\n请输入成绩(0-100): ");
    scanf("%d", &score);
    
    if(score >= 90) {
        printf("优秀 (A)\n");
    } else if(score >= 80) {
        printf("良好 (B)\n");
    } else if(score >= 70) {
        printf("中等 (C)\n");
    } else if(score >= 60) {
        printf("及格 (D)\n");
    } else {
        printf("不及格 (F)\n");
    }
    
    // switch 示例：星期判断
    int day;
    printf("\n请输入数字(1-7): ");
    scanf("%d", &day);
    
    switch(day) {
        case 1:
            printf("星期一\n");
            break;
        case 2:
            printf("星期二\n");
            break;
        case 3:
            printf("星期三\n");
            break;
        case 4:
            printf("星期四\n");
            break;
        case 5:
            printf("星期五\n");
            break;
        case 6:
            printf("星期六\n");
            break;
        case 7:
            printf("星期日\n");
            break;
        default:
            printf("无效输入！请输入1-7之间的数字\n");
    }
    
    return 0;
}
