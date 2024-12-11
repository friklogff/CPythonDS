#include <stdio.h>
#include <string.h>

void getNext(char *pattern, int *next) {
	int m = strlen(pattern); // ģʽ������
	next[0] = -1; // ��ʼ����һ��Ԫ��
	int j = 0; // ָ��ǰ������ַ�
	int k = -1; // next[j]��ֵ

	while (j < m - 1) {
		// ���ƥ��ɹ�����ʼkΪ-1ֱ��ʧ�ܣ�����ݹ鵽next[k]��ֵ��ͬ
		if (k == -1 || pattern[j] == pattern[k]) {
			++j;
			++k;
			next[j] = k;
		} else {
			k = next[k]; // �ݹ�ƥ��ʧ�ܻ��˵�֮ǰ��ĳ��λ��
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
