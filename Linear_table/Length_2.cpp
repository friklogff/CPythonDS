#include <stdio.h>

#define MaxSize 10 // 定义最大长度

typedef struct {
    int data[MaxSize]; // 用静态的数组存放数据元素
    int length; // 顺序表的当前长度
} SqList; // 顺序表的类型定义

// 求线性表的长度
int Length(const SqList* L) {
    return L->length;
}

int main() {
    SqList L; // 声明一个顺序表

    // 添加一些示例数据
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = i + 1;
    }
    L.length = MaxSize;

    // 输出线性表的长度
    printf("Length of the list: %d\n", Length(&L));

    return 0;
}