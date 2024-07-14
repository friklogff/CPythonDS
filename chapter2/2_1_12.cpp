#include <stdio.h>
#include <stdbool.h>

int n = 8;  // 数组的长度

/**
 * 使用摩尔投票算法查找数组中出现次数超过一半的数字
 * @param arr 输入数组
 * @param result 保存出现次数超过一半的数字
 * @return 如果找到返回 true，否则返回 false
 */
bool findMajorityElementMoore(int arr[], int &result) {
	int candidate = arr[0], count = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] == candidate)
			count++;
		else {
			if (count > 0)
				count--;
			else {
				candidate = arr[i];
				count = 1;
			}
		}
	}

	// 验证候选人是否真的是多数元素
	int occurrences = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == candidate)
			occurrences++;
	}

	if (occurrences > n / 2) {
		result = candidate;
		return true;
	} else {
		return false;
	}
}

/**
 * 使用哈希表查找数组中出现次数超过一半的数字
 * @param arr 输入数组
 * @param result 保存出现次数超过一半的数字
 * @return 如果找到返回 true，否则返回 false
 */
bool findMajorityElementHash(int arr[], int &result) {
	int hashTable[100] = {0};
	int maxCount = 0;
	int majorityElement;
	for (int i = 0; i < n; i++) {
		hashTable[arr[i]]++;
	}

	for (int i = 0; i < 100; i++) {
		if (hashTable[i] > maxCount) {
			majorityElement = i;
			maxCount = hashTable[i];
		}
	}

	if (maxCount > n / 2) {
		result = majorityElement;
		return true;
	} else {
		return false;
	}
}

/**
 * 快速排序辅助函数，执行排序过程
 * @param arr 输入数组
 * @param low 数组的起始下标
 * @param high 数组的结束下标
 */
void quickSortUtility(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high]; // 选择最后一个元素作为枢轴
		int i = low - 1;

		for (int j = low; j < high; j++) {
			if (arr[j] < pivot) {
				i++;
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		int temp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = temp;

		int pivotIndex = i + 1;

		quickSortUtility(arr, low, pivotIndex - 1);
		quickSortUtility(arr, pivotIndex + 1, high);
	}
}

/**
 * 快速排序主函数，调用辅助函数
 * @param arr 输入数组
 * @param length 数组的长度
 */
void quickSort(int arr[], int length) {
	quickSortUtility(arr, 0, length - 1);
}

/**
 * 使用快速排序方法查找数组中出现次数超过一半的数字
 * @param arr 输入数组
 * @param length 数组长度
 * @param result 保存出现次数超过一半的数字
 * @return 如果找到返回 true，否则返回 false
 */
bool findMajorityElementQuickSort(int arr[], int length, int &result) {
	quickSort(arr, length);

	int currentElement = arr[0];
	int count = 1;

	for (int i = 1; i < length; i++) {
		if (arr[i] == currentElement) {
			count++;
			if (count > length / 2) {
				result = currentElement;
				return true;
			}
		} else {
			currentElement = arr[i];
			count = 1;
		}
	}

	return false;
}

int main() {
	int result;
	int a1[8] = {0, 5, 5, 3, 5, 7, 5, 5};
	int a2[8] = {0, 5, 5, 3, 5, 7, 5, 5}; // 复制原始数组，用于快速排序方法

	// 使用哈希表的方式查找
	if (findMajorityElementHash(a1, result))
		printf("Hash Method: 出现次数超过一半的数字为 %d\n", result);
	else
		printf("Hash Method: 没有出现次数超过一半的数字\n");

	// 使用摩尔投票算法的方式查找
	if (findMajorityElementMoore(a1, result))
		printf("Moore's Voting Method: 出现次数超过一半的数字为 %d\n", result);
	else
		printf("Moore's Voting Method: 没有出现次数超过一半的数字\n");

	// 使用快速排序后查找
	if (findMajorityElementQuickSort(a2, n, result))
		printf("Quick Sort Method: 出现次数超过一半的数字为 %d\n", result);
	else
		printf("Quick Sort Method: 没有出现次数超过一半的数字\n");

	return 0;
}
