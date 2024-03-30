#include <stdlib.h>

typedef struct {
	int *data; // ָʾ��̬���������ָ��
	int length; // ˳���ĵ�ǰ����
	int maxSize; // ˳�����������
} SeqList;

void InitList(SeqList &L, int initSize) {
	L.data = (int *)malloc(initSize * sizeof(int)); // ��malloc��������һƬ�����Ĵ洢�ռ�
	L.length = 0; // ˳���ĵ�ǰ����Ϊ0
	L.maxSize = initSize; // ˳�����������Ϊ��ʼ��С
}

void IncreaseSize(SeqList &L, int len) {
	int *p = L.data; // ����ԭ���ݵ�ָ��

	// �����µĸ���Ĵ洢�ռ�
	L.data = (int *)malloc((L.maxSize + len) * sizeof(int));

	// �����ݸ��Ƶ�������
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];
	}

	L.maxSize = L.maxSize + len; // ˳�����󳤶�����len
	free(p); // �ͷ�ԭ�����ڴ�ռ�
}

int main() {
	SeqList L; // ����һ��˳���

	int initSize = 10; // Ĭ�ϵ���󳤶�

	// ��ʼ��˳���
	InitList(L, initSize);

	// ���Ӷ�̬����ĳ���
	int len = 5;
	IncreaseSize(L, len);

	free(L.data); // �ͷŶ�̬������ڴ�ռ�

	return 0;
}
