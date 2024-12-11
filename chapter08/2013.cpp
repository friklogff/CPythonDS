//https://zhuanlan.zhihu.com/p/572303218
//https://leetcode.cn/problems/find-majority-element-lcci/description/
//数组中占比超过一半的元素称之为主要元素。给你一个 整数 数组，找出其中的主要元素。
//若没有，返回 -1 。请设计时间复杂度为 O(N) 、空间复杂度为 O(1) 的解决方案。
#include <stdio.h>

int Partition(int a[], int l, int r) {
	int mid = a[l];
	while (l < r) {
		while (a[r] >= mid && l < r)//右大
			r--;
		a[l] = a[r];
		while (a[l] <= mid && l < r)//左小
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
	int a[] = {0, 5, 5, 5, 5, 1, 5, 7}; // 未排序数组
	int n = sizeof(a) / sizeof(a[0]); // 数组长度

//	int b[] = {2, 4, 6, 8, 20}; // 未排序数组
//	int m = sizeof(b) / sizeof(b[0]); // 数组长度
	printf("%d", hfm(a, n));

	return 0;
}
