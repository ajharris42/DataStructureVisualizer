#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    public:
        Node(T value);
        ~Node();

        Node<T> *get_next();
        void set_next(Node<T> *next);

        T get_value();
    protected:
    private:
        Node<T> *next;

        T value;
};

template <class T>
Node<T>::Node(T value)
{
    next = nullptr;

    this->value = value;
}

template <class T>
T Node<T>::get_value()
{
    return value;
}

template <class T>
Node<T> *Node<T>::get_next()
{
    return next;
}

template <class T>
void Node<T>::set_next(Node<T> *next)
{
    this->next = next;
}

template <class T>
Node<T>::~Node()
{

}

#endif // NODE_H
