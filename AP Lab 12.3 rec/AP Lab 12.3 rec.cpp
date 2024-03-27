#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeBefore(int targetValue, Node* current = nullptr) {
        if (current == nullptr) {
            if (head == nullptr || head->next == nullptr)
                return;

            current = head->next;
        }

        if (current != nullptr && current->data != targetValue) {
            Node* temp = current->next;
            if (temp != nullptr && temp->data == targetValue) {
                if (current == head->next) {
                    head->next = temp;
                    temp->prev = head;
                    delete current;
                    return;
                }
                else {
                    Node* prevNode = current->prev;
                    prevNode->next = temp;
                    temp->prev = prevNode;
                    delete current;
                    return;
                }
            }
            removeBefore(targetValue, current->next);
        }
    }
    void printListRecursive(Node* current) {
        if (current == nullptr) {
            std::cout << std::endl;
            return;
        }
        std::cout << current->data << " ";
        printListRecursive(current->next);
    }

    void printList() {
        printListRecursive(head);
    }
};

int main() {
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    std::cout << "Original List: ";
    list.printList();

    int targetValue = 4;
    list.removeBefore(targetValue);

    std::cout << "List after removing element before " << targetValue << ": ";
    list.printList();

    return 0;
}
