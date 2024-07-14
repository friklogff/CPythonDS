#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ��������Ԫ������
typedef char ElemType;

// ����ڵ�ṹ�嶨��
typedef struct LNode {
	ElemType data;       // ������
	struct LNode *next;  // ָ����ָ����һ���ڵ�
} LNode, *LinkList;

// ��ʼ����������鳤��
char s1[4] = {'a', 'b', 'b', 'c'};
int n = 4;

/**
 * @brief ������������
 * @param L ����ͷ�ڵ�ָ��
 */
void BuildList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(LNode)); // ����ͷ�ڵ�ռ�
	LNode *newNode, *lastNode = *L; // ʹ�� lastNode ָ����������һ���ڵ�
	for (int i = 0; i < n; i++) {
		newNode = (LNode *)malloc(sizeof(LNode)); // Ϊ�½ڵ����ռ�
		newNode->data = s1[i]; // �����ݸ�ֵ���½ڵ�
		lastNode->next = newNode; // ���½ڵ����ӵ�����ĩβ
		lastNode = lastNode->next; // �ƶ����µ�����ĩβ
	}
	lastNode->next = NULL; // ���һ���ڵ�� next ��Ϊ NULL
}

/**
 * @brief ��������Ƿ�Ϊ����
 * @param L ����ͷ�ڵ�
 * @param n ������
 * @return true ����ǻ��ģ����� false
 */
bool IsPalindrome(LinkList L, int n) {
	char str[n / 2]; // ���ڴ洢ǰ��ε��ַ�
	LNode *p = L->next;
	int i;

	// ��ǰ����ַ���������
	for (i = 0; i < n / 2; i++) {
		str[i] = p->data;
		p = p->next;
	}
	i--; // ��i���������һ�������ַ���λ��

	// �������Ϊ�����������м���ַ�
	if (n % 2 != 0)
		p = p->next;

	// �������ַ��Ƿ���ǰ����ַ��Գ�
	while (p && p->data == str[i]) {
		i--;
		p = p->next;
	}

	// ��� i == -1���������ַ�ƥ�䣬����true�����򷵻�false
	return i == -1;
}

int main() {
	LinkList L;
	BuildList(&L); // ��������
	if (IsPalindrome(L, n)) // ��������Ƿ�Ϊ����
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
