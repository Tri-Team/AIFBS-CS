#ifndef AIFBS_BTreeNode_def
#define	AIFBS_BTreeNode_def
	
namespace AIFBS {
	class AIFBS_BTreeNode {
		
		int *keys;
		int t;	 // Minimum degree (defines the range for number of keys)
		AIFBS_BTreeNode **C; // An array of child pointers
		bool leaf; 
		int n;	 // Current number of keys
	public:
		AIFBS_BTreeNode(int _t, bool _leaf);
	
		void insertNonFull(int k);
	
		// A utility function to split the child y of this node. i is index of y in
		// child array C[]. The Child y must be full when this function is called
		void splitChild(int i, AIFBS_BTreeNode *y);
	
		void traverse();
	
		// A function to search a key in subtree rooted with this node.
		AIFBS_BTreeNode *search(int k); // returns NULL if k is not present.
	
	friend class AIFBS_BTree;
	friend class AIFBS_FileTree;
	friend class AIFBS_ChunkTree;
	};
}
#endif
