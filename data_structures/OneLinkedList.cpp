#include <iostream>


class Node {
public:
	double data;
	Node* next;
public:
	Node(double data) {
		this->data = data;
		this->next = NULL;
	}
};

class OneLinkedList {
public:
	Node* head, * tail;
public:
	OneLinkedList() {
		this->head = this->tail = NULL;
	}

	~OneLinkedList() {
		while (head != NULL)
			pop_front();
	}

	void push_front(double data) { // Добавляем элемент в начало списка
		Node* node = new Node(data);
		node->next = head;
		head = node;
		if (tail == NULL) tail = node;
	}
	
	void push_back(double data) { // Добавляем элемент в конец списка
		Node* node = new Node(data);
		if (head == NULL) head = node;
		if (tail != NULL) tail->next = node;
		tail = node;
	}

	void pop_front() { // Удаляем первый элемент в списке
		if (head == NULL) return;
		if (head == tail) {
			delete tail;
			head = tail = NULL;
			return;
		}

		Node* node = head;
		head = node->next;
		delete node;
	}

	void pop_back() { // Удаляем последний элемент в списке
		if (tail == NULL) return;
		if (head == tail) {
			delete tail;
			head = tail = NULL;
			return;
		}

		Node* node = head;
		for (; node->next != tail; node = node->next);
		node->next = NULL;
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

	void insert(int k, double data) { // Вставляем элемент в список по индексу k
		if (k > 0)
		{
			Node* left = getAt(k - 1);
			if (left == NULL) return;

			Node* node = new Node(data);
			node->next = left->next;

			if (left->next == NULL) tail = node;
			left->next = node;
		}
		else if (k == 0)
			push_front(data);
	}

	void erase(int k) { // Удаляем элемент в списке по индексу k
		if (k < 0) return;
		if (k == 0) {
			pop_front();
			return;
		}

		Node* left = getAt(k - 1);
		Node* node = left->next;
		if (node == NULL) return;
		Node* right = node->next;
		left->next = right;
		if (node == tail) tail = left;
		delete node;
	}
};


int main() {
	OneLinkedList list;
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


	for (Node* node = list.head; node != NULL; node = node->next)
		std::cout << node->data << " ";
	return 0;
}
