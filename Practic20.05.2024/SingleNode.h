#pragma once
#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};

class SingleList {
	Node* head;
	Node* tail;
public:
	SingleList();
	// ƒобавление в конец списка
	void Add(int value);
	// ѕоказать список
	void Show();
	// добавление в начало списка
	void Push(int value);
	// втсавка в определенное положение
	void Insert(int value, int pos);
	// извлечение первого(head) элемента
	int Pop();
	// извлечение последнего(tail) элемента
	int removeLast();
	// извлечение элемента по позиции
	int removeByIndex(int pos);

};

SingleList::SingleList() {
	head = nullptr;
	tail = nullptr;
}
void SingleList::Add(int value) {
	Node* temp = new Node;
	temp->value = value;
	temp->next = nullptr;

	if (head == nullptr) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}

}
void SingleList::Show() {
	Node* current = head;

	while (current != nullptr) {
		cout << current->value << endl;
		current = current->next;
	}
}
void SingleList::Push(int value) {
	Node* temp = new Node;
	temp->value = value;
	temp->next = head;

	head = temp;
}
void SingleList::Insert(int value, int pos) {
	Node* temp = new Node;
	Node* pre = nullptr;
	Node* current = nullptr;

	current = head;

	for (int i = 1; i < pos; i++) {
		pre = current;
		current = current->next;
	}
	temp->value = value;
	pre->next = temp;
	temp->next = current;
}
int SingleList::Pop() {
	Node* temp = nullptr;
	if (head != nullptr) {
		temp = head->next;
		int val = head->value;

		delete head;

		head = temp;

		return val;
	}
	return -1;
}
int SingleList::removeLast() {
	int val = -1;
	if (head->next == nullptr) {
		val = head->value;
		delete head;
		return val;
	}

	Node* current = head;
	while (current->next->next != nullptr)
		current = current->next;

	val = current->next->value;
	delete current->next;
	current->next = nullptr;

	return val;
}
int SingleList::removeByIndex(int pos) {
	Node* current = head;
	Node* temp = nullptr;

	if (pos == 0) return Pop();

	for (int i = 0; i < pos - 1; i++) {
		if (current->next == nullptr)
			return -1;
		current = current->next;
	}

	temp = current->next;
	int val = temp->value;
	current->next = temp->next;
	delete temp;

	return val;

}