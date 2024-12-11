#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct TreeNode {
	char data; // 节点值
	struct TreeNode *leftChild, *rightChild; // 左右孩子指针
} TreeNode, *Tree;

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

// 全局变量：头结点和前驱结点
Tree head = NULL, pre = NULL;

/**
 * @brief 中序遍历，将二叉树的叶结点按从左到右的顺序连成一个单链表
 * @param t 二叉树根节点指针
 * @return 头结点
 */
Tree Inorder(Tree t) {
	if (t) { // 如果当前节点不为空
		Inorder(t->leftChild); // 递归处理左子树

		// 处理叶子节点
		if (t->leftChild == NULL && t->rightChild == NULL) {
			if (pre == NULL) { // 第一个叶子节点
				head = t; // 头结点赋值为当前节点
				pre = t; // 前驱结点更新为当前节点
			} else { // 非第一个叶子节点
				pre->rightChild = t; // 前驱结点的右指针指向当前节点
				pre = t; // 更新前驱结点
			}
		}

		Inorder(t->rightChild); // 递归处理右子树
	}

	return head; // 返回头结点
}

int main() {
	Tree t; // 定义树根节点指针
	BuildTree(&t); // 构建二叉树

	Tree leafList = Inorder(t); // 将二叉树的叶结点连成单链表
	while (leafList) { // 遍历并打印单链表
		printf("%c ", leafList->data);
		leafList = leafList->rightChild;
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

输出结果:
D E F G
*/
