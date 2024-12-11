#include <stdio.h>
#include <stdlib.h>

// �ϲ��������ںϲ�����������
void merge(int arr[], int l, int m1, int m2, int r) {
	int i, j, k;
	int n1 = m1 - l + 1;
	int n2 = m2 - m1;
	int n3 = r - m2;

	int L[n1], M[n2], R[n3];

	// �������ݵ���ʱ���� L, M �� R
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

	// �ϲ�����������Ϊһ��
	while (i < n1 && j < n2 && k < n3) {
		if (L[i] <= M[j] && L[i] <= R[k]) {
			arr[idx++] = L[i++];
		} else if (M[j] <= L[i] && M[j] <= R[k]) {
			arr[idx++] = M[j++];
		} else {
			arr[idx++] = R[k++];
		}
	}

	// ����ʣ��Ԫ��
	while (i < n1)
		arr[idx++] = L[i++];
	while (j < n2)
		arr[idx++] = M[j++];
	while (k < n3)
		arr[idx++] = R[k++];
}

// �ݹ������·�鲢����
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
//�ڴ�����ģ���ݼ�ʱ��ѡ�����·�Ĺ鲢������ܻ���һЩ���ƣ���Ҫ���������¼������棺
//
//1. **���ٵݹ����**�����ֳɸ���·ʱ��ÿ��������Ĵ�С����Ӧ��С����˵ݹ���Ȼ���١���С�ĵݹ������ζ�ſ��Լ��ٺ������ú�ջ�ռ��ʹ�ã������˵ݹ�Ŀ�����
//
//2. **���ٱȽϴ���**���ںϲ������У�������·����������кϲ����ܻ��������ıȽϴ������������ĳЩ�����������ܣ������Ƕ��ڴ��ģ���ݼ���
//
//3. **���ø������**���ڶ�˴������ϣ����л��鲢������ܻ����Ч��ͨ��������·��������������ͬ�Ĵ��������ģ�����ͬʱ���ж���ϲ�����������˲������ܡ�
//
//4. **ƽ�⸺��**��ӵ�и���·�Ĺ鲢������Ը��õ�ƽ�⸺�أ���Ϊ���ݱ��ֳɸ��ಿ�֣����Ը����ȵط������ͬ����������
//
//������ʵ���У���·�鲢�������������һЩ����ĸ����ԣ������ڴ��ģ���ݼ���˵������ͨ���ܹ��ṩ���õ����ܱ��֣��������ڴ���޴����ݼ�ʱ��ѡ�����Ķ�·�鲢����ȡ����������ض������Լ����õ�Ӳ�������������
