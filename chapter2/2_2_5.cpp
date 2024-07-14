//05.给定两个单链表，试分析找出两个链表的公共结点的思想（不用写代码)
//### 思想分析
//1. **长度对齐**：
//   - 首先计算两个链表的长度，分别设为 `lenA` 和 `lenB`。
//   - 如果两个链表长度不等，需要先对齐它们的起点，使得后续的比较仅发生在长度较短的公共部分上。
//   - 具体方法是，较长的链表先向前移动 `|lenA ? lenB|` 个节点，使得两链表的剩余长度相等。
//
//2. **双指针遍历**：
//   - 分别定义两个指针 `pA` 和 `pB`，分别指向两个链表的当前节点。
//   - 同时遍历两个链表，比较两个指针指向节点的引用（或值），如果相同，则找到了第一个公共节点。
//   - 如果 `pA` 和 `pB` 不同，则两个指针同步向前移动一个节点，继续比较。
//
//3. **结束条件**：
//   - 如果遍历到某一个指针到达链表末尾（即指向 NULL），而另外一个指针仍未找到相同的节点，则可以确认两个链表没有公共节点。
//
//### 具体步骤
//1. **计算链表长度**：
//   - 遍历链表 A 和链表 B，分别计算它们的长度 `lenA` 和 `lenB`。
//
//2. **对齐链表**：
//   - 如果 `lenA` 与 `lenB` 相等，直接进入下一步。
//   - 如果 `lenA` > `lenB`，则让链表 A 向前移动 `lenA - lenB` 个节点。
//   - 如果 `lenA` < `lenB`，则让链表 B 向前移动 `lenB - lenA` 个节点。
//
//3. **同步遍历比较**：
//   - 同时遍历对齐后的链表 A 和链表 B，比较当前节点是否相同（引用相同）。
//   - 若相同，则找到第一个公共节点。
//   - 若不同，则指针同时向前移动，继续比较。
//
//4. **结束条件**：
//   - 遍历到任意一个链表的末尾（指针为 NULL），则没有公共节点。
//
//### 示例代码结构（非完整代码，仅为示意结构）
//```c
#include <stdio.h>
#include <stdlib.h>

// 定义链表元素类型
typedef int ElemType;

// 链表节点结构体定义
typedef struct LNode {
	ElemType data;         // 数据域
	struct LNode *next;    // 指针域，指向下一个节点
} LNode, *LinkList;

/**
 * 创建新的链表节点
 * @param data 节点数据
 * @return 新创建的节点
 */
LNode *createNode(ElemType data) {
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

/**
 * 计算链表长度
 * @param head 链表头节点
 * @return 链表长度
 */
int getListLength(LinkList head) {
	int length = 0;
	LNode *current = head;
	while (current != NULL) {
		length++;
		current = current->next;
	}
	return length;
}

/**
 * 找出两个链表的第一个公共节点
 * @param headA 链表A的头节点
 * @param headB 链表B的头节点
 * @return 第一个公共节点
 */
LNode *findIntersection(LinkList headA, LinkList headB) {
	// 计算两个链表的长度
	int lenA = getListLength(headA);
	int lenB = getListLength(headB);

	// 对齐两个链表，使它们的剩余长度相等
	LNode *longer = lenA > lenB ? headA : headB;
	LNode *shorter = lenA > lenB ? headB : headA;
	int diff = abs(lenA - lenB);

	while (diff--) {
		longer = longer->next;
	}

	// 同时遍历对齐后的链表，寻找第一个公共节点
	while (longer != NULL && shorter != NULL) {
		if (longer == shorter) {
			return longer; // 找到第一个公共节点
		}
		longer = longer->next;
		shorter = shorter->next;
	}

	return NULL; // 没有公共节点
}

/**
 * 打印链表
 * @param head 链表头节点
 */
void printList(LinkList head) {
	LNode *current = head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

int main() {
	// 创建链表A
	LNode *headA = createNode(1);
	headA->next = createNode(2);
	headA->next->next = createNode(3);
	headA->next->next->next = createNode(4);
	headA->next->next->next->next = createNode(5);

	// 创建链表B
	LNode *headB = createNode(6);
	headB->next = headA->next->next->next; // 链表B的第2个节点指向链表A的第4个节点

	// 打印链表A
	printf("链表A: ");
	printList(headA);

	// 打印链表B
	printf("链表B: ");
	printList(headB);

	// 查找两个链表的第一个公共节点
	LNode *intersection = findIntersection(headA, headB);
	if (intersection != NULL) {
		printf("第一个公共节点是: %d\n", intersection->data);
	} else {
		printf("没有找到公共节点。\n");
	}

	return 0;
}

//```
//### 总结
//这个思想的核心是在链表长度对齐后，通过同步遍历两个链表来找到第一个公共节点。这种方法的时间复杂度为 O(m + n)，适用于大部分寻找链表交点的问题。通过同步移动指针，确保了没有遗漏任何可能的公共节点。