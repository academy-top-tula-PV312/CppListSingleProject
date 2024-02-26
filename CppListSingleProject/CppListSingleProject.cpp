#include <iostream>

template <typename T>
struct Node
{
    T value;
    Node<T>* next = nullptr;
};

template <typename T>
void PushHead(Node<T>*& head, T value);

template <typename T>
void List(Node<T>* head);

template <typename T>
T GetValue(Node<T>* head, int index);


int main()
{
    Node<int>* head = nullptr;

    PushHead(head, 100);
    PushHead(head, 200);
    PushHead(head, 300);
    PushHead(head, 400);
    PushHead(head, 500);
    PushHead(head, 600);

    List(head);

    std::cout << "\n" << GetValue(head, 0) << "\n";
}

template<typename T>
void PushHead(Node<T>*& head, T value)
{
    Node<T>* nodeNew{ new Node<T> };

    nodeNew->next = head;
    nodeNew->value = value;

    head = nodeNew;
}

template<typename T>
void List(Node<T>* head)
{
    while (head)
    {
        std::cout << head->value << "\n";
        head = head->next;
    }
}

template<typename T>
T GetValue(Node<T>* head, int index)
{
    for (int i{}; i < index; i++)
        head = head->next;
    return head->value;
}
