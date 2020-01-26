#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <map>

using namespace std;

class Node;
typedef vector<shared_ptr<Node>> children_t;

class Node 
{
    children_t children;

    int ident;

    Node() {}

public:
    Node(int ident) : ident(ident) {}

    void addChild(Node& node)
    {
        children.push_back(make_shared<Node>(node));
    }

    children_t getChildren()
    {
        return children;
    }

    children_t getGrandChildren() {
        children_t grandChildren;

        for(auto child : children) {
            children_t gc = child->getChildren();
            grandChildren.insert(grandChildren.end(), gc.begin(), gc.end());
        }

        return grandChildren;
    }

    int getTotalDescendants()
    {
        children_t grandChildren = getGrandChildren();
        int descendants = grandChildren.size();

        for(auto grandChild : grandChildren) {
            descendants += grandChild->getTotalDescendants();
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

    map<int, Node> nodes;

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
                nodes[start] = Node(start);
            }

            if (nodes.find(finish) == nodes.end()) {
                nodes[finish] = Node(finish);
            }

            nodes[start].addChild(nodes[finish]);
        }

        for (auto node : nodes) {
            totalPaths += node.second.getTotalDescendants();
        }

        cout << totalPaths << endl;
    }

    return 0;
}