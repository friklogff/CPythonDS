//05.���������������Է����ҳ���������Ĺ�������˼�루����д����)
//### ˼�����
//1. **���ȶ���**��
//   - ���ȼ�����������ĳ��ȣ��ֱ���Ϊ `lenA` �� `lenB`��
//   - ������������Ȳ��ȣ���Ҫ�ȶ������ǵ���㣬ʹ�ú����ıȽϽ������ڳ��Ƚ϶̵Ĺ��������ϡ�
//   - ���巽���ǣ��ϳ�����������ǰ�ƶ� `|lenA ? lenB|` ���ڵ㣬ʹ���������ʣ�೤����ȡ�
//
//2. **˫ָ�����**��
//   - �ֱ�������ָ�� `pA` �� `pB`���ֱ�ָ����������ĵ�ǰ�ڵ㡣
//   - ͬʱ�������������Ƚ�����ָ��ָ��ڵ�����ã���ֵ���������ͬ�����ҵ��˵�һ�������ڵ㡣
//   - ��� `pA` �� `pB` ��ͬ��������ָ��ͬ����ǰ�ƶ�һ���ڵ㣬�����Ƚϡ�
//
//3. **��������**��
//   - ���������ĳһ��ָ�뵽������ĩβ����ָ�� NULL����������һ��ָ����δ�ҵ���ͬ�Ľڵ㣬�����ȷ����������û�й����ڵ㡣
//
//### ���岽��
//1. **����������**��
//   - �������� A ������ B���ֱ�������ǵĳ��� `lenA` �� `lenB`��
//
//2. **��������**��
//   - ��� `lenA` �� `lenB` ��ȣ�ֱ�ӽ�����һ����
//   - ��� `lenA` > `lenB`���������� A ��ǰ�ƶ� `lenA - lenB` ���ڵ㡣
//   - ��� `lenA` < `lenB`���������� B ��ǰ�ƶ� `lenB - lenA` ���ڵ㡣
//
//3. **ͬ�������Ƚ�**��
//   - ͬʱ�������������� A ������ B���Ƚϵ�ǰ�ڵ��Ƿ���ͬ��������ͬ����
//   - ����ͬ�����ҵ���һ�������ڵ㡣
//   - ����ͬ����ָ��ͬʱ��ǰ�ƶ��������Ƚϡ�
//
//4. **��������**��
//   - ����������һ�������ĩβ��ָ��Ϊ NULL������û�й����ڵ㡣
//
//### ʾ������ṹ�����������룬��Ϊʾ��ṹ��
//```c
#include <stdio.h>
#include <stdlib.h>

// ��������Ԫ������
typedef int ElemType;

// ����ڵ�ṹ�嶨��
typedef struct LNode {
	ElemType data;         // ������
	struct LNode *next;    // ָ����ָ����һ���ڵ�
} LNode, *LinkList;

/**
 * �����µ�����ڵ�
 * @param data �ڵ�����
 * @return �´����Ľڵ�
 */
LNode *createNode(ElemType data) {
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

/**
 * ����������
 * @param head ����ͷ�ڵ�
 * @return ������
 */
int getListLength(LinkList head) {
	int length = 0;
	LNode *current = head;
	while (current != NULL) {
		length++;
		current = current->next;
	}
	return length;
}

/**
 * �ҳ���������ĵ�һ�������ڵ�
 * @param headA ����A��ͷ�ڵ�
 * @param headB ����B��ͷ�ڵ�
 * @return ��һ�������ڵ�
 */
LNode *findIntersection(LinkList headA, LinkList headB) {
	// ������������ĳ���
	int lenA = getListLength(headA);
	int lenB = getListLength(headB);

	// ������������ʹ���ǵ�ʣ�೤�����
	LNode *longer = lenA > lenB ? headA : headB;
	LNode *shorter = lenA > lenB ? headB : headA;
	int diff = abs(lenA - lenB);

	while (diff--) {
		longer = longer->next;
	}

	// ͬʱ��������������Ѱ�ҵ�һ�������ڵ�
	while (longer != NULL && shorter != NULL) {
		if (longer == shorter) {
			return longer; // �ҵ���һ�������ڵ�
		}
		longer = longer->next;
		shorter = shorter->next;
	}

	return NULL; // û�й����ڵ�
}

/**
 * ��ӡ����
 * @param head ����ͷ�ڵ�
 */
void printList(LinkList head) {
	LNode *current = head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

int main() {
	// ��������A
	LNode *headA = createNode(1);
	headA->next = createNode(2);
	headA->next->next = createNode(3);
	headA->next->next->next = createNode(4);
	headA->next->next->next->next = createNode(5);

	// ��������B
	LNode *headB = createNode(6);
	headB->next = headA->next->next->next; // ����B�ĵ�2���ڵ�ָ������A�ĵ�4���ڵ�

	// ��ӡ����A
	printf("����A: ");
	printList(headA);

	// ��ӡ����B
	printf("����B: ");
	printList(headB);

	// ������������ĵ�һ�������ڵ�
	LNode *intersection = findIntersection(headA, headB);
	if (intersection != NULL) {
		printf("��һ�������ڵ���: %d\n", intersection->data);
	} else {
		printf("û���ҵ������ڵ㡣\n");
	}

	return 0;
}

//```
//### �ܽ�
//���˼��ĺ������������ȶ����ͨ��ͬ�����������������ҵ���һ�������ڵ㡣���ַ�����ʱ�临�Ӷ�Ϊ O(m + n)�������ڴ󲿷�Ѱ������������⡣ͨ��ͬ���ƶ�ָ�룬ȷ����û����©�κο��ܵĹ����ڵ㡣