#include <stdio.h>

#define MaxSize 10 // ������󳤶�

typedef struct {
    int data[MaxSize]; // �þ�̬������������Ԫ��
    int length; // ˳���ĵ�ǰ����
} SqList; // ˳�������Ͷ���

// ����������Ա��е�����Ԫ��
void PrintList(SqList L) {
    printf("Elements in the list: ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList L; // ����һ��˳���

    // ���һЩʾ������
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = i + 1;
    }
    L.length = MaxSize;

    // ������Ա��е�Ԫ��
    PrintList(L);

    return 0;
}