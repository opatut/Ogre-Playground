#include "Node.hpp"

Node::Node() {
	mParentNode = NULL;
}

Node::Node(const std::string& name) {
	mParentNode = NULL;
	mName = name;
}

const Ogre::Vector3 Node::GetPosition(RelativityType::Type rt) const {
	if(rt == RelativityType::LOCAL || mParentNode == NULL) {
		return mPosition;
	} else {
		return mPosition + mParentNode->GetPosition(RelativityType::GLOBAL);
	}
}

const Ogre::Vector3 Node::GetScale(RelativityType::Type rt) const {
	if(rt == RelativityType::LOCAL || mParentNode == NULL) {
		return mScale;
	} else {
		return mScale * mParentNode->GetScale(RelativityType::GLOBAL);
	}
}

const Ogre::Quaternion Node::GetRotation(RelativityType::Type rt) const {
	if(rt == RelativityType::LOCAL || mParentNode == NULL) {
		return mRotation;
	} else {
		return mRotation * mParentNode->GetRotation(RelativityType::GLOBAL); // watch the order: second rotation * first rotation
	}
}

void Node::SetPosition(const Ogre::Vector3 position, RelativityType::Type rt) {
	if(rt == RelativityType::LOCAL || mParentNode == NULL) {
		mPosition = position;
	} else {
		mPosition = position - mParentNode->GetPosition(RelativityType::GLOBAL);
	}
}

void Node::SetScale(const Ogre::Vector3 scale, RelativityType::Type rt) {
	if(rt == RelativityType::LOCAL || mParentNode == NULL) {
		mScale = scale;
	} else {
		mScale = scale - mParentNode->GetScale(RelativityType::GLOBAL);
	}
}

void Node::SetScale(float scale, RelativityType::Type rt) {
	SetScale(Ogre::Vector3(scale,scale,scale), rt);
}

void Node::SetRotation(const Ogre::Quaternion rotation, RelativityType::Type rt) {
	if(rt == RelativityType::LOCAL || mParentNode == NULL) {
		mRotation = rotation;
	} else {
		mRotation = rotation * mParentNode->GetRotation(RelativityType::GLOBAL).Inverse();
	}
}

const Node* Node::GetParentNode() const {
	return mParentNode;
}

void Node::SetParentNode(Node* node) {
	mParentNode = node;
}


bool Node::GetEnabled() const {
	return mEnabled;
}

void Node::SetEnabled(bool enabled) {
	mEnabled = enabled;
}

const std::string& Node::GetName() const {
	return mName;
}

void Node::SetName(const std::string& name) {
	mName = name;
}
