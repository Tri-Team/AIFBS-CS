#ifndef AIFBS_CS_DEF
#define AIFBS_CS_DEF

#include "AIFBS_CS.hpp"
namespace AIFBS
{
	void AIFBS_CS::insert(std::string t_name, int payload) {
		SplittedNames sn = split(t_name);
		AIFBS_FileNodeKey tempNode;
		tempNode.setKey(sn.m_fileName);

		AIFBS_FileNodeKey *fileNodeKey = fileTree->searchKeyRef(tempNode);

		if(fileNodeKey == NULL) {
			AIFBS_BTree<AIFBS_ChunkNodeKey> chunkTree(m_chunkT);
			AIFBS_FileNodeKey newFileNodeKey(sn.m_fileName, &chunkTree);
			fileTree->insert(newFileNodeKey);
			fileNodeKey = &newFileNodeKey;
		}

		AIFBS_ChunkNodeKey chunkNodeKey;
		chunkNodeKey.setKey(sn.m_chunkName);
		fileNodeKey->m_chunkTree->insert(chunkNodeKey);
	}

	SplittedNames AIFBS_CS::split(std::string name) {
		int index;
		for(int i = (name.size()-1); i>=0;i--) {
			if(name.at(i) == '/') {
				index = i;
				break;
			}
		}
		
		SplittedNames SN;
		SN.m_fileName = name.substr(0, index-1);
		SN.m_chunkName = name.substr(index+1, name.size()-1);

		return SN;
	}
}
#endif