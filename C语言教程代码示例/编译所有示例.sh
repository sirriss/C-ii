#!/bin/bash

# C语言教程代码示例 - 编译脚本
# 适用于 M1 MacBook Pro

echo "========================================="
echo "  C语言教程代码示例编译脚本"
echo "  专为 M1 MacBook Pro 设计"
echo "========================================="
echo ""

# 检查gcc是否安装
if ! command -v gcc-14 &> /dev/null; then
    echo "⚠️ 警告：未检测到 gcc-14"
    echo "正在尝试使用 clang..."
    COMPILER="clang"
else
    COMPILER="gcc-14"
fi

echo "使用编译器: $COMPILER"
echo ""

# 编译所有示例
FILES=(
    "第2章_hello.c"
    "第3章_变量和数据类型.c"
    "第4章_运算符.c"
    "第5章_分支结构.c"
    "第6章_循环结构.c"
    "第7章_数组.c"
    "第8章_函数.c"
    "第9章_指针.c"
    "第10章_学生成绩管理系统.c"
)

OUTPUTS=(
    "hello"
    "variables"
    "operators"
    "branches"
    "loops"
    "arrays"
    "functions"
    "pointers"
    "student_system"
)

echo "开始编译..."
echo ""

for i in ${!FILES[@]}; do
    file="${FILES[$i]}"
    output="${OUTPUTS[$i]}"
    
    echo -n "正在编译 $file ... "
    
    if $COMPILER "$file" -o "$output" 2>/dev/null; then
        echo "✅ 成功"
    else
        echo "❌ 失败"
        echo "   尝试使用 clang..."
        if clang "$file" -o "$output" 2>/dev/null; then
            echo "   ✅ clang 编译成功"
        else
            echo "   ❌ clang 也失败了，请检查代码"
        fi
    fi
done

echo ""
echo "========================================="
echo "编译完成！"
echo "========================================="
echo ""
echo "可执行文件列表:"
for output in "${OUTPUTS[@]}"; do
    if [ -f "$output" ]; then
        echo "  ./$output"
    fi
done

echo ""
echo "使用方法:"
echo "  1. 运行程序: ./hello"
echo "  2. 查看帮助: ./student_system (然后按0退出)"
echo ""
echo "提示: 如果提示权限不足，请运行: chmod +x 文件名"
