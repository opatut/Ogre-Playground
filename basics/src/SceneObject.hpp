#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP

#include <boost/ptr_container/ptr_vector.hpp>

#include "Node.hpp"
#include "IComponent.hpp"

typedef boost::ptr_vector<IComponent> ComponentList;

class SceneObject : public Node {
public:
    SceneObject();

private:
	ComponentList mComponents;
};

#endif // SCENEOBJECT_HPP
