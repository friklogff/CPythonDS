#include <stdio.h>

#define MaxSize 10 // ������󳤶�

typedef struct {
    int data[MaxSize]; // �þ�̬������������Ԫ��
    int length; // ˳���ĵ�ǰ����
} SqList; // ˳�������Ͷ���

// ��ָ��λ�ò���Ԫ��
int ListInsert(SqList* L, int i, int e) {
    // �жϲ���λ�õĺϷ���
    if (i < 1 || i > L->length + 1 || L->length == MaxSize) {
        return 0; // ����ʧ��
    }
    // ������λ�ú��Ԫ����������ƶ�һλ
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    // ����Ԫ�ز��뵽ָ��λ��
    L->data[i - 1] = e;
    L->length++; // ���Ա��ȼ�1
    return 1; // ����ɹ�
}

int main() {
    SqList L; // ����һ��˳���

    // ��ʼ��˳���
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;
    }
    L.length = 0;

    // ����Ԫ��
    ListInsert(&L, 1, 10);
    ListInsert(&L, 2, 20);

    // ������������Ա�
    printf("Elements in the list: ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    return 0;
}