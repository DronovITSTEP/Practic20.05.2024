#pragma once
#include <iostream>

using namespace std;

class Stack {
	// ������ � ������� ������� �����
	enum {EMPTY = -1, FULL = 20};
	// ������ ��� �������� ������
	char st[FULL + 1];
	// ��������� �� ������� �����
	int top;

public:
	Stack();

	// ���������� ��������
	void Push(char c);
	// ���������� ��������
	char Pop();
	// ������� �����
	void Clear();

	// �������� �� ������������� ��������� � �����
	bool IsEmpty();
	// �������� �� ������������ �����
	bool IsFull();
	// ���-�� ��������� � �����
	int GetCount();
};

Stack::Stack() {
	top = EMPTY;
}

bool Stack::IsEmpty() {
	return top == EMPTY;
}
bool Stack::IsFull() {
	return top == FULL;
}
int Stack::GetCount() {
	return top + 1;
}

void Stack::Push(char c) {
	if (!IsFull())
		st[++top] = c;
}
char Stack::Pop() {
	if (!IsEmpty())
		return st[top--];
	return 0;
}
void Stack::Clear() {
	top = EMPTY;
}
