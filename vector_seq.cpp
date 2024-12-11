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
		                &p) { //operator== ��һ�����ص������������������ʹ�� == ��������Ƚ����� PHONEBOOK ���͵Ķ����Ƿ���ȡ�
//		������������Ϊ�Ƚ������绰����Ŀ�� m_ID ��Ա�����Ƿ���ͬ��
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
		vec.push_back(pbook[i]);  //ʹ�����鷽ʽ����ÿ��Ԫ��
	cout << "ͨ��¼�����б�:" << endl;
	for (int i = 0; i < vec.size(); i++)
		vec[i].print();
	PHONEBOOK record(20181209, "phoneix", "1593020920", "teacher");
	vec.insert(vec.begin(), record);
	cout << "ͨ��¼�����б�:" << endl;
	for (vector<PHONEBOOK>::iterator it = vec.begin(); it != vec.end(); it++)
		(*it).print(); //ʹ�õ���������ÿ��Ԫ��
	cout << "ɾ��Ԫ��:" << endl;
	vec.erase((++ ++vec.begin()))->print();  //ɾ������λ�õ�Ԫ��
	cout << "ͨ��¼�����б�:" << endl;
	for (vector<PHONEBOOK>::iterator it = vec.begin(); it != vec.end(); it++)
		(*it).print(); //ʹ�õ���������ÿ��Ԫ��
	cout << endl;
}
