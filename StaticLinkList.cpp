#include <iostream>
using namespace std;

const int MAXSIZE = 100;

template<class T>
struct StaticNode {
	T data;
	int next;
};

template<class T>
class StaticLinkList {
	public:
		StaticLinkList();
		StaticLinkList(T a[], int n);
		void Insert(int i, T a);
		T Delete(int i);
		int Get(int i);
		int Locate(T x);
		int NewNode();
		void DeleteNode(int i);

	private:
		int front;
		int tail;
		StaticNode<T> SArray[MAXSIZE];
};

template<class T>
StaticLinkList<T>::StaticLinkList() {
	for (int i = 0; i < MAXSIZE - 1; i++) {
		SArray[i].next = i + 1;
	}
	SArray[MAXSIZE - 1].next = -1;
	front = -1;
	tail = 0;
}

template<class T>
StaticLinkList<T>::StaticLinkList(T a[], int n) {
	if (n > MAXSIZE)
		throw "���";
	for (int i = 0; i < MAXSIZE - 1; i++)
		SArray[i].next = i + 1;
	SArray[MAXSIZE - 1].next = -1;
	for (int i = 0; i < n; i++)
		SArray[i].data = a[i];
	front = 0;
	tail = SArray[n - 1].next;
	SArray[n - 1].next = -1;
}

template<class T>
int StaticLinkList<T>::NewNode() {
	if (tail == -1)
		throw "�ռ䲻��";
	int pos = tail;
	tail = SArray[tail].next;
	return pos;
}

template<class T>
void StaticLinkList<T>::DeleteNode(int i) {
	if (i < 0 || i > MAXSIZE - 1 || front == -1)
		throw "�ͷſռ����";

	int p = SArray[i].next;
	if (p != -1)
		SArray[i] = SArray[p];
	else {
		p = i;
		int k = front;
		int prek = k;
		while (SArray[k].next != -1) {
			prek = k;
			k = SArray[k].next;
		}
		SArray[prek].next = -1;
	}
	SArray[p].next = tail;
	tail = p;
	if (front == i)
		front = SArray[i].next;
}

template<class T>

int StaticLinkList<T>::Get(int i) {
	if (i < 0 || i >= MAXSIZE - 1 || front == -1)
		throw "��ȡλ�ô���";
	return SArray[i].data;
}

template<class T>
int StaticLinkList<T>::Locate(T x) {
	int j = front;
	while (j != -1 && SArray[j].data != x)
		j = SArray[j].next;
	return j;
}
template<class T>

void StaticLinkList<T>::Insert(int i, T a) {
	int p = NewNode();
	if (p == -1)
		throw "����ռ䲻��";

	SArray[p].data = a;
	if (i < 0 || i > MAXSIZE - 1)
		throw "����λ����Ч";

	if (front == -1 || i == 0) {
		SArray[p].next = front;
		front = i;
		return;
	}

	int k = front;
	for (int j = 0; j < i - 1 && k != -1; j++) {
		k = SArray[k].next;
	}

	if (k == -1)
		throw "����λ����Ч";

	SArray[p].next = SArray[k].next;
	SArray[k].next = p;
}

template<class T>
T StaticLinkList<T>::Delete(int i) {
	if (i < 0 || i >= MAXSIZE || front == -1)
		throw "ɾ��λ����Ч";

	if (i == 0) {
		int delPos = front;
		T deletedData = SArray[delPos].data;
		front = SArray[front].next;
		SArray[delPos].next = tail;
		tail = delPos;
		return deletedData;
	}

	int k = front;
	for (int j = 0; j < i - 1 && k != -1; j++) {
		k = SArray[k].next;
	}

	if (k == -1 || SArray[k].next == -1)
		throw "ɾ��λ����Ч";

	int delPos = SArray[k].next;
	T deletedData = SArray[delPos].data;
	SArray[k].next = SArray[delPos].next;
	SArray[delPos].next = tail;
	tail = delPos;

	return deletedData;
}

int main() {
	try {
		int arr[] = {1, 2, 3, 4, 5};
		StaticLinkList<int> list(arr, 5);

		// �������
		list.Insert(3, 10);
		cout << "����10�������";
		for (int i = 0; i < 6; i++) {
			cout << list.Get(i) << " ";
		}
		cout << endl;

		// ɾ������
		int deletedValue = list.Delete(2);
		cout << "ɾ����3��Ԫ�غ������";
		for (int i = 0; i < 5; i++) {
			cout << list.Get(i) << " ";
		}
		cout << endl;
		cout << "ɾ����Ԫ���ǣ�" << deletedValue << endl;

		// ��ȡ����
		int value = list.Get(2);
		cout << "��3��Ԫ���ǣ�" << value << endl;

		// ���Ҳ���
		int index = list.Locate(4);
		if (index != -1) {
			cout << "ֵΪ4��Ԫ���ڵ�" << index + 1 << "��λ��" << endl;
		} else {
			cout << "ֵΪ4��Ԫ�ز�����" << endl;
		}
	} catch (const char *msg) {
		cerr << "�쳣: " << msg << endl;
	}

	return 0;
}