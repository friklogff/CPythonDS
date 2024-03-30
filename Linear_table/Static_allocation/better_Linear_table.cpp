#include <stdio.h>

#define MaxSize 10 // ������󳤶�

typedef struct {
    int data[MaxSize]; // �þ�̬������������Ԫ��
    int length; // ˳���ĵ�ǰ����
} SqList; // ˳�������Ͷ���

// ��ʼ��һ��˳���
void InitList(SqList& L) {
    L.length = 0; // ˳����ʼ����Ϊ0
}

// ��ȡ˳�����ָ��λ�õ�Ԫ��
int GetElem(const SqList& L, int i) {
    // �ж�λ���Ƿ�Ϸ�
    if (i < 1 || i > L.length) {
        printf("Error: Invalid position\n");
        return -1; // ����һ����ʾ�����ֵ���ɸ���ʵ���������
    }
    return L.data[i - 1]; // ����ָ��λ�õ�Ԫ��
}

int main() {
    SqList L; // ����һ��˳���
    InitList(L); // ��ʼ��˳���L

    // ���һЩʾ������
    L.data[0] = 10;
    L.data[1] = 20;
    L.data[2] = 30;
    L.length = 3;

    // ��ȡָ��λ�õ�Ԫ�ز���ӡ
    int position = 2;
    int elem = GetElem(L, position);
    printf("The element at position %d is %d\n", position, elem);

    return 0;
}