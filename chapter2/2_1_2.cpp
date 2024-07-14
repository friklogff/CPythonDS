#include <stdio.h>
#include <stdbool.h>

#define Max 50 // 定义顺序表的最大长度

// 结构体定义，表示顺序表 (Sequence List)
typedef struct {
	int data[Max]; // 用数组存放数据元素
	int length;    // 线性表的当前长度
} SqList; // 线性表的类型定义

/**
 * 初始化顺序表
 * @param list 顺序表
 */
void initializeList(SqList &list) {
	// 定义初始化数组
	int initValues[] = {1, 4, 6, 3, 2, 8, 7};
	int initLength = sizeof(initValues) / sizeof(initValues[0]);

	// 将初始值赋给顺序表
	for (int i = 0; i < initLength; i++) {
		list.data[i] = initValues[i];
	}
	list.length = initLength; // 设置顺序表长度
}

/**
 * 反转顺序表
 * @param list 顺序表
 */
void reverseList(SqList &list) {
	// 交换顺序表中对称位置的元素
	for (int i = 0; i < list.length / 2; i++) {
		int temp = list.data[i];
		list.data[i] = list.data[list.length - i - 1];
		list.data[list.length - i - 1] = temp;
	}
}

/**
 * 打印顺序表
 * @param list 顺序表
 */
void printList(const SqList &list) {
	// 输出顺序表中的每个元素
	for (int i = 0; i < list.length; i++) {
		printf("%d ", list.data[i]);
	}
	printf("\n");
}

int main() {
	SqList list; // 定义一个顺序表
	initializeList(list); // 初始化顺序表

	printf("Original list:\n");
	printList(list); // 打印原始顺序表

	reverseList(list); // 反转顺序表

	printf("Reversed list:\n");
	printList(list); // 打印反转后的顺序表

	return 0; // 程序结束
}
