#include <vector>
#include <memory>

class Node;
typedef std::vector<std::shared_ptr<Node>> children_t;

class Node 
{
    children_t children;

    int ident;

public:

    Node(int ident);

    int operator==(const Node& n)
    {
        return &n == this && ident == n.ident;
    }

    void addChild(Node& node)
    {
        children.push_back(std::make_shared<Node>(node));
    }

    children_t getChildren()
    {
        return children;
    }

    children_t getGrandChildren() ;

    int getTotalDescendants();

};