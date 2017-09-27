#include "AIFBS_BTreeNode.hpp"
#include "AIFBS_BTreeNode.cpp"
namespace AIFBS {
	class AIFBS_ChunkTreeNode : public AIFBS_BTreeNode
	{
		public:
			AIFBS_ChunkTreeNode(int _t, bool _leaf)
			:AIFBS_BTreeNode(_t, _leaf)
			{

			}
	};

}