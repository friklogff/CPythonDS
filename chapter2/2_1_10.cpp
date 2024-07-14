#include <stdio.h>

/**
 * ��ת����ָ�������Ԫ��
 * @param array ��������
 * @param from ������ʼλ��
 * @param to �������λ��
 */
void reverse(int array[], int from, int to) {
	int temp;
	// ��תָ�������Ԫ��
	for (int i = 0; i < (to - from + 1) / 2; i++) {
		temp = array[from + i];
		array[from + i] = array[to - i];
		array[to - i] = temp;
	}
}

/**
 * ͨ����η�ת����������������
 * �ȷ�תǰ p ��Ԫ�أ��ٷ�תʣ�µ�Ԫ�أ����ת��������
 * ��������Ч�������ڽ�����ǰ p ��Ԫ�ذᵽ����ĩβ������Ԫ������ǰ��
 * @param array ��������
 * @param length ���鳤��
 * @param p ��Ҫ�ᵽĩβ��Ԫ�ظ���
 */
void rearrangeArray(int array[], int length, int p) {
	reverse(array, 0, p - 1);      // ��תǰ p ��Ԫ��
	reverse(array, p, length - 1); // ��תʣ�µ�Ԫ��
	reverse(array, 0, length - 1); // ��ת��������
}

/**
 * ��ӡ����Ԫ��
 * @param array ��������
 * @param length ���鳤��
 */
void printArray(const int array[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7}; // ��ʼ������
	int length = 7;
	int p = 4;

	printf("Original Array: ");
	printArray(array, length);

	// �����������������
	rearrangeArray(array, length, p);

	printf("Array after operation: ");
	printArray(array, length);

	return 0; // �������
}
