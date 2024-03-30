#include <stdio.h>

#define MaxSize 10 // 定义最大长度

typedef struct {
    int data[MaxSize]; // 用静态的数组存放数据元素
    int length; // 顺序表的当前长度
} SqList; // 顺序表的类型定义

// 在指定位置插入元素
int ListInsert(SqList* L, int i, int e) {
    // 判断插入位置的合法性
    if (i < 1 || i > L->length + 1 || L->length == MaxSize) {
        return 0; // 插入失败
    }
    // 将插入位置后的元素依次向后移动一位
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    // 将新元素插入到指定位置
    L->data[i - 1] = e;
    L->length++; // 线性表长度加1
    return 1; // 插入成功
}

int main() {
    SqList L; // 声明一个顺序表

    // 初始化顺序表
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;
    }
    L.length = 0;

    // 插入元素
    ListInsert(&L, 1, 10);
    ListInsert(&L, 2, 20);

    // 输出插入后的线性表
    printf("Elements in the list: ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    return 0;
}