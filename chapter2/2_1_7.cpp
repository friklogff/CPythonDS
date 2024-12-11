//07．已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,a3,…, am)和(b1,b2,b3…,bn)。
//编写一个函数,将数组中两个顺序表的位置互换,即将(b1,b2,b3…,bn)放在(a1,a2,a3,…, am)的前面。
#include <stdio.h>

#define MaxSize 50 // 定义顺序表的最大长度

// 结构体定义，表示顺序表 (Sequence List)
typedef struct {
	int data[MaxSize]; // 用数组存放数据元素
	int length;        // 线性表的当前长度
} SqList; // 线性表的类型定义

/**
 * 翻转顺序表中从 left 到 right 的元素
 * @param list 顺序表
 * @param left 左边界
 * @param right 右边界
 */
void reverseList(SqList &list, int left, int right) {
	for (int i = left; i <= (right + left) / 2; i++) {
		int temp = list.data[i];
		list.data[i] = list.data[right + left - i];
		list.data[right + left - i] = temp;
	}
}

/**
 * 打印顺序表
 * @param list 顺序表
 */
void printSqList(const SqList &list) {
	for (int i = 0; i < list.length; i++)
		printf("%d ", list.data[i]);
	printf("\n");
}

/**
 * 根据翻转方法将顺序表进行特定的元素重排
 * @param list 顺序表
 * @param m 第一个区间的元素数量
 * @param n 第二个区间的元素数量
 */
void rearrangeList(SqList &list, int m, int n) {
	printf("第一次整体翻转：\n");
	reverseList(list, 0, m + n - 1);
	printSqList(list);

	printf("第二次翻转前 %d 个元素：\n", n);
	reverseList(list, 0, n - 1);
	printSqList(list);

	printf("第三次翻转剩余的 %d 个元素：\n", m);
	reverseList(list, n, m + n - 1);
	printSqList(list);
}

int main() {
	SqList list = {{1, 2, 3, 4, 5, 6, 7}, 7}; // 初始化顺序表
	rearrangeList(list, 3, 4); // 执行元素重排，m 为 3，n 为 4
	return 0; // 程序结束
}
