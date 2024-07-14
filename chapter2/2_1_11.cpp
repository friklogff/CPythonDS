#include <stdio.h>

// ��ʼ���������� a �� b��������洢��������� c
int a[5] = {11, 13, 15, 17, 19};

int b[5] = {2, 4, 6, 8, 20};
int c[10];

/**
 * �ϲ������������鲢�ҵ���λ��
 * @param a ���� a
 * @param b ���� b
 * @param c ���ڴ洢�ϲ����������
 * @return �ϲ�����������λ��
 */
int mergeAndFindMedian(int a[], int b[], int c[]) {
	int i = 0, j = 0, k = 0;

	// �ϲ�������������
	while (i < 5 && j < 5) {
		if (a[i] <= b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}

	// ����ʣ��Ԫ��
	while (i < 5)
		c[k++] = a[i++];

	while (j < 5)
		c[k++] = b[j++];

	// ���غϲ��������λ��
	return c[(k - 1) / 2];
}

int main() {
	// �ҵ��ϲ�����������λ��
	int median = mergeAndFindMedian(a, b, c);

	// ��ӡ�ϲ��������
	printf("�ϲ�������飺\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", c[i]);
	}
	printf("\n");

	// ��ӡ��λ��
	printf("��λ��Ϊ��%d\n", median);

	return 0;
}
