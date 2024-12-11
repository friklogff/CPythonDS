//43����֪��n (n��2����ֹ���������Ĺ���A 1aR0�İ˰�t"Ly��R�ؼ�һ�������ܸ�Ч��A��A��Ԫ�ظ����ֱ���n��n��A��A��Ԫ��֮�ͷֱ�ΪS��S�����һ�������ܸ�Ч
//�Ļ����㷨������|n1-nz��С��|S1-S2|���Ҫ��:
//(1�������㷨�Ļ������˼�롣
//(2���������˼�룬����C��C++���������㷨���ؼ�֮������ע�͡�(3��˵��������ǧ�㷨��ƽ��ʱ�临�ӶȺͿռ临�Ӷȡ�


#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int i, int j) {
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int partition(int *a, int p, int r) {
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; ++j) {
		if (a[j] <= x) {
			++i;
			swap(a, i, j);
		}
	}
	swap(a, i + 1, r);
	return i + 1;
}

int randomized_partition(int *a, int p, int r) {
	int i = rand() % (r - p + 1) + p; // ���ѡһ����Ϊ��Ԫ
	swap(a, r, i);
	return partition(a, p, r);
}

void randomized_quicksort(int *a, int p, int r) {
	if (p < r) {
		int q = randomized_partition(a, p, r);
		randomized_quicksort(a, p, q - 1);
		randomized_quicksort(a, q + 1, r);
	}
}

int maxDifference(int *a, int n) {
	randomized_partition(a, 0, n - 1);
	int s1 = 0;
	for (int i = 0; i < n / 2; ++i) {
		s1 += a[i];
	}
	int s2 = 0;
	for (int i = n / 2; i < n; ++i) {
		s2 += a[i];
	}
	return s2 - s1;
}

int main(int argc, const char *argv[]) {
	int a[5] = {30, 41, 9, 2, 17};
	int res = maxDifference(a, 5);
	printf("%d", res);
	return 0;
}