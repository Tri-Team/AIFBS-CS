#include "AIFBS_ChunkTreeNode.cpp"
#include "AIFBS_ChunkTree.cpp"
#include <iostream>

using namespace std;
using namespace AIFBS;
int main() {
	AIFBS_ChunkTree t(3);
	t.insert(10);
	t.insert(20);
	t.insert(5);
	t.insert(6);
	t.insert(12);
	t.insert(30);
	t.insert(7);
	t.insert(17);

	cout << "Traversal of the constucted tree is ";
	t.traverse();

	int k = 6;
	(t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present\n";

	k = 15;
	(t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present\n";

	return 0;
}

