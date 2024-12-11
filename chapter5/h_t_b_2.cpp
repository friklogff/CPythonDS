#include <stdio.h>
#include <stdlib.h>

#define ElemType char

// 定义线索二叉树的节点结构
typedef struct ThreadNode {
	ElemType data; // 数据元素
	struct ThreadNode *lchild, *rchild, *parent; // 左右孩子指针，指向双亲的指针
	int ltag; // 左线索标记
	int rtag; // 右线索标记
} ThreadNode, *ThreadTree;

// 访问节点，打印数据
void visit(ThreadTree T) {
	printf("%c ", T->data);
}

// 后序线索化递归函数，左右根
void PostThread(ThreadTree p, ThreadTree *pre) {
	if (p) {
		if (p->ltag != 1) // 若左孩子不是线索，则递归线索化左子树
			PostThread(p->lchild, pre);
		if (p->rtag != 1) // 若右孩子不是线索，则递归线索化右子树
			PostThread(p->rchild, pre);

		if (p->lchild == NULL) { // 如果左孩子为空，建立前驱线索
			p->lchild = *pre;
			p->ltag = 1;
		}
		if (*pre != NULL && (*pre)->rchild == NULL) { // 建立前驱节点的后继线索
			(*pre)->rchild = p;
			(*pre)->rtag = 1;
		}

		*pre = p; // 标记当前结点成为刚刚访问过的结点
	}
}

// 创建后序线索二叉树
void CreatePostThread(ThreadTree *T) {
	ThreadTree pre = NULL;
	if (*T) { // 非空二叉树，线索化
		PostThread(*T, &pre); // 线索化二叉树
		if (pre->rchild == NULL) { // 处理遍历的最后一个结点
			pre->rtag = 1;
		} else {
			pre->rtag = 0;
		}
	}
}

// 求后序线索二叉树中后序序列下的第一个结点
ThreadNode *Firstnode(ThreadNode *p) {
	while (p->ltag == 0) { // 走到最左下结点，不一定是叶子结点
		p = p->lchild;
	}
	return p; // 返回该结点
}

// 求后序线索二叉树中, 结点p在后序序列下的后继
ThreadNode *Nextnode(ThreadNode *p) {
	if (!p->parent) { // 根节点无双亲
		return NULL;
	}
	if (p->parent->rtag == 0 && p->parent->rchild != p) { // 若为左孩子且有右子树
		return Firstnode(p->parent->rchild);
	} else { // 返回后继线索
		return p->parent;
	}
}

// 后序线索二叉树的后序遍历算法
void Postorder(ThreadNode *T) {
	for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p)) {
		visit(p);
	}
}

// 根据预设值创建线索二叉树，按前序 AB#D##C##
void CreateTreeFromPreset(ThreadTree *T, ThreadTree parent, const char *preset, int *index) {
	char ch = preset[*index];
	(*index)++;

	if (ch == '#') { // 空节点
		*T = NULL;
	} else {
		*T = (ThreadTree)malloc(sizeof(ThreadNode)); // 分配新节点
		if (!*T) {
			printf("内存分配失败\n");
			exit(1);
		}
		(*T)->data = ch; // 设置节点数据
		(*T)->ltag = (*T)->rtag = 0; // 初始线索标记为0
		(*T)->parent = parent; // 设置双亲
		CreateTreeFromPreset(&(*T)->lchild, *T, preset, index); // 创建左子树
		CreateTreeFromPreset(&(*T)->rchild, *T, preset, index); // 创建右子树
	}
}

// 后序递归销毁线索二叉树
bool DestroyThreadTree(ThreadTree T) {
	if (T == NULL) {
		printf("空节点\n");
		return false;
	}
	if (T->ltag != 1) { // 左子树不是线索
		DestroyThreadTree(T->lchild);
	}
	if (T->rtag != 1) { // 右子树不是线索
		DestroyThreadTree(T->rchild);
	}

	printf("销毁%c\n", T->data);
	free(T); // 释放节点
	T = NULL; // 将指针设为NULL
	return true;
}

// 后序递归遍历线索二叉树
void PostOrder(ThreadTree T) {
	if (T) {
		if (T->ltag != 1)
			PostOrder(T->lchild);
		if (T->rtag != 1)
			PostOrder(T->rchild);
		visit(T);
	}
}

// 主函数
int main() {
	ThreadTree T = NULL;
	const char *preset = "AB#D##C##";
	int index = 0;

	printf("按预设值 AB#D##C## 创建二叉树\n");
	CreateTreeFromPreset(&T, NULL, preset, &index); // 使用预设值建立二叉树

	CreatePostThread(&T); // 通过后序遍历建立线索二叉树

	ThreadNode *p = Firstnode(T); // 求后序遍历下的第一个结点
	printf("\n后序遍历的第一个结点p: %c\n", p->data);
	ThreadNode *r = Nextnode(p); // 求后序遍历下p的后继
	if (r != NULL) {
		printf("p的后继r: %c\n", r->data);
	} else {
		printf("p没有后继节点\n");
	}

	printf("后序遍历线索二叉树(递归PostOrder ≈ 正常BinaryTree遍历): \n");
	PostOrder(T);
	printf("\n");

	printf("\n后序遍历线索二叉树(非递归Postorder ≈ Firstnode+Nextnode): \n");
	Postorder(T);

	printf("\n用完要记得销毁哦!\n");
	DestroyThreadTree(T);

	return 0;
}
