#include <stdio.h>
#include <string.h>

#define N 1000002

int nextArray[N]; // 存储模式串的next数组
char mainString[N], patternString[N]; // 主串S和模式串T
int mainStringLength, patternStringLength; // 主串S和模式串T的长度

// 计算模式串的next数组
void computeNextArray() {
	int j = 0, k = -1;
	nextArray[0] = -1;
	while (j < patternStringLength) {
		if (k == -1 || patternString[j] == patternString[k]) {
			nextArray[++j] = ++k;
		} else {
			k = nextArray[k];
		}
	}

	// 输出计算得到的next数组
	for (int i = 0; i <= patternStringLength; i++)
		printf("%d%c", nextArray[i], i == patternStringLength ? '\n' : ' ');
}

// 返回模式串T在主串S中首次出现的位置
int KMP_FirstOccurrenceIndex() {
	int i = 0, j = 0;
	computeNextArray();

	while (i < mainStringLength && j < patternStringLength) {
		if (j == -1 || mainString[i] == patternString[j]) {
			i++;
			j++;
		} else {
			j = nextArray[j];
		}
	}

	if (j == patternStringLength) {
		return i - patternStringLength; // 返回匹配的起始位置
	} else {
		return -1; // 没有匹配，返回-1
	}
}

// 返回模式串在主串S中出现的次数
int KMP_PatternCount() {
	int count = 0;
	int i, j = 0;

	if (mainStringLength == 1 && patternStringLength == 1) {
		if (mainString[0] == patternString[0])
			return 1;
		else
			return 0;
	}

	computeNextArray();

	for (i = 0; i < mainStringLength; i++) {
		while (j > 0 && mainString[i] != patternString[j])
			j = nextArray[j];

		if (mainString[i] == patternString[j])
			j++;

		if (j == patternStringLength) { // 匹配成功
			count++;
			j = nextArray[j]; // 继续寻找下一个匹配
		}
	}

	return count; // 返回匹配次数
}

int main() {
	int testCases;
	scanf("%d", &testCases); // 读取测试用例数量

	while (testCases--) {
		scanf("%s%s", mainString, patternString); // 读取主串S和模式串T
		mainStringLength = strlen(mainString); // 计算主串S的长度
		patternStringLength = strlen(patternString); // 计算模式串T的长度

		printf("模式串T在主串S中首次出现的位置是: %d\n", KMP_FirstOccurrenceIndex()); // 输出模式串首次出现位置
		printf("模式串T在主串S中出现的次数为: %d\n", KMP_PatternCount()); // 输出模式串出现次数

		for (int i = 0; i <= patternStringLength; i++)
			printf("%d  ", nextArray[i]); // 输出模式串的next数组
		printf("\n");
	}

	return 0;
}
