#include "Node.hpp"

using namespace std;

Node::Node(int ident) : ident(ident) {}

children_t Node::getGrandChildren()
{
    children_t grandChildren;

    for(auto child : children) {
        children_t gc = child->getChildren();
        grandChildren.insert(grandChildren.end(), gc.begin(), gc.end());
    }

    return grandChildren;
}

int Node::getTotalDescendants()
{
    children_t grandChildren = getGrandChildren();
    int descendants = grandChildren.size();

    for(auto grandChild : grandChildren) {
        descendants += grandChild->getTotalDescendants();
    }

    return descendants;
}

