#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* prev, * next;
public:
    Node(T data) {
        this->data = data;
        this->prev = this->next = NULL;
    }
};

template <typename T>
class DoublyLinkedList {
public:
    Node<T>* head, * tail;
public:
    DoublyLinkedList() {
        this->head = this->tail = NULL;
    }

    ~DoublyLinkedList() {
        while (head != NULL)
            pop_front();
    }

    Node<T>* push_front(T data) {
        Node<T>* node = new Node<T>(data);
        node->next = head;
        if (head != NULL)
            head->prev = node;
        if (tail == NULL)
            tail = node;
        head = node;
        return node;
    }

    Node<T>* push_back(T data) {
        Node<T>* node = new Node<T>(data);
        node->prev = tail;
        if (tail != NULL)
            tail->next = node;
        if (head == NULL)
            head = node;
        tail = node;
        return node;
    }

    void pop_front() {
        if (head == NULL) return;

        Node<T>* node = head->next;
        if (node != NULL)
            node->prev = NULL;
        else
            tail = NULL;

        delete head;
        head = node;
    }

    void pop_back() {
        if (tail == NULL) return;

        Node<T>* node = tail->prev;
        if (node != NULL)
            node->next = NULL;
        else
            head = NULL;

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

    Node<T>* operator [] (int k) {
        return getAt(k);
    }

    Node<T>* insert(int k, T data) {
        Node<T>* right = getAt(k);
        if (right == NULL)
            return push_back(data);

        Node<T>* left = right->prev;
        if (left == NULL)
            return push_front(data);

        Node<T>* node = new Node<T>(data);
        node->prev = left;
        node->next = right;
        left->next = node;
        right->prev = node;

        return node;
    }

    void erase(int k) {
        Node<T>* node = getAt(k);
        if (node == NULL) return;
        if (node->prev == NULL) {
            pop_front();
            return;
        }
        if (node->next == NULL) {
            pop_back();
            return;
        }

        Node<T>* left = node->prev;
        Node<T>* right = node->next;
        left->next = right;
        right->prev = left;
        delete node;
    }
};

int main() {
    DoublyLinkedList<int> list;
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

    for (Node<int>* node = list.tail; node != NULL; node = node->prev)
        std::cout << node->data << " ";
    return 0;
}
