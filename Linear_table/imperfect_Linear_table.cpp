#include <stdio.h>

#define MaxSize 10 // ������󳤶�

typedef struct {
	int data[MaxSize]; // �þ�̬������������Ԫ��
	int length; // ˳���ĵ�ǰ����
} SqList; // ˳�������Ͷ���

// ��ʼ��һ��˳���
void InitList(SqList &L) {
//    for (int i = 0; i < MaxSize; i++) {
//        L.data[i] = 0; // ������Ԫ�������Ԫ������ΪĬ��ֵ
//    }
	L.length = 0; // ˳����ʼ����Ϊ0
}

int main() {
	SqList L; // ����һ��˳���
	InitList(L); // ��ʼ��˳���L

	// ����Υ���ӡ����data����
	for (int i = 0; i < MaxSize; i++) {
		printf("data[%d] = %d\n", i, L.data[i]);
	}

	return 0;
}