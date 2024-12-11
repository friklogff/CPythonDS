#include <stdio.h>

// 计数排序函数
void countingSort(int arr[], int n) {
	int max = 65535; // 假设待排序整数的范围为0~65535
	int count[max + 1];

	// 初始化数组count[]
	for (int i = 0; i <= max; i++) {
		count[i] = 0;
	}

	// 遍历待排序列，对应位置计数加一
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	// 再次遍历count[]数组，输出排序结果
	int outputPos = 0;
	for (int i = 0; i <= max; i++) {
		while (count[i] > 0) {
			arr[outputPos++] = i;
			count[i]--;
		}
	}
}

int main() {
	int arr[] = {3, 6, 8, 10, 1, 1, 2};
	int n = sizeof(arr) / sizeof(arr[0]);

	countingSort(arr, n);

	printf("排序后的数组: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
