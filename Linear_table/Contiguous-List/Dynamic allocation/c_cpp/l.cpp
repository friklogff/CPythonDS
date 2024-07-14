#include <iostream>

#define Initsize 10  // Ĭ�ϵ���󳤶�

struct SeqList {
	int *data;    // ��new����������һƬ�����Ĵ洢�ռ�
	int length;   // ˳���ĵ�ǰ����
	int MaxSize;  // ˳�����������
};

// ��ʼ��˳���
void InitList(SeqList &L) {
	L.data = new int[Initsize];
	L.length = 0;
	L.MaxSize = Initsize;
}

// ���Ӷ�̬����ĳ���
void Increasesize(SeqList &L, int len) {
	int *p = L.data;

	// ���·����ڴ�ռ�
	L.data = new int[L.MaxSize + len];

	// �����ݸ��Ƶ�������
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];
	}

	L.MaxSize = L.MaxSize + len;

	// �ͷ�ԭ�����ڴ�ռ�
	delete[] p;
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
		std::cout << L.data[i] << " ";
	}
	std::cout << std::endl;

    delete[] L.data;


	return 0;
}
