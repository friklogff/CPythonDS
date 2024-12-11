#include <stdio.h>

// 定义二叉树结构体
struct BinaryTree {
	int data[12]; // 数组表示二叉树节点，-1 表示空节点
};

/**
 * @brief 查找两个节点的公共祖先
 *
 * @param t 二叉树结构体
 * @param i 第一个节点的编号
 * @param j 第二个节点的编号
 * @return int 公共祖先的值，如果不存在则返回 -1
 */
int FindCommonAncestor(struct BinaryTree t, int i, int j) {
	// 如果两个节点都存在，则开始查找公共祖先
	if (t.data[i] != -1 && t.data[j] != -1) {
		// 不断将两个节点向根节点移动，直到相遇为止
		while (i != j) {
			if (i > j) {
				i /= 2; // 左移一位等价于除以 2
			} else {
				j /= 2; // 左移一位等价于除以 2
			}
		}
		return t.data[i]; // 返回相遇节点的值作为公共祖先
	} else {
		return -1; // 如果两个节点不存在，则返回 -1
	}
}

int main() {
	// 定义一个二叉树结构体实例
	struct BinaryTree t = {{-1, 1, 2, 3, -1, 4, -1, 5, -1, -1, -6, -1}};
	// 查找节点编号为 7 和 10 的公共祖先
	int ans = FindCommonAncestor(t, 7, 10);
	// 输出结果到控制台
	printf("%d\n", ans);
	return 0;
}
