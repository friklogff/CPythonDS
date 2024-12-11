#include <stdio.h>

/**
 * @brief ������������ǰ������ת��Ϊ��������
 * @param pre ԭʼǰ������
 * @param l1 ǰ��������ʼλ��
 * @param h1 ǰ�����н���λ��
 * @param post Ŀ���������
 * @param l2 ����������ʼλ��
 * @param h2 �������н���λ��
 */
void PreToPost(char pre[], int l1, int h1, char post[], int l2, int h2) {
	if (l1 <= h1) { // �ݹ�������ȷ����Χ��Ч
		post[h2] = pre[l1]; // ���ڵ��ں��������е�λ��
		int half = (h1 - l1) / 2; // �������������ٽ�

		// �ݹ鴦��������
		PreToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);

		// �ݹ鴦��������
		PreToPost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1);
	}
}

int main() {
	char pre[8] = "ABDECFG"; // ǰ������
	char post[8]; // �������У��������
	PreToPost(pre, 0, 6, post, 0, 6); // ����ת������

	for (int i = 0; i < 7; i++) { // �����������
		printf("%c ", post[i]);
	}

	return 0;
}

/*
ԭʼ��������:
             A
          B    C
        D  E  F  G

ǰ���������: ABD##E##CF##G##
�����������: DEBFGCA
*/
