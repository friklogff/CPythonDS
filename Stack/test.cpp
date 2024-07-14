#include <stdio.h>

typedef struct {
	int data;
} SqList, *LSqList;

void ParamByReference(SqList &L) {
	L.data = 100;
}

void ParamByPointer(SqList *L) {
	L->data = 200;
}

void ParamByLSqListReference(LSqList &L) {
	L->data = 300;
}

void ParamByLSqListPointer(LSqList *L) {
	(*L)->data = 400; // 注意语法
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

	SqList L3;
	LSqList pL3 = &L3;
	L3.data = 0;

	SqList L4;
	LSqList pL4 = &L4;
	L4.data = 0;

	ParamByLSqListReference(pL3);
	printf("通过LSqList引用传递后的值: %d\n", L3.data); // 输出 300

	ParamByLSqListPointer(&pL4);
	printf("通过LSqList指针传递后的值: %d\n", L4.data); // 输出 400

	return 0;
}
