#include "Root.hpp"

Root::Root() {
	mRootNode.SetName("_ROOT");
}

Node* Root::GetRootNode() {
	return &mRootNode;
}

Node* Root::GetNodeByName(const std::string& name) {
	for(auto iter = mNodes.begin(); iter != mNodes.end(); ++iter) {
		if(iter->GetName() == name) {
			return &(*iter);
		}
	}
	return NULL;
}

Node* Root::CreateNode(const std::string& name) {
	assert(GetNodeByName(name) == NULL); // A node with that name already exists.

	Node* n = new Node(name);
	n->SetParentNode(&mRootNode);
	mNodes.push_back(n);
	return &(mNodes.back());
}
