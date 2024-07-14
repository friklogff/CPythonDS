//16.设有一个长度n(n为偶数)的不带头结点的单链表，且结点值都大于0，设计算法求这
//个单链表的最大孪生和。孪生和定义为一个结点值与其孪生结点值之和，对于第i个结点（从0开始)，其孪生结点为第n一i-1个结点。要求:
//1)给出算法的基本设计思想。
//2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。3）说明你的算法的时间复杂度和空间复杂度。
#include <stdio.h>
#include <stdlib.h>

// 定义链表元素类型
typedef int ElemType;

// 链表节点结构体定义
typedef struct LNode {
	ElemType data;       // 数据域
	struct LNode *next;  // 指针域，指向下一个节点
} LNode, *LinkList;

/**
 * @brief 构建单向链表
 * @param L 链表头节点指针
 * @param arr 数组
 * @param n 数组长度
 */
void BuildList(LinkList *L, int arr[], int n) {
	*L = (LinkList)malloc(sizeof(LNode)); // 分配头节点空间
	LNode *newNode, *lastNode = *L; // 使用 lastNode 指向链表的最后一个节点
	for (int i = 0; i < n; i++) {
		newNode = (LNode *)malloc(sizeof(LNode)); // 为新节点分配空间
		newNode->data = arr[i]; // 将数据赋值给新节点
		lastNode->next = newNode; // 将新节点连接到链表末尾
		lastNode = lastNode->next; // 移动到新的链表末尾
	}
	lastNode->next = NULL; // 最后一个节点的 next 设为 NULL
}

/**
 * @brief 显示链表元素
 * @param L 链表头节点
 */
void DisplayList(LinkList L) {
	LNode *currentNode = L->next; // 跳过头节点
	while (currentNode) {
		printf("%d ", currentNode->data); // 打印当前节点数据
		currentNode = currentNode->next; // 移动到下一个节点
	}
	printf("\n");
}

/**
 * @brief 计算链表的最大孪生和
 * @param L 链表头节点
 * @return 最大孪生和
 */
int CalculateMaxTwinSum(LinkList L) {
	if (L == NULL || L->next == NULL)
		return 0;

	LNode *fast = L->next, *slow = L;
	// 找到链表中间节点
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	// 反转链表后半部分
	LNode *newHead = NULL, *p = slow->next, *tmp;
	while (p != NULL) {
		tmp = p->next;
		p->next = newHead;
		newHead = p;
		p = tmp;
	}

	// 计算孪生和的最大值
	int maxTwinSum = 0;
	LNode *front = L->next, *back = newHead;
	while (back != NULL) {
		int twinSum = front->data + back->data;
		if (twinSum > maxTwinSum) {
			maxTwinSum = twinSum;
		}
		front = front->next;
		back = back->next;
	}

	// 恢复链表的后半部分顺序（可选）
	p = newHead;
	newHead = NULL;
	while (p != NULL) {
		tmp = p->next;
		p->next = newHead;
		newHead = p;
		p = tmp;
	}
	slow->next = newHead;

	return maxTwinSum;
}

int main() {
	LinkList L;
	// 示例数组
	int arr[] = {2, 6, 1, 4, 3, 8, 5, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	BuildList(&L, arr, n); // 构建链表
	printf("链表内容：\n");
	DisplayList(L); // 显示链表
	int maxTwinSum = CalculateMaxTwinSum(L); // 计算最大孪生和
	printf("最大孪生和为: %d\n", maxTwinSum);
	return 0;
}
