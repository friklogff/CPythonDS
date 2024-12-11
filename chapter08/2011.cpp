//https://zhuanlan.zhihu.com/p/554883795

//https://zhuanlan.zhihu.com/p/573721052
//https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
//4. Ѱ�����������������λ��
//����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2��
//�����ҳ���������������������� ��λ�� ��
//�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log (m+n)) ��
#include <stdio.h>
int Partition(int a[], int l, int r) {
	int mid = a[l];
	while (l < r) {
		while (a[r] >= mid && l < r)//�Ҵ�
			r--;
		a[l] = a[r];
		while (a[l] <= mid && l < r)//��С
			l++;
		a[r] = a[l];
	}
	a[l] = mid;
	return l;
}

void QuickSort(int a[], int l, int r) {
	if (l < r) {
		int p = Partition(a, l, r);
//		printf("sz:%d\t", a[p]);
		QuickSort(a, l, p - 1);
		QuickSort(a, p + 1, r);
	}
}

int hfm(int a[], int n, int b[], int m) {
	int c[n + m];
	for (int i = 0; i < n; i++)
		c[i] = a[i];
	for (int i = 0; i < m; i++)
		c[i + n] = b[i];
	QuickSort(c, 0, n + m - 1);
	return c[(n + m - 1) / 2];
}

int main() {
	int a[] = {11, 13, 15, 17, 19}; // δ��������
	int n = sizeof(a) / sizeof(a[0]); // ���鳤��

	int b[] = {2, 4, 6, 8, 20}; // δ��������
	int m = sizeof(b) / sizeof(b[0]); // ���鳤��
	printf("%d", hfm(a, n, b, m));

	return 0;
}
