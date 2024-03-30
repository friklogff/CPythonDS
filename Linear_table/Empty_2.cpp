#include <stdio.h>
#include <stdbool.h>

#define MaxSize 10 // 定义最大长度

typedef struct {
    int data[MaxSize]; // 用静态的数组存放数据元素
    int length; // 顺序表的当前长度
} SqList; // 顺序表的类型定义

// 判断线性表是否为空
bool Empty(const SqList* L) {
    return (L->length == 0);
}

int main() {
    SqList L; // 声明一个顺序表

    // 初始化顺序表
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;
    }
    L.length = 0;

    // 判断线性表是否为空
    if (Empty(&L)) {
        printf("The list is empty\n");
    } else {
        printf("The list is not empty\n");
    }

    return 0;
}