#include <stdio.h>
#include <stdbool.h>

#define MaxSize 50 // ����˳������󳤶�

// �ṹ�嶨�壬��ʾ˳��� (Sequence List)
typedef struct {
	int data[MaxSize]; // ������������Ԫ��
	int length;        // ���Ա�ĵ�ǰ����
} SqList; // ���Ա�����Ͷ���

/**
 * ��ʼ��˳���
 * @param list ˳���
 */
void initializeSqList(SqList &list) {
	int initialData[] = {1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5};
	list.length = 11;
	for (int i = 0; i < list.length; i++) {
		list.data[i] = initialData[i]; // ��ʼ��˳��������
	}
}

/**
 * ɾ��˳����������ظ���Ԫ��
 * @param list ˳���
 * @return �ɹ�ɾ������ true�����򷵻� false
 */
bool deleteAdjacentDuplicates(SqList &list) {
	if (list.length == 0)
		return false; // ��˳���Ϊ�գ����� false ��ʾʧ��

	int i = 0;
	// j �ӵڶ���Ԫ�ؿ�ʼ�����������ظ�Ԫ������ǰ��
	for (int j = 1; j < list.length; j++) {
		if (list.data[i] != list.data[j])
			list.data[++i] = list.data[j]; // ����˳���Ԫ��λ��
	}
	list.length = i + 1; // ����˳���ĳ���

	return true; // ���� true ��ʾ�ɹ�
}

int main() {
	SqList list;
	initializeSqList(list); // ��ʼ��˳���

	// ��ӡԭʼ˳���
	for (int i = 0; i < list.length; i++)
		printf("%d ", list.data[i]);
	printf("\n");

	// ����ɾ�������ظ���Ԫ��
	if (!deleteAdjacentDuplicates(list))
		printf("����: ˳���Ϊ��\n");

	// ��ӡɾ���������˳���
	for (int i = 0; i < list.length; i++)
		printf("%d ", list.data[i]);

	return 0; // �������
}
