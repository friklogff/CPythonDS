#include <stdio.h>

#define MaxSize 10 // 定义最大长度

typedef struct {
	int data[MaxSize]; // 用静态的数组存放数据元素
	int length; // 顺序表的当前长度
} SqList; // 顺序表的类型定义

// 初始化一个顺序表
void InitList(SqList &L) {
//    for (int i = 0; i < MaxSize; i++) {
//        L.data[i] = 0; // 将数据元素数组的元素设置为默认值
//    }
	L.length = 0; // 顺序表初始长度为0
}

int main() {
	SqList L; // 声明一个顺序表
	InitList(L); // 初始化顺序表L

	// 尝试违规打印整个data数组
	for (int i = 0; i < MaxSize; i++) {
		printf("data[%d] = %d\n", i, L.data[i]);
	}

	return 0;
}