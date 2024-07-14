#include <stdio.h>

/**
 * 反转数组指定区间的元素
 * @param array 输入数组
 * @param from 区间起始位置
 * @param to 区间结束位置
 */
void reverse(int array[], int from, int to) {
	int temp;
	// 反转指定区间的元素
	for (int i = 0; i < (to - from + 1) / 2; i++) {
		temp = array[from + i];
		array[from + i] = array[to - i];
		array[to - i] = temp;
	}
}

/**
 * 通过多次反转操作重新排列数组
 * 先反转前 p 个元素，再反转剩下的元素，最后反转整个数组
 * 重新排列效果类似于将数组前 p 个元素搬到数组末尾，其余元素依次前移
 * @param array 输入数组
 * @param length 数组长度
 * @param p 需要搬到末尾的元素个数
 */
void rearrangeArray(int array[], int length, int p) {
	reverse(array, 0, p - 1);      // 反转前 p 个元素
	reverse(array, p, length - 1); // 反转剩下的元素
	reverse(array, 0, length - 1); // 反转整个数组
}

/**
 * 打印数组元素
 * @param array 输入数组
 * @param length 数组长度
 */
void printArray(const int array[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7}; // 初始化数组
	int length = 7;
	int p = 4;

	printf("Original Array: ");
	printArray(array, length);

	// 对数组进行重新排列
	rearrangeArray(array, length, p);

	printf("Array after operation: ");
	printArray(array, length);

	return 0; // 程序结束
}
