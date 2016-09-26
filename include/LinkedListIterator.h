#ifndef LINKEDLISTITERATOR_H_INCLUDED
#define LINKEDLISTITERATOR_H_INCLUDED

#include "Node.h"

template<class T>
class LinkedListIterator {
    public:
        LinkedListIterator(Node<T> *first_node) {
            current_node = first_node;
        }

        bool has_next() {
            return (current_node != nullptr);
        }

        T next() {
            T element;

            if (has_next()) {
                element = current_node->get_value();
                current_node = current_node->get_next();
            }
            return element;
        }

        //This is a special method that is necessary for my implementation
        T get_next_value()
        {
            if(current_node != nullptr)
                return current_node->get_value();
            else
                return -1;
        }
    private:
        Node<T> *current_node;

};

#endif // LINKEDLISTITERATOR_H_INCLUDED
