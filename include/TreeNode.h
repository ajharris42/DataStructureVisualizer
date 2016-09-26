#pragma once

template <class T>
class TreeNode
{
	public:
		TreeNode(T value);
		~TreeNode();

		TreeNode<T> *get_left();
		TreeNode<T> *get_right();

		void set_left(TreeNode<T> *left);
		void set_right(TreeNode<T> *right);

		T get_value();
	private:
		T value;

		TreeNode<T> *left;
		TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode(T value)
{
	left = nullptr;
	right = nullptr;

	this->value = value;
}

template <class T>
inline T TreeNode<T>::get_value()
{
    return value;
}

template <class T>
inline TreeNode<T> *TreeNode<T>::get_left()
{
    return left;
}

template <class T>
inline TreeNode<T> *TreeNode<T>::get_right()
{
    return right;
}

template <class T>
inline void TreeNode<T>::set_left(TreeNode<T> *left)
{
    this->left = left;
}

template <class T>
inline void TreeNode<T>::set_right(TreeNode<T> *right)
{
    this->right = right;
}

template <class T>
TreeNode<T>::~TreeNode()
{

}
