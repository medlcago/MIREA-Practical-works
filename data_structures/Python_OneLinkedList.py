class Node:
    def __init__(self, data):
        self.__data = data
        self.__next = None

    @property
    def next(self):
        return self.__next

    @next.setter
    def next(self, obj):
        if isinstance(obj, Node) or obj is None:
            self.__next = obj

    @property
    def data(self):
        return self.__data

    @data.setter
    def data(self, data):
        self.__data = data


class OneLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def push_front(self, obj) -> None:
        if self.tail is None:
            self.tail = obj
        obj.next = self.head
        self.head = obj

    def push_back(self, obj) -> None:
        if self.head is None:
            self.head = obj
        if self.tail:
            self.tail.next = obj
        self.tail = obj

    def pop_front(self) -> None:
        if self.head is None:
            return
        if self.head == self.tail:
            self.head = self.tail = None
            return
        self.head = self.head.next

    def pop_back(self) -> None:
        if self.tail is None:
            return
        if self.head == self.tail:
            self.head = self.tail = None
            return
        node = self.head
        while node.next != self.tail:
            node = node.next
        node.next = None
        self.tail = node

    def getAt(self, index) -> Node | None:
        if index < 0:
            return
        node = self.head
        n = 0
        while node and n != index and node.next:
            node = node.next
            n += 1
        return node if n == index else None

    def insert(self, index, data) -> None:
        if index > 0:
            left = self.getAt(index - 1)
            if left is None:
                return
            data.next = left.next
            left.next = data
            if left.next is None:
                self.tail = data
        else:
            self.push_front(data)

    def erase(self, index) -> None:
        if index < 0:
            return
        if index == 0:
            self.pop_front()
            return
        left = self.getAt(index - 1)
        node = left.next
        if node is None:
            return
        right = node.next
        left.next = right
        if node == self.tail:
            self.tail = left

    def get_data(self) -> list:
        lst = []
        node = self.head
        while node:
            lst.append(node.data)
            node = node.next
        return lst

    def clear(self) -> None:
        self.head = None
        self.tail = None


if __name__ == '__main__':
    lst = OneLinkedList()
    lst.push_front(Node(1))
    lst.push_back(Node(5))
    lst.push_back(Node(7))
    lst.push_front(Node(9))
    lst.pop_back()
    lst.pop_front()
    lst.insert(0, Node(123))
    lst.push_back(Node(93))
    lst.insert(1, Node(0))
    lst.erase(0)
    print(lst.get_data()) # [0, 1, 5, 93]

    lst.clear()
    print(lst.get_data()) # []

    lst.push_front(Node(1))
    lst.push_back(Node(5))
    lst.insert(1, Node(4444))
    print(lst.get_data()) # [1, 4444, 5]
