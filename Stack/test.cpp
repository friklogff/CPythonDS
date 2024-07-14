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
	(*L)->data = 400; // ע���﷨
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

	SqList L3;
	LSqList pL3 = &L3;
	L3.data = 0;

	SqList L4;
	LSqList pL4 = &L4;
	L4.data = 0;

	ParamByLSqListReference(pL3);
	printf("ͨ��LSqList���ô��ݺ��ֵ: %d\n", L3.data); // ��� 300

	ParamByLSqListPointer(&pL4);
	printf("ͨ��LSqListָ�봫�ݺ��ֵ: %d\n", L4.data); // ��� 400

	return 0;
}
