#include <stdio.h>

#define MaxSize 10 // ������󳤶�

typedef struct {
    int data[MaxSize]; // �þ�̬������������Ԫ��
    int length; // ˳���ĵ�ǰ����
} SqList; // ˳�������Ͷ���

// �������Ա�
void DestroyList(SqList &L) {
    L.length = 0; // �����Ա�ĳ�����Ϊ0���൱��������Ա�
}

int main() {
    SqList L; // ����һ��˳���

    // ���һЩʾ������
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;

    // �������Ա�
    DestroyList(L);

    // ������ٺ�ĳ���
    printf("Length of the list after destruction: %d\n", L.length);

    return 0;
}