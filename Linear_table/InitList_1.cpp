#include <stdio.h>

#define MaxSize 10 // ������󳤶�

typedef struct {
    int data[MaxSize]; // �þ�̬������������Ԫ��
    int length; // ˳���ĵ�ǰ����
} SqList; // ˳�������Ͷ���

// ��ʼ��һ��˳���
void InitList(SqList &L) {
    L.length = 0; // ˳����ʼ����Ϊ0
}

int main() {
    SqList L; // ����һ��˳���
    InitList(L); // ��ʼ��˳���L

    // �����ʼ����
    printf("Length of the list: %d\n", L.length);

    return 0;
}