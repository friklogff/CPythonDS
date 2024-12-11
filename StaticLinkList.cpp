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
		throw "溢出";
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
		throw "空间不足";
	int pos = tail;
	tail = SArray[tail].next;
	return pos;
}

template<class T>
void StaticLinkList<T>::DeleteNode(int i) {
	if (i < 0 || i > MAXSIZE - 1 || front == -1)
		throw "释放空间错误";

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
		throw "获取位置错误";
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
		throw "插入空间不足";

	SArray[p].data = a;
	if (i < 0 || i > MAXSIZE - 1)
		throw "插入位置无效";

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
		throw "插入位置无效";

	SArray[p].next = SArray[k].next;
	SArray[k].next = p;
}

template<class T>
T StaticLinkList<T>::Delete(int i) {
	if (i < 0 || i >= MAXSIZE || front == -1)
		throw "删除位置无效";

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
		throw "删除位置无效";

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

		// 插入操作
		list.Insert(3, 10);
		cout << "插入10后的链表：";
		for (int i = 0; i < 6; i++) {
			cout << list.Get(i) << " ";
		}
		cout << endl;

		// 删除操作
		int deletedValue = list.Delete(2);
		cout << "删除第3个元素后的链表：";
		for (int i = 0; i < 5; i++) {
			cout << list.Get(i) << " ";
		}
		cout << endl;
		cout << "删除的元素是：" << deletedValue << endl;

		// 获取操作
		int value = list.Get(2);
		cout << "第3个元素是：" << value << endl;

		// 查找操作
		int index = list.Locate(4);
		if (index != -1) {
			cout << "值为4的元素在第" << index + 1 << "个位置" << endl;
		} else {
			cout << "值为4的元素不存在" << endl;
		}
	} catch (const char *msg) {
		cerr << "异常: " << msg << endl;
	}

	return 0;
}