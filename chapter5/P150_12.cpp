#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct TreeNode {
	char data; // 节点数据
	struct TreeNode *leftChild, *rightChild; // 左右孩子指针
} TreeNode, *Tree;

// 定义栈结构体，用于存储树节点和标记
typedef struct {
	TreeNode *node; // 树节点指针
	int tag; // 标记，表示是否已访问右子树
} StackElement;

/**
 * @brief 构建二叉树
 * @param t 指向二叉树根节点的指针
 */
void BuildTree(Tree *t) {
	char ch;
	ch = getchar(); // 从输入中读取一个字符

	if (ch == '#') { // 如果读取到 '#'，则该位置为空节点
		*t = NULL;
	} else {
		*t = (TreeNode *)malloc(sizeof(TreeNode)); // 分配新节点的内存
		(*t)->data = ch; // 将读取到的字符赋值给节点数据
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;

		BuildTree(&((*t)->leftChild)); // 递归构建左子树
		BuildTree(&((*t)->rightChild)); // 递归构建右子树
	}
}

/**
 * @brief 查找给定二叉树中两个节点的最近公共祖先
 * @param t 二叉树根节点
 * @param p 第一个待查找的节点
 * @param q 第二个待查找的节点
 * @return 最近公共祖先节点的指针，如果不存在则返回NULL
 */
TreeNode *Ancestor(Tree t, TreeNode *p, TreeNode *q) {
	StackElement S1[10], S2[10]; // 用于存储路径的栈
	int top1 = 0, top2 = 0;
	TreeNode *current = t;

	while (current != NULL || top1 > 0) {
		while (current != NULL) { // 遍历左子树
			S1[++top1].node = current;
			S1[top1].tag = 0;
			current = current->leftChild;
		}

		while (top1 != 0 && S1[top1].tag == 1) { // 遍历右子树或回溯
			if (S1[top1].node == p) { // 找到第一个节点
				for (int i = 1; i <= top1; i++) {
					S2[i] = S1[i];
				}
				top2 = top1;
			}

			if (S1[top1].node == q) { // 找到第二个节点
				for (int i = top1; i > 0; i--) {
					for (int j = top2; j > 0; j--) {
						if (S2[j].node == S1[i].node)
							return S1[i].node; // 返回最近公共祖先
					}
				}
			}

			top1--;
		}

		if (top1 != 0) {
			S1[top1].tag = 1;
			current = S1[top1].node->rightChild; // 遍历右子树
		}
	}

	return NULL; // 没有找到公共祖先，返回NULL
}

int main() {
	Tree t; // 定义树根节点指针
	BuildTree(&t); // 构建二叉树
	TreeNode *p = t->rightChild->leftChild; // 指向节点F
	TreeNode *q = t->rightChild->rightChild; // 指向节点G

	TreeNode *ancestor = Ancestor(t, p, q); // 查找最近公共祖先
	if (ancestor != NULL) {
		printf("%c\n", ancestor->data); // 打印最近公共祖先节点的数据
	} else {
		printf("无公共祖先\n");
	}

	return 0;
}

/*
示例输入:
ABD##E##CF##G##

原始二叉树:
             A
          B    C
        D  E  F  G
              p  q
*/
