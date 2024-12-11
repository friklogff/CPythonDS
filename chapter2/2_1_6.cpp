//06．将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。

#include <stdio.h>

#define MaxSize 50 // 定义顺序表的最大长度

// 结构体定义，表示顺序表 (Sequence List)
typedef struct {
	int data[MaxSize]; // 用数组存放数据元素
	int length;        // 线性表的当前长度
} SqList; // 线性表的类型定义

/**
 * 将两个有序顺序表合并成一个有序顺序表
 * @param listA 顺序表 A
 * @param listB 顺序表 B
 * @param listC 用于存储合并结果的顺序表
 * @return 成功合并返回 1，否则返回 0
 */
int mergeOrderedLists(SqList listA, SqList listB, SqList &listC) {
	if (listC.length < listA.length + listB.length)
		return 0; // 如果 listC 的容量不足以存储合并结果，返回 0 表示失败

	int i = 0, j = 0, k = 0;

	// 合并两个有序顺序表
	while (i < listA.length && j < listB.length) {
		if (listA.data[i] <= listB.data[j])
			listC.data[k++] = listA.data[i++];
		else
			listC.data[k++] = listB.data[j++];
	}

	// 将 listA 中剩余的元素加入 listC
	while (i < listA.length)
		listC.data[k++] = listA.data[i++];

	// 将 listB 中剩余的元素加入 listC
	while (j < listB.length)
		listC.data[k++] = listB.data[j++];

	// 更新合并后顺序表的长度
	listC.length = listA.length + listB.length;
	return 1; // 返回 1 表示成功
}

int main() {
	// 初始化三个顺序表
	SqList listA = {{2, 3, 4, 6, 7}, 5};
	SqList listB = {{3, 4, 4}, 3};
	SqList listC;
	listC.length = MaxSize; // 预先设置 listC 的容量为最大容量

	// 打印原始顺序表 listA
	printf("List A: ");
	for (int i = 0; i < listA.length; i++)
		printf("%d ", listA.data[i]);
	printf("\n");

	// 打印原始顺序表 listB
	printf("List B: ");
	for (int i = 0; i < listB.length; i++)
		printf("%d ", listB.data[i]);
	printf("\n");

	// 尝试合并顺序表 listA 和 listB
	if (!mergeOrderedLists(listA, listB, listC))
		printf("合并错误: 目标顺序表容量不足\n");
	else {
		// 打印合并后的顺序表 listC
		printf("Merged List C: ");
		for (int i = 0; i < listC.length; i++) {
			printf("%d ", listC.data[i]);
		}
		printf("\n");
	}

	return 0; // 程序结束
}
