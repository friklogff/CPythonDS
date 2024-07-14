#include <stdio.h>

#define MaxSize 10 // ������󳤶�

typedef struct {
	int data[MaxSize]; // �þ�̬������������Ԫ��
	int length; // ˳���ĵ�ǰ����
} SqList; // ˳�������Ͷ���

// ��ֵ����Ԫ�ص�λ��
int LocateElem(const SqList* L, int e) {
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] == e) {
			return i + 1; // ����λ�ã���1��ʼ������
		}
	}
	return -1; // δ�ҵ�ʱ����-1
}

int main() {
	SqList L; // ����һ��˳���

	// ���һЩʾ������
	for (int i = 0; i < MaxSize; i++) {
		L.data[i] = i + 1;
	}
	L.length = MaxSize;

	// ����Ԫ�ص�λ��
	int elem = 5;
	int position = LocateElem(&L, elem);
	if (position != -1) {
		printf("Element %d is at position %d\n", elem, position);
	} else {
		printf("Element %d not found\n", elem);
	}

	return 0;
}