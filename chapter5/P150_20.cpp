#include <stdio.h>
#include <stdlib.h>

// 定义树节点结构体
typedef struct TreeNode {
	char data; // 结点值
	struct TreeNode *leftChild, *rightChild; // 左右孩子的指针
} TreeNode, *Tree;

// 构建表达式树
/**
 * brief   构建表达式树
 * param   t   树的根节点指针
 */
void buildTree(Tree *t) {
	char ch;
	// 读取一个字符数据
	scanf(" %c", &ch);
	// 判断是否为结束标志
	if (ch == '#') {
		*t = NULL; // 如果是结束标志，则当前树为空
	} else {
		// 分配内存空间给当前节点
		*t = (TreeNode *)malloc(sizeof(TreeNode));
		// 将读取的字符赋值给节点的数据域
		(*t)->data = ch;
		// 初始化左右孩子指针为空
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;
		// 递归构建左子树
		buildTree(&((*t)->leftChild));
		// 递归构建右子树
		buildTree(&((*t)->rightChild));
	}
}

// 将表达式树转化成中缀表达式
/**
 * brief   将表达式树转化成中缀表达式输出
 * param   t     树的根节点
 * param   depth 当前结点深度
 */
void treeToInfixExpr(Tree t, int depth) {
	// 如果树为空，直接返回
	if (t == NULL)
		return;

	// 如果是叶子节点，直接输出数据
	else if (t->leftChild == NULL && t->rightChild == NULL) {
		printf("%c", t->data);
	} else {
		// 如果当前深度大于1，输出左括号
		if (depth > 1)
			printf("(");

		// 递归处理左子树，深度加1
		treeToInfixExpr(t->leftChild, depth + 1);
		// 输出当前节点数据
		printf("%c", t->data);
		// 递归处理右子树，深度加1
		treeToInfixExpr(t->rightChild, depth + 1);

		// 如果当前深度大于1，输出右括号
		if (depth > 1)
			printf(")");
	}
}

// 主函数：测试表达式树的构建和中缀表达式输出
int main() {
	Tree t; // 定义树的根节点
	// 构建表达式树
	buildTree(&t);
	// 将表达式树转化成中缀表达式并输出
	treeToInfixExpr(t, 1);
	return 0;
}

/*

        *
    +       *
  a   b   c   -
  *+a##b##*c##-#d##

            +
        *      -
    a    b         -
                c     d

  +*a##b##-#-c##d##

   +
 a   b
  +a##b##

*/
