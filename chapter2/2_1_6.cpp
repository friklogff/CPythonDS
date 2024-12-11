//06������������˳���ϲ�Ϊһ���µ�����˳������ɺ������ؽ��˳���

#include <stdio.h>

#define MaxSize 50 // ����˳������󳤶�

// �ṹ�嶨�壬��ʾ˳��� (Sequence List)
typedef struct {
	int data[MaxSize]; // ������������Ԫ��
	int length;        // ���Ա�ĵ�ǰ����
} SqList; // ���Ա�����Ͷ���

/**
 * ����������˳���ϲ���һ������˳���
 * @param listA ˳��� A
 * @param listB ˳��� B
 * @param listC ���ڴ洢�ϲ������˳���
 * @return �ɹ��ϲ����� 1�����򷵻� 0
 */
int mergeOrderedLists(SqList listA, SqList listB, SqList &listC) {
	if (listC.length < listA.length + listB.length)
		return 0; // ��� listC �����������Դ洢�ϲ���������� 0 ��ʾʧ��

	int i = 0, j = 0, k = 0;

	// �ϲ���������˳���
	while (i < listA.length && j < listB.length) {
		if (listA.data[i] <= listB.data[j])
			listC.data[k++] = listA.data[i++];
		else
			listC.data[k++] = listB.data[j++];
	}

	// �� listA ��ʣ���Ԫ�ؼ��� listC
	while (i < listA.length)
		listC.data[k++] = listA.data[i++];

	// �� listB ��ʣ���Ԫ�ؼ��� listC
	while (j < listB.length)
		listC.data[k++] = listB.data[j++];

	// ���ºϲ���˳���ĳ���
	listC.length = listA.length + listB.length;
	return 1; // ���� 1 ��ʾ�ɹ�
}

int main() {
	// ��ʼ������˳���
	SqList listA = {{2, 3, 4, 6, 7}, 5};
	SqList listB = {{3, 4, 4}, 3};
	SqList listC;
	listC.length = MaxSize; // Ԥ������ listC ������Ϊ�������

	// ��ӡԭʼ˳��� listA
	printf("List A: ");
	for (int i = 0; i < listA.length; i++)
		printf("%d ", listA.data[i]);
	printf("\n");

	// ��ӡԭʼ˳��� listB
	printf("List B: ");
	for (int i = 0; i < listB.length; i++)
		printf("%d ", listB.data[i]);
	printf("\n");

	// ���Ժϲ�˳��� listA �� listB
	if (!mergeOrderedLists(listA, listB, listC))
		printf("�ϲ�����: Ŀ��˳�����������\n");
	else {
		// ��ӡ�ϲ����˳��� listC
		printf("Merged List C: ");
		for (int i = 0; i < listC.length; i++) {
			printf("%d ", listC.data[i]);
		}
		printf("\n");
	}

	return 0; // �������
}
