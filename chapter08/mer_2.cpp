#include <stdio.h>

// 合并两个子数组函数
void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// 创建临时数组
	int L[n1], R[n2];

	// 复制数据到临时数组 L 和 R
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// 合并临时数组回到 arr
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// 拷贝剩余元素
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// 归并排序主函数
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int main() {
	int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	for (int i = 0; i < arr_size; i++)
		printf("%d ", arr[i]);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	for (int i = 0; i < arr_size; i++)
		printf("%d ", arr[i]);

	return 0;
}
