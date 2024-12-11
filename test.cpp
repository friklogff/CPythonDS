
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100 // 定义最大长度为100

// 结构体定义，表示顺序表 (Sequence List)
typedef struct {



	int data[MaxSize]; // 用数组存放数据元素
	int length;        // 线性表的当前长度
} SqList; // 线性表的类型定义
//08.线性表(a1, a2, a3,……, an)中的元素递增有序且按顺序存储于计算机内。要求设计一个算法，完成用最少时间在表中查找数值为x的元素，
//若找到，则将其与后继元素位置相交换，若找不到，则将其插入表中并使表中元素仍递增有序。
void findd(SqList *L, int x) {
	int left, right, mid;
	left = 0, right = L->length - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (x > L->data[mid])
			left = mid + 1;
		if (x = L->data[mid])
			break;
		if (x < L->data[mid])
			right = mid - 1;
	}
	if (left > right) {

	}

}

int main() {
	SqList L = {{1, 2, 3, 4, 5, 7, 8, 9, 10}, 9};

	for (int i = 0; i < L.length; i++)
		printf("%d ", L.data[i]);
	printf("\n");

	findd(&L, 6);

	for (int i = 0; i < L.length; i++)
		printf("%d ", L.data[i]);
	printf("\n");

	return 0;
}
