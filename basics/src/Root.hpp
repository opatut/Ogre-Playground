#ifndef ROOT_HPP
#define ROOT_HPP

#include <boost/ptr_container/ptr_vector.hpp>

#include <OgreSceneNode.h>

#include "Node.hpp"

typedef boost::ptr_vector<Node> NodeList;

class Root{
public:
	Root();

	Node* GetRootNode();

	Node* GetNodeByName(const std::string& name);
	Node* CreateNode(const std::string& name);
private:
	Node mRootNode;
	NodeList mNodes;
};

#endif // ROOT_HPP
