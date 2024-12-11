#include <stdio.h>
#include <stdlib.h>

// 结构体定义
typedef struct TreeNode {
	// 结点值
	char data;
	// 左孩子域和右兄弟域指针
	struct TreeNode *child, *rbro;
} TreeNode, *Tree;

/**
 * @brief 构建孩子兄弟表示法的森林
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
 * @brief 递归计算孩子兄弟表示法存储的树中的叶子结点数
 * @param t 树根节点指针
 * @return 叶子结点数
 */
int CountLeaves(Tree t) {
	if (t == NULL)
		return 0; // 空节点返回0

	// 如果当前节点的左孩子为空，则是叶子节点
	if (t->child == NULL)
		return 1 + CountLeaves(t->rbro); // 结果加1并加上右兄弟子树的叶子结点数

	// 否则，结果为左孩子子树和右兄弟子树的叶子结点数之和
	return CountLeaves(t->child) + CountLeaves(t->rbro);
}

// 主函数测试
int main() {
	Tree t;
	BuildTree(&t); // 构建孩子兄弟表示法的森林
	printf("%d\n", CountLeaves(t)); // 输出叶子结点数
	return 0;
}

/*
示例输入:
ABD#E##C##FG###

原始树:
         A
     B        F
  D     C   G
   \
    E
*/

