#pragma once

#include <string>
#include <vector>
#include <memory>



class Node
{
public:
	typedef std::unique_ptr<Node> Ptr;
	Node();
	~Node();
private:
	std::string value = "";
	std::vector<Ptr> children;
	Node* parent = nullptr;
public:
	void attachChild(Ptr child);
	Ptr detachChild(const Node& node);
};

