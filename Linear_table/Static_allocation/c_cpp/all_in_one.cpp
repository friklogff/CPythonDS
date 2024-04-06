#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100 // ������󳤶�

typedef struct {
    int data[MaxSize]; // ������������Ԫ��
    int length; // ���Ա�ĵ�ǰ����
} SqList; // ���Ա�����Ͷ���

// ��ʼ��һ�����Ա�
void InitList(SqList* L) {
    L->length = 0; // �����Ա�ĳ��ȳ�ʼ��Ϊ0
}

// �������Ա�
void DestroyList(SqList* L) {
    L->length = 0; // �����Ա�ĳ�����Ϊ0���൱��������Ա�
}

// ��ָ��λ�ò���Ԫ��
bool ListInsert(SqList* L, int i, int e) {
    // �жϲ���λ�õĺϷ���
    if (i < 1 || i > L->length + 1) {
        printf("Error: Invalid position\n");
        return false;
    }
    // �ж����Ա��Ƿ�����
    if (L->length == MaxSize) {
        printf("Error: Linear list is full\n");
        return false;
    }
    // ������λ�ú��Ԫ����������ƶ�һλ
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    // ����Ԫ�ز��뵽ָ��λ��
    L->data[i - 1] = e;
    L->length++; // ���Ա��ȼ�1
    return true;
}

// ɾ��ָ��λ�õ�Ԫ�أ�����ֵ���ظ�e
bool ListDelete(SqList* L, int i, int* e) {
    // �ж�ɾ��λ�õĺϷ���
    if (i < 1 || i > L->length) {
        printf("Error: Invalid position\n");
        return false;
    }
    // ��Ҫɾ����Ԫ�ص�ֵ���浽e��
    *e = L->data[i - 1];
    // ��ɾ��λ�ú��Ԫ��������ǰ�ƶ�һλ
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--; // ���Ա��ȼ�1
    return true;
}

// ��ֵ����Ԫ�ص�λ��
int LocateElem(const SqList* L, int e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i + 1; // ����λ�ã���1��ʼ������
        }
    }
    return -1; // δ�ҵ�ʱ����-1
}

// ��λ����Ԫ�ص�ֵ
bool GetElem(const SqList* L, int i, int* e) {
    // �жϲ���λ�õĺϷ���
    if (i < 1 || i > L->length) {
        printf("Error: Invalid position\n");
        return false;
    }
    // ���ҵ���Ԫ�ص�ֵ���浽e��
    *e = L->data[i - 1];
    return true;
}

// �����Ա�ĳ���
int Length(const SqList* L) {
    return L->length;
}

// ����������Ա��е�����Ԫ��
void PrintList(const SqList* L) {
    printf("Elements in the linear list: ");
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// �ж����Ա��Ƿ�Ϊ��
bool Empty(const SqList* L) {
    return (L->length == 0);
}

int main() {
    SqList L; // ����һ�����Ա�
    InitList(&L); // ��ʼ�����Ա�L

    // ����ʾ��Ԫ��
    ListInsert(&L, 1, 10);
    ListInsert(&L, 2, 20);
    ListInsert(&L, 3, 30);

    // ������Ա��е�Ԫ��
    PrintList(&L);

    // ��ȡָ��λ�õ�Ԫ��
    int position = 2;
    int elem;
    if (GetElem(&L, position, &elem)) {
        printf("The element at position %d is %d\n", position, elem);
    }

    // ɾ��ָ��λ�õ�Ԫ��
    int deletedElem;
    if (ListDelete(&L, 2, &deletedElem)) {
        printf("Deleted element: %d\n", deletedElem);
    }

    // ���ɾ��Ԫ�غ�����Ա�
    PrintList(&L);

    // �������Ա�
    DestroyList(&L);

    return 0;
}