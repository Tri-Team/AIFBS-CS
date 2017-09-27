#include "AIFBS_BTreeNode.cpp"
#include "AIFBS_BTree.cpp"
#include <iostream>
#include <string>

using namespace std;
using namespace AIFBS;
int main() {
	AIFBS_BTree<string> t(3);
	t.insert("chunk1");
	t.insert("chunk2");
	t.insert("chunk3");
	t.insert("chunk4");
	t.insert("chunk5");
	t.insert("chunk6");
	t.insert("chunk7");
	t.insert("chunk8");

	cout << "Traversal of the constucted tree is ";
	t.traverse();

	string k = "chunk2";
	(t.search(k) != NULL)? cout << "\nPresent\n" : cout << "\nNot Present\n";

	k = "15";
	(t.search(k) != NULL)? cout << "\nPresent\n" : cout << "\nNot Present\n";
	// AIFBS_BTreeNode<int> n(3,true);

	return 0;
}

