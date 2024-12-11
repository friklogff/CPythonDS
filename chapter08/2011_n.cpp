//43����֪��n (n��2����ֹ���������Ĺ���A 1aR0�İ˰�t"Ly��R�ؼ�һ�������ܸ�Ч��A��A��Ԫ�ظ����ֱ���n��n��A��A��Ԫ��֮�ͷֱ�ΪS��S�����һ�������ܸ�Ч
//�Ļ����㷨������|n1-nz��С��|S1-S2|���Ҫ��:
//(1�������㷨�Ļ������˼�롣
//https://zhuanlan.zhihu.com/p/554883795

//https://zhuanlan.zhihu.com/p/573721052
//https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
//4. Ѱ�����������������λ��
//����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2��
//�����ҳ���������������������� ��λ�� ��
//�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log (m+n)) ��#include <stdio.h>
#include <stdio.h>

int Merge(int a[], int n, int b[], int m, int c[]) {
	int i = 0, j = 0, k = 0;
	while (i < n && j < m) {
		if (a[i] <= b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	while (i < n)
		c[k++] = a[i++];
	while (j < m)
		c[k++] = b[j++];
	return 1;
}
int hfm(int a[], int n, int b[], int m) {
	int c[n + m];
	Merge(a, n, b, m, c);
//	for (int i = 0; i < n + m; i++)
//		printf("%d ", c[i]);
	return c[(n + m - 1) / 2];
}
int main() {
	int a[] = {11, 13, 15, 17, 19}; // δ��������
	int n = sizeof(a) / sizeof(a[0]); // ���鳤��

	int b[] = {2, 4, 6, 8, 20}; // δ��������
	int m = sizeof(b) / sizeof(b[0]); // ���鳤��
	int c[n + m];
	Merge(a, n, b, m, c);
//	for (int i = 0; i < n + m; i++)
//		printf("%d ", c[i]);
//	hfm(a, n, b, m);
	printf("%d", hfm(a, n, b, m));

	return 0;
}