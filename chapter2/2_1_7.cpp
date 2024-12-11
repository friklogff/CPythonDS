//07����֪��һά����A[m+n]�����δ���������Ա�(a1,a2,a3,��, am)��(b1,b2,b3��,bn)��
//��дһ������,������������˳����λ�û���,����(b1,b2,b3��,bn)����(a1,a2,a3,��, am)��ǰ�档
#include <stdio.h>

#define MaxSize 50 // ����˳������󳤶�

// �ṹ�嶨�壬��ʾ˳��� (Sequence List)
typedef struct {
	int data[MaxSize]; // ������������Ԫ��
	int length;        // ���Ա�ĵ�ǰ����
} SqList; // ���Ա�����Ͷ���

/**
 * ��ת˳����д� left �� right ��Ԫ��
 * @param list ˳���
 * @param left ��߽�
 * @param right �ұ߽�
 */
void reverseList(SqList &list, int left, int right) {
	for (int i = left; i <= (right + left) / 2; i++) {
		int temp = list.data[i];
		list.data[i] = list.data[right + left - i];
		list.data[right + left - i] = temp;
	}
}

/**
 * ��ӡ˳���
 * @param list ˳���
 */
void printSqList(const SqList &list) {
	for (int i = 0; i < list.length; i++)
		printf("%d ", list.data[i]);
	printf("\n");
}

/**
 * ���ݷ�ת������˳�������ض���Ԫ������
 * @param list ˳���
 * @param m ��һ�������Ԫ������
 * @param n �ڶ��������Ԫ������
 */
void rearrangeList(SqList &list, int m, int n) {
	printf("��һ�����巭ת��\n");
	reverseList(list, 0, m + n - 1);
	printSqList(list);

	printf("�ڶ��η�תǰ %d ��Ԫ�أ�\n", n);
	reverseList(list, 0, n - 1);
	printSqList(list);

	printf("�����η�תʣ��� %d ��Ԫ�أ�\n", m);
	reverseList(list, n, m + n - 1);
	printSqList(list);
}

int main() {
	SqList list = {{1, 2, 3, 4, 5, 6, 7}, 7}; // ��ʼ��˳���
	rearrangeList(list, 3, 4); // ִ��Ԫ�����ţ�m Ϊ 3��n Ϊ 4
	return 0; // �������
}
