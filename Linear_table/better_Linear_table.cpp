#include <stdio.h>

#define MaxSize 10 // 定义最大长度

typedef struct {
    int data[MaxSize]; // 用静态的数组存放数据元素
    int length; // 顺序表的当前长度
} SqList; // 顺序表的类型定义

// 初始化一个顺序表
void InitList(SqList& L) {
    L.length = 0; // 顺序表初始长度为0
}

// 获取顺序表中指定位置的元素
int GetElem(const SqList& L, int i) {
    // 判断位置是否合法
    if (i < 1 || i > L.length) {
        printf("Error: Invalid position\n");
        return -1; // 返回一个表示错误的值，可根据实际需求调整
    }
    return L.data[i - 1]; // 返回指定位置的元素
}

int main() {
    SqList L; // 声明一个顺序表
    InitList(L); // 初始化顺序表L

    // 添加一些示例数据
    L.data[0] = 10;
    L.data[1] = 20;
    L.data[2] = 30;
    L.length = 3;

    // 获取指定位置的元素并打印
    int position = 2;
    int elem = GetElem(L, position);
    printf("The element at position %d is %d\n", position, elem);

    return 0;
}