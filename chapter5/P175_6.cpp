#include <stdio.h>
#include <stdlib.h>

// 结构体定义
typedef struct TreeNode {
	// 结点值
	char data;
	// 左孩子指针和右兄弟指针
	struct TreeNode *child, *rbro;
} TreeNode, *Tree;

/**
 * @brief 构造孩子-兄弟链表表示的树
 * @param t 指向树根节点的指针
 * @param elements 层次遍历序列数组
 * @param degrees 每个结点的度数组
 * @param n 数组长度
 */
void CreateTree(Tree *t, char elements[], int degrees[], int n) {
	// 动态申请结点数组
	Tree *nodes = (TreeNode **)malloc(n * sizeof(TreeNode *));

	for (int i = 0; i < n; i++) {
		// 给每个结点动态申请内存
		nodes[i] = (TreeNode *)malloc(sizeof(TreeNode));
		// 赋值给结点并初始化左右指针为空
		nodes[i]->data = elements[i];
		nodes[i]->child = nodes[i]->rbro = NULL;
	}

	// 孩子结点序号
	int k = 0;

	// 按照给定的结点顺序访问结点
	for (int i = 0; i < n; i++) {
		// 获取该结点的度
		int d = degrees[i];

		// 如果有度，说明有孩子结点
		if (d > 0) {
			// 孩子序号递增
			k++;
			// 将第一个孩子作为自己的左孩子结点
			nodes[i]->child = nodes[k];

			// 剩余的孩子，每个结点依次为前一个结点的兄弟结点
			for (int j = 2; j <= d; j++) {
				// 孩子序号递增
				k++;
				// 前一个结点的右兄弟指针指向当前孩子结点
				nodes[k - 1]->rbro = nodes[k];
			}
		}
	}

	*t = nodes[0]; // 根节点指向第一个结点
	free(nodes); // 释放动态申请的内存
}

/**
 * @brief 输出孩子-兄弟链表表示的树的先序遍历结果
 * @param t 树根节点指针
 */
void PrintPreOrder(Tree t) {
	if (t != NULL) {
		printf("%c ", t->data);
		PrintPreOrder(t->child);
		PrintPreOrder(t->rbro);
	}
}

// 主函数测试
int main() {
	// 树根节点指针
	Tree t;
	// 层次遍历序列
	char elements[8] = "ABCDEFG";
	// 每个结点的度数组
	int degrees[8] = {3, 2, 1, 0, 0, 0, 0};

	// 构造孩子-兄弟链表表示的树
	CreateTree(&t, elements, degrees, 7);

	// 输出先序遍历结果进行验证
	PrintPreOrder(t);
	return 0;
}

/*
示例输入:
elements: ABCDEFG
degrees: 3210000

原始树:
                   A
             B     C     D
           E   F   G

构造的孩子-兄弟链表表示的树:
                   A
                B
            E      C
               F  G  D

先序遍历输出:
A B E C F G D
*/

