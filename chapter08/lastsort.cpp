#include <stdio.h>

// ����������
void countingSort(int arr[], int n) {
	int max = 65535; // ��������������ķ�ΧΪ0~65535
	int count[max + 1];

	// ��ʼ������count[]
	for (int i = 0; i <= max; i++) {
		count[i] = 0;
	}

	// �����������У���Ӧλ�ü�����һ
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	// �ٴα���count[]���飬���������
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

	printf("����������: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
