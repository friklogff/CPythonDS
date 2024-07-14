#include <stdio.h>
#include <stdbool.h>

int n = 8;  // ����ĳ���

/**
 * ʹ��Ħ��ͶƱ�㷨���������г��ִ�������һ�������
 * @param arr ��������
 * @param result ������ִ�������һ�������
 * @return ����ҵ����� true�����򷵻� false
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

	// ��֤��ѡ���Ƿ�����Ƕ���Ԫ��
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
 * ʹ�ù�ϣ����������г��ִ�������һ�������
 * @param arr ��������
 * @param result ������ִ�������һ�������
 * @return ����ҵ����� true�����򷵻� false
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
 * ����������������ִ���������
 * @param arr ��������
 * @param low �������ʼ�±�
 * @param high ����Ľ����±�
 */
void quickSortUtility(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high]; // ѡ�����һ��Ԫ����Ϊ����
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
 * �������������������ø�������
 * @param arr ��������
 * @param length ����ĳ���
 */
void quickSort(int arr[], int length) {
	quickSortUtility(arr, 0, length - 1);
}

/**
 * ʹ�ÿ������򷽷����������г��ִ�������һ�������
 * @param arr ��������
 * @param length ���鳤��
 * @param result ������ִ�������һ�������
 * @return ����ҵ����� true�����򷵻� false
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
	int a2[8] = {0, 5, 5, 3, 5, 7, 5, 5}; // ����ԭʼ���飬���ڿ������򷽷�

	// ʹ�ù�ϣ��ķ�ʽ����
	if (findMajorityElementHash(a1, result))
		printf("Hash Method: ���ִ�������һ�������Ϊ %d\n", result);
	else
		printf("Hash Method: û�г��ִ�������һ�������\n");

	// ʹ��Ħ��ͶƱ�㷨�ķ�ʽ����
	if (findMajorityElementMoore(a1, result))
		printf("Moore's Voting Method: ���ִ�������һ�������Ϊ %d\n", result);
	else
		printf("Moore's Voting Method: û�г��ִ�������һ�������\n");

	// ʹ�ÿ�����������
	if (findMajorityElementQuickSort(a2, n, result))
		printf("Quick Sort Method: ���ִ�������һ�������Ϊ %d\n", result);
	else
		printf("Quick Sort Method: û�г��ִ�������һ�������\n");

	return 0;
}
