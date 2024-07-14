#include <stdio.h>
#include <stdbool.h>

#define MaxSize 50 // 定义顺序表的最大长度

// 结构体定义，表示顺序表 (Sequence List)
typedef struct {
	int data[MaxSize]; // 用数组存放数据元素
	int length;        // 线性表的当前长度
} SqList; // 线性表的类型定义

/**
 * 初始化顺序表
 * @param list 顺序表
 */
void initializeSqList(SqList &list) {
	int initialData[] = {1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5};
	list.length = 11;
	for (int i = 0; i < list.length; i++) {
		list.data[i] = initialData[i]; // 初始化顺序表的数据
	}
}

/**
 * 删除顺序表中相邻重复的元素
 * @param list 顺序表
 * @return 成功删除返回 true，否则返回 false
 */
bool deleteAdjacentDuplicates(SqList &list) {
	if (list.length == 0)
		return false; // 若顺序表为空，返回 false 表示失败

	int i = 0;
	// j 从第二个元素开始遍历，将非重复元素移至前面
	for (int j = 1; j < list.length; j++) {
		if (list.data[i] != list.data[j])
			list.data[++i] = list.data[j]; // 更新顺序表元素位置
	}
	list.length = i + 1; // 更新顺序表的长度

	return true; // 返回 true 表示成功
}

int main() {
	SqList list;
	initializeSqList(list); // 初始化顺序表

	// 打印原始顺序表
	for (int i = 0; i < list.length; i++)
		printf("%d ", list.data[i]);
	printf("\n");

	// 尝试删除相邻重复的元素
	if (!deleteAdjacentDuplicates(list))
		printf("错误: 顺序表为空\n");

	// 打印删除操作后的顺序表
	for (int i = 0; i < list.length; i++)
		printf("%d ", list.data[i]);

	return 0; // 程序结束
}
