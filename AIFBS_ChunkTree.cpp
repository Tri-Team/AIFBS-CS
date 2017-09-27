#include "AIFBS_BTree.hpp"
#include "AIFBS_BTree.cpp"
namespace AIFBS {
	class AIFBS_ChunkTree : public AIFBS_BTree
	{

		public:
			AIFBS_ChunkTree (int _t)
			:AIFBS_BTree(_t)
			{

			}
	};

}