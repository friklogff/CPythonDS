#include <stdio.h>
#include <string.h>

#define N 1000002

int nextArray[N]; // �洢ģʽ����next����
char mainString[N], patternString[N]; // ����S��ģʽ��T
int mainStringLength, patternStringLength; // ����S��ģʽ��T�ĳ���

// ����ģʽ����next����
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

	// �������õ���next����
	for (int i = 0; i <= patternStringLength; i++)
		printf("%d%c", nextArray[i], i == patternStringLength ? '\n' : ' ');
}

// ����ģʽ��T������S���״γ��ֵ�λ��
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
		return i - patternStringLength; // ����ƥ�����ʼλ��
	} else {
		return -1; // û��ƥ�䣬����-1
	}
}

// ����ģʽ��������S�г��ֵĴ���
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

		if (j == patternStringLength) { // ƥ��ɹ�
			count++;
			j = nextArray[j]; // ����Ѱ����һ��ƥ��
		}
	}

	return count; // ����ƥ�����
}

int main() {
	int testCases;
	scanf("%d", &testCases); // ��ȡ������������

	while (testCases--) {
		scanf("%s%s", mainString, patternString); // ��ȡ����S��ģʽ��T
		mainStringLength = strlen(mainString); // ��������S�ĳ���
		patternStringLength = strlen(patternString); // ����ģʽ��T�ĳ���

		printf("ģʽ��T������S���״γ��ֵ�λ����: %d\n", KMP_FirstOccurrenceIndex()); // ���ģʽ���״γ���λ��
		printf("ģʽ��T������S�г��ֵĴ���Ϊ: %d\n", KMP_PatternCount()); // ���ģʽ�����ִ���

		for (int i = 0; i <= patternStringLength; i++)
			printf("%d  ", nextArray[i]); // ���ģʽ����next����
		printf("\n");
	}

	return 0;
}
