#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100 // 定义最大长度

typedef struct {
    int data[MaxSize]; // 用数组存放数据元素
    int length; // 线性表的当前长度
} SqList; // 线性表的类型定义

// 初始化一个线性表
void InitList(SqList* L) {
    L->length = 0; // 将线性表的长度初始化为0
}

// 销毁线性表
void DestroyList(SqList* L) {
    L->length = 0; // 将线性表的长度置为0，相当于清空线性表
}

// 在指定位置插入元素
bool ListInsert(SqList* L, int i, int e) {
    // 判断插入位置的合法性
    if (i < 1 || i > L->length + 1) {
        printf("Error: Invalid position\n");
        return false;
    }
    // 判断线性表是否已满
    if (L->length == MaxSize) {
        printf("Error: Linear list is full\n");
        return false;
    }
    // 将插入位置后的元素依次向后移动一位
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    // 将新元素插入到指定位置
    L->data[i - 1] = e;
    L->length++; // 线性表长度加1
    return true;
}

// 删除指定位置的元素，并将值返回给e
bool ListDelete(SqList* L, int i, int* e) {
    // 判断删除位置的合法性
    if (i < 1 || i > L->length) {
        printf("Error: Invalid position\n");
        return false;
    }
    // 将要删除的元素的值保存到e中
    *e = L->data[i - 1];
    // 将删除位置后的元素依次向前移动一位
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--; // 线性表长度减1
    return true;
}

// 按值查找元素的位置
int LocateElem(const SqList* L, int e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i + 1; // 返回位置（从1开始计数）
        }
    }
    return -1; // 未找到时返回-1
}

// 按位查找元素的值
bool GetElem(const SqList* L, int i, int* e) {
    // 判断查找位置的合法性
    if (i < 1 || i > L->length) {
        printf("Error: Invalid position\n");
        return false;
    }
    // 将找到的元素的值保存到e中
    *e = L->data[i - 1];
    return true;
}

// 求线性表的长度
int Length(const SqList* L) {
    return L->length;
}

// 遍历输出线性表中的所有元素
void PrintList(const SqList* L) {
    printf("Elements in the linear list: ");
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 判断线性表是否为空
bool Empty(const SqList* L) {
    return (L->length == 0);
}

int main() {
    SqList L; // 声明一个线性表
    InitList(&L); // 初始化线性表L

    // 插入示例元素
    ListInsert(&L, 1, 10);
    ListInsert(&L, 2, 20);
    ListInsert(&L, 3, 30);

    // 输出线性表中的元素
    PrintList(&L);

    // 获取指定位置的元素
    int position = 2;
    int elem;
    if (GetElem(&L, position, &elem)) {
        printf("The element at position %d is %d\n", position, elem);
    }

    // 删除指定位置的元素
    int deletedElem;
    if (ListDelete(&L, 2, &deletedElem)) {
        printf("Deleted element: %d\n", deletedElem);
    }

    // 输出删除元素后的线性表
    PrintList(&L);

    // 销毁线性表
    DestroyList(&L);

    return 0;
}