#pragma once
#include <iostream>

using namespace std;

class Stack {
	// нижняя и верхняя граница стека
	enum {EMPTY = -1, FULL = 20};
	// массив для хранения данных
	char st[FULL + 1];
	// указатель на вершину стека
	int top;

public:
	Stack();

	// добавление элемента
	void Push(char c);
	// Извлечение элемента
	char Pop();
	// очистка стека
	void Clear();

	// проверка на существование элементов в стеке
	bool IsEmpty();
	// проверка на переполнение стека
	bool IsFull();
	// кол-во элементов в стеке
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
