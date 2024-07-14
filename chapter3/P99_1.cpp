#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 10 // 栈的最大容量

typedef struct {
	char data[Max + 1]; // 数据域，支持存放Max个元素
	int top;            // 栈顶指针
} Stack;

/**
 * @brief 判断栈是否为空
 * @param s 栈
 * @return true 如果为空，否则 false
 */
bool IsStackEmpty(Stack s) {
	return s.top == -1;
}

/**
 * @brief 判断栈是否已满
 * @param s 栈
 * @return true 如果已满，否则 false
 */
bool IsStackFull(Stack s) {
	return s.top == Max - 1;
}

/**
 * @brief 将元素 x 进栈
 * @param s 栈指针
 * @param x 要进栈的元素
 * @return true 表示操作成功，false 表示操作失败
 */
bool Push(Stack *s, char x) {
	if (IsStackFull(*s)) {
		printf("栈满\n");
		return false;
	}
	s->data[++s->top] = x;
	return true;
}

/**
 * @brief 从栈中出栈一个元素
 * @param s 栈指针
 * @param x 指向保存出栈元素的指针
 * @return 1 表示操作成功，0 表示操作失败
 */
int Pop(Stack *s, char *x) {
	if (IsStackEmpty(*s)) {
		printf("栈空\n");
		return 0;
	}
	*x = s->data[s->top--];
	return 1;
}

/**
 * @brief 检查括号是否匹配
 * @param str 输入的括号字符串
 * @return true 如果匹配，否则 false
 */
bool IsParenthesesMatched(char *str) {
	Stack s;
	s.top = -1; // 初始化栈
	int i = 0;
	char ans;
	while (str[i] != '\0') {
		// 遇到左括号入栈
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
	// 检查栈是否为空，如果为空，所有括号匹配
	return IsStackEmpty(s);
}

int main() {
	char *str = "()[](}{}()";
	printf("输入的括号序列: %s\n", str);
	if (!IsParenthesesMatched(str))
		printf("括号不匹配\n");
	else
		printf("括号匹配\n");
	return 0;
}
