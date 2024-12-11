//43．已知由n (n≥2）个止整数构欣的果后A 1aR0心八八t"Ly，R沿计一个尽可能高效集A和A，元素个数分别是n和n，A和A中元素之和分别为S和S。设计一个尽可能高效
//的划分算法，满足|n1-nz最小且|S1-S2|最大。要求:
//(1）给出算法的基本设计思想。
//https://zhuanlan.zhihu.com/p/554883795

//https://zhuanlan.zhihu.com/p/573721052
//https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
//4. 寻找两个正序数组的中位数
//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
//请你找出并返回这两个正序数组的 中位数 。
//算法的时间复杂度应该为 O(log (m+n)) 。#include <stdio.h>
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
	int a[] = {11, 13, 15, 17, 19}; // 未排序数组
	int n = sizeof(a) / sizeof(a[0]); // 数组长度

	int b[] = {2, 4, 6, 8, 20}; // 未排序数组
	int m = sizeof(b) / sizeof(b[0]); // 数组长度
	int c[n + m];
	Merge(a, n, b, m, c);
//	for (int i = 0; i < n + m; i++)
//		printf("%d ", c[i]);
//	hfm(a, n, b, m);
	printf("%d", hfm(a, n, b, m));

	return 0;
}