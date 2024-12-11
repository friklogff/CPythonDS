//https://leetcode.cn/problems/first-missing-positive/description/
//https://zhuanlan.zhihu.com/p/569384179
//����һ��δ������������� nums �������ҳ�����û�г��ֵ���С����������
//����ʵ��ʱ�临�Ӷ�Ϊ O(n) ����ֻʹ�ó����������ռ�Ľ��������
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
	int f = -1;
	for (int i = 0; i < n ; i++)
		if (a[i] > 0) {
			f = i;
			break;
		}
	if (f == -1 || a[f] != 1)
		return 1;
	for (f = f + 1; f < n; f++)
		if (a[f] - a[f - 1] > 1)
			return a[f - 1] + 1;
	return a[n - 1] + 1;
}

int main() {
	int a[] = {0, 5, 5, 5, 5, 1, 5, 7}; // δ��������
	int n = sizeof(a) / sizeof(a[0]); // ���鳤��

//	int b[] = {2, 4, 6, 8, 20}; // δ��������
//	int m = sizeof(b) / sizeof(b[0]); // ���鳤��
	printf("%d", hfm(a, n));

	return 0;
}

