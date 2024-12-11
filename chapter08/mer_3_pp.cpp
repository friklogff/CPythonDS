#include <iostream>
#include <vector>

using namespace std;

// 合并三个子数组函数
void merge(vector<int> &arr, int l, int m1, int m2, int r) {
	vector<int> L(arr.begin() + l, arr.begin() + m1 + 1);
	vector<int> M(arr.begin() + m1 + 1, arr.begin() + m2 + 1);
	vector<int> R(arr.begin() + m2 + 1, arr.begin() + r + 1);

	int i = 0, j = 0, k = 0;
	int idx = l;

	while (i < L.size() && j < M.size() && k < R.size()) {
		if (L[i] <= M[j] && L[i] <= R[k]) {
			arr[idx++] = L[i++];
		} else if (M[j] <= L[i] && M[j] <= R[k]) {
			arr[idx++] = M[j++];
		} else {
			arr[idx++] = R[k++];
		}
	}

	while (i < L.size())
		arr[idx++] = L[i++];
	while (j < M.size())
		arr[idx++] = M[j++];
	while (k < R.size())
		arr[idx++] = R[k++];
}

// 递归进行三路归并排序
void mergeSort(vector<int> &arr, int l, int r) {
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
	vector<int> arr = {12, 11, 13, 5, 6, 7};
	int arr_size = arr.size();

	cout << "Given array is:\n";
	for (auto num : arr)
		cout << num << " ";

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is:\n";
	for (auto num : arr)
		cout << num << " ";

	return 0;
}
