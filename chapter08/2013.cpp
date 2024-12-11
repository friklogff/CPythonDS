//https://zhuanlan.zhihu.com/p/572303218
//https://leetcode.cn/problems/find-majority-element-lcci/description/
//������ռ�ȳ���һ���Ԫ�س�֮Ϊ��ҪԪ�ء�����һ�� ���� ���飬�ҳ����е���ҪԪ�ء�
//��û�У����� -1 �������ʱ�临�Ӷ�Ϊ O(N) ���ռ临�Ӷ�Ϊ O(1) �Ľ��������
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

int hfm(int a[], int n) {
	QuickSort(a, 0, n - 1);
	for (int i = 0; i < 1 + n / 2; i++)
		if (a[i] == a[i + n / 2])
			return a[i];
	return -1;
}

int main() {
	int a[] = {0, 5, 5, 5, 5, 1, 5, 7}; // δ��������
	int n = sizeof(a) / sizeof(a[0]); // ���鳤��

//	int b[] = {2, 4, 6, 8, 20}; // δ��������
//	int m = sizeof(b) / sizeof(b[0]); // ���鳤��
	printf("%d", hfm(a, n));

	return 0;
}
