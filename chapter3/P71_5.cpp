#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 50 // ջ���������

// ���干��ռ��˫ջ�ṹ��
typedef struct {
	int data[Max]; // ������
	int top[2];    // ����ջ��ջ��ָ��
} Stack;

// ȫ�ֱ�������
Stack s; // ����һ������ռ��˫ջ

/**
 * @brief ��Ԫ�� x ѹ���i��ջ��
 * @param i ջ�ı�ţ�0��1��
 * @param x Ҫѹ���Ԫ��
 * @return 1 ��ʾ�����ɹ���-1 ��ʾ����ʧ��
 */
int Push(int i, int x) {
	if (i != 0 && i != 1) { // ���ջ��Ų�Ϊ0��1
		printf("��Чջ���\n");
		return -1;
	}
	if (s.top[1] - s.top[0] == 1) { // ���ջ����
		printf("ջ����\n");
		return -1;
	}
	// ����ջ���ѹ����Ӧջ��
	if (i == 0)
		s.data[++s.top[0]] = x; // 0��ջ��ջ��ָ�����ƺ�ѹ��Ԫ��
	else
		s.data[--s.top[1]] = x; // 1��ջ��ջ��ָ�����ƺ�ѹ��Ԫ��
	return 1;
}

/**
 * @brief �ӵ�i��ջ�е���Ԫ��
 * @param i ջ�ı�ţ�0��1��
 * @return ������Ԫ�ػ�-1��ʾ����ʧ��
 */
int Pop(int i) {
	if (i != 0 && i != 1) { // ���ջ��Ų�Ϊ0��1
		printf("��Чջ���\n");
		return -1;
	}
	if (i == 0) {
		if (s.top[0] == -1) { // 0��ջΪ��
			printf("0��ջΪ��\n");
			return -1;
		}
		return s.data[s.top[0]--]; // 0��ջ������Ԫ�ز�ջ��ָ������
	} else {
		if (s.top[1] == Max) { // 1��ջΪ��
			printf("1��ջΪ��\n");
			return -1;
		}
		return s.data[s.top[1]++]; // 1��ջ������Ԫ�ز�ջ��ָ������
	}
}

int main() {
	// ��ʼ��ջ��ָ��
	s.top[0] = -1;
	s.top[1] = Max;

	// ���� 0��ջ��ѹջ����
	if (Push(0, 1) != -1)
		printf("0��ջѹջ�ɹ�\n");

	// ���� 0��ջ�ĵ�ջ����
	int x = Pop(0);
	if (x != -1) {
		printf("0��ջ��ջ�ɹ�  ");
		printf("0��ջ��ջԪ��Ϊ: %d\n", x);
	}

	// �ٴγ��Ե�ջ������Ӧ����� 0��ջΪ��
	int y = Pop(0);

	return 0;
}
