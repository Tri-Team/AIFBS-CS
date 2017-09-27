#include <iostream>
#include "AIFBS_BTreeNode.hpp"
#ifndef AIFBS_BTree_def
#define	AIFBS_BTree_def
	
namespace AIFBS {
	template<class T>
	class AIFBS_BTree {
		AIFBS_BTreeNode<T> *root; // Pointer to root node
		int t; // Minimum degree
	
	public:
		
		AIFBS_BTree<T> (int _t)
		{ 
			root = NULL; 
			t = _t; 
		}
	
		void traverse()
		{ 
			if (root != NULL) 
				root->traverse(); 
		}
	
		AIFBS_BTreeNode<T>* search(T k)
		{ 
			return (root == NULL)? NULL : root->search(k); 
		}
	
		void insert(T k);
	};
}
#endif
