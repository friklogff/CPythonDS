#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100 // 定义最大长度为100

// 结构体定义，表示顺序表 (Sequence List)
typedef struct {
	int data[MaxSize]; // 用数组存放数据元素
	int length;        // 线性表的当前长度
} SqList; // 线性表的类型定义

/**
 * 从顺序表中删除最小值元素并返回该值
 * @param list 顺序表
 * @param minValue 引用参数，用于保存删除的最小值
 * @return 如果成功删除返回 true，否则返回 false
 */
bool deleteMinElement(SqList &list, int &minValue) {
	// 如果表为空，返回 false
	if (list.length == 0)
		return false;

	// 记录最小值元素的下标
	int minIndex = 0;
	for (int i = 1; i < list.length; i++) {
		// 寻找最小值元素的下标
		if (list.data[i] < list.data[minIndex])
			minIndex = i;
	}

	// 将最小值赋给引用变量 minValue
	minValue = list.data[minIndex];
	// 用最后一个元素覆盖最小值元素所在位置
	list.data[minIndex] = list.data[list.length - 1];
	// 缩小顺序表长度
	list.length--;

	return true; // 返回成功标志
}

int main() {
	// 定义一个顺序表，并初始化其长度和元素
	SqList list;
	list.length = 5; // 假设初始长度为5，元素可以根据需要预设
	list.data[0] = 3;
	list.data[1] = 1;
	list.data[2] = 4;
	list.data[3] = 1;
	list.data[4] = 5;

	// 输出原先数组的内容
	printf("原先数组为:\n");
	for (int i = 0; i < list.length; i++) {
		// 输出数组元素
		printf("%d ", list.data[i]);
	}
	printf("\n");

	int minValue = 0; // 保存最小值
	// 调用 deleteMinElement 函数并判断是否成功
	if (deleteMinElement(list, minValue)) {
		// 若成功，输出删除的最小值
		printf("最小元素 = %d\n", minValue);
		// 并输出修改之后的线性表
		printf("修改之后的线性表为:\n");
		for (int i = 0; i < list.length; i++) {
			// 输出数组元素
			printf("%d ", list.data[i]);
		}
		printf("\n");
	} else {
		// 若失败，提示顺序表为空
		printf("错误: 顺序表为空\n");
	}

	return 0; // 程序结束
}
