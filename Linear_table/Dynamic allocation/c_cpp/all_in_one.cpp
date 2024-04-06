#include <stdio.h>
#include <stdlib.h>

#define Initsize 10   // Ĭ�ϵ��������

typedef struct {
	int *data;    // �洢���Ա�Ԫ�ص�����
	int length;   // ˳���ĵ�ǰ����
	int MaxSize;  // ˳�����������
} SeqList;

void InitList(SeqList &L) {
	L.data = (int *)malloc(Initsize * sizeof(int));
	L.length = 0;
	L.MaxSize = Initsize;
}

// ���Ӷ�̬����ĳ���
void IncreaseSize(SeqList &L, int len) {
	int *p = L.data;

	// ���·����ڴ�ռ�
	L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));

	// �����ݸ��Ƶ�������
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];
	}

	L.MaxSize = L.MaxSize + len;

	// �ͷ�ԭ�����ڴ�ռ�
	free(p);
}

void DestroyList(SeqList &L) {
	free(L.data);
	L.length = 0;
	L.MaxSize = 0;
}

void ListInsert(SeqList &L, int i, int e) {
	if (i < 1 || i > L.length + 1) {
		printf("����λ�ô���\n");
		return;
	}
	if (L.length >= L.MaxSize) {
		printf("���Ա�����\n");
		return;
	}
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
}

void ListDelete(SeqList &L, int i) {
	if (i < 0 || i >= L.length) {
		printf("ɾ��λ�ô���\n");
		return;
	}
	for (int j = i; j < L.length - 1; j++) {
		L.data[j] = L.data[j + 1];
	}
	L.length--;
}

int LocateElem(SeqList L, int e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}

int GetElem(SeqList L, int i) {
	if (i < 1 || i > L.length) {
		printf("����λ�ô���\n");
		return -1;
	}
	return L.data[i - 1];
}

int Length(SeqList L) {
	return L.length;
}

void PrintList(SeqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}

int Empty(SeqList L) {
	return L.length == 0;
}

int main() {
	SeqList L;  // ����һ��˳���
	InitList(L);  // ��ʼ��˳���

	// ��˳����������뼸��Ԫ��
	ListInsert(L, 1, 10);
	ListInsert(L, 2, 20);
	ListInsert(L, 3, 30);

	printf("���Ա��е�һ��Ԫ��: %d\n", GetElem(L, 1));
	printf("���Ա�ĳ���: %d\n", Length(L));
	PrintList(L);

	ListDelete(L, 1);
	printf("���Ա�ĳ���: %d\n", Length(L));
	PrintList(L);

	DestroyList(L);
	return 0;
}
