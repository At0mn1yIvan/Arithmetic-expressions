#include <iostream>

template <typename T>
struct Node{
	T value;
	Node* next;
};

int main() {
	Node<int>* head = new Node<int>();
	head->value = 100;
	auto ptrHead = head;
	for (int i = 0; i < 10; i++) {
		Node<int>* newNode = new Node<int>();
		newNode->value = i;
		head->next = newNode;
		head = newNode;
		head->next = nullptr;
	}

	
	while (ptrHead != nullptr) {
		std::cout << ptrHead->value << "\n";
		ptrHead = ptrHead->next;
	}

	//удаление
	Node<int>* tmp;
	while (ptrHead != nullptr) {
		tmp = ptrHead->next;
		delete ptrHead;
		ptrHead = tmp;
	}

	return 0;
}