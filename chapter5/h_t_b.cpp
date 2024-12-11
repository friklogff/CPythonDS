#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ
typedef struct Node {
	char key;  // ����ֵ
	struct Node *left;  // ����ָ��
	struct Node *right;  // �Һ���ָ��
	struct Node *parent;  // ˫��ָ��
} Node;

// �������ṹ
typedef struct {
	Node *root;  // ���ڵ��ָ��
} PostOrderThreadedBinaryTree;

// �����½ڵ�
Node *createNode(char key) {
	// Ϊ�½ڵ�����ڴ�
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->key = key;  // ���ýڵ��ֵ
	newNode->left = NULL;  // ��ʼ������ΪNULL
	newNode->right = NULL;  // ��ʼ���Һ���ΪNULL
	newNode->parent = NULL;  // ��ʼ��˫��ΪNULL
	return newNode;  // �����´����Ľڵ�
}

// ����ڵ㵽����
void insert(PostOrderThreadedBinaryTree *tree, char key) {
	// �����½ڵ�
	Node *newNode = createNode(key);
	if (!tree->root) {  // ������ǿյ�
		tree->root = newNode;  // �½ڵ�Ϊ���ڵ�
	} else {
		Node *queue[100];  // �����������ڲ�α���
		int front = 0, rear = 0;  // ��ʼ������ǰ��ָ��
		queue[rear++] = tree->root;  // �����ڵ����

		while (front < rear) {  // ���в�Ϊ��
			Node *current = queue[front++];  // ����һ���ڵ�
			if (!current->left) {  // �����ǰ�ڵ�û������
				current->left = newNode;  // ���½ڵ����Ϊ����
				newNode->parent = current;  // �����½ڵ��˫��ָ��
				break;  // ��������
			} else {
				queue[rear++] = current->left;  // ���������
			}
			if (!current->right) {  // �����ǰ�ڵ�û���Һ���
				current->right = newNode;  // ���½ڵ����Ϊ�Һ���
				newNode->parent = current;  // �����½ڵ��˫��ָ��
				break;  // ��������
			} else {
				queue[rear++] = current->right;  // ���Һ������
			}
		}
	}
}

// Ѱ�Һ�������еĵ�һ���ڵ㣨�������������½ڵ㣩
Node *leftmostChild(Node *node) {
	Node *current = node;  // �ӵ�ǰ�ڵ㿪ʼ
	while (current->left) {  // ����������
		current = current->left;  // �ƶ�������
	}
	return current;  // ���������µĽڵ�
}

// Ѱ�ҽڵ�ĺ��
Node *findPostorderSuccessor(Node *node) {
	// ���1: �ڵ�x�Ǹ��ڵ�
	if (!node->parent) {
		return NULL;
	}
	// ���2: �ڵ�x����˫�׵��Һ��ӣ�������˫�׵���������˫��û��������
	if (node->parent->right == node || (node->parent->left == node && !node->parent->right)) {
		return node->parent;  // �������˫��
	}
	// ���3: �ڵ�x����˫�׵����ӣ�����˫����������
	if (node->parent->left == node && node->parent->right) {
		return leftmostChild(node->parent->right);  // �����˫�׵��������к�������ĵ�һ���ڵ�
	}
	return NULL;  // ���򣬺��Ϊ��
}

// ������
int main() {
	PostOrderThreadedBinaryTree tree = {NULL};  // ��ʼ������

	// ����ڵ�
	insert(&tree, 'A');
	insert(&tree, 'B');
	insert(&tree, 'C');
	insert(&tree, 'D');
	insert(&tree, 'E');
	insert(&tree, 'F');
//# The tree structure:
//#        A
//#      /   \
//#     B     C
//#    / \   /
//#   D   E F
	// ����B�ĺ��
	Node *b = tree.root->left;  // �ڵ�B
	Node *successorB = findPostorderSuccessor(b);  // ����B�ĺ��
	if (successorB) {
		printf("B�ĺ�̽ڵ���: %c\n", successorB->key);  // �����̽ڵ�
	} else {
		printf("Bû�к�̽ڵ�\n");  // ���Bû�к��
	}

	// ����E�ĺ��
	Node *e = tree.root->left->right;  // �ڵ�E
	Node *successorE = findPostorderSuccessor(e);  // ����E�ĺ��
	if (successorE) {
		printf("E�ĺ�̽ڵ���: %c\n", successorE->key);  // �����̽ڵ�
	} else {
		printf("Eû�к�̽ڵ�\n");  // ���Eû�к��
	}

	return 0;
}
