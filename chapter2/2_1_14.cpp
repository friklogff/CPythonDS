#include <stdio.h>

#define MAX_INT 0x7fffffff // 定义一个最大整数常量

/**
 * 计算整数的绝对值
 * @param x 整数
 * @return x 的绝对值
 */
int absolute(int x) {
	if (x < 0)
		return -x;
	else
		return x;
}

/**
 * 判断第一个参数是否是三个参数中的最小值
 * @param a 第一个数
 * @param b 第二个数
 * @param c 第三个数
 * @return 如果 a 是最小值，返回 1，否则返回 0
 */
int isMin(int a, int b, int c) {
	return (a <= b && a <= c);
}

/**
 * 找出三个数组中元素的最小差值组合
 * @param a 数组 a
 * @param b 数组 b
 * @param c 数组 c
 * @param na 数组 a 的长度
 * @param nb 数组 b 的长度
 * @param nc 数组 c 的长度
 * @return 最小差值组合的值
 */
int findMinDifference(int a[], int b[], int c[], int na, int nb, int nc) {
	int i = 0, j = 0, k = 0;
	int minDifference = MAX_INT;

	while (i < na && j < nb && k < nc) {
		int currentDifference = absolute(a[i] - b[j]) + absolute(b[j] - c[k]) + absolute(c[k] - a[i]);
		if (currentDifference < minDifference)
			minDifference = currentDifference;

		// 逐步增大最小的那个数对应的下标
		if (isMin(a[i], b[j], c[k]))
			i++;
		else if (isMin(b[j], a[i], c[k]))
			j++;
		else
			k++;
	}

	return minDifference;
}

int main() {
	int a[3] = {-1, 0, 9};
	int b[4] = {-25, -10, 10, 11};
	int c[5] = {2, 9, 17, 30, 41};
	int na = 3, nb = 4, nc = 5;

	printf("The minimum difference is: %d\n", findMinDifference(a, b, c, na, nb, nc));

	return 0;
}
