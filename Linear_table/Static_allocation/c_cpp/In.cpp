#include <stdlib.h>
#include <stdio.h>

#define Initsize 10  // 默认的最大长度

typedef struct {
	int *data;    // 用malloc函数申请一片连续的存储空间
	int length;   // 顺序表的当前长度
	int MaxSize;  // 顺序表的最大容量
} SeqList;

// 初始化顺序表
void InitList(SeqList &L) {
	L.data = (int *)malloc(Initsize * sizeof(int));
	L.length = 0;
	L.MaxSize = Initsize;
}

// 增加动态数组的长度
void Increasesize(SeqList &L, int len) {
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

int main() {
	SeqList L;  // 声明一个顺序表

	InitList(L);  // 初始化顺序表

	// 往顺序表中随便插入几个元素
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;

	Increasesize(L, 5);

	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
    free(L.data);  // 释放内存空间

	return 0;
}
