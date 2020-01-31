#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <map>

using namespace std;

class Node;
typedef vector<reference_wrapper<Node>> children_t;

class Node 
{
    children_t children;

    int ident;

public:

    Node(int ident) : ident(ident) {}

    Node(const Node& n)
    {
        ident = n.ident;
        children = n.children;
    }

    int operator==(const Node& n)
    {
        return &n == this && ident == n.ident;
    }

    int getIdent()
    {
        return ident;
    }

    void addChild(Node& node)
    {
        children.push_back(ref(node));
    }

    children_t getChildren()
    {
        return children;
    }

    children_t getGrandChildren()
    {
        children_t grandChildren;

        for(auto child : children) {
            children_t gc = child.get().getChildren();
            grandChildren.insert(grandChildren.end(), gc.begin(), gc.end());
        }

        return grandChildren;
    }

    int getTotalDescendants()
    {
        children_t grandChildren = getGrandChildren();
        int descendants = grandChildren.size();

        for(auto grandChild : grandChildren) {
            descendants += grandChild.get().getTotalDescendants();
        }

        return descendants;
    }

};

int main() 
{
    int testCount = 0;

    cin >> testCount;

    int nodeCount, start, finish, totalPaths;
    string edges;

    typedef map<int, Node> nodes_t;
    nodes_t nodes;

    while(testCount--) {
        // Reset everything
        nodes.clear();
        totalPaths = 0;

        cin >> nodeCount;
        cin.ignore();

        getline(cin, edges);
        istringstream edges_ss(edges);

        while(edges_ss >> start >> finish) {
            // Ensure the 2 nodes exist in our map. If they don't, 
            // create them so we can add `finish` as a child of `start`.
            if(nodes.find(start) == nodes.end()) {
                nodes.insert(nodes_t::value_type(start, Node(start)));
            }

            if (nodes.find(finish) == nodes.end()) {
                nodes.insert(nodes_t::value_type(finish, Node(finish)));
            }

            nodes.find(start)->second.addChild(nodes.find(finish)->second);
        }

        int descendants;
        for (auto node : nodes) {
            descendants = node.second.getTotalDescendants();
            cerr << node.second.getIdent() << " has " << descendants << " descendants" << endl;
            totalPaths += descendants;
        }

        cout << totalPaths << endl;
    }

    return 0;
}