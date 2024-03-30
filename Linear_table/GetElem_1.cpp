#include <stdio.h>

#define MaxSize 10 // 定义最大长度

typedef struct {
	int data[MaxSize]; // 用静态的数组存放数据元素
	int length; // 顺序表的当前长度
} SqList; // 顺序表的类型定义

// 按位查找元素的值
int GetElem(SqList L, int i) {
	// 判断查找位置的合法性
	if (i < 1 || i > L.length) {
		return -1; // 返回一个表示错误的值
	}
	// 返回指定位置的元素的值
	return L.data[i - 1];
}

int main() {
	SqList L; // 声明一个顺序表

	// 添加一些示例数据
	for (int i = 0; i < MaxSize; i++) {
		L.data[i] = i + 1;
	}
	L.length = MaxSize;

	// 获取指定位置的元素
	int position = 3;
	int elem = GetElem(L, position);
	if (elem != -1) {
		printf("Element at position %d is %d\n", position, elem);
	} else {
		printf("Invalid position\n");
	}

	return 0;
}