#pragma once

#include "stdafx.h"
#include <iostream>



template <typename KEY, typename ELEMENT>
class Node
{
public:
	Node() 
	{
		left = NULL;
		right = NULL;
		parent = NULL;
	};

	void SetKey(KEY k) 
		{
			this->key = k;
		};

	void SetElement(ELEMENT e) 
		{
			this->elem = e;
		};

	void SetLeft(Node* l) 
		{
			left = l;
		};

	void SetRight(Node* r) 
		{
			right = r;
		};

	void SetParent(Node* p) 
		{
			parent = p;
		};

	KEY GetKey() 
		{
			return key;
		};

	ELEMENT GetElement() 
		{
			return elem;
		};

	Node* GetLeft() 
		{
			return left;
		};

	Node* GetRight() 
		{
			return right;
		};

	Node* GetParent() 
		{
			return parent;
		};

	

	inline bool operator==(const Node& n2){
		if (this->GetKey() == n2->GetKey()){
			if (this->GetElement().getLeft() == n2->GetElement().getLeft()){
				if (this->GetElement().getRight() == n2->GetElement().getRight()){
					return true;
				}
			}
		}

		return false;
	}

private:
	KEY key;
	ELEMENT elem;
	Node* left;
	Node* right;
	Node* parent;
};

template <typename KEY, typename ELEMENT>
class BST
{
public:
	/*
	Description: creates a new binary search tree and initializes the root
	Data: -
	Precondition: -
	Postcondition: -
	 * */
	BST(void);

	/*
	Description: deallocates the memory for the BST
	Data: -
	Precondition: -
	Postcondition: -
	*/
	~BST(void);

	/*Description: returns the root of the binary search tree
	Data: -
	Precondition: -
	Postcondition: n is Node
	Result: n
	 * */
	Node<KEY, ELEMENT>* GetRoot()
	{
		return root;
	}

	/*Description: adds a new node (with key and element) to the tree
	Data: k, e
	Precondition: k is Key, e is TElement
	Postcondition: -
	 * */
	void AddNode(KEY k, ELEMENT e);

	/*Description: searches for a node with the specified key and then returns the node
	Data: k, n
	Precondition: k is Key, n is Node
	Postcondition: no is Node or NIL
	Result: no or NIL
	 * */
	Node<KEY, ELEMENT>* FindNode (KEY k, Node<KEY, ELEMENT>* parent);

	/*Description: deletes a node from a binary search tree and rearranges the tree to be properly
	                   constructed
		       there are 3 cases: - if it’s just a leaf
	                              - if it has one child
								  - if it has two children
	  Data: k
	  Precondition: k is Key
	  Postcondition: -
		 * */
	void DeleteNode(KEY k);

	/*Description: Finds the node with the minimum key value
	         Traverses the left subtree recursively until the left subtree is empty
	Data: n
	Precondition: n is Node
	Postcondition: no is Node or NIL
	Result: no or NIL
	 * */
	Node<KEY, ELEMENT>* MinimumKey(Node<KEY, ELEMENT>* node);

	/*Description: Finds the node with the maximum key value
	         Traverses the right subtree recursively until the right subtree is empty
	Data: n
	Precondition: n is Node
	Postcondition: no is Node or NIL
	Result: no or NIL
	 * */
	Node<KEY, ELEMENT>* MaximumKey(Node<KEY, ELEMENT>* node);

	/*Description: Finds the successor of a node
	Find the node, get the node with the max key for the right subtree to get the successor
	Data: k, n
	Precondition: k is Key, n is Node
	Postcondition: no is Node or NIL
	Result: no or NIL
	 * */
	Node <KEY, ELEMENT>* Successor(KEY k, Node<KEY, ELEMENT>* parent);

	/*Description: Finds the predecessor of a node
	          Find the node, get the node with the max value for the left subtree to get the predecessor
	Data: k, n
	Precondition: k is Key, n is Node
	Postcondition: no is Node or NIL
	Result: no or NIL
	 * */
	Node<KEY, ELEMENT>* Predecessor(KEY k, Node<KEY, ELEMENT>* parent);

	/*Description: walks in the tree, onLevels (prints the tree)
	Data: n
	Precondition: n is Node
	Postcondition: -

	 * */
	void Walk(Node <KEY, ELEMENT>* e);

	/*Description: returns the nubmer of nodes
	Data: size 
	Precondition: size is an unsigned int
	Postcondition: -
	* */
	int getSize();


	void remove(KEY value);
private:
	Node<KEY, ELEMENT>* root;
	unsigned int size;
	/*Description: adds a new Node only if the new node is not the root
	Data: k, e, n
	Precondition: k is Key, e is TElement, n is Node
	Postcondition: -
	 * */
	void AddNode(KEY K, ELEMENT e, Node<KEY, ELEMENT>* leaf);

	/*Description: frees the memory and then deletes the tree
	Data: n
	Precondition: n is Node
	Postcondition: -
	 * */
	void FreeNode(Node<KEY, ELEMENT>* leaf);

};



template <typename KEY, typename ELEMENT>
int BST<KEY, ELEMENT>::getSize(){
	return this->size;
}

template <typename KEY, typename ELEMENT>
BST<KEY, ELEMENT>:: BST()
{
	size = 0;
	root = NULL;
};

template <typename KEY, typename ELEMENT>
BST<KEY, ELEMENT>::~BST()
{
	FreeNode(root);
};

template <typename KEY, typename ELEMENT>
void BST<KEY, ELEMENT>::FreeNode(Node<KEY, ELEMENT>* leaf)
{
	if (leaf != NULL)
	{
		FreeNode(leaf->GetLeft());
		FreeNode(leaf->GetRight());
		delete leaf;
	}
};

template <typename KEY, typename ELEMENT>
void BST<KEY, ELEMENT>::AddNode(KEY k, ELEMENT e)
{
	if (this->root == NULL)
	{
		Node<KEY, ELEMENT>* n = new Node<KEY, ELEMENT>();
		n->SetKey(k);
		n->SetElement(e);
		this->root = n;
	}
	else
		AddNode(k, e, root);
};

template <typename KEY, typename ELEMENT>
void BST<KEY, ELEMENT>::AddNode(KEY k, ELEMENT e, Node<KEY, ELEMENT>* leaf)
{
	
	if (k <= leaf->GetKey())
	{
		if (leaf->GetLeft() != NULL)
		{
			AddNode(k, e, leaf->GetLeft());
		}
		else
		{
			Node<KEY, ELEMENT>* n = new Node<KEY, ELEMENT>();
			n->SetKey(k);
			n->SetElement(e);
			n->SetParent(leaf);
			leaf->SetLeft(n);
		}
	}

	else
	{
		if (leaf->GetRight() != NULL)
		{
			AddNode(k, e, leaf->GetRight());
		}
		else
		{
			Node<KEY, ELEMENT>* n = new Node<KEY, ELEMENT>();
			n->SetKey(k);
			n->SetElement(e);
			n->SetParent(leaf);
			leaf->SetRight(n);
		}
	}

};

template <typename KEY, typename ELEMENT>
Node<KEY, ELEMENT>* BST<KEY, ELEMENT>::FindNode(KEY k, Node<KEY, ELEMENT>* node)
{
	
	if (node == NULL)
		return NULL;
	else if ( node->GetKey() == k)
		return node;
	else if (k<=node->GetKey())
		return FindNode(k, node->GetLeft());
	else if (k > node->GetKey())
		return FindNode(k, node->GetRight());
	else
		return NULL;
}

template <typename KEY, typename ELEMENT>
Node<KEY, ELEMENT>* BST<KEY, ELEMENT>::MinimumKey(Node<KEY, ELEMENT>* node)
{
	if (node == NULL)
		return NULL;

	if (node->GetLeft())
		MinimumKey(node->GetLeft());
	else
		return node;
};

template <typename KEY, typename ELEMENT>
Node<KEY, ELEMENT>* BST<KEY, ELEMENT>::MaximumKey(Node<KEY, ELEMENT>* node)
{
	if (node == NULL)
		return NULL;

	if (node->GetRight())
		MaximumKey(node->GetRight());
	else
		return node;
};

template <typename KEY, typename ELEMENT>
Node<KEY, ELEMENT>* BST<KEY, ELEMENT>::Successor(KEY k, Node<KEY, ELEMENT>* node)
{
	Node <KEY, ELEMENT>* thiskey = FindNode(k, node);

	if (thiskey != NULL)
		return MaximumKey(thiskey->GetRight());

	return NULL;
};

template <typename KEY, typename ELEMENT>
Node<KEY, ELEMENT>* BST<KEY, ELEMENT>::Predecessor(KEY k, Node<KEY, ELEMENT>* node)
{
	Node <KEY, ELEMENT>* thiskey = FindNode(k, node);

	if (thiskey != NULL)
		return MaximumKey(thiskey->GetLeft());

	return NULL;
};

template <typename KEY, typename ELEMENT>
void BST<KEY, ELEMENT>::DeleteNode(KEY k)
{
	Node<KEY, ELEMENT>* thisKey = FindNode(k, this->root);

	if (thisKey == this->root){

		if (root->GetLeft() != NULL){
			root = root->GetLeft();
		}
		else{
			root = root->GetRight();
		}

		delete thisKey;
		return;
	}

	if (thisKey->GetLeft() == NULL && thisKey->GetRight() == NULL)
	{
		if (thisKey->GetKey() > thisKey->GetParent()->GetKey())
			thisKey->GetParent()->SetRight(NULL);
		else
			thisKey->GetParent()->SetLeft(NULL);

		delete thisKey;
		return;
	}


	if (thisKey->GetLeft() == NULL && thisKey->GetRight() != NULL)
	{
		if (thisKey->GetKey() > thisKey->GetParent()->GetKey())
			thisKey->GetParent()->SetRight(thisKey->GetRight());
		else
			thisKey->GetParent()->SetLeft(thisKey->GetRight());

		thisKey->GetRight()->SetParent(thisKey->GetParent());

		delete thisKey;
		return;
	}

	if (thisKey->GetLeft() != NULL && thisKey->GetRight() == NULL)
	{
		if (thisKey->GetKey() > thisKey->GetParent()->GetKey())
			thisKey->GetParent()->SetRight(thisKey->GetLeft());
		else
			thisKey->GetParent()->SetLeft(thisKey->GetLeft());

		thisKey->GetLeft()->SetParent(thisKey->GetParent());

		delete thisKey;
		return;
	}


	if (thisKey->GetLeft() != NULL && thisKey->GetRight() != NULL)
	{
		Node<KEY, ELEMENT>* sub = Predecessor(thisKey->GetKey(), thisKey);

		if (sub == NULL)
			sub = Successor(thisKey->GetKey(), thisKey);

		if (sub->GetParent()->GetKey() <= sub->GetKey())
			sub->GetParent()->SetRight(sub->GetRight());
		else
			sub->GetParent()->SetLeft(sub->GetLeft());

		thisKey->SetKey(sub->GetKey());
		thisKey->SetElement(sub->GetElement());
		delete sub;
	}
};

template <typename KEY, typename ELEMENT>
void BST<KEY, ELEMENT>::Walk(Node<KEY, ELEMENT>* node)
{
	if (node != NULL)
	{
		Walk(node->GetLeft());
		std::cout << node->GetKey() << " ";
		Walk(node->GetRight());
	}
};


		