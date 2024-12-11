#include <stdio.h>
#include <string.h>

void getNext(char *pattern, int *next) {
	int m = strlen(pattern); // 模式串长度
	next[0] = -1; // 初始化第一个元素
	int j = 0; // 指向当前处理的字符
	int k = -1; // next[j]的值

	while (j < m - 1) {
		// 如果匹配成功（初始k为-1直接失败），或递归到next[k]的值相同
		if (k == -1 || pattern[j] == pattern[k]) {
			++j;
			++k;
			next[j] = k;
		} else {
			k = next[k]; // 递归匹配失败回退到之前的某个位置
		}
	}
}

int main() {
	char pattern[] = "ABABACA";
	int m = strlen(pattern);
	int next[m];

	getNext(pattern, next);

	printf("Pattern: %s\n", pattern);
	printf("Next array: ");
	for (int i = 0; i < m; i++) {
		printf("%d ", next[i]);
	}
	printf("\n");

	return 0;
}
