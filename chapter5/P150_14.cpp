//������������ö�������洢�ṹ�����һ���㷨����ǿն�����b�Ŀ��(�����н����������һ��Ľ�����)��
#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct TreeNode {
	char data; // �ڵ�����
	struct TreeNode *leftChild, *rightChild; // ���Һ���ָ��
} TreeNode, *Tree;

// ������нṹ�壬���ڴ洢���ڵ�Ͳ����Ϣ
typedef struct {
	TreeNode *data[10]; // ���д洢�����ڵ�
	int level[10]; // ���ڵ��Ӧ�Ĳ��
	int front, rear; // ���е�ͷβָ��
} Queue;

/**
 * @brief ����������
 * @param t ָ����������ڵ��ָ��
 */
void BuildTree(Tree *t) {
	char ch;
	ch = getchar(); // �������ж�ȡһ���ַ�

	if (ch == '#') { // �����ȡ�� '#'�����λ��Ϊ�սڵ�
		*t = NULL;
	} else {
		*t = (TreeNode *)malloc(sizeof(TreeNode)); // �����½ڵ���ڴ�
		(*t)->data = ch; // ����ȡ�����ַ���ֵ���ڵ�����
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;

		BuildTree(&((*t)->leftChild)); // �ݹ鹹��������
		BuildTree(&((*t)->rightChild)); // �ݹ鹹��������
	}
}

/**
 * @brief ����������������
 * @param root ���������ڵ�ָ��
 * @return �������������
 */
int GetWidth(Tree root) {
	Queue Q; // ����һ������
	TreeNode *currentNode;
	int currentLevel;

	Q.front = Q.rear = -1; // ��ʼ�����е�ͷβָ��

	// ���ڵ���Ӳ���������Ϊ1
	Q.rear++;
	Q.data[Q.rear] = root;
	Q.level[Q.rear] = 1;

	while (Q.front < Q.rear) { // ���зǿ�
		Q.front++;
		currentNode = Q.data[Q.front]; // ��ǰ�ڵ����
		currentLevel = Q.level[Q.front]; // ��ȡ��ǰ�ڵ�Ĳ��

		// ������Ӳ���������
		if (currentNode->leftChild != NULL) {
			Q.rear++;
			Q.data[Q.rear] = currentNode->leftChild;
			Q.level[Q.rear] = currentLevel + 1;
		}

		// �Һ�����Ӳ���������
		if (currentNode->rightChild != NULL) {
			Q.rear++;
			Q.data[Q.rear] = currentNode->rightChild;
			Q.level[Q.rear] = currentLevel + 1;
		}
	}

	int maxWidth = 0, i = 0, nodeCount;
	currentLevel = 1;

	while (i <= Q.rear) { // �������нڵ㣬����ÿһ��Ŀ��
		nodeCount = 0;

		// ͳ�Ƶ�ǰ��Ľڵ�����
		while (i <= Q.rear && Q.level[i] == currentLevel) {
			nodeCount++;
			i++;
		}

		currentLevel = Q.level[i]; // ���µ���һ��

		// ���������
		if (nodeCount > maxWidth)
			maxWidth = nodeCount;
	}

	return maxWidth; // ���ض������������
}

int main() {
	Tree t; // ���������ڵ�ָ��
	BuildTree(&t); // ����������
	printf("%d\n", GetWidth(t)); // ���㲢��ӡ�������������
	return 0;
}

/*
ʾ������:
ABD##E##CF##G##

ԭʼ������:
             A
          B    C
        D  E  F  G
 p  q
*/
