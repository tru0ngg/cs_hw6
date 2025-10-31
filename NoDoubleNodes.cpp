// This file is called NoDoubleNodes.cpp
#include <iostream>
using std::cout, std::cin, std::endl;

struct Node {
    int value = -1;
    Node* next = nullptr;
};

void remove_duplicates(Node* head) {
    Node* current = head;
    while (current != nullptr && current->next != nullptr){
            if (current->value == current->next->value){
                        Node* duplicated_value = current->next;
                        current->next = duplicated_value->next;
                        delete duplicated_value;
            } else {
                    current = current->next;
            }
    }
}

int main() {
    int N;
    cin >> N;
    Node* head = new Node;
    cin >> head->value;
    Node* tail = head;
    for (int i = 1; i < N; i++) {
        Node* new_node = new Node;
        cin >> new_node->value;
        tail->next = new_node;
        tail = new_node;
    }
    remove_duplicates(head);
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        Node* next = current->next;
        delete current;
        current = next;
    }
    cout << endl;
    return 0;
}
