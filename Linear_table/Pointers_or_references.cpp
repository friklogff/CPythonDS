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
    printf("通过引用传递后的值: %d\n", L1.data); // 输出 100

    ParamByPointer(&L2);
    printf("通过指针传递后的值: %d\n", L2.data); // 输出 200

    return 0;
}