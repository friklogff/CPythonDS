#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct Node {
	char key;  // 结点的值
	struct Node *left;  // 左孩子指针
	struct Node *right;  // 右孩子指针
	struct Node *parent;  // 双亲指针
} Node;

// 定义树结构
typedef struct {
	Node *root;  // 根节点的指针
} PostOrderThreadedBinaryTree;

// 创建新节点
Node *createNode(char key) {
	// 为新节点分配内存
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->key = key;  // 设置节点的值
	newNode->left = NULL;  // 初始化左孩子为NULL
	newNode->right = NULL;  // 初始化右孩子为NULL
	newNode->parent = NULL;  // 初始化双亲为NULL
	return newNode;  // 返回新创建的节点
}

// 插入节点到树中
void insert(PostOrderThreadedBinaryTree *tree, char key) {
	// 创建新节点
	Node *newNode = createNode(key);
	if (!tree->root) {  // 如果树是空的
		tree->root = newNode;  // 新节点为根节点
	} else {
		Node *queue[100];  // 创建队列用于层次遍历
		int front = 0, rear = 0;  // 初始化队列前后指针
		queue[rear++] = tree->root;  // 将根节点入队

		while (front < rear) {  // 队列不为空
			Node *current = queue[front++];  // 出队一个节点
			if (!current->left) {  // 如果当前节点没有左孩子
				current->left = newNode;  // 将新节点插入为左孩子
				newNode->parent = current;  // 设置新节点的双亲指针
				break;  // 结束插入
			} else {
				queue[rear++] = current->left;  // 将左孩子入队
			}
			if (!current->right) {  // 如果当前节点没有右孩子
				current->right = newNode;  // 将新节点插入为右孩子
				newNode->parent = current;  // 设置新节点的双亲指针
				break;  // 结束插入
			} else {
				queue[rear++] = current->right;  // 将右孩子入队
			}
		}
	}
}

// 寻找后序遍历中的第一个节点（左子树的最左下节点）
Node *leftmostChild(Node *node) {
	Node *current = node;  // 从当前节点开始
	while (current->left) {  // 遍历左子树
		current = current->left;  // 移动到左孩子
	}
	return current;  // 返回最左下的节点
}

// 寻找节点的后继
Node *findPostorderSuccessor(Node *node) {
	// 情况1: 节点x是根节点
	if (!node->parent) {
		return NULL;
	}
	// 情况2: 节点x是其双亲的右孩子，或是其双亲的左孩子且其双亲没有右子树
	if (node->parent->right == node || (node->parent->left == node && !node->parent->right)) {
		return node->parent;  // 后继是其双亲
	}
	// 情况3: 节点x是其双亲的左孩子，且其双亲有右子树
	if (node->parent->left == node && node->parent->right) {
		return leftmostChild(node->parent->right);  // 后继是双亲的右子树中后序遍历的第一个节点
	}
	return NULL;  // 否则，后继为空
}

// 主函数
int main() {
	PostOrderThreadedBinaryTree tree = {NULL};  // 初始化空树

	// 插入节点
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
	// 查找B的后继
	Node *b = tree.root->left;  // 节点B
	Node *successorB = findPostorderSuccessor(b);  // 查找B的后继
	if (successorB) {
		printf("B的后继节点是: %c\n", successorB->key);  // 输出后继节点
	} else {
		printf("B没有后继节点\n");  // 输出B没有后继
	}

	// 查找E的后继
	Node *e = tree.root->left->right;  // 节点E
	Node *successorE = findPostorderSuccessor(e);  // 查找E的后继
	if (successorE) {
		printf("E的后继节点是: %c\n", successorE->key);  // 输出后继节点
	} else {
		printf("E没有后继节点\n");  // 输出E没有后继
	}

	return 0;
}
