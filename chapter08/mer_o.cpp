//43．已知由n (n≥2）个止整数构欣的果后A 1aR0心八八t"Ly，R沿计一个尽可能高效集A和A，元素个数分别是n和n，A和A中元素之和分别为S和S。设计一个尽可能高效
//的划分算法，满足|n1-nz最小且|S1-S2|最大。要求:
//(1）给出算法的基本设计思想。
//(2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。(3）说明你所设千算法的平均时间复杂度和空间复杂度。
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
	int n = 5; // 数组A的长度
	int m = 5; // 数组B的长度
	int A[] = {1, 3, 5, 7, 9}; // 数组A
	int B[] = {2, 4, 6, 8, 10}; // 数组B
//	int a[] = {11, 13, 15, 17, 19}; // 未排序数组
//	int n = sizeof(a) / sizeof(a[0]); // 数组长度
//
//	int b[] = {2, 4, 6, 8, 20}; // 未排序数组
//	int m = sizeof(b) / sizeof(b[0]); // 数组长度
	int C[n + m]; // 合并后的数组C

	Merge(A, n, B, m, C);

	// 对合并后的数组进行排序

	// 根据题目要求选择元素分配到两个子数组中
	for (int i = 0; i < n + m; i++)
		printf("%d ", C[i]);
	return 0;
}