#include <stdio.h>

#define MaxSize 10 // ������󳤶�

typedef struct {
    int data[MaxSize]; // �þ�̬������������Ԫ��
    int length; // ˳���ĵ�ǰ����
} SqList; // ˳�������Ͷ���

// �����Ա�ĳ���
int Length(const SqList* L) {
    return L->length;
}

int main() {
    SqList L; // ����һ��˳���

    // ���һЩʾ������
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = i + 1;
    }
    L.length = MaxSize;

    // ������Ա�ĳ���
    printf("Length of the list: %d\n", Length(&L));

    return 0;
}