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
	int A[] = {4, 2, 7, 8, 10}; // δ��������
	int n = sizeof(A) / sizeof(A[0]); // ���鳤��

	printf("ԭʼ����Ԫ����ֵ: ");
	PrintArray(A, n);

	QuickSort(A, 0, n - 1); // ���ÿ���������

	printf("����������Ԫ����ֵ: ");
	PrintArray(A, n);

	return 0;
}
