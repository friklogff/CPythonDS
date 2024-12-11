#include <iostream>
#include <vector>
using namespace std;

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
		void print() {
			cout << m_ID << '\t' << m_name << '\t' << m_phone << '\t' << m_group << endl;
		}
		bool operator==(PHONEBOOK
		                &p) { //operator== 是一个重载的运算符函数，它允许使用 == 运算符来比较两个 PHONEBOOK 类型的对象是否相等。
//		这个函数被设计为比较两个电话簿条目的 m_ID 成员变量是否相同。
			if (p.m_ID == m_ID)
				return true;
			return false;
		}
};

int main() {
	vector<PHONEBOOK> vec;
	PHONEBOOK pbook[4] = {
		{20181208, "Mary", "13011221827", "classmates"},
		{20181127, "Tom", "13934621123", "family"},
		{20181156, "John", "1324579880", "classmates"},
		{20181123, "Lisa", "1378001822", "clsaamates"}
	};
	for (int i = 0; i < 4; i++)
		vec.push_back(pbook[i]);  //使用数组方式访问每个元素
	cout << "通信录内容列表:" << endl;
	for (int i = 0; i < vec.size(); i++)
		vec[i].print();
	PHONEBOOK record(20181209, "phoneix", "1593020920", "teacher");
	vec.insert(vec.begin(), record);
	cout << "通信录内容列表:" << endl;
	for (vector<PHONEBOOK>::iterator it = vec.begin(); it != vec.end(); it++)
		(*it).print(); //使用迭代器访问每个元素
	cout << "删除元素:" << endl;
	vec.erase((++ ++vec.begin()))->print();  //删除第三位置的元素
	cout << "通信录内容列表:" << endl;
	for (vector<PHONEBOOK>::iterator it = vec.begin(); it != vec.end(); it++)
		(*it).print(); //使用迭代器访问每个元素
	cout << endl;
}
