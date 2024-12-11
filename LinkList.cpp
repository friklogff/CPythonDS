#include <iostream>  // ��������������⣬���ڱ�׼�����������
using namespace std;  // ʹ�ñ�׼�����ռ䣬�򻯱�׼�⺯���Ͷ����ʹ��

template<class T>  // ģ������������һ��ͨ������T
struct Node { // ����һ���ṹ��Node����ʾ����Ľڵ�
	T data;  // �ڵ������������ΪT
	struct Node<T> *next;  // �ڵ��ָ����ָ����һ���ڵ�
};

template<class T>  // ģ������������һ��ͨ������T
class LinkList { // ����һ����LinkList����ʾ����
	public:
		LinkList() { // ���캯�������ڳ�ʼ�������ڴ�������ʱ�Զ����á�
			front = new Node<T>;  // ����һ���µ�ͷ�ڵ�
			front->next = NULL;  // ͷ�ڵ��nextָ��ָ��NULL
		}

		LinkList(T a[], int n);  // ���ع��캯�������ڸ��ݲ�ͬ�Ĳ�����ʼ�������ڴ�������ʱ�Զ����á�

		~LinkList();  // ���������������ͷŶ���ռ�õ���Դ���ڶ�������ʱ�Զ����á�

		void PrintList();  // ��ӡ�����е�����Ԫ��

		int GetLength();  // ��ȡ����ĳ���

		Node<T> *Get(int i);  // ��λ���ң���ȡ��i���ڵ�

		int Locate(T x);  // ��ֵ���ң���ȡֵΪx�Ľڵ��λ��

		void Insert(int i, T x);  // ����������ڵ�i��λ�ò���ֵΪx�Ľڵ�

		T Delet(int i);  // ɾ��������ɾ����i��λ�õĽڵ㣬��������ֵ

	private:
		Node<T> *front;  // �����ͷ�ڵ�ָ��
};

// β�巨����������
template<class T>
LinkList<T>::LinkList(T a[], int n) { // ���캯����ͨ�������ʼ������
	front = new Node<T>;  // ����һ���µ�ͷ�ڵ�
	Node<T> *r = front;  // ����һ��βָ��r����ʼָ��ͷ�ڵ�
	for (int i = 0; i < n; i++) { // ��������
		Node<T> *s = new Node<T>;  // ����һ���µĽڵ�s
		s->data = a[i];  // �������е�Ԫ�ظ�ֵ���ڵ��������
		r->next = s;  // ��βָ���nextָ��ָ���½ڵ�
		r = s;  // ����βָ�룬ָ���½ڵ�
	}
	r->next = NULL;  // β�ڵ��nextָ��ָ��NULL
}

// ��������
template<class T>
LinkList<T>::~LinkList() { // �����������ͷ�����ռ�õ��ڴ�
	Node<T> *p = front;  // ����һ��ָ��p����ʼָ��ͷ�ڵ�
	while (p) { // ��������
		Node<T> *temp = p;  // ����һ����ʱָ��temp��ָ��ǰ�ڵ�
		p = p->next;  // ����ָ��p��ָ����һ���ڵ�
		delete temp;  // �ͷŵ�ǰ�ڵ���ڴ�
	}
}

// ��λ����
template<class T>
Node<T> *LinkList<T>::Get(int i) { // ��λ���ң���ȡ��i���ڵ�
	Node<T> *p = front->next;  // ����һ��ָ��p����ʼָ��ͷ�ڵ����һ���ڵ�
	int j = 1;  // ����һ��������j����ʼֵΪ1
	while (p && j != i) { // ��������ֱ���ҵ���i���ڵ�򵽴�����ĩβ
		p = p->next;  // ����ָ��p��ָ����һ���ڵ�
		j++;  // ���¼�����j
	}
	return p;  // ���ص�i���ڵ��ָ��
}

// ��ֵ����
template<class T>
int LinkList<T>::Locate(T x) { // ��ֵ���ң���ȡֵΪx�Ľڵ��λ��
	Node<T> *p = front->next;  // ����һ��ָ��p����ʼָ��ͷ�ڵ����һ���ڵ�
	int j = 1;  // ����һ��������j����ʼֵΪ1
	while (p) { // ��������
		if (p->data == x)  // ����ҵ�ֵΪx�Ľڵ�
			return j;  // ���ؽڵ��λ��
		p = p->next;  // ����ָ��p��ָ����һ���ڵ�
		j++;  // ���¼�����j
	}
	return -1;  // ���û���ҵ�ֵΪx�Ľڵ㣬����-1
}

// �������
template<class T>
void LinkList<T>::Insert(int i, T x) { // ����������ڵ�i��λ�ò���ֵΪx�Ľڵ�
	Node<T> *p = front;  // ����һ��ָ��p����ʼָ��ͷ�ڵ�
	if (i != 1)  // �������λ�ò��ǵ�һ��λ��
		p = Get(i - 1);  // ��ȡ����λ�õ�ǰһ���ڵ�
	if (p) { // �������λ�úϷ�
		Node<T> *s = new Node<T>;  // ����һ���µĽڵ�s
		s->data = x;  // ��ֵx��ֵ���ڵ��������
		s->next = p->next;  // ���½ڵ��nextָ��ָ�����λ�õĽڵ�
		p->next = s;  // ������λ�õ�ǰһ���ڵ��nextָ��ָ���½ڵ�
	} else
		throw "����λ�ô���";  // �������λ�ò��Ϸ����׳��쳣
}

// ɾ������
template<class T>
T LinkList<T>::Delet(int i) { // ɾ��������ɾ����i��λ�õĽڵ㣬��������ֵ
	Node<T> *p = front;  // ����һ��ָ��p����ʼָ��ͷ�ڵ�
	if (i != 1)  // ���ɾ��λ�ò��ǵ�һ��λ��
		p = Get(i - 1);  // ��ȡɾ��λ�õ�ǰһ���ڵ�
	Node<T> *q = p->next;  // ����һ��ָ��q��ָ��ɾ��λ�õĽڵ�
	p->next = q->next;  // ��ɾ��λ�õ�ǰһ���ڵ��nextָ��ָ��ɾ��λ�õ���һ���ڵ�
	T x = q->data;  // ��ȡɾ���ڵ��ֵ
	delete q;  // �ͷ�ɾ���ڵ���ڴ�
	return x;  // ����ɾ���ڵ��ֵ
}

// ��ӡ����
template<class T>
void LinkList<T>::PrintList() { // ��ӡ�����е�����Ԫ��
	Node<T> *p = front->next;  // ����һ��ָ��p����ʼָ��ͷ�ڵ����һ���ڵ�
	while (p != NULL) { // ��������
//		cout << p->data << " ";  // ����ֱ�Ӵ�ӡ��ǰ�ڵ���������˽�б���
		p->data.print();// ��ӡ��ǰ�ڵ��������,ʹ�ù��еķ���������

		p = p->next;  // ����ָ��p��ָ����һ���ڵ�
	}
	cout << endl;  // ����
}
//#include "LinkList.h"  // �����Զ��������ͷ�ļ�
#include <string>  // �����ַ������ͷ�ļ�

class PHONEBOOK { // ����һ����PHONEBOOK����ʾͨѶ¼�е�һ����¼
	private:
		int m_ID;  // ��¼��ID
		string m_name;  // ��¼������
		string m_phone;  // ��¼�ĵ绰����
		string m_group;  // ��¼�ķ���

	public:
		PHONEBOOK() {}  // Ĭ�Ϲ��캯�����������κγ�ʼ��

		PHONEBOOK(int id, string name, string phone, string group) {
			// �������Ĺ��캯�������ڴ���һ�� PHONEBOOK ����    PHONEBOOK pbook(20181208, "Mary", "13011221827", "classmates");ʱ
			// ��ʼ��˽�г�Ա���� m_ID��m_name��m_phone �� m_group
			m_ID = id;
			m_name = name;
			m_phone = phone;
			m_group = group;
		}

		void print() { // ��ӡ��¼����Ϣ����˽�г�Ա���� m_ID��m_name��m_phone �� m_group ��ֵ�������׼�������ʹ���Ʊ�� \t �ָ���
			cout << m_ID << '\t' << m_name << '\t' << m_phone << '\t' << m_group << endl;
		}

		bool operator == (PHONEBOOK &p) { // ����==����������ڱȽ�������¼��ID�Ƿ���ͬ
			if (p.m_ID == m_ID)
				return true;
			return false;
		}
};

int main() { // ������
	PHONEBOOK pbook[4] = {  // ��ʼ��һ������4����¼��ͨѶ¼����
		{20181208, "Mary", "13011221827", "classmates"},
		{20181127, "Tom", "13934621123", "family"},
		{20181156, "John", "1324579880", "classmates"},
		{20181123, "Lisa", "1378001822", "clsaamates"}
	};

	PHONEBOOK record(20181209, "phoneix", "1593020920", "teacher");  // ����һ���µļ�¼

	LinkList<PHONEBOOK> list(pbook, 4);  // ʹ��ͨѶ¼�����ʼ������

	cout << "ͨ��¼�����б�:" << endl;
	list.PrintList();  // ��ӡ�����е����м�¼

	list.Insert(1, record);  // ������ĵ�һ��λ�ò����µļ�¼

	cout << "ͨ��¼�����б�:" << endl;
	list.PrintList();  // ��ӡ�����е����м�¼

	PHONEBOOK x = list.Delet(3);  // ɾ�������еĵ�������¼��������ɾ���ļ�¼

	cout << "ɾ��Ԫ��:" << endl;
	x.print();  // ��ӡɾ���ļ�¼

	cout << "ͨ��¼�����б�:" << endl;
	list.PrintList();  // ��ӡ�����е����м�¼

	int p = list.Locate(record);  // �����µļ�¼�������е�λ��
	cout << "phoenix��λ����:" << p << endl;  // ��ӡ�µļ�¼��λ��

	return 0;  // ����0����ʾ������������
}
/*
`string` �� `char*` �������ڴ����ַ������������ͣ������������������������Ƕ����ǵ���ϸ���ͺͱȽϣ�

### `string`

`string` �� C++ ��׼���е�һ���࣬������ `<string>` ͷ�ļ��С����ṩ�˷ḻ���ַ����������ܣ�ʹ���ַ���������ӷ���Ͱ�ȫ��

**���Ժ��ŵ㣺**
1. **��̬��С**��`string` ���Զ�̬������С������Ҫ�ֶ������ڴ档
2. **�ḻ�ĳ�Ա����**���ṩ������Ա�������� `length()`��`size()`��`substr()`��`find()`��`append()` �ȣ�������и����ַ���������
3. **��ȫ��**��`string` �Զ������ڴ棬�������ڴ�й©��Խ����ʵķ��ա�
4. **������**��`string` ������ `char*` ��������ͨ�� `c_str()` ��Ա�������Ի�ȡ `const char*`��

**ʾ����**
```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    std::cout << "Length: " << str.length() << std::endl;
    std::cout << "Substring: " << str.substr(7, 5) << std::endl;
    return 0;
}
```

### `char*`

`char*` �� C �����е��ַ�����ʾ��ʽ��Ҳ������ C++ ��ʹ�á�����һ��ָ���ַ������ָ�롣

**���Ժ��ŵ㣺**
1. **�����**��`char*` �ṩ�˶Եײ��ַ������ֱ�ӷ��ʣ����Խ��еͼ�����ַ���������
2. **������**��`char*` ������ C ���Ե��ַ����������� `strlen()`��`strcpy()`��`strcat()` �ȣ����ݡ�

**ȱ�㣺**
1. **�ڴ����**����Ҫ�ֶ������ڴ棬���׳����ڴ�й©��Խ����ʵ����⡣
2. **����ȫ**�����׳��ֻ���������Ȱ�ȫ���⡣
3. **��������**����Ҫ�ֶ���д����ַ������������������˴���ĸ����ԡ�

**ʾ����**
```cpp
#include <iostream>
#include <cstring>

int main() {
    char str[] = "Hello, World!";
    std::cout << "Length: " << std::strlen(str) << std::endl;
    char substr[6];
    std::strncpy(substr, str + 7, 5);
    substr[5] = '\0';
    std::cout << "Substring: " << substr << std::endl;
    return 0;
}
```

### �Ƚ�

1. **�ڴ����**��
   - `string`���Զ������ڴ棬�����ڴ�й©��Խ����ʵķ��ա�
   - `char*`����Ҫ�ֶ������ڴ棬���׳����ڴ�й©��Խ����ʵ����⡣

2. **����������**��
   - `string`���ṩ�˷ḻ�ĳ�Ա������������и����ַ���������
   - `char*`����Ҫ�ֶ���д����ַ������������������˴���ĸ����ԡ�

3. **��ȫ��**��
   - `string`������ȫ�������˻���������Ȱ�ȫ���⡣
   - `char*`�����׳��ֻ���������Ȱ�ȫ���⡣

4. **������**��
   - `string`�������� `char*` ��������ͨ�� `c_str()` ��Ա�������Ի�ȡ `const char*`��
   - `char*`�������� C ���Ե��ַ����������ݡ�

### �ܽ�

�� C++ �У��Ƽ�ʹ�� `string` ���������ַ�������Ϊ���ṩ�˸��ߵİ�ȫ�Ժͱ����ԡ�ֻ������Ҫ�� C ���Լ��ݻ���еͼ����ַ�������ʱ���ſ���ʹ�� `char*`��
*/