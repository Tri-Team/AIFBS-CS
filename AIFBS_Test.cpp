#include "AIFBS_CS.hpp"

using namespace std;
using namespace AIFBS;
int main() {

	//region Test 1
		// AIFBS_BTree<string> t(3);
		// t.insert("chunk1");
		// t.insert("chunk2");
		// t.insert("chunk3");
		// t.insert("chunk4");
		// t.insert("chunk5");
		// t.insert("chunk6");
		// t.insert("chunk7");
		// t.insert("chunk8");

		// cout << "Traversal of the constucted tree is ";
		// t.traverse();

		// string k = "chunk2";
		// (t.search(k) != NULL)? cout << "\nPresent\n" : cout << "\nNot Present\n";

		// k = "15";
		// (t.search(k) != NULL)? cout << "\nPresent\n" : cout << "\nNot Present\n";
	//endregion


	//region With Custom ChunkNodeKey
		// AIFBS_BTree<AIFBS_ChunkNodeKey> t(3);
		// AIFBS_BTree<AIFBS_ChunkNodeKey> t2(3);
		// AIFBS_ChunkNodeKey c, c2, c3, c4, c5;
		// c2.setKey("abcd");
		// c.setKey("aBcd");
		// c3.setKey("aBcd");
		// c4.setKey("Zbcd");
		// c5.setKey("abCd");
		// t.insert(c);
		// t.insert(c2);
		// t2.insert(c3);
		// t2.insert(c4);
		// t.insert(c5);

		// // t.traverse();

		// AIFBS_BTree<AIFBS_FileNodeKey> filetree(3);
		// AIFBS_FileNodeKey filetreeNode1("file1", &t);
		// AIFBS_FileNodeKey filetreeNode2("file2", &t2);
		// filetree.insert(filetreeNode1);
		// filetree.insert(filetreeNode2);

		// filetree.traverse();
	//endregion

	//region Inserting files with chunk names
		//Building a Scenario
//		AIFBS_CS cs(3);
//
//		cs.insert("cd/cfd/file1/chunk1", 1);
//		cs.insert("cd/cfd/file1/chunk3", 1);
//		cs.insert("cd/cfd/file1/chunk2", 1);
//		cs.insert("cd/cfd/file1/chunk4", 1);
//		
//		cs.insert("cd/cfd/file2/chunk3", 1);
//		cs.insert("cd/cfd/file2/chunk1", 1);
//		cs.insert("cd/cfd/file2/chunk2", 1);
//
//		cs.insert("cd/cfd/file3/chunk4", 1);
//		cs.insert("cd/cfd/file3/chunk1", 1);
//		cs.insert("cd/cfd/file3/chunk9", 1);
//		
//		cs.traverse();
		
	//endregion		
		
	//region Inserting files and searching chunks
		AIFBS_CS cs(3);

		cs.insert("cd/cfd/file1/chunk1", 1);
		cs.insert("cd/cfd/file1/chunk3", 1);
		cs.insert("cd/cfd/file1/chunk2", 1);
		cs.insert("cd/cfd/file1/chunk4", 1);
		
		cs.insert("cd/cfd/file2/chunk3", 1);
		cs.insert("cd/cfd/file2/chunk1", 1);
		cs.insert("cd/cfd/file2/chunk2", 1);

		cs.insert("cd/cfd/file3/chunk4", 1);
		cs.insert("cd/cfd/file3/chunk1", 1);
		cs.insert("cd/cfd/file3/chunk9", 1);
		
		cs.traverse();
		
		AIFBS_ChunkNodeKey* requiredChunk = cs.find("cd/cfd/tempFile/chunk4"); //not found case
		//AIFBS_ChunkNodeKey* requiredChunk = cs.find("cd/cfd/file2/chunk3"); //found case
		if(requiredChunk != NULL)
			cout<<"\n\nChunk found: "<<requiredChunk->getKey()<<endl;
		else
			cout<<"\n\nChunk not found."<<endl;
	//endregion
			
	//region Splitting names test
		// SplittedNames sn = cs.split("cd/cfd/file1/chunk1");
		// cout<<sn.m_fileName<<" "<<sn.m_chunkName;

	//endregion


	return 0;
}

