// BlackMagic.cpp : Homework exercise for Black Magic.

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <atomic>
#include <mutex>


using namespace std;

void reverseWordsInString(char *myString)
{
	int length = strlen(myString);

	int i;
	for (i = length - 1; i >= 0; i--) {
		if (myString[i] == ' ') {
			myString[i] = '\0';
			printf("%s ", &(myString[i]) + 1);
		}
	}
	printf("%s", myString);
}

char* copyStr(const char* someStr) {
	char buf[100];
	sprintf_s(buf, "%s", someStr);
	return buf;
}

bool isPowerTwo(int num) {
	return (num != 0) && ((num & (num - 1)) == 0);
}

void putlong(unsigned long a) {
	if (a / 10)
		putlong(a / 10);
	putchar(a % 10 + '0');
}

float angleMinutesHours(int hh, int mm) {
	float angleDiff;
	// handle 24 hour format
	if (hh > 12) {
		hh -= 12;
	}
	if (hh != 12) {
		angleDiff = abs(hh * 30 - mm * 6);
	}
	else {
		angleDiff = mm * 6;
	}
	if (angleDiff < 180) {
		angleDiff = 360 - angleDiff;
	}
	return angleDiff;
}


class ThreadSafeSingleton {
public:
	static ThreadSafeSingleton* Inst();
private:
	ThreadSafeSingleton() = default;
	~ThreadSafeSingleton() = default;
	static atomic<ThreadSafeSingleton*> pinst;
	static mutex mut;
};
atomic<ThreadSafeSingleton*> ThreadSafeSingleton::pinst{ nullptr };
mutex ThreadSafeSingleton::mut;

ThreadSafeSingleton* ThreadSafeSingleton::Inst() {
	if (pinst == nullptr) {
		lock_guard<mutex> lock(mut);
		if (pinst == nullptr) {
			pinst = new ThreadSafeSingleton();
		}
	}
	return pinst;
}

typedef struct List {
	int data;
	struct List* next;
} Node;

class Stack {
	Node * node;
	int size_;
	Stack() : node(0), size_(0) { }
	~Stack() { delete node; };

	int size() const { return size_; }

	void Push(int data) {
		Node *temp;
		temp = new Node();
		temp->data = data;

		if (node == nullptr)
		{
			temp->next = nullptr;
		}
		else
		{
			temp->next = node;
		}
		node = temp;
		size_++;
	}

	int Pop() {
		if (node == nullptr) {
			cout << "empty stack!";
			exit(1);
		}
		else {
			Node *temp = node;
			node = node->next;
			node->next = 0;
			delete(temp);
			--size_;
		}
		return node->data;
	}

};


int main()
{
	ThreadSafeSingleton* tss = ThreadSafeSingleton::Inst();
	char query[] = "honey i love you";
	reverseWordsInString(query);
	bool abc = isPowerTwo(5);
	bool def = isPowerTwo(32);
	printf("printf true : %d\n", abc);
	printf("printf true : %d\n", def);
	putlong(125L);
	float ang = angleMinutesHours(14, 23);
	printf("angleDiff : %f\n", ang);
	Node * na = new Node();
	Stack stk();
}
