#include <stdio.h>

#define MaxSize 10 // ������󳤶�

typedef struct {
	int data[MaxSize]; // �þ�̬������������Ԫ��
	int length; // ˳���ĵ�ǰ����
} SqList; // ˳�������Ͷ���

// ��λ����Ԫ�ص�ֵ
int GetElem(SqList L, int i) {
	// �жϲ���λ�õĺϷ���
	if (i < 1 || i > L.length) {
		return -1; // ����һ����ʾ�����ֵ
	}
	// ����ָ��λ�õ�Ԫ�ص�ֵ
	return L.data[i - 1];
}

int main() {
	SqList L; // ����һ��˳���

	// ���һЩʾ������
	for (int i = 0; i < MaxSize; i++) {
		L.data[i] = i + 1;
	}
	L.length = MaxSize;

	// ��ȡָ��λ�õ�Ԫ��
	int position = 3;
	int elem = GetElem(L, position);
	if (elem != -1) {
		printf("Element at position %d is %d\n", position, elem);
	} else {
		printf("Invalid position\n");
	}

	return 0;
}