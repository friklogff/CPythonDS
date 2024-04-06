#include <stdio.h>

#define MaxSize 10 // 定义最大长度

typedef struct {
    int data[MaxSize]; // 用静态的数组存放数据元素
    int length; // 顺序表的当前长度
} SqList; // 顺序表的类型定义

// 遍历输出线性表中的所有元素
void PrintList(SqList L) {
    printf("Elements in the list: ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList L; // 声明一个顺序表

    // 添加一些示例数据
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = i + 1;
    }
    L.length = MaxSize;

    // 输出线性表中的元素
    PrintList(L);

    return 0;
}