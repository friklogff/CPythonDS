#include <stdio.h>

#define MaxSize 50 // ����˳������󳤶�

// �ṹ�嶨�壬��ʾ˳��� (Sequence List)
typedef struct {
	int data[MaxSize]; // ������������Ԫ��
	int length;        // ���Ա�ĵ�ǰ����
} SqList; // ���Ա�����Ͷ���

/**
 * ��˳�����ɾ������ֵΪ x ��Ԫ��
 * @param list ˳���
 * @param x Ҫɾ����ֵ
 */
void deleteElements(SqList &list, int x) {
	int shiftCount = 0; // ��¼��ɾ����Ԫ������
	for (int i = 0; i < list.length; i++) {
		if (list.data[i] == x) {
			// ���Ԫ�ص��� x������ɾ������
			shiftCount++;
		} else {
			// ���򽫵�ǰԪ����ǰ�ƶ� shiftCount λ
			list.data[i - shiftCount] = list.data[i];
		}
	}
	// ����˳���ĳ���
	list.length -= shiftCount;
}

int main() {
	// ��ʼ��һ��˳���
	SqList list = {{5, 2, 0, 1, 3, 1, 4, 1, 1, 4}, 10};

	// ��ӡԭʼ˳���
	for (int i = 0; i < list.length; i++) {
		printf("%d ", list.data[i]);
	}
	printf("\n");

	// ��˳�����ɾ������ֵΪ 1 ��Ԫ��
	deleteElements(list, 1);

	// ��ӡɾ�����˳���
	for (int i = 0; i < list.length; i++) {
		printf("%d ", list.data[i]);
	}
	printf("\n");

	return 0; // �������
}
