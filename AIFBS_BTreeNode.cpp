#include <iostream>
#include "AIFBS_BTreeNode.hpp"
namespace AIFBS {
	
	/**
	*	Implentations
	*	All Tree Node Base definations
	**/
	
	template <class T>
	AIFBS_BTreeNode<T>::AIFBS_BTreeNode(int t1, bool leaf1)
	{
		n = 0;
		
		t = t1;
		leaf = leaf1;
	
		keys = new T[2*t-1];
		C = new AIFBS_BTreeNode<T> *[2*t];
	}
	
	template <class T>
	void AIFBS_BTreeNode<T>::traverse()
	{
		int i;
		for (i = 0; i < n; i++)
		{
			if (leaf == false)
				C[i]->traverse();
			std::cout << " " << keys[i];
		}
	
		if (leaf == false)
			C[i]->traverse();
	}

	template <class T>
	AIFBS_BTreeNode<T> *AIFBS_BTreeNode<T>::search(T k)
	{
		// Find the first key greater than or equal to k
		int i = 0;
		while (i < n && k > keys[i])
			i++;
	
		// If the found key is equal to k, return this node
		if (keys[i] == k)
			return this;
	
		// If key is not found here and this is a leaf node
		if (leaf == true)
			return NULL;
	
		// Go to the appropriate child
		return C[i]->search(k);
	}



	template <class T>
	void AIFBS_BTreeNode<T>::insertNonFull(T k)
	{
		// Initialize index as index of rightmost element
		int i = n-1;
	
		// If this is a leaf node
		if (leaf == true)
		{
			// The following loop does two things
			// a) Finds the location of new key to be inserted
			// b) Moves all greater keys to one place ahead
			while (i >= 0 && keys[i] > k)
			{
				keys[i+1] = keys[i];
				i--;
			}
	
			// Insert the new key at found location
			keys[i+1] = k;
			n = n+1;
		}
		else // If this node is not leaf
		{
			// Find the child which is going to have the new key
			while (i >= 0 && keys[i] > k)
				i--;
	
			// See if the found child is full
			if (C[i+1]->n == 2*t-1)
			{
				// If the child is full, then split it
				splitChild(i+1, C[i+1]);
	
				// After split, the middle key of C[i] goes up and
				// C[i] is splitted into two. See which of the two
				// is going to have the new key
				if (keys[i+1] < k)
					i++;
			}
			C[i+1]->insertNonFull(k);
		}
	}
	
	// A utility function to split the child y of this node
	// Note that y must be full when this function is called
	template <class T>
	void AIFBS_BTreeNode<T>::splitChild(int i, AIFBS_BTreeNode *y)
	{
		// Create a new node which is going to store (t-1) keys
		// of y
		AIFBS_BTreeNode<T> *z = new AIFBS_BTreeNode<T>(y->t, y->leaf);
		z->n = t - 1;
	
		// Copy the last (t-1) keys of y to z
		for (int j = 0; j < t-1; j++)
			z->keys[j] = y->keys[j+t];
	
		// Copy the last t children of y to z
		if (y->leaf == false)
		{
			for (int j = 0; j < t; j++)
				z->C[j] = y->C[j+t];
		}
	
		// Reduce the number of keys in y
		y->n = t - 1;
	
		// Since this node is going to have a new child,
		// create space of new child
		for (int j = n; j >= i+1; j--)
			C[j+1] = C[j];
	
		// Link the new child to this node
		C[i+1] = z;
	
		// A key of y will move to this node. Find location of
		// new key and move all greater keys one space ahead
		for (int j = n-1; j >= i; j--)
			keys[j+1] = keys[j];
	
		// Copy the middle key of y to this node
		keys[i] = y->keys[t-1];
	
		// Increment count of keys in this node
		n = n + 1;
	}
}
