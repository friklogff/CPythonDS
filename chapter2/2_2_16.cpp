//16.����һ������n(nΪż��)�Ĳ���ͷ���ĵ������ҽ��ֵ������0������㷨����
//�����������������͡������Ͷ���Ϊһ�����ֵ�����������ֵ֮�ͣ����ڵ�i����㣨��0��ʼ)�����������Ϊ��nһi-1����㡣Ҫ��:
//1)�����㷨�Ļ������˼�롣
//2���������˼�룬����C��C++���������㷨���ؼ�֮������ע�͡�3��˵������㷨��ʱ�临�ӶȺͿռ临�Ӷȡ�
#include <stdio.h>
#include <stdlib.h>

// ��������Ԫ������
typedef int ElemType;

// ����ڵ�ṹ�嶨��
typedef struct LNode {
	ElemType data;       // ������
	struct LNode *next;  // ָ����ָ����һ���ڵ�
} LNode, *LinkList;

/**
 * @brief ������������
 * @param L ����ͷ�ڵ�ָ��
 * @param arr ����
 * @param n ���鳤��
 */
void BuildList(LinkList *L, int arr[], int n) {
	*L = (LinkList)malloc(sizeof(LNode)); // ����ͷ�ڵ�ռ�
	LNode *newNode, *lastNode = *L; // ʹ�� lastNode ָ����������һ���ڵ�
	for (int i = 0; i < n; i++) {
		newNode = (LNode *)malloc(sizeof(LNode)); // Ϊ�½ڵ����ռ�
		newNode->data = arr[i]; // �����ݸ�ֵ���½ڵ�
		lastNode->next = newNode; // ���½ڵ����ӵ�����ĩβ
		lastNode = lastNode->next; // �ƶ����µ�����ĩβ
	}
	lastNode->next = NULL; // ���һ���ڵ�� next ��Ϊ NULL
}

/**
 * @brief ��ʾ����Ԫ��
 * @param L ����ͷ�ڵ�
 */
void DisplayList(LinkList L) {
	LNode *currentNode = L->next; // ����ͷ�ڵ�
	while (currentNode) {
		printf("%d ", currentNode->data); // ��ӡ��ǰ�ڵ�����
		currentNode = currentNode->next; // �ƶ�����һ���ڵ�
	}
	printf("\n");
}

/**
 * @brief ������������������
 * @param L ����ͷ�ڵ�
 * @return ���������
 */
int CalculateMaxTwinSum(LinkList L) {
	if (L == NULL || L->next == NULL)
		return 0;

	LNode *fast = L->next, *slow = L;
	// �ҵ������м�ڵ�
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	// ��ת�����벿��
	LNode *newHead = NULL, *p = slow->next, *tmp;
	while (p != NULL) {
		tmp = p->next;
		p->next = newHead;
		newHead = p;
		p = tmp;
	}

	// ���������͵����ֵ
	int maxTwinSum = 0;
	LNode *front = L->next, *back = newHead;
	while (back != NULL) {
		int twinSum = front->data + back->data;
		if (twinSum > maxTwinSum) {
			maxTwinSum = twinSum;
		}
		front = front->next;
		back = back->next;
	}

	// �ָ�����ĺ�벿��˳�򣨿�ѡ��
	p = newHead;
	newHead = NULL;
	while (p != NULL) {
		tmp = p->next;
		p->next = newHead;
		newHead = p;
		p = tmp;
	}
	slow->next = newHead;

	return maxTwinSum;
}

int main() {
	LinkList L;
	// ʾ������
	int arr[] = {2, 6, 1, 4, 3, 8, 5, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	BuildList(&L, arr, n); // ��������
	printf("�������ݣ�\n");
	DisplayList(L); // ��ʾ����
	int maxTwinSum = CalculateMaxTwinSum(L); // �������������
	printf("���������Ϊ: %d\n", maxTwinSum);
	return 0;
}
