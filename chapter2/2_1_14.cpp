#include <stdio.h>

#define MAX_INT 0x7fffffff // ����һ�������������

/**
 * ���������ľ���ֵ
 * @param x ����
 * @return x �ľ���ֵ
 */
int absolute(int x) {
	if (x < 0)
		return -x;
	else
		return x;
}

/**
 * �жϵ�һ�������Ƿ������������е���Сֵ
 * @param a ��һ����
 * @param b �ڶ�����
 * @param c ��������
 * @return ��� a ����Сֵ������ 1�����򷵻� 0
 */
int isMin(int a, int b, int c) {
	return (a <= b && a <= c);
}

/**
 * �ҳ�����������Ԫ�ص���С��ֵ���
 * @param a ���� a
 * @param b ���� b
 * @param c ���� c
 * @param na ���� a �ĳ���
 * @param nb ���� b �ĳ���
 * @param nc ���� c �ĳ���
 * @return ��С��ֵ��ϵ�ֵ
 */
int findMinDifference(int a[], int b[], int c[], int na, int nb, int nc) {
	int i = 0, j = 0, k = 0;
	int minDifference = MAX_INT;

	while (i < na && j < nb && k < nc) {
		int currentDifference = absolute(a[i] - b[j]) + absolute(b[j] - c[k]) + absolute(c[k] - a[i]);
		if (currentDifference < minDifference)
			minDifference = currentDifference;

		// ��������С���Ǹ�����Ӧ���±�
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
