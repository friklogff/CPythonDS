#include <stdio.h>

typedef struct {
    int data;
} SqList;

void ParamByReference(SqList& L) {
    L.data = 100;
}

void ParamByPointer(SqList* L) {
    L->data = 200;
}

int main() {
    SqList L1;
    L1.data = 0;

    SqList L2;
    L2.data = 0;

    ParamByReference(L1);
    printf("ͨ�����ô��ݺ��ֵ: %d\n", L1.data); // ��� 100

    ParamByPointer(&L2);
    printf("ͨ��ָ�봫�ݺ��ֵ: %d\n", L2.data); // ��� 200

    return 0;
}