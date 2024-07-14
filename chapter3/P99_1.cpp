#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 10 // ջ���������

typedef struct {
	char data[Max + 1]; // ������֧�ִ��Max��Ԫ��
	int top;            // ջ��ָ��
} Stack;

/**
 * @brief �ж�ջ�Ƿ�Ϊ��
 * @param s ջ
 * @return true ���Ϊ�գ����� false
 */
bool IsStackEmpty(Stack s) {
	return s.top == -1;
}

/**
 * @brief �ж�ջ�Ƿ�����
 * @param s ջ
 * @return true ������������� false
 */
bool IsStackFull(Stack s) {
	return s.top == Max - 1;
}

/**
 * @brief ��Ԫ�� x ��ջ
 * @param s ջָ��
 * @param x Ҫ��ջ��Ԫ��
 * @return true ��ʾ�����ɹ���false ��ʾ����ʧ��
 */
bool Push(Stack *s, char x) {
	if (IsStackFull(*s)) {
		printf("ջ��\n");
		return false;
	}
	s->data[++s->top] = x;
	return true;
}

/**
 * @brief ��ջ�г�ջһ��Ԫ��
 * @param s ջָ��
 * @param x ָ�򱣴��ջԪ�ص�ָ��
 * @return 1 ��ʾ�����ɹ���0 ��ʾ����ʧ��
 */
int Pop(Stack *s, char *x) {
	if (IsStackEmpty(*s)) {
		printf("ջ��\n");
		return 0;
	}
	*x = s->data[s->top--];
	return 1;
}

/**
 * @brief ��������Ƿ�ƥ��
 * @param str ����������ַ���
 * @return true ���ƥ�䣬���� false
 */
bool IsParenthesesMatched(char *str) {
	Stack s;
	s.top = -1; // ��ʼ��ջ
	int i = 0;
	char ans;
	while (str[i] != '\0') {
		// ������������ջ
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			Push(&s, str[i]);
		else if (str[i] == ')') {
			Pop(&s, &ans);
			if (ans != '(')
				return false;
		} else if (str[i] == ']') {
			Pop(&s, &ans);
			if (ans != '[')
				return false;
		} else if (str[i] == '}') {
			Pop(&s, &ans);
			if (ans != '{')
				return false;
		}
		i++;
	}
	// ���ջ�Ƿ�Ϊ�գ����Ϊ�գ���������ƥ��
	return IsStackEmpty(s);
}

int main() {
	char *str = "()[](}{}()";
	printf("�������������: %s\n", str);
	if (!IsParenthesesMatched(str))
		printf("���Ų�ƥ��\n");
	else
		printf("����ƥ��\n");
	return 0;
}
