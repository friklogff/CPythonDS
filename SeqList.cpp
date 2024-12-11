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
//���캯��
template<class T, int N>

SeqList<T, N>::SeqList(T a[], int n) {
	if (n > N)
		throw "���鳤�ȳ���˳�����󳤶�";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	length = n;
}
//���������͵ı�������
template<class T, int N>

void SeqList<T, N>::PrintList() {
	/*cout<<"��������α������Ա��еĸ�������Ԫ��"<<endl;
	for (int i = 0; i < length; i++)
		cout<<data[i]<<" ";
	cout<<endl;
	*/
	for (int i = 0; i < length; i++)
		data[i].print();
	cout << endl;
}
//˳���Ĳ������
template<class T, int N>

void SeqList<T, N>::Insert(int i, T x) {
	if (length >= N)
		throw "�����쳣";
	if (i < 1 || i > length + 1)
		throw "λ���쳣";
	for (int j = length; j >= i; j--)
		data[j] = data[j - 1];
	data[i - 1] = x;
	length++;
}
//˳���ɾ������
template<class T, int N>

T SeqList<T, N>::Delet(int i) {
	if (length == 0)
		throw "�����쳣";
	if (i < 1 || i > length)
		throw "λ���쳣";
	T x = data[i - 1];
	for (int j = i; j < length; j++)
		data[j - 1] = data[j];
	length--;
	return x;
}
//���Ҳ��� --- ��λ����
template<class T, int N>

T SeqList<T, N>::Get(int i) {
	if (i < 1 || i > length)
		throw "����λ�÷Ƿ�";
	return data[i - 1];
}
//���Ҳ��� --- ��ֵ����
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
		/*ԭ�����ڴ˴��Ĺ��캯����˴���ͬ, ԭ������Visual Studio 2022��ʹ��"char*"ʱ�ں����ʼ��ʱ�ᱨ��, ��Ҫ�ĳ�"const char*", �Ƚ��鷳, ����ʹ��string����*/
		void print() {
			cout << m_ID << '\t' << m_name << '\t' << m_phone << '\t' << m_group << endl;
		}
		bool operator == (PHONEBOOK &p) { //����==�����, �Ӷ�ʹlocate()��������
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
	cout << "ͨ��¼�����б�:" << endl;
	list.PrintList();
	list.Insert(1, record);
	cout << "ͨ��¼�����б�:" << endl;
	list.PrintList();
	PHONEBOOK x = list.Delet(3);
	cout << "ɾ��Ԫ��:" << endl;
	x.print();
	cout << "ͨ��¼�����б�:" << endl;
	list.PrintList();
	int p = list.Locate(record);
	cout << "phoenix��λ����:" << p << endl;
}
