
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100 // ������󳤶�Ϊ100

// �ṹ�嶨�壬��ʾ˳��� (Sequence List)
typedef struct {



	int data[MaxSize]; // ������������Ԫ��
	int length;        // ���Ա�ĵ�ǰ����
} SqList; // ���Ա�����Ͷ���
//08.���Ա�(a1, a2, a3,����, an)�е�Ԫ�ص��������Ұ�˳��洢�ڼ�����ڡ�Ҫ�����һ���㷨�����������ʱ���ڱ��в�����ֵΪx��Ԫ�أ�
//���ҵ�����������Ԫ��λ���ཻ�������Ҳ��������������в�ʹ����Ԫ���Ե�������
void findd(SqList *L, int x) {
	int left, right, mid;
	left = 0, right = L->length - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (x > L->data[mid])
			left = mid + 1;
		if (x = L->data[mid])
			break;
		if (x < L->data[mid])
			right = mid - 1;
	}
	if (left > right) {

	}

}

int main() {
	SqList L = {{1, 2, 3, 4, 5, 7, 8, 9, 10}, 9};

	for (int i = 0; i < L.length; i++)
		printf("%d ", L.data[i]);
	printf("\n");

	findd(&L, 6);

	for (int i = 0; i < L.length; i++)
		printf("%d ", L.data[i]);
	printf("\n");

	return 0;
}
