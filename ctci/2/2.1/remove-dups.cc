#include <unordered_set>
#include <iostream>

struct Node
{
    Node(int value) : next(nullptr), value(value){};

    Node* next;
    int value;
};

void removeDuplicates(Node* first)
{
    if (first == nullptr) return;
    
    std::unordered_set<int> seen;
    seen.insert(first->value);

    while (first->next != nullptr) {
        if (seen.find(first->next->value) == seen.end()) {
            first = first->next;
            seen.insert(first->value);
        } else if(first->next->next != nullptr) {
            first->next = first->next->next;
            first = first->next;
            seen.insert(first->value);
        } else {
            first->next = nullptr;
        }
    }
}

void printList(Node* first)
{
    if (first != nullptr) {
        std::cout << first->value;
    }

    first = first->next;

    while (first != nullptr) {
        std::cout << " --> " << first->value;
        first = first->next;
    }

    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    Node* n1 = new Node(50);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(20);
    Node* n5 = new Node(40);
    Node* n6 = new Node(60);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    printList(n1);
    removeDuplicates(n1);
    printList(n1);
}