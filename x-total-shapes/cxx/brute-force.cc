#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>

typedef std::set<std::pair<int, int>> group;
typedef std::vector<group> group_container;

void exploreGroup(int n, int m, std::vector<std::string>> *data, std::vector<std::pair<int,int>> *visited)
{

}

int getGroupCount(int nMax, int mMax, std::vector<std::string>> *data)
{
    // Loop over everything
    // If there's _not_ a group containing coords, create a new one
    //  Inspect surrounding coordinates for Xs and add them too
    // Else we are part of a group, inspect surrounding coords
    // and add if X

    int groups = 0;
    std::vector<std::pair<int, int>> visited;

    int n, m;
    for(n = 0; n < nMax; n++) {
        for(m = 0; m < mMax; m++) {
            std::pair<int, int> p = std::make_pair(n, m);

            if(*data[n][m] == 'X' && visited.find(p) != visited.end())
                exploreGroup(n, m, data, &visited);
        }
    }
}

int main()
{
    int testCases = 0;
    std::cin >> testCases;

    int n = 0;
    int m = 0;
    std::vector<std::string>> data;

    for(int testCasesIter = 0; testCasesIter < testCases; testCasesIter++) {
        std::cin >> n;
        std::cin >> m;

        // Make sure our vector is clear from any previous test cases
        data.clear()

        // Get rid of the remaining whitespace after cin >> calls
        std::cin.ignore();

        for(std::string line; std::getline(std::cin, line, ' ');) {
            data.push_back(line)
        }
    }

    return 0;
}
