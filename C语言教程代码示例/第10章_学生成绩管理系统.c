/*
 * 第10章：综合实战项目 - 简易学生成绩管理系统
 * 适用于 M1 MacBook Pro
 * 编译命令: gcc-14 学生成绩管理系统.c -o student_system
 * 运行命令: ./student_system
 */

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100  // 最大学生数
#define MAX_NAME_LENGTH 50  // 姓名最大长度

// 学生结构体
typedef struct {
    int id;                           // 学号
    char name[MAX_NAME_LENGTH];       // 姓名
    float chinese;                    // 语文成绩
    float math;                       // 数学成绩
    float english;                    // 英语成绩
    float average;                    // 平均分
} Student;

// 全局变量
Student students[MAX_STUDENTS];
int student_count = 0;

// 函数声明
void show_menu();
void add_student();
void display_all_students();
void search_student();
void calculate_class_average();
void sort_by_average();
void show_statistics();
void clear_screen();

int main() {
    int choice;
    
    printf("=========================================\n");
    printf("    学生成绩管理系统 v1.0\n");
    printf("    专为 M1 MacBook Pro 优化\n");
    printf("=========================================\n\n");
    
    while(1) {
        show_menu();
        printf("请选择操作: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_all_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                calculate_class_average();
                break;
            case 5:
                sort_by_average();
                break;
            case 6:
                show_statistics();
                break;
            case 0:
                printf("\n感谢使用！再见！\n");
                return 0;
            default:
                printf("无效的选择！请重新输入。\n");
        }
        
        printf("\n按回车键继续...");
        getchar();  // 吸收换行符
        getchar();  // 等待用户按键
        clear_screen();
    }
    
    return 0;
}

// 显示菜单
void show_menu() {
    printf("\n========== 主菜单 ==========\n");
    printf("1. 添加学生信息\n");
    printf("2. 显示所有学生\n");
    printf("3. 查询学生成绩\n");
    printf("4. 计算班级平均分\n");
    printf("5. 按平均分排序\n");
    printf("6. 成绩统计\n");
    printf("0. 退出系统\n");
    printf("=============================\n");
}

// 添加学生
void add_student() {
    if(student_count >= MAX_STUDENTS) {
        printf("学生数量已达上限！\n");
        return;
    }
    
    Student *s = &students[student_count];
    
    printf("\n--- 添加学生 ---\n");
    
    printf("请输入学号: ");
    scanf("%d", &s->id);
    
    printf("请输入姓名: ");
    scanf("%s", s->name);
    
    printf("请输入语文成绩: ");
    scanf("%f", &s->chinese);
    
    printf("请输入数学成绩: ");
    scanf("%f", &s->math);
    
    printf("请输入英语成绩: ");
    scanf("%f", &s->english);
    
    // 计算平均分
    s->average = (s->chinese + s->math + s->english) / 3.0;
    
    student_count++;
    
    printf("\n✅ 学生 %s 添加成功！\n", s->name);
    printf("平均分: %.2f\n", s->average);
}

// 显示所有学生
void display_all_students() {
    if(student_count == 0) {
        printf("\n暂无学生信息！\n");
        return;
    }
    
    printf("\n--- 所有学生信息 ---\n");
    printf("%-8s %-12s %-8s %-8s %-8s %-8s\n", 
           "学号", "姓名", "语文", "数学", "英语", "平均分");
    printf("--------------------------------------------------\n");
    
    for(int i = 0; i < student_count; i++) {
        printf("%-8d %-12s %-8.1f %-8.1f %-8.1f %-8.2f\n",
               students[i].id,
               students[i].name,
               students[i].chinese,
               students[i].math,
               students[i].english,
               students[i].average);
    }
    
    printf("--------------------------------------------------\n");
    printf("总人数: %d\n", student_count);
}

// 查询学生
void search_student() {
    if(student_count == 0) {
        printf("\n暂无学生信息！\n");
        return;
    }
    
    int search_id;
    int found = 0;
    
    printf("\n--- 查询学生 ---\n");
    printf("请输入学号: ");
    scanf("%d", &search_id);
    
    for(int i = 0; i < student_count; i++) {
        if(students[i].id == search_id) {
            printf("\n找到学生！\n");
            printf("学号: %d\n", students[i].id);
            printf("姓名: %s\n", students[i].name);
            printf("语文: %.1f\n", students[i].chinese);
            printf("数学: %.1f\n", students[i].math);
            printf("英语: %.1f\n", students[i].english);
            printf("平均分: %.2f\n", students[i].average);
            
            // 判断等级
            if(students[i].average >= 90) {
                printf("等级: 优秀 🌟\n");
            } else if(students[i].average >= 80) {
                printf("等级: 良好 👍\n");
            } else if(students[i].average >= 70) {
                printf("等级: 中等 😊\n");
            } else if(students[i].average >= 60) {
                printf("等级: 及格 📝\n");
            } else {
                printf("等级: 不及格 ⚠️\n");
            }
            
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("\n❌ 未找到学号为 %d 的学生！\n", search_id);
    }
}

// 计算班级平均分
void calculate_class_average() {
    if(student_count == 0) {
        printf("\n暂无学生信息！\n");
        return;
    }
    
    float total_chinese = 0, total_math = 0, total_english = 0;
    float avg_chinese, avg_math, avg_english;
    
    for(int i = 0; i < student_count; i++) {
        total_chinese += students[i].chinese;
        total_math += students[i].math;
        total_english += students[i].english;
    }
    
    avg_chinese = total_chinese / student_count;
    avg_math = total_math / student_count;
    avg_english = total_english / student_count;
    
    printf("\n--- 班级平均分 ---\n");
    printf("语文平均分: %.2f\n", avg_chinese);
    printf("数学平均分: %.2f\n", avg_math);
    printf("英语平均分: %.2f\n", avg_english);
    printf("总平均分: %.2f\n", (avg_chinese + avg_math + avg_english) / 3.0);
}

// 按平均分排序
void sort_by_average() {
    if(student_count == 0) {
        printf("\n暂无学生信息！\n");
        return;
    }
    
    // 使用冒泡排序
    for(int i = 0; i < student_count - 1; i++) {
        for(int j = 0; j < student_count - i - 1; j++) {
            if(students[j].average < students[j + 1].average) {
                // 交换学生信息
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    printf("\n✅ 已按平均分从高到低排序！\n");
    display_all_students();
}

// 成绩统计
void show_statistics() {
    if(student_count == 0) {
        printf("\n暂无学生信息！\n");
        return;
    }
    
    int pass_count = 0;
    int excellent_count = 0;
    float max_average = students[0].average;
    float min_average = students[0].average;
    int max_index = 0, min_index = 0;
    
    for(int i = 0; i < student_count; i++) {
        // 统计及格人数
        if(students[i].average >= 60) {
            pass_count++;
        }
        
        // 统计优秀人数
        if(students[i].average >= 90) {
            excellent_count++;
        }
        
        // 找最高和最低分
        if(students[i].average > max_average) {
            max_average = students[i].average;
            max_index = i;
        }
        if(students[i].average < min_average) {
            min_average = students[i].average;
            min_index = i;
        }
    }
    
    float pass_rate = (float)pass_count / student_count * 100;
    float excellent_rate = (float)excellent_count / student_count * 100;
    
    printf("\n--- 成绩统计 ---\n");
    printf("总人数: %d\n", student_count);
    printf("及格人数: %d\n", pass_count);
    printf("优秀人数: %d\n", excellent_count);
    printf("及格率: %.2f%%\n", pass_rate);
    printf("优秀率: %.2f%%\n", excellent_rate);
    printf("\n最高分:\n");
    printf("  学生: %s (%.2f分)\n", students[max_index].name, max_average);
    printf("\n最低分:\n");
    printf("  学生: %s (%.2f分)\n", students[min_index].name, min_average);
}

// 清屏函数
void clear_screen() {
    // 在终端中清屏
    printf("\033[2J\033[H");
}
