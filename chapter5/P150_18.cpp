#include <stdio.h>
#include <stdlib.h>

// 线索二叉树结点结构体
typedef struct TreeNode {
	char data; // 结点的值
	struct TreeNode *leftChild, *rightChild; // 左右孩子指针
	int ltag, rtag; // 标志位，1 表示线索，0 表示孩子
} TreeNode, *Tree;

/**
 * @brief 构建二叉树
 * @param t 指向二叉树根节点的指针
 */
void BuildTree(Tree *t) {
	char ch;
	scanf("%c", &ch); // 从输入中读取一个字符

	if (ch == '#') { // 如果读取到 '#'，则该位置为空节点
		*t = NULL;
	} else {
		*t = (TreeNode *)malloc(sizeof(TreeNode)); // 分配新节点的内存
		(*t)->data = ch; // 将读取到的字符赋值给节点数据
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;
		(*t)->ltag = (*t)->rtag = 0; // 初始化标志位

		BuildTree(&((*t)->leftChild)); // 递归构建左子树
		BuildTree(&((*t)->rightChild)); // 递归构建右子树
	}
}

TreeNode *pre = NULL; // 全局变量，用于保存遍历过程中前一个处理的节点

/**
 * @brief 中序遍历并线索化二叉树
 * @param t 二叉树根节点的指针
 */
void InorderThreading(Tree *t) {
	if (*t) { // 递归的条件，确保当前节点不为空
		InorderThreading(&((*t)->leftChild)); // 向左延伸，找叶子结点

		if ((*t)->leftChild == NULL) { // 左孩子为空，建立线索
			(*t)->ltag = 1;
			(*t)->leftChild = pre;
		}

		if (pre != NULL && pre->rightChild == NULL) { // 前驱结点没有右孩子，建立线索
			pre->rtag = 1; // 前驱结点指向当前结点
			pre->rightChild = *t;
		}

		pre = *t; // 更新前驱结点
		InorderThreading(&((*t)->rightChild)); // 向右递归
	}
}

/**
 * @brief 在中序线索二叉树中查找指定结点在后序的前驱结点
 * @param t 二叉树根节点指针
 * @param p 指定结点指针
 * @return 后序前驱结点指针
 */
TreeNode *FindPostOrderPredecessor(Tree t, TreeNode *p) {
	TreeNode *q;

	if (p->rtag == 0) { // 若该结点有右孩子，其后序前驱即为其右孩子
		q = p->rightChild;
	} else if (p->ltag == 0) { // 若该结点无右孩子但有左孩子，其后序前驱即为其左孩子
		q = p->leftChild;
	} else if (p->leftChild == NULL) { // 若该结点为中序第一个结点，无后序前驱
		q = NULL;
	} else {
		while (p->ltag == 1 && p->leftChild != NULL) { // 沿线索找到祖先结点
			p = p->leftChild;
		}
		if (p->ltag == 0) { // 若找到祖先结点且有左孩子，其后序前驱即为其左孩子
			q = p->leftChild;
		} else {
			q = NULL; // 否则无后序前驱
		}
	}

	return q;
}

// 主函数 测试
int main() {
	Tree t;
	BuildTree(&t); // 构建二叉树
	InorderThreading(&t); // 中序遍历并线索化二叉树

	// 查找指定节点在后序遍历中的前驱结点，例如从根的右孩子开始找其在后序中的前驱结点
	TreeNode *postPredecessor = FindPostOrderPredecessor(t, t->rightChild);
	if (postPredecessor != NULL) {
		printf("%c\n", postPredecessor->data); // 输出找到的前驱节点的数据
	} else {
		printf("NULL\n"); // 如果没有找到前驱节点，输出NULL
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

ABD##E##CF##G##
*/
