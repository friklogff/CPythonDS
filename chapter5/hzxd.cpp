#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *fch, *nsib;
} *Tree;

int Leaves(Tree t) {
	if (t == NULL)
		return 0;

	if (t->fch == NULL)
		return 1 + Leaves(t->nsib);
	else
		return Leaves(t->fch) + Leaves(t->nsib);
}

int main() {
	// ������һ����
	Tree root1 = (Tree)malloc(sizeof(struct node));
	root1->data = 1;
	root1->fch = (Tree)malloc(sizeof(struct node));
	root1->fch->data = 2;
	root1->fch->fch = NULL;
	root1->fch->nsib = (Tree)malloc(sizeof(struct node));
	root1->fch->nsib->data = 3;
	root1->fch->nsib->fch = NULL;
	root1->fch->nsib->nsib = NULL;

	// �����ڶ�����
	Tree root2 = (Tree)malloc(sizeof(struct node));
	root2->data = 4;
	root2->fch = (Tree)malloc(sizeof(struct node));
	root2->fch->data = 5;
	root2->fch->fch = NULL;
	root2->fch->nsib = NULL;

	// ������������
	Tree root3 = (Tree)malloc(sizeof(struct node));
	root3->data = 6;
	root3->fch = NULL;

	int leafCount = Leaves(root1) + Leaves(root2) + Leaves(root3);
	printf("��Ҷ�����Ϊ��%d\n", leafCount);

	// �ͷ��ڴ�
	free(root1->fch->nsib);
	free(root1->fch);
	free(root1);

	free(root2->fch);
	free(root2);

	free(root3);

	return 0;
}
