#pragma once

#include "TreeNode.h"
#include "LinkedList.h"

template <class T>
class BinaryTree
{
	public:
		BinaryTree();
		~BinaryTree();

		//-1 on failure
		int insert(T value);
		TreeNode<T> *insert_helper(TreeNode<T> *current_node, T value);

		T remove();
		T remove_helper(TreeNode<T> *current_node);

        LinkedList<T> *inorder();
        void inorder_helper(TreeNode<T> *node, LinkedList<T> *list);

        LinkedList<T> *preorder();
        void preorder_helper(TreeNode<T> *node, LinkedList<T> *list);

		bool is_empty();


	private:
		TreeNode<T> *root;
		int size;
};

template <class T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template <class T>
inline bool BinaryTree<T>::is_empty()
{
	return (size == 0);
}

template <class T>
inline int BinaryTree<T>::insert(T value)
{
	root = insert_helper(root, value);

	if(root == nullptr)
		return -1;

    ++size;

	return 1;
}

template <class T>
inline TreeNode<T> *BinaryTree<T>::insert_helper(TreeNode<T> *current_node, T value)
{
	if(root == nullptr)
		return new TreeNode<T>(value);

	if(value >= current_node->get_value())
	{
		if(current_node->get_right() == nullptr)
		{
			current_node->set_right(new TreeNode<T>(value));

			return root;
		}else{
			return insert_helper(current_node->get_right(), value);
		}
	}else{
		if(current_node->get_left() == nullptr)
		{
			current_node->set_left(new TreeNode<T>(value));

			return root;
		}else{
			return insert_helper(current_node->get_left(), value);
		}
	}
}

template <class T>
inline LinkedList<T> *BinaryTree<T>::inorder()
{
    LinkedList<T> *list = new LinkedList<T>();

    inorder_helper(root, list);

    return list;
}

template <class T>
inline void BinaryTree<T>::inorder_helper(TreeNode<T> *node, LinkedList<T> *list)
{
    if(node != nullptr)
    {
        inorder_helper(node->get_left(), list);
        list->insert(node->get_value());
        inorder_helper(node->get_right(), list);
    }
}

template <class T>
inline LinkedList<T> *BinaryTree<T>::preorder()
{
    LinkedList<T> *list = new LinkedList<T>();

    preorder_helper(root, list);

    return list;
}

template <class T>
inline void BinaryTree<T>::preorder_helper(TreeNode<T> *node, LinkedList<T> *list)
{
    if(node != nullptr)
    {
        list->insert(node->get_value());
        preorder_helper(node->get_left(), list);
        preorder_helper(node->get_right(), list);
    }
}

template <class T>
inline T BinaryTree<T>::remove()
{
    --size;

    return remove_helper(root);
}

template <class T>
inline T BinaryTree<T>::remove_helper(TreeNode<T> *current_node)
{
    TreeNode<T> *prev = current_node;

    while(current_node->get_left() != nullptr)
    {
        prev = current_node;
        current_node = current_node->get_left();
    }

    //current_node = current_node->get_left();

    T value = current_node->get_value();

    prev->set_left(nullptr);

    if(current_node->get_right() != nullptr)
    {
        prev->set_left(current_node->get_right());
    }

    if(current_node == root)
    {
        root = current_node->get_right();
    }

    delete current_node;
    current_node = nullptr;

    return value;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{

}

