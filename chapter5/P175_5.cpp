#include <stdio.h>
#include <stdlib.h>

// 定义树节点结构体
typedef struct TreeNode {
	// 结点值
	char data;
	// 左孩子域和右兄弟域指针
	struct TreeNode *child, *rbro;
} TreeNode, *Tree;

/**
 * @brief 构建孩子兄弟表示法的树
 * @param t 指向树根节点的指针
 */
void BuildTree(Tree *t) {
	char ch;
	scanf("%c", &ch); // 从输入中读取一个字符

	if (ch == '#') { // 如果读取到 '#'，则该位置为空节点
		*t = NULL;
	} else {
		// 分配新节点的内存
		*t = (TreeNode *)malloc(sizeof(TreeNode));
		// 将读取到的字符赋值给节点数据
		(*t)->data = ch;
		// 初始化左右孩子域和右兄弟域为空
		(*t)->child = NULL;
		(*t)->rbro = NULL;

		// 递归构建左孩子和右兄弟子树
		BuildTree(&((*t)->child));
		BuildTree(&((*t)->rbro));
	}
}

/**
 * @brief 递归计算孩子兄弟表示法存储的树的深度
 * @param t 树根节点指针
 * @return 树的深度
 */
int CalculateDepth(Tree t) {
	if (t == NULL)
		return 0; // 空树返回0

	// 递归计算左孩子子树高度
	int lDepth = CalculateDepth(t->child);
	// 递归计算右兄弟子树高度
	int rDepth = CalculateDepth(t->rbro);

	// 返回当前子树的深度
	// 左子树深度+1（当前节点）与右兄弟子树深度之间取较大值
	return (lDepth + 1 > rDepth) ? (lDepth + 1) : rDepth;
}

// 主函数测试
int main() {
	Tree t;
	BuildTree(&t); // 构建孩子兄弟表示法的树
	printf("%d\n", CalculateDepth(t)); // 输出树的深度
	return 0;
}

/*
示例输入:
ABD#E##CF####

原始树:
                 A
             B
         D       C
           E   F
*/

