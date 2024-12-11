#include <stdio.h>
#include <stdlib.h>

#define ElemType char

// ���������������Ľڵ�ṹ
typedef struct ThreadNode {
	ElemType data; // ����Ԫ��
	struct ThreadNode *lchild, *rchild, *parent; // ���Һ���ָ�룬ָ��˫�׵�ָ��
	int ltag; // ���������
	int rtag; // ���������
} ThreadNode, *ThreadTree;

// ���ʽڵ㣬��ӡ����
void visit(ThreadTree T) {
	printf("%c ", T->data);
}

// �����������ݹ麯�������Ҹ�
void PostThread(ThreadTree p, ThreadTree *pre) {
	if (p) {
		if (p->ltag != 1) // �����Ӳ�����������ݹ�������������
			PostThread(p->lchild, pre);
		if (p->rtag != 1) // ���Һ��Ӳ�����������ݹ�������������
			PostThread(p->rchild, pre);

		if (p->lchild == NULL) { // �������Ϊ�գ�����ǰ������
			p->lchild = *pre;
			p->ltag = 1;
		}
		if (*pre != NULL && (*pre)->rchild == NULL) { // ����ǰ���ڵ�ĺ������
			(*pre)->rchild = p;
			(*pre)->rtag = 1;
		}

		*pre = p; // ��ǵ�ǰ����Ϊ�ոշ��ʹ��Ľ��
	}
}

// ������������������
void CreatePostThread(ThreadTree *T) {
	ThreadTree pre = NULL;
	if (*T) { // �ǿն�������������
		PostThread(*T, &pre); // ������������
		if (pre->rchild == NULL) { // ������������һ�����
			pre->rtag = 1;
		} else {
			pre->rtag = 0;
		}
	}
}

// ����������������к��������µĵ�һ�����
ThreadNode *Firstnode(ThreadNode *p) {
	while (p->ltag == 0) { // �ߵ������½�㣬��һ����Ҷ�ӽ��
		p = p->lchild;
	}
	return p; // ���ظý��
}

// �����������������, ���p�ں��������µĺ��
ThreadNode *Nextnode(ThreadNode *p) {
	if (!p->parent) { // ���ڵ���˫��
		return NULL;
	}
	if (p->parent->rtag == 0 && p->parent->rchild != p) { // ��Ϊ��������������
		return Firstnode(p->parent->rchild);
	} else { // ���غ������
		return p->parent;
	}
}

// ���������������ĺ�������㷨
void Postorder(ThreadNode *T) {
	for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p)) {
		visit(p);
	}
}

// ����Ԥ��ֵ������������������ǰ�� AB#D##C##
void CreateTreeFromPreset(ThreadTree *T, ThreadTree parent, const char *preset, int *index) {
	char ch = preset[*index];
	(*index)++;

	if (ch == '#') { // �սڵ�
		*T = NULL;
	} else {
		*T = (ThreadTree)malloc(sizeof(ThreadNode)); // �����½ڵ�
		if (!*T) {
			printf("�ڴ����ʧ��\n");
			exit(1);
		}
		(*T)->data = ch; // ���ýڵ�����
		(*T)->ltag = (*T)->rtag = 0; // ��ʼ�������Ϊ0
		(*T)->parent = parent; // ����˫��
		CreateTreeFromPreset(&(*T)->lchild, *T, preset, index); // ����������
		CreateTreeFromPreset(&(*T)->rchild, *T, preset, index); // ����������
	}
}

// ����ݹ���������������
bool DestroyThreadTree(ThreadTree T) {
	if (T == NULL) {
		printf("�սڵ�\n");
		return false;
	}
	if (T->ltag != 1) { // ��������������
		DestroyThreadTree(T->lchild);
	}
	if (T->rtag != 1) { // ��������������
		DestroyThreadTree(T->rchild);
	}

	printf("����%c\n", T->data);
	free(T); // �ͷŽڵ�
	T = NULL; // ��ָ����ΪNULL
	return true;
}

// ����ݹ��������������
void PostOrder(ThreadTree T) {
	if (T) {
		if (T->ltag != 1)
			PostOrder(T->lchild);
		if (T->rtag != 1)
			PostOrder(T->rchild);
		visit(T);
	}
}

// ������
int main() {
	ThreadTree T = NULL;
	const char *preset = "AB#D##C##";
	int index = 0;

	printf("��Ԥ��ֵ AB#D##C## ����������\n");
	CreateTreeFromPreset(&T, NULL, preset, &index); // ʹ��Ԥ��ֵ����������

	CreatePostThread(&T); // ͨ�����������������������

	ThreadNode *p = Firstnode(T); // ���������µĵ�һ�����
	printf("\n��������ĵ�һ�����p: %c\n", p->data);
	ThreadNode *r = Nextnode(p); // ����������p�ĺ��
	if (r != NULL) {
		printf("p�ĺ��r: %c\n", r->data);
	} else {
		printf("pû�к�̽ڵ�\n");
	}

	printf("�����������������(�ݹ�PostOrder �� ����BinaryTree����): \n");
	PostOrder(T);
	printf("\n");

	printf("\n�����������������(�ǵݹ�Postorder �� Firstnode+Nextnode): \n");
	Postorder(T);

	printf("\n����Ҫ�ǵ�����Ŷ!\n");
	DestroyThreadTree(T);

	return 0;
}
