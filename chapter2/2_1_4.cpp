#include <stdio.h>

#define MaxSize 50 // 定义顺序表的最大长度

// 结构体定义，表示顺序表 (Sequence List)
typedef struct {
	int data[MaxSize]; // 用数组存放数据元素
	int length;        // 线性表的当前长度
} SqList; // 线性表的类型定义

/**
 * 删除顺序表中所有值在区间 [s, v] 的元素
 * @param list 顺序表
 * @param s 区间下限
 * @param v 区间上限
 * @return 成功删除返回 1，否则返回 0
 */
int deleteElementsInRange(SqList &list, int s, int v) {
	if (s >= v || list.length == 0) {
		// 当 s 大于等于 v 或者顺序表为空时，返回 0 表示失败
		return 0;
	}

	int start = -1; // 标记第一个 >= s 的元素下标
	// 找到第一个 >= s 的元素
	for (int i = 0; i < list.length; i++) {
		if (list.data[i] >= s) {
			start = i;
			break;
		}
	}

	// 如果没有找到 >= s 的元素，返回 0
	if (start == -1)
		return 0;

	int end = list.length; // 标记第一个 > v 的元素下标
	// 找到第一个 > v 的元素
	for (int i = start; i < list.length; i++) {
		if (list.data[i] > v) {
			end = i;
			break;
		}
	}

	// 将位于区间 [s, v] 之外的元素向前移动
	int newLength = start;
	for (int i = end; i < list.length; i++) {
		list.data[newLength] = list.data[i];
		newLength++;
	}

	// 更新顺序表的长度
	list.length = newLength;

	return 1; // 返回 1 表示成功
}

int main() {
	// 初始化一个顺序表
	SqList list = {{1, 2, 3, 3, 4, 5, 6, 7, 7, 7, 8, 9}, 12};

	// 打印原始顺序表
	for (int i = 0; i < list.length; i++)
		printf("%d ", list.data[i]);
	printf("\n");

	// 尝试删除值在区间 [10, 20] 之间的元素
	if (!deleteElementsInRange(list, 10, 20))
		printf("错误: 无符合条件的元素被删除\n");

	// 打印删除操作后的顺序表
	printf("删除后线性表长度为: %d\n", list.length);
	for (int i = 0; i < list.length; i++)
		printf("%d ", list.data[i]);

	return 0; // 程序结束
}
