//43����֪��n (n��2����ֹ���������Ĺ���A 1aR0�İ˰�t"Ly��R�ؼ�һ�������ܸ�Ч��A��A��Ԫ�ظ����ֱ���n��n��A��A��Ԫ��֮�ͷֱ�ΪS��S�����һ�������ܸ�Ч
//�Ļ����㷨������|n1-nz��С��|S1-S2|���Ҫ��:
//(1�������㷨�Ļ������˼�롣
//(2���������˼�룬����C��C++���������㷨���ؼ�֮������ע�͡�(3��˵��������ǧ�㷨��ƽ��ʱ�临�ӶȺͿռ临�Ӷȡ�
#include <stdio.h>

int Merge(int a[], int n, int b[], int m, int c[]) {
	int i = 0, j = 0, k = 0;
	while (i < n && j < m) {
		if (a[i] <= b[j]) {
//			printf("%d %d\n", a[i], a[j] );

			c[k++] = a[i++];
		} else
			c[k++] = b[j++];
	}
	while (i < n)
		c[k++] = a[i++];
	while (j < m)
		c[k++] = b[j++];
	return 1;
}
int main() {
	int n = 5; // ����A�ĳ���
	int m = 5; // ����B�ĳ���
	int A[] = {1, 3, 5, 7, 9}; // ����A
	int B[] = {2, 4, 6, 8, 10}; // ����B
//	int a[] = {11, 13, 15, 17, 19}; // δ��������
//	int n = sizeof(a) / sizeof(a[0]); // ���鳤��
//
//	int b[] = {2, 4, 6, 8, 20}; // δ��������
//	int m = sizeof(b) / sizeof(b[0]); // ���鳤��
	int C[n + m]; // �ϲ��������C

	Merge(A, n, B, m, C);

	// �Ժϲ���������������

	// ������ĿҪ��ѡ��Ԫ�ط��䵽������������
	for (int i = 0; i < n + m; i++)
		printf("%d ", C[i]);
	return 0;
}