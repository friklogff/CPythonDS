#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100 // ������󳤶�Ϊ100

// �ṹ�嶨�壬��ʾ˳��� (Sequence List)
typedef struct {
	int data[MaxSize]; // ������������Ԫ��
	int length;        // ���Ա�ĵ�ǰ����
} SqList; // ���Ա�����Ͷ���

/**
 * ��˳�����ɾ����СֵԪ�ز����ظ�ֵ
 * @param list ˳���
 * @param minValue ���ò��������ڱ���ɾ������Сֵ
 * @return ����ɹ�ɾ������ true�����򷵻� false
 */
bool deleteMinElement(SqList &list, int &minValue) {
	// �����Ϊ�գ����� false
	if (list.length == 0)
		return false;

	// ��¼��СֵԪ�ص��±�
	int minIndex = 0;
	for (int i = 1; i < list.length; i++) {
		// Ѱ����СֵԪ�ص��±�
		if (list.data[i] < list.data[minIndex])
			minIndex = i;
	}

	// ����Сֵ�������ñ��� minValue
	minValue = list.data[minIndex];
	// �����һ��Ԫ�ظ�����СֵԪ������λ��
	list.data[minIndex] = list.data[list.length - 1];
	// ��С˳�����
	list.length--;

	return true; // ���سɹ���־
}

int main() {
	// ����һ��˳�������ʼ���䳤�Ⱥ�Ԫ��
	SqList list;
	list.length = 5; // �����ʼ����Ϊ5��Ԫ�ؿ��Ը�����ҪԤ��
	list.data[0] = 3;
	list.data[1] = 1;
	list.data[2] = 4;
	list.data[3] = 1;
	list.data[4] = 5;

	// ���ԭ�����������
	printf("ԭ������Ϊ:\n");
	for (int i = 0; i < list.length; i++) {
		// �������Ԫ��
		printf("%d ", list.data[i]);
	}
	printf("\n");

	int minValue = 0; // ������Сֵ
	// ���� deleteMinElement �������ж��Ƿ�ɹ�
	if (deleteMinElement(list, minValue)) {
		// ���ɹ������ɾ������Сֵ
		printf("��СԪ�� = %d\n", minValue);
		// ������޸�֮������Ա�
		printf("�޸�֮������Ա�Ϊ:\n");
		for (int i = 0; i < list.length; i++) {
			// �������Ԫ��
			printf("%d ", list.data[i]);
		}
		printf("\n");
	} else {
		// ��ʧ�ܣ���ʾ˳���Ϊ��
		printf("����: ˳���Ϊ��\n");
	}

	return 0; // �������
}
