#include <stdio.h>

#define MaxSize 10 // 定义最大长度

typedef struct {
	int data[MaxSize]; // 用静态的数组存放数据元素
	int length; // 顺序表的当前长度
} SqList; // 顺序表的类型定义

// 按值查找元素的位置
int LocateElem(const SqList* L, int e) {
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] == e) {
			return i + 1; // 返回位置（从1开始计数）
		}
	}
	return -1; // 未找到时返回-1
}

int main() {
	SqList L; // 声明一个顺序表

	// 添加一些示例数据
	for (int i = 0; i < MaxSize; i++) {
		L.data[i] = i + 1;
	}
	L.length = MaxSize;

	// 查找元素的位置
	int elem = 5;
	int position = LocateElem(&L, elem);
	if (position != -1) {
		printf("Element %d is at position %d\n", elem, position);
	} else {
		printf("Element %d not found\n", elem);
	}

	return 0;
}