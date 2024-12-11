#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct TreeNode {
	char data; // �ڵ�����
	struct TreeNode *leftChild, *rightChild; // ���Һ���ָ��
} TreeNode, *Tree;

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
 * @brief ����������ĸ߶ȣ���α�����
 * @param t ���������ڵ�ָ��
 * @return ���ĸ߶�
 */
int Depth(Tree t) {
	if (!t) // �����Ϊ�գ����ظ߶�Ϊ0
		return 0;

	Tree queue[10]; // ����һ���̶���С�Ķ��У����ڲ�α���
	int front = -1, rear = -1; // ��ʼ������ͷβָ��
	int currentLevelEnd = 0, height = 0; // ��ǰ�����λ�ú����ĸ߶�

	queue[++rear] = t; // ���ڵ����
	Tree p;

	while (front < rear) { // ���зǿ�
		p = queue[++front]; // �ڵ����

		if (p->leftChild) // ���ӷǿգ��������
			queue[++rear] = p->leftChild;

		if (p->rightChild) // �Һ��ӷǿգ��Һ������
			queue[++rear] = p->rightChild;

		if (front == currentLevelEnd) { // ��ǰ���ѱ�����
			height++; // �������ĸ߶�
			currentLevelEnd = rear; // ���µ�ǰ�����λ��
		}
	}

	return height; // �������ĸ߶�
}

int main() {
	Tree t; // ���������ڵ�ָ��
	BuildTree(&t); // ����������
	printf("���ĸ߶�Ϊ: %d\n", Depth(t)); // ��ӡ���ĸ߶�
	return 0;
}
// ʾ������: ABD##E##CF##G##
