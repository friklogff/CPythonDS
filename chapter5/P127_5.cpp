#include <stdio.h>

// ����������ṹ��
struct BinaryTree {
	int data[12]; // �����ʾ�������ڵ㣬-1 ��ʾ�սڵ�
};

/**
 * @brief ���������ڵ�Ĺ�������
 *
 * @param t �������ṹ��
 * @param i ��һ���ڵ�ı��
 * @param j �ڶ����ڵ�ı��
 * @return int �������ȵ�ֵ������������򷵻� -1
 */
int FindCommonAncestor(struct BinaryTree t, int i, int j) {
	// ��������ڵ㶼���ڣ���ʼ���ҹ�������
	if (t.data[i] != -1 && t.data[j] != -1) {
		// ���Ͻ������ڵ�����ڵ��ƶ���ֱ������Ϊֹ
		while (i != j) {
			if (i > j) {
				i /= 2; // ����һλ�ȼ��ڳ��� 2
			} else {
				j /= 2; // ����һλ�ȼ��ڳ��� 2
			}
		}
		return t.data[i]; // ���������ڵ��ֵ��Ϊ��������
	} else {
		return -1; // ��������ڵ㲻���ڣ��򷵻� -1
	}
}

int main() {
	// ����һ���������ṹ��ʵ��
	struct BinaryTree t = {{-1, 1, 2, 3, -1, 4, -1, 5, -1, -1, -6, -1}};
	// ���ҽڵ���Ϊ 7 �� 10 �Ĺ�������
	int ans = FindCommonAncestor(t, 7, 10);
	// ������������̨
	printf("%d\n", ans);
	return 0;
}
