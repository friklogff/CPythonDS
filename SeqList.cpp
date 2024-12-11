#include <iostream>
using namespace std;
template<class T, int N>

class SeqList {
	public:
		SeqList() {
			length = 0;
		}
		SeqList(T a[], int n);
		int GetLength() {
			return length;
		}
		void PrintList();
		void Insert(int i, T x);
		T Delet(int i);
		T Get(int i);
		int Locate(T x);
	private:
		T data[N];
		int length;
};
//构造函数
template<class T, int N>

SeqList<T, N>::SeqList(T a[], int n) {
	if (n > N)
		throw "数组长度超过顺序表最大长度";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	length = n;
}
//简单数据类型的遍历操作
template<class T, int N>

void SeqList<T, N>::PrintList() {
	/*cout<<"按序号依次遍历线性表中的各个数据元素"<<endl;
	for (int i = 0; i < length; i++)
		cout<<data[i]<<" ";
	cout<<endl;
	*/
	for (int i = 0; i < length; i++)
		data[i].print();
	cout << endl;
}
//顺序表的插入操作
template<class T, int N>

void SeqList<T, N>::Insert(int i, T x) {
	if (length >= N)
		throw "上溢异常";
	if (i < 1 || i > length + 1)
		throw "位置异常";
	for (int j = length; j >= i; j--)
		data[j] = data[j - 1];
	data[i - 1] = x;
	length++;
}
//顺序表删除操作
template<class T, int N>

T SeqList<T, N>::Delet(int i) {
	if (length == 0)
		throw "下溢异常";
	if (i < 1 || i > length)
		throw "位置异常";
	T x = data[i - 1];
	for (int j = i; j < length; j++)
		data[j - 1] = data[j];
	length--;
	return x;
}
//查找操作 --- 按位查找
template<class T, int N>

T SeqList<T, N>::Get(int i) {
	if (i < 1 || i > length)
		throw "查找位置非法";
	return data[i - 1];
}
//查找操作 --- 按值查找
template<class T, int N>

int SeqList<T, N>::Locate(T x) {
	for (int i = 0; i < length; i++)
		if (data[i] == x)
			return i + 1;
	return 0;
}

#include <string>
class PHONEBOOK {
	private:
		int m_ID;
		string m_name;
		string m_phone;
		string m_group;
	public:
		PHONEBOOK() {}
		PHONEBOOK(int id, string name, string phone, string group) {
			m_ID = id;
			m_name = name;
			m_phone = phone;
			m_group = group;
		}
		/*原书中在此处的构造函数与此处不同, 原因是在Visual Studio 2022中使用"char*"时在后面初始化时会报错, 需要改成"const char*", 比较麻烦, 所以使用string代替*/
		void print() {
			cout << m_ID << '\t' << m_name << '\t' << m_phone << '\t' << m_group << endl;
		}
		bool operator == (PHONEBOOK &p) { //重载==运算符, 从而使locate()函数可用
			if (p.m_ID == m_ID)
				return true;
			return false;
		}
};

int main() {
	PHONEBOOK pbook[4] = {
		{20181208, "Mary", "13011221827", "classmates"},
		{20181127, "Tom", "13934621123", "family"},
		{20181156, "John", "1324579880", "classmates"},
		{20181123, "Lisa", "1378001822", "clsaamates"}
	};
	PHONEBOOK record(20181209, "phoneix", "1593020920", "teacher");
	SeqList <PHONEBOOK, 100>list(pbook, 4);
	cout << "通信录内容列表:" << endl;
	list.PrintList();
	list.Insert(1, record);
	cout << "通信录内容列表:" << endl;
	list.PrintList();
	PHONEBOOK x = list.Delet(3);
	cout << "删除元素:" << endl;
	x.print();
	cout << "通信录内容列表:" << endl;
	list.PrintList();
	int p = list.Locate(record);
	cout << "phoenix的位置是:" << p << endl;
}
