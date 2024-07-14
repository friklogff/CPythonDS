#include <stdio.h>

// 初始化两个数组 a 和 b，并定义存储结果的数组 c
int a[5] = {11, 13, 15, 17, 19};

int b[5] = {2, 4, 6, 8, 20};
int c[10];

/**
 * 合并两个有序数组并找到中位数
 * @param a 数组 a
 * @param b 数组 b
 * @param c 用于存储合并结果的数组
 * @return 合并后的数组的中位数
 */
int mergeAndFindMedian(int a[], int b[], int c[]) {
	int i = 0, j = 0, k = 0;

	// 合并两个有序数组
	while (i < 5 && j < 5) {
		if (a[i] <= b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}

	// 处理剩余元素
	while (i < 5)
		c[k++] = a[i++];

	while (j < 5)
		c[k++] = b[j++];

	// 返回合并数组的中位数
	return c[(k - 1) / 2];
}

int main() {
	// 找到合并后的数组的中位数
	int median = mergeAndFindMedian(a, b, c);

	// 打印合并后的数组
	printf("合并后的数组：\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", c[i]);
	}
	printf("\n");

	// 打印中位数
	printf("中位数为：%d\n", median);

	return 0;
}
