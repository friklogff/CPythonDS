#include <stdio.h>

/**
 * @brief 将满二叉树的前序序列转换为后序序列
 * @param pre 原始前序序列
 * @param l1 前序序列起始位置
 * @param h1 前序序列结束位置
 * @param post 目标后序序列
 * @param l2 后序序列起始位置
 * @param h2 后序序列结束位置
 */
void PreToPost(char pre[], int l1, int h1, char post[], int l2, int h2) {
	if (l1 <= h1) { // 递归条件，确保范围有效
		post[h2] = pre[l1]; // 根节点在后序序列中的位置
		int half = (h1 - l1) / 2; // 计算左右子树临界

		// 递归处理左子树
		PreToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);

		// 递归处理右子树
		PreToPost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1);
	}
}

int main() {
	char pre[8] = "ABDECFG"; // 前序序列
	char post[8]; // 后序序列，将被填充
	PreToPost(pre, 0, 6, post, 0, 6); // 调用转换函数

	for (int i = 0; i < 7; i++) { // 输出后序序列
		printf("%c ", post[i]);
	}

	return 0;
}

/*
原始满二叉树:
             A
          B    C
        D  E  F  G

前序遍历序列: ABD##E##CF##G##
后序遍历序列: DEBFGCA
*/
