#include <stdio.h>
#include <time.h>
#include <math.h>

void originalCode(int n) {
	clock_t start, end;
	double cpu_time_used;

	start = clock();

	for (int i = 1; i < n; i *= 2) {
		for (int j = 0; j < i; j++) {
			// Code block - Original code
			printf("Original Code - i=%d, j=%d\n", i, j);
		}
	}

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Original Code - Time taken for n=%d: %f seconds\n", n, cpu_time_used);
}

void modifiedCode(int n) {
	clock_t start, end;
	double cpu_time_used;

	start = clock();

	int logn = log2(n);
	int powOfTwo = 1;
	for (int k = 0; k < logn; k++) {
		for (int j = 0; j < powOfTwo; j++) {
			// Code block - Modified code
			printf("Modified Code - k=%d, j=%d\n", k, j);
		}
		powOfTwo *= 2; // Calculate 2 raised to the power of k
	}

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Modified Code - Time taken for n=%d: %f seconds\n", n, cpu_time_used);
}

int main() {
	int n = 100; // Input size

	// Testing original code
	printf("Testing Original Code:\n");
	originalCode(n);

	printf("\n");

	// Testing modified code
	printf("Testing Modified Code:\n");
	modifiedCode(n);

	return 0;
}
