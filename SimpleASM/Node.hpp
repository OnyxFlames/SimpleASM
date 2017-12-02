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
	std::string value = "";
	std::vector<Node*> children;
	Node* parent = nullptr;
};

