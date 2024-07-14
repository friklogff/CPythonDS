#include <stdio.h>

#define MaxSize 10

typedef struct {
	int data[MaxSize]; // 用数组存放数据元素
	int length; // 线性表的当前长度
} SqList; // 线性表的类型定义

void findd(SqList *L, int x) {
	int left, right, mid;
	left = 0, right = L->length - 1;

	while (left <= right) {
		mid = (left + right) / 2;
		if (L->data[mid] == x)
			break;
		else if (L->data[mid] > x)
			right = mid - 1;
		else
			left = mid + 1;
	}

	if (L->data[mid] == x && mid != L->length - 1) {
		int t = L->data[mid];
		L->data[mid] = L->data[mid + 1];
		L->data[mid + 1] = t;
	}

	if (right < left) {
		int i;
		for (i = L->length - 1; i > right; i--) {
			L->data[i + 1] = L->data[i];
		}
		L->data[i + 1] = x;
		L->length++;
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
