#include <stdio.h>

// 原始数组和数组长度
int array[4] = {1, 2, 4, 3};
int arrayLength = 4;

/**
 * 寻找数组中缺失的最小正整数
 * @param arr 输入数组
 * @return 缺失的最小正整数
 */
int findMissingMinimum(int arr[], int length) {
	// 创建一个辅助数组，长度为原数组长度 + 2，全部初始化为 0
	int auxiliary[length + 2];
	for (int i = 0; i < length + 2; i++) {
		auxiliary[i] = 0;
	}

	// 将原数组中满足条件的元素在辅助数组中标记为 1
	for (int i = 0; i < length; i++) {
		if (arr[i] > 0 && arr[i] <= length + 1) {
			auxiliary[arr[i]] = 1;
		}
	}

	// 寻找辅助数组中第一个等于 0 的位置，该位置即为缺失的最小正整数
	int missingNumber = 0;
	for (int i = 1; i < length + 2; i++) {
		if (auxiliary[i] == 0) {
			missingNumber = i;
			break;
		}
	}
	return missingNumber;
}

int main() {
	// 打印原始数组
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	// 查找并打印缺失的最小正整数
	printf("Missing minimum positive integer: %d\n", findMissingMinimum(array, arrayLength));

	return 0;
}
