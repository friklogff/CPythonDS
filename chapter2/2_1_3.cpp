#include <stdio.h>

#define MaxSize 50 // 定义顺序表的最大长度

// 结构体定义，表示顺序表 (Sequence List)
typedef struct {
	int data[MaxSize]; // 用数组存放数据元素
	int length;        // 线性表的当前长度
} SqList; // 线性表的类型定义

/**
 * 从顺序表中删除所有值为 x 的元素
 * @param list 顺序表
 * @param x 要删除的值
 */
void deleteElements(SqList &list, int x) {
	int shiftCount = 0; // 记录被删除的元素数量
	for (int i = 0; i < list.length; i++) {
		if (list.data[i] == x) {
			// 如果元素等于 x，增加删除计数
			shiftCount++;
		} else {
			// 否则将当前元素向前移动 shiftCount 位
			list.data[i - shiftCount] = list.data[i];
		}
	}
	// 更新顺序表的长度
	list.length -= shiftCount;
}

int main() {
	// 初始化一个顺序表
	SqList list = {{5, 2, 0, 1, 3, 1, 4, 1, 1, 4}, 10};

	// 打印原始顺序表
	for (int i = 0; i < list.length; i++) {
		printf("%d ", list.data[i]);
	}
	printf("\n");

	// 从顺序表中删除所有值为 1 的元素
	deleteElements(list, 1);

	// 打印删除后的顺序表
	for (int i = 0; i < list.length; i++) {
		printf("%d ", list.data[i]);
	}
	printf("\n");

	return 0; // 程序结束
}
