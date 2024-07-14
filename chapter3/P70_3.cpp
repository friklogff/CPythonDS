#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ���г���
int n;

/**
 * @brief ���ջ���������Ƿ�Ϸ�
 * @param s ջ��������
 * @return true �Ϸ���false ���Ϸ�
 */
bool IsSequenceValid(char s[]) {
	int countI = 0, countO = 0; // I �� O �ļ���
	for (int i = 0; i < n; i++) {
		if (s[i] == 'I')
			countI++; // ��ջ����
		else
			countO++; // ��ջ����
		if (countO > countI) // �����ջ��������������ջ�����������򲻺Ϸ�
			return false;
	}
	// �����ջ�ͳ�ջ����������ȣ���Ϸ�
	if (countO == countI)
		return true;
	return false; // ���򲻺Ϸ�
}

int main() {
	char s[8] = {'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O'};
	n = 8; // ���г���
	if (IsSequenceValid(s))
		printf("�Ϸ�\n");
	else
		printf("���Ϸ�\n");
	return 0;
}
