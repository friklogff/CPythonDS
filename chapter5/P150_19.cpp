#include <stdio.h>
#include <stdlib.h>

// 结构体定义
typedef struct TreeNode {
	// 结点的值（权重）
	char weight;
	// 左右孩子指针
	struct TreeNode *leftChild, *rightChild;
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
		// 分配新节点的内存
		*t = (TreeNode *)malloc(sizeof(TreeNode));
		// 将读取到的字符赋值给结点权重
		(*t)->weight = ch;
		// 初始化左右孩子指针为空
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;

		// 递归构建左子树和右子树
		BuildTree(&((*t)->leftChild));
		BuildTree(&((*t)->rightChild));
	}
}

/**
 * @brief 计算带权路径长度之和（WPL）
 * @param t 二叉树根节点指针
 * @param depth 当前节点的深度
 * @return 带权路径长度之和
 */
int CalculateWPL(Tree t, int depth) {
	static int wpl = 0; // 静态变量，用于存储结果值并在函数末尾返回

	if (t != NULL) {
		// 若是叶子结点，累加其权重乘以深度的值
		if (t->leftChild == NULL && t->rightChild == NULL) {
			wpl += (depth * ((t->weight) - '0'));
		}

		// 若不是叶子结点，递归遍历左子树找叶子结点，并增加当前深度
		CalculateWPL(t->leftChild, depth + 1);
		// 递归遍历右子树找叶子结点，并增加当前深度
		CalculateWPL(t->rightChild, depth + 1);
	}

	return wpl;
}

// 主函数测试
int main() {
	Tree t;
	BuildTree(&t); // 构建二叉树
	printf("%d\n", CalculateWPL(t, 0)); // 输出带权路径长度之和
	return 0;
}

/*
示例输入:
124##5##36##7##

原始二叉树:
             1
          2    3
        4  5  6  7

带权路径长度之和 (WPL):
ans = (4*2 + 5*2 + 6*2 + 7*2) = 44
*/
