#include <iostream>


class Node {
public:
	double data;
	Node* prev, * next;
public:
	Node(double data) {
		this->data = data;
		this->prev = this->next = NULL;
	}
};

class DoublyLinkedList {
public:
	Node* head, * tail;
public:
	DoublyLinkedList() {
		this->head = this->tail = NULL;
	}

	~DoublyLinkedList() {
		while (head != NULL)
			pop_front();
	}

	Node* push_front(double data) { // Добавляем элемент в начало списка
		Node* node = new Node(data);
		node->next = head;
		if (head != NULL)
			head->prev = node;
		if (tail == NULL)
			tail = node;
		head = node;
		return node;
	}

	Node* push_back(double data) { // Добавляем элемент в конец списка
		Node* node = new Node(data);
		node->prev = tail;
		if (tail != NULL)
			tail->next = node;
		if (head == NULL)
			head = node;
		tail = node;
		return node;
	}

	void pop_front() { // Удаляем первый элемент в списке
		if (head == NULL) return;

		Node* node = head->next;
		if (node != NULL)
			node->prev = NULL;
		else
			tail = NULL;

		delete head;
		head = node;
	}

	void pop_back() { // Удаляем последний элемент в списке
		if (tail == NULL) return;

		Node* node = tail->prev;
		if (node != NULL)
			node->next = NULL;
		else
			head = NULL;

		delete tail;
		tail = node;

	}

	Node* getAt(int k) { // Получаем элемент списка по индексу k
		if (k < 0) return NULL;
		Node* node = head;
		int n = 0;
		while (node && n != k && node->next) {
			node = node->next;
			n++;
		}
		return (n == k) ? node : NULL;
	}

	Node* operator [] (int k) {
		return getAt(k);
	}

	Node* insert(int k, double data) { // Вставляем элемент в список по индексу k
		Node* right = getAt(k);
		if (right == NULL)
			return push_back(data);

		Node* left = right->prev;
		if (left == NULL)
			return push_front(data);

		Node* node = new Node(data);
		node->prev = left;
		node->next = right;
		left->next = node;
		right->prev = node;

		return node;
	}

	void erase(int k) { // Удаляем элемент в списке по индексу k
		Node* node = getAt(k);
		if (node == NULL) return;
		if (node->prev == NULL) {
			pop_front();
			return;
		}
		if (node->next == NULL) {
			pop_back();
			return;
		}

		Node* left = node->prev;
		Node* right = node->next;
		left->next = right;
		right->prev = left;
		delete node;
	}
};


int main() {
	DoublyLinkedList list;
	list.push_front(1);
	list.push_back(5);
	list.push_back(7);
	list.push_front(9);
	list.pop_back();
	list.pop_front();
	list.insert(1, 123);
	list.push_back(93);
	list.insert(2, 0);
	list.erase(0);

	for (Node* node = list.tail; node != NULL; node = node->prev)
		std::cout << node->data << " ";
	return 0;
}
