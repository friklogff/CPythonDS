#include <stdlib.h>
#include <stdio.h>

#define Initsize 10  // Ĭ�ϵ���󳤶�

typedef struct {
	int *data;    // ��malloc��������һƬ�����Ĵ洢�ռ�
	int length;   // ˳���ĵ�ǰ����
	int MaxSize;  // ˳�����������
} SeqList;

// ��ʼ��˳���
void InitList(SeqList &L) {
	L.data = (int *)malloc(Initsize * sizeof(int));
	L.length = 0;
	L.MaxSize = Initsize;
}

// ���Ӷ�̬����ĳ���
void Increasesize(SeqList &L, int len) {
	int *p = L.data;

	// ���·����ڴ�ռ�
	L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));

	// �����ݸ��Ƶ�������
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];
	}

	L.MaxSize = L.MaxSize + len;

	// �ͷ�ԭ�����ڴ�ռ�
	free(p);
}

int main() {
	SeqList L;  // ����һ��˳���

	InitList(L);  // ��ʼ��˳���

	// ��˳����������뼸��Ԫ��
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;

	Increasesize(L, 5);

	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
    free(L.data);  // �ͷ��ڴ�ռ�

	return 0;
}
