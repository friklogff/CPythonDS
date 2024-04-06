#include <stdio.h>
#include <stdlib.h>

#define Initsize 10   // 默认的最大容量

typedef struct {
	int *data;    // 存储线性表元素的数组
	int length;   // 顺序表的当前长度
	int MaxSize;  // 顺序表的最大容量
} SeqList;

void InitList(SeqList &L) {
	L.data = (int *)malloc(Initsize * sizeof(int));
	L.length = 0;
	L.MaxSize = Initsize;
}

// 增加动态数组的长度
void IncreaseSize(SeqList &L, int len) {
	int *p = L.data;

	// 重新分配内存空间
	L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));

	// 将数据复制到新区域
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];
	}

	L.MaxSize = L.MaxSize + len;

	// 释放原来的内存空间
	free(p);
}

void DestroyList(SeqList &L) {
	free(L.data);
	L.length = 0;
	L.MaxSize = 0;
}

void ListInsert(SeqList &L, int i, int e) {
	if (i < 1 || i > L.length + 1) {
		printf("插入位置错误\n");
		return;
	}
	if (L.length >= L.MaxSize) {
		printf("线性表已满\n");
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
		printf("删除位置错误\n");
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
		printf("查找位置错误\n");
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
	SeqList L;  // 声明一个顺序表
	InitList(L);  // 初始化顺序表

	// 往顺序表中随便插入几个元素
	ListInsert(L, 1, 10);
	ListInsert(L, 2, 20);
	ListInsert(L, 3, 30);

	printf("线性表中第一个元素: %d\n", GetElem(L, 1));
	printf("线性表的长度: %d\n", Length(L));
	PrintList(L);

	ListDelete(L, 1);
	printf("线性表的长度: %d\n", Length(L));
	PrintList(L);

	DestroyList(L);
	return 0;
}
