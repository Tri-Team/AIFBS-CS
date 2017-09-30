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
			AIFBS_BTree<AIFBS_ChunkNodeKey> *chunkTree = new AIFBS_BTree<AIFBS_ChunkNodeKey>(m_chunkT);
			AIFBS_FileNodeKey newFileNodeKey(sn.m_fileName, chunkTree);
			fileTree->insert(newFileNodeKey);
			fileNodeKey = &newFileNodeKey;
		}

		AIFBS_ChunkNodeKey *chunkNodeKey = new AIFBS_ChunkNodeKey();
		chunkNodeKey->setKey(sn.m_chunkName);
		fileNodeKey->m_chunkTree->insert(*chunkNodeKey);
	}
	
	AIFBS_ChunkNodeKey* AIFBS_CS::find(std::string t_name){
		SplittedNames sn = split(t_name);
		AIFBS_FileNodeKey tempFileKey;
		tempFileKey.setKey(sn.m_fileName);
		AIFBS_FileNodeKey *fileNodeKey = fileTree->searchKeyRef(tempFileKey);
		if(fileNodeKey == NULL) {
			//required file does not exists and therefore chunks does not exists
			return NULL;
		}
		else {
			AIFBS_ChunkNodeKey tempChunkKey;
			tempChunkKey.setKey(sn.m_chunkName);
			AIFBS_ChunkNodeKey* requiredChunk = fileNodeKey->m_chunkTree->searchKeyRef(tempChunkKey);
			if(requiredChunk == NULL){
				//required chunk not found
				return NULL;
			}
			else{
				return requiredChunk;
			}
		}
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
		SN.m_fileName = name.substr(0, index);
		SN.m_chunkName = name.substr(index+1, name.size()-1);

		return SN;
	}
}
#endif
