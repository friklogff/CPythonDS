//43．已知由n (n≥2）个止整数构欣的果后A 1aR0心八八t"Ly，R沿计一个尽可能高效集A和A，元素个数分别是n和n，A和A中元素之和分别为S和S。设计一个尽可能高效
//的划分算法，满足|n1-nz最小且|S1-S2|最大。要求:
//(1）给出算法的基本设计思想。
//(2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。(3）说明你所设千算法的平均时间复杂度和空间复杂度。


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
	int i = rand() % (r - p + 1) + p; // 随机选一个作为主元
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