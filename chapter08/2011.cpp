//https://zhuanlan.zhihu.com/p/554883795

//https://zhuanlan.zhihu.com/p/573721052
//https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
//4. 寻找两个正序数组的中位数
//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
//请你找出并返回这两个正序数组的 中位数 。
//算法的时间复杂度应该为 O(log (m+n)) 。
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
	int a[] = {11, 13, 15, 17, 19}; // 未排序数组
	int n = sizeof(a) / sizeof(a[0]); // 数组长度

	int b[] = {2, 4, 6, 8, 20}; // 未排序数组
	int m = sizeof(b) / sizeof(b[0]); // 数组长度
	printf("%d", hfm(a, n, b, m));

	return 0;
}
