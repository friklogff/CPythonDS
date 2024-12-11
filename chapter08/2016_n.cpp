//43．已知由n (n≥2）个止整数构欣的果后A 1aR0心八八t"Ly，R沿计一个尽可能高效集A和A，元素个数分别是n和n，A和A中元素之和分别为S和S。设计一个尽可能高效
//的划分算法，满足|n1-nz最小且|S1-S2|最大。要求:
//(1）给出算法的基本设计思想。
//(2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。(3）说明你所设千算法的平均时间复杂度和空间复杂度。
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
	int a[] = {0, 3, 4, 6, 8, 9, 5, 7}; // 未排序数组
	int n = sizeof(a) / sizeof(a[0]); // 数组长度

//	int b[] = {2, 4, 6, 8, 20}; // 未排序数组
//	int m = sizeof(b) / sizeof(b[0]); // 数组长度
	printf("%d", hfm(a, 0, n));

	return 0;
}
