//18.��2012ͳ�����⡿�ٶ����ô�ͷ���ĵ������浥�ʣ���������������ͬ�ĺ�׺ʱ��
//�ɹ�����ͬ�ĺ�׺�洢�ռ䣬���磬loading �� being �Ĵ洢ӳ������ͼ��ʾ��
//strl��
//��ioʮa��al
//str2,
//n]һ
//��bʮe]
//��str1��str2�ֱ�ָ�������������ڵ������ͷ��㣬������ṹΪdata ] next ,�����һ��ʱ���Ͼ����ܸ�Ч���㷨���ҳ���strl��str2��ָ����������ͬ��׺����ʼλ�ã���ͼ���ַ�i���ڽ���λ��p)��Ҫ��:
//1)�����㷨�Ļ������˼�롣
//2���������˼�룬����C��C++��Java���������㷨���ؼ�֮������ע�͡�3��˵����������㷨��ʱ�临�Ӷȡ�

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char ElemType; // ��������Ԫ������

// ����ڵ�ṹ�嶨��
typedef struct LNode {
	ElemType data;       // ������
	struct LNode *next;  // ָ����ָ����һ���ڵ�
} LNode, *LinkList;

// ��ʼ�������ַ���������ǵĳ���
char a[7] = {'l', 'o', 'a', 'd', 'i', 'n', 'g'};

char b[5] = {'b', 'e', 'i', 'n', 'g'};
int n1 = 7, n2 = 5;

/**
 * @brief   ������������
 * @param   L      ����ͷ�ڵ��ָ��
 * @param   arr    ����
 * @param   n      ���鳤��
 */
void BuildList(LinkList *L, char arr[], int n) {
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
 * @brief   ��ʾ����Ԫ��
 * @param   L      ����ͷ�ڵ�
 */
void DisplayList(LinkList L) {
	LNode *currentNode = L->next; // ����ͷ�ڵ�
	while (currentNode) {
		printf("%c ", currentNode->data); // ��ӡ��ǰ�ڵ�����
		currentNode = currentNode->next; // �ƶ�����һ���ڵ�
	}
	printf("\n");
}

/**
 * @brief   ����������
 * @param   L      ����ͷ�ڵ�
 * @return  ������
 */
int GetListLength(LinkList L) {
	int length = 0; // ��ʼ������Ϊ 0
	LNode *currentNode = L->next; // ����ͷ�ڵ�
	while (currentNode) {
		length++; // ÿ����һ���ڵ㣬���ȼ� 1
		currentNode = currentNode->next; // �ƶ�����һ���ڵ�
	}
	return length;
}

/**
 * @brief   ������������Ĺ�����׺��ʼ�ڵ�
 * @param   L1     ��һ������
 * @param   L2     �ڶ�������
 * @return  ������׺��ʼ�ڵ��ָ��
 */
LinkList FindFirstCommonNode(LinkList L1, LinkList L2) {
	int len1 = GetListLength(L1), len2 = GetListLength(L2); // ��ȡ��������ĳ���
	int lengthDifference = abs(len1 - len2); // ���㳤�Ȳ�
	LNode *pNode = L1->next, *qNode = L2->next; // ����ͷ�ڵ㣬ָ���һ���ڵ�

	// �ýϳ����������� "���Ȳ�" ��
	if (len1 >= len2) {
		while (lengthDifference--) {
			pNode = pNode->next;
		}
	} else {
		while (lengthDifference--) {
			qNode = qNode->next;
		}
	}

	// ͬʱ������������Ѱ�ҵ�һ����ͬ�Ľڵ�
	while (pNode && qNode) {
		if (pNode->data != qNode->data) {
			pNode = pNode->next;
			qNode = qNode->next;
		} else
			return pNode; // �ҵ���һ����ͬ�Ľڵ�
	}
	return NULL; // ���û���ҵ���ͬ�Ľڵ�
}

int main() {
	LinkList L1, L2;
	BuildList(&L1, a, n1); // �������� L1
	BuildList(&L2, b, n2); // �������� L2
	printf("L1:\n");
	DisplayList(L1); // ��ʾ���� L1
	printf("L2:\n");
	DisplayList(L2); // ��ʾ���� L2
	LinkList commonNode = FindFirstCommonNode(L1, L2); // ���ҹ�����׺����ʼ�ڵ�
	if (commonNode != NULL) {
		printf("������׺����ʼ���Ϊ: %c\n", commonNode->data); // ��ʾ������׺��ʼ�ڵ��ֵ
	} else {
		printf("û���ҵ�������׺��\n");
	}
	return 0;
}
