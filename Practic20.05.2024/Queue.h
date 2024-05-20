#pragma once
#include <iostream>

using namespace std;

class Queue {

	// �������
	int* wait;
	//������������ ������ �������
	int maxQueueLength;
	// ������� ������ �������
	int curQueueLength;

public:
	Queue(int m);
	~Queue();

	// �������� �� ������������� ��������� � �������
	bool IsEmpty();
	// �������� �� ������������ �������
	bool IsFull();
	// ���-�� ��������� � �������
	int GetCount();

	// ������� �������
	void Clear();
	// ���������� �������� � �������
	void Add(int num);
	// ���������� �������� �� �������
	int Extract();

	void Show();
};

Queue::Queue(int m) {
	maxQueueLength = m;
	wait = new int[maxQueueLength];
	curQueueLength = 0;
}
Queue::~Queue() {
	delete[] wait;
}

bool Queue::IsEmpty() {
	return curQueueLength == 0;
}
bool Queue::IsFull() {
	return curQueueLength == maxQueueLength;
}
int Queue::GetCount() {
	return curQueueLength;
}
void Queue::Clear() {
	curQueueLength = 0;
}

void Queue::Add(int num) {
	if (!IsFull())
		wait[curQueueLength++] = num;
}

int Queue::Extract() {
	if (!IsEmpty()) {
		int temp = wait[0];

		for (int i = 1; i < curQueueLength; i++) {
			wait[i - 1] = wait[i];
		}
		curQueueLength--;
		return temp;
	}
	return -1;
}

void Queue::Show() {
	cout << endl;
	for (int i = 0; i < curQueueLength; i++) {
		cout << wait[i] << " ";
	}
	cout << endl;
}