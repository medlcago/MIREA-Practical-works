#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
public:
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class OneLinkedList {
public:
    Node<T>* head, * tail;
public:
    OneLinkedList() {
        this->head = this->tail = NULL;
    }

    ~OneLinkedList() {
        while (head != NULL)
            pop_front();
    }

    void push_front(T data) {
        Node<T>* node = new Node<T>(data);
        node->next = head;
        head = node;
        if (tail == NULL) tail = node;
    }

    void push_back(T data) {
        Node<T>* node = new Node<T>(data);
        if (head == NULL) head = node;
        if (tail != NULL) tail->next = node;
        tail = node;
    }

    void pop_front() {
        if (head == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }

        Node<T>* node = head;
        head = node->next;
        delete node;
    }

    void pop_back() {
        if (tail == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }

        Node<T>* node = head;
        for (; node->next != tail; node = node->next);
        node->next = NULL;
        delete tail;
        tail = node;
    }

    Node<T>* getAt(int k) {
        if (k < 0) return NULL;
        Node<T>* node = head;
        int n = 0;
        while (node && n != k && node->next) {
            node = node->next;
            n++;
        }
        return (n == k) ? node : NULL;
    }

    void insert(int k, T data) {
        if (k > 0)
        {
            Node<T>* left = getAt(k - 1);
            if (left == NULL) return;

            Node<T>* node = new Node<T>(data);
            node->next = left->next;

            if (left->next == NULL) tail = node;
            left->next = node;
        }
        else if (k == 0)
            push_front(data);
    }

    void erase(int k) {
        if (k < 0) return;
        if (k == 0) {
            pop_front();
            return;
        }

        Node<T>* left = getAt(k - 1);
        Node<T>* node = left->next;
        if (node == NULL) return;
        Node<T>* right = node->next;
        left->next = right;
        if (node == tail) tail = left;
        delete node;
    }
};

int main() {
    OneLinkedList<int> list;
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

    for (Node<int>* node = list.head; node != NULL; node = node->next)
        std::cout << node->data << " ";
    return 0;
}
