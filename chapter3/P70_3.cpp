#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 序列长度
int n;

/**
 * @brief 检查栈操作序列是否合法
 * @param s 栈操作序列
 * @return true 合法，false 不合法
 */
bool IsSequenceValid(char s[]) {
	int countI = 0, countO = 0; // I 和 O 的计数
	for (int i = 0; i < n; i++) {
		if (s[i] == 'I')
			countI++; // 入栈操作
		else
			countO++; // 出栈操作
		if (countO > countI) // 如果出栈操作次数超过入栈操作次数，则不合法
			return false;
	}
	// 如果入栈和出栈操作次数相等，则合法
	if (countO == countI)
		return true;
	return false; // 否则不合法
}

int main() {
	char s[8] = {'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O'};
	n = 8; // 序列长度
	if (IsSequenceValid(s))
		printf("合法\n");
	else
		printf("不合法\n");
	return 0;
}
