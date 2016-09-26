#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "LinkedListIterator.h"

template <class T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();

        void insert(T value);
        T remove();

        T get(int i);

        bool is_empty();

        LinkedListIterator<T> *getIterator();

        int getSize(){return size;}
    protected:
    private:
        Node<T> *head;

        int size;
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;

    size = 0;
}

template <class T>
LinkedListIterator<T> *LinkedList<T>::getIterator()
{
    return new LinkedListIterator<T>(head);
}

template <class T>
bool LinkedList<T>::is_empty()
{
    return (size == 0);
}

template <class T>
void LinkedList<T>::insert(T value)
{
    if(head == nullptr)
    {
        head = new Node<T>(value);
        ++size;
        return;
    }

    Node<T> *curr = head;

    while(curr->get_next() != nullptr)
    {
        curr = curr->get_next();
    }

    Node<T> *new_node = new Node<T>(value);

    curr->set_next(new_node);

    ++size;
}

template <class T>
T LinkedList<T>::remove()
{
    Node<T> *tmp = head;

    T value = head->get_value();

    head = head->get_next();

    delete tmp;
    tmp = nullptr;

    --size;

    return value;
}

template <class T>
T LinkedList<T>::get(int i)
{
    Node<T> *curr = head;

    for(int j = 0; j < i; ++j)
    {
        curr = curr->get_next();
    }

    return curr->get_value();
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *curr = head;
    Node<T> *tmp;

    while(curr->get_next() != nullptr)
    {
        tmp = curr;
        curr = curr->get_next();

        delete tmp;
        tmp = nullptr;
    }

    delete curr;
    curr = nullptr;

    size = 0;
}

#endif // LINKEDLIST_H
