//43����֪��n (n��2����ֹ���������Ĺ���A 1aR0�İ˰�t"Ly��R�ؼ�һ�������ܸ�Ч��A��A��Ԫ�ظ����ֱ���n��n��A��A��Ԫ��֮�ͷֱ�ΪS��S�����һ�������ܸ�Ч
//�Ļ����㷨������|n1-nz��С��|S1-S2|���Ҫ��:
//(1�������㷨�Ļ������˼�롣
//(2���������˼�룬����C��C++���������㷨���ؼ�֮������ע�͡�(3��˵��������ǧ�㷨��ƽ��ʱ�临�ӶȺͿռ临�Ӷȡ�
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

int hfm(int a[], int l, int r) {
	int k = r / 2;
	while (1) {
		int p = Partition(a, l, r);
		if (p == k - 1)
			break;
		else if (p > k - 1)
			r = p - 1;
		else if (p < k - 1)
			l = p + 1;
	}
	return a[k - 1];
}

int main() {
	int a[] = {0, 3, 4, 6, 8, 9, 5, 7}; // δ��������
	int n = sizeof(a) / sizeof(a[0]); // ���鳤��

//	int b[] = {2, 4, 6, 8, 20}; // δ��������
//	int m = sizeof(b) / sizeof(b[0]); // ���鳤��
	printf("%d", hfm(a, 0, n));

	return 0;
}
