#include <stdlib.h>

typedef struct {
	int *data; // 指示动态分配数组的指针
	int length; // 顺序表的当前长度
	int maxSize; // 顺序表的最大容量
} SeqList;

void InitList(SeqList &L, int initSize) {
	L.data = (int *)malloc(initSize * sizeof(int)); // 用malloc函数申请一片连续的存储空间
	L.length = 0; // 顺序表的当前长度为0
	L.maxSize = initSize; // 顺序表的最大容量为初始大小
}

void IncreaseSize(SeqList &L, int len) {
	int *p = L.data; // 保存原数据的指针

	// 分配新的更大的存储空间
	L.data = (int *)malloc((L.maxSize + len) * sizeof(int));

	// 将数据复制到新区域
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];
	}

	L.maxSize = L.maxSize + len; // 顺序表最大长度增加len
	free(p); // 释放原来的内存空间
}

int main() {
	SeqList L; // 声明一个顺序表

	int initSize = 10; // 默认的最大长度

	// 初始化顺序表
	InitList(L, initSize);

	// 增加动态数组的长度
	int len = 5;
	IncreaseSize(L, len);

	free(L.data); // 释放动态分配的内存空间

	return 0;
}
