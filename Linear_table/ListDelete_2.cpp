#include <stdio.h>

#define MaxSize 10 // ������󳤶�

typedef struct {
    int data[MaxSize]; // �þ�̬������������Ԫ��
    int length; // ˳���ĵ�ǰ����
} SqList; // ˳�������Ͷ���

// ɾ��ָ��λ�õ�Ԫ�أ�����ֵ���ظ�e
int ListDelete(SqList* L, int i, int* e) {
    // �ж�ɾ��λ�õĺϷ���
    if (i < 1 || i > L->length) {
        return 0; // ɾ��ʧ��
    }
    // ��Ҫɾ����Ԫ�ص�ֵ���浽e��
    *e = L->data[i - 1];
    // ��ɾ��λ�ú��Ԫ��������ǰ�ƶ�һλ
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--; // ���Ա��ȼ�1
    return 1; // ɾ���ɹ�
}

int main() {
    SqList L; // ����һ��˳���

    // ���һЩʾ������
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = i + 1;
    }
    L.length = MaxSize;

    // ɾ��Ԫ��
    int deletedElem;
    if (ListDelete(&L, 2, &deletedElem)) {
        printf("Deleted element: %d\n", deletedElem);
    }

    // ���ɾ��Ԫ�غ�����Ա�
    printf("Elements in the list: ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    return 0;
}