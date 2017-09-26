#include <iostream>
#include "AIFBS_BTreeNode.hpp"
#ifndef AIFBS_BTree_def
#define	AIFBS_BTree_def
	
namespace AIFBS {
	class AIFBS_BTree {
		AIFBS_BTreeNode *root; // Pointer to root node
		int t; // Minimum degree
	
	public:
		
		AIFBS_BTree (int _t)
		{ 
			root = NULL; 
			t = _t; 
		}
	
		void traverse()
		{ 
			if (root != NULL) 
				root->traverse(); 
		}
	
		AIFBS_BTreeNode* search(int k)
		{ 
			return (root == NULL)? NULL : root->search(k); 
		}
	
		void insert(int k);
	};
}
#endif
