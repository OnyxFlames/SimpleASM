#include "Node.hpp"

#include <cassert>
#include <algorithm>


Node::Node()
{
}


Node::~Node()
{
}

void Node::attachChild(Node::Ptr child)
{
	child->parent = this;
	children.push_back(std::move(child));
}

Node::Ptr Node::detachChild(const Node & node)
{
	auto found = std::find_if(children.begin(), children.end(),
		[&](Ptr& p) -> bool { return p.get() == &node; });

	assert(found != children.end());

	Ptr result = std::move(*found);
	result->parent = nullptr;
	children.erase(found);
	return result;
}
