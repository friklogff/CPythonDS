#include <stdio.h>

#define MaxSize 50 // ����˳������󳤶�

// �ṹ�嶨�壬��ʾ˳��� (Sequence List)
typedef struct {
	int data[MaxSize]; // ������������Ԫ��
	int length;        // ���Ա�ĵ�ǰ����
} SqList; // ���Ա�����Ͷ���

/**
 * ɾ��˳���������ֵ������ [s, v] ��Ԫ��
 * @param list ˳���
 * @param s ��������
 * @param v ��������
 * @return �ɹ�ɾ������ 1�����򷵻� 0
 */
int deleteElementsInRange(SqList &list, int s, int v) {
	if (s >= v || list.length == 0) {
		// �� s ���ڵ��� v ����˳���Ϊ��ʱ������ 0 ��ʾʧ��
		return 0;
	}

	int start = -1; // ��ǵ�һ�� >= s ��Ԫ���±�
	// �ҵ���һ�� >= s ��Ԫ��
	for (int i = 0; i < list.length; i++) {
		if (list.data[i] >= s) {
			start = i;
			break;
		}
	}

	// ���û���ҵ� >= s ��Ԫ�أ����� 0
	if (start == -1)
		return 0;

	int end = list.length; // ��ǵ�һ�� > v ��Ԫ���±�
	// �ҵ���һ�� > v ��Ԫ��
	for (int i = start; i < list.length; i++) {
		if (list.data[i] > v) {
			end = i;
			break;
		}
	}

	// ��λ������ [s, v] ֮���Ԫ����ǰ�ƶ�
	int newLength = start;
	for (int i = end; i < list.length; i++) {
		list.data[newLength] = list.data[i];
		newLength++;
	}

	// ����˳���ĳ���
	list.length = newLength;

	return 1; // ���� 1 ��ʾ�ɹ�
}

int main() {
	// ��ʼ��һ��˳���
	SqList list = {{1, 2, 3, 3, 4, 5, 6, 7, 7, 7, 8, 9}, 12};

	// ��ӡԭʼ˳���
	for (int i = 0; i < list.length; i++)
		printf("%d ", list.data[i]);
	printf("\n");

	// ����ɾ��ֵ������ [10, 20] ֮���Ԫ��
	if (!deleteElementsInRange(list, 10, 20))
		printf("����: �޷���������Ԫ�ر�ɾ��\n");

	// ��ӡɾ���������˳���
	printf("ɾ�������Ա���Ϊ: %d\n", list.length);
	for (int i = 0; i < list.length; i++)
		printf("%d ", list.data[i]);

	return 0; // �������
}
