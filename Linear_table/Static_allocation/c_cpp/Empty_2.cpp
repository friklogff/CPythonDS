#include <stdio.h>
#include <stdbool.h>

#define MaxSize 10 // ������󳤶�

typedef struct {
    int data[MaxSize]; // �þ�̬������������Ԫ��
    int length; // ˳���ĵ�ǰ����
} SqList; // ˳�������Ͷ���

// �ж����Ա��Ƿ�Ϊ��
bool Empty(const SqList* L) {
    return (L->length == 0);
}

int main() {
    SqList L; // ����һ��˳���

    // ��ʼ��˳���
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;
    }
    L.length = 0;

    // �ж����Ա��Ƿ�Ϊ��
    if (Empty(&L)) {
        printf("The list is empty\n");
    } else {
        printf("The list is not empty\n");
    }

    return 0;
}