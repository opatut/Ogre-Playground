#ifndef NODE_HPP
#define NODE_HPP

#include <OgreVector3.h>

#include "RelativityType.hpp"

class Node {
public:
	Node();
	Node(const std::string& name);

	const Ogre::Vector3 GetPosition(RelativityType::Type rt = RelativityType::LOCAL) const;
	const Ogre::Vector3 GetScale(RelativityType::Type rt = RelativityType::LOCAL) const;
	const Ogre::Quaternion GetRotation(RelativityType::Type rt = RelativityType::LOCAL) const;

	void SetPosition(const Ogre::Vector3 position, RelativityType::Type rt = RelativityType::LOCAL);
	void SetScale(const Ogre::Vector3 scale, RelativityType::Type rt = RelativityType::LOCAL);
	void SetScale(float scale, RelativityType::Type rt = RelativityType::LOCAL);
	void SetRotation(const Ogre::Quaternion rotation, RelativityType::Type rt = RelativityType::LOCAL);

	const Node* GetParentNode() const;
	void SetParentNode(Node* node);

	bool GetEnabled() const;
	void SetEnabled(bool enabled);

	const std::string& GetName() const;
	void SetName(const std::string& name);

private:
	Ogre::Vector3 mPosition;
	Ogre::Vector3 mScale;
	Ogre::Quaternion mRotation;
	Node* mParentNode;
	bool mEnabled;
	std::string mName;
};

#endif // NODE_HPP
