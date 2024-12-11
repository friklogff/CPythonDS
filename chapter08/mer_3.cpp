#include <stdio.h>
#include <stdlib.h>

// 合并函数用于合并三个子数组
void merge(int arr[], int l, int m1, int m2, int r) {
	int i, j, k;
	int n1 = m1 - l + 1;
	int n2 = m2 - m1;
	int n3 = r - m2;

	int L[n1], M[n2], R[n3];

	// 复制数据到临时数组 L, M 和 R
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		M[j] = arr[m1 + 1 + j];
	for (k = 0; k < n3; k++)
		R[k] = arr[m2 + 1 + k];

	i = 0;
	j = 0;
	k = 0;
	int idx = l;

	// 合并三个子数组为一个
	while (i < n1 && j < n2 && k < n3) {
		if (L[i] <= M[j] && L[i] <= R[k]) {
			arr[idx++] = L[i++];
		} else if (M[j] <= L[i] && M[j] <= R[k]) {
			arr[idx++] = M[j++];
		} else {
			arr[idx++] = R[k++];
		}
	}

	// 拷贝剩余元素
	while (i < n1)
		arr[idx++] = L[i++];
	while (j < n2)
		arr[idx++] = M[j++];
	while (k < n3)
		arr[idx++] = R[k++];
}

// 递归进行三路归并排序
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m1 = l + (r - l) / 3;
		int m2 = l + 2 * (r - l) / 3;

		mergeSort(arr, l, m1);
		mergeSort(arr, m1 + 1, m2);
		mergeSort(arr, m2 + 1, r);

		merge(arr, l, m1, m2, r);
	}
}

int main() {
	int arr[] = {12, 11, 13, 5, 6, 7, 10, 8, 9};
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
//在处理大规模数据集时，选择更多路的归并排序可能会有一些优势，主要是由于以下几个方面：
//
//1. **减少递归深度**：当分成更多路时，每个子数组的大小会相应减小，因此递归深度会减少。较小的递归深度意味着可以减少函数调用和栈空间的使用，降低了递归的开销。
//
//2. **减少比较次数**：在合并过程中，将更多路的子数组进行合并可能会减少总体的比较次数。这可以在某些情况下提高性能，尤其是对于大规模数据集。
//
//3. **利用更多核心**：在多核处理器上，并行化归并排序可能会更有效。通过将更多路的子数组分配给不同的处理器核心，可以同时进行多个合并操作，提高了并行性能。
//
//4. **平衡负载**：拥有更多路的归并排序可以更好地平衡负载，因为数据被分成更多部分，可以更均匀地分配给不同的排序任务。
//
//尽管在实践中，多路归并排序可能增加了一些额外的复杂性，但对于大规模数据集来说，它们通常能够提供更好的性能表现，尤其是在处理巨大数据集时。选择具体的多路归并排序取决于问题的特定需求以及可用的硬件和软件环境。
