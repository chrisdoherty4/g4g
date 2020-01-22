#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <sstream>

typedef std::set<std::pair<int, int>> group;
typedef std::vector<group> group_container;

void markGroupVisited(int row, int column, std::vector<std::string> &data, std::set<std::pair<int,int>> &visited)
{
    std::pair<int, int> p = std::make_pair(row, column);

    // Make sure the coordinates are within bounds.
    if(row < 0 || row >= data.size() || column < 0 || column >= data[0].size()) return;

    // Make sure we are in-fact an X
    if(data[row][column] != 'X') return;

    // Make sure we haven't already visited these coordinates.
    if(visited.find(p) != visited.end()) return;

    // Mark the node as visited.
    visited.insert(p);

    // Visit everything around the coordinates.
    markGroupVisited(row + 1, column, data, visited);
    markGroupVisited(row - 1, column, data, visited);
    markGroupVisited(row, column + 1, data, visited);
    markGroupVisited(row, column - 1, data, visited);
}

int getGroupCount(std::vector<std::string> &data)
{
    int groups = 0;
    std::set<std::pair<int, int>> visited;

    int row, column;
    for(row = 0; row < data.size(); row++) {
        for(column = 0; column < data[0].size(); column) {
            // If we have an X and we haven't visited the coordinates before, explore the new group.
            if((*data)[row][column] == 'X' && visited.find(std::make_pair(row, column)) == visited.end()) {
                markGroupVisited(row, column, data, visited);
                groups++;
            }
        }
    }

    return groups;
}

int main()
{
    int testCases = 0, mute = 0;
    std::cin >> testCases;
    std::vector<std::string> data;
    std::string t, line;

    for(int testCasesIter = 0; testCasesIter < testCases; testCasesIter++) {
        // Make sure our vector is clear from any previous test cases
        data.clear();

        std::cin >> mute;
        std::cin >> mute;
        std::cin >> t;

        std::stringstream ss(t);

        while(std::getline(ss, line, ' ')) {
            data.push_back(line);
        }

        std::cout << getGroupCount(data) << std::endl;        
    }

    return 0;
}
