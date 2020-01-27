#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <map>
#include "Node.hpp"

using namespace std;

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
                nodes.insert(map<int, Node>::value_type (start, Node(start)));
            }

            if (nodes.find(finish) == nodes.end()) {
                nodes.insert(map<int, Node>::value_type (finish, Node(finish)));
            }

            nodes.find(start)->second.addChild(nodes.find(finish)->second);
        }

        for (auto node : nodes) {
            totalPaths += node.second.getTotalDescendants();
        }

        cout << totalPaths << endl;
    }

    return 0;
}