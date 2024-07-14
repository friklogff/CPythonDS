#include <stdio.h>

#define MaxSize 10 // 定义最大长度

typedef struct {
    int data[MaxSize]; // 用静态的数组存放数据元素
    int length; // 顺序表的当前长度
} SqList; // 顺序表的类型定义

// 删除指定位置的元素，并将值返回给e
int ListDelete(SqList* L, int i, int* e) {
    // 判断删除位置的合法性
    if (i < 1 || i > L->length) {
        return 0; // 删除失败
    }
    // 将要删除的元素的值保存到e中
    *e = L->data[i - 1];
    // 将删除位置后的元素依次向前移动一位
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--; // 线性表长度减1
    return 1; // 删除成功
}

int main() {
    SqList L; // 声明一个顺序表

    // 添加一些示例数据
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = i + 1;
    }
    L.length = MaxSize;

    // 删除元素
    int deletedElem;
    if (ListDelete(&L, 2, &deletedElem)) {
        printf("Deleted element: %d\n", deletedElem);
    }

    // 输出删除元素后的线性表
    printf("Elements in the list: ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    return 0;
}