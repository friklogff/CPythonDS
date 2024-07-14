#include <stdio.h>

#define MaxSize 10 // 定义最大长度

typedef struct {
    int data[MaxSize]; // 用静态的数组存放数据元素
    int length; // 顺序表的当前长度
} SqList; // 顺序表的类型定义

// 销毁线性表
void DestroyList(SqList &L) {
    L.length = 0; // 将线性表的长度置为0，相当于清空线性表
}

int main() {
    SqList L; // 声明一个顺序表

    // 添加一些示例数据
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;

    // 销毁线性表
    DestroyList(L);

    // 输出销毁后的长度
    printf("Length of the list after destruction: %d\n", L.length);

    return 0;
}