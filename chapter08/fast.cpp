#include <stdio.h>

void PrintArray(int A[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

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




//void QuickSort(int a[], int l, int r) {
//	if (l < r) {
//		int p = Partition(a, l, r);
//		printf("sz:%d\t", a[p]);
//		QuickSort(a, l, p - 1);
//		QuickSort(a, p + 1, r);
//	}
//}
void QuickSort(int a[], int l, int r) {
	if (l >= r)
		return;
	int p = Partition(a, l, r);
	printf("sz:%d\t", a[p]);
	QuickSort(a, l, p - 1);
	QuickSort(a, p + 1, r);

}

int main() {
	int A[] = {4, 2, 7, 8, 10}; // 未排序数组
	int n = sizeof(A) / sizeof(A[0]); // 数组长度

	printf("原始数组元素数值: ");
	PrintArray(A, n);

	QuickSort(A, 0, n - 1); // 调用快速排序函数

	printf("排序后的数组元素数值: ");
	PrintArray(A, n);

	return 0;
}
