#include <stdio.h>

// ԭʼ��������鳤��
int array[4] = {1, 2, 4, 3};
int arrayLength = 4;

/**
 * Ѱ��������ȱʧ����С������
 * @param arr ��������
 * @return ȱʧ����С������
 */
int findMissingMinimum(int arr[], int length) {
	// ����һ���������飬����Ϊԭ���鳤�� + 2��ȫ����ʼ��Ϊ 0
	int auxiliary[length + 2];
	for (int i = 0; i < length + 2; i++) {
		auxiliary[i] = 0;
	}

	// ��ԭ����������������Ԫ���ڸ��������б��Ϊ 1
	for (int i = 0; i < length; i++) {
		if (arr[i] > 0 && arr[i] <= length + 1) {
			auxiliary[arr[i]] = 1;
		}
	}

	// Ѱ�Ҹ��������е�һ������ 0 ��λ�ã���λ�ü�Ϊȱʧ����С������
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
	// ��ӡԭʼ����
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	// ���Ҳ���ӡȱʧ����С������
	printf("Missing minimum positive integer: %d\n", findMissingMinimum(array, arrayLength));

	return 0;
}
