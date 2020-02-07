#include <iostream>
#include <vector>
#include <cstdint>
#include <set>

using namespace std;

typedef vector<vector<uint16_t>> matrix;

void zero(matrix& m)
{
    // Iterate over every element recording which rows and columns need zeroing.
    // Iteate over data again zeroing elements when x or y vaules are in recorded 0 x or y
    // O(m x n)
    
    // Possible optimizations
    // Record if an x or y is to be zeroed and don't evaluate an element if it's x,y falls into that.

    set<uint16_t> xCoordTracker;
    set<uint16_t> yCoordTracker;

    for (int y = 0; y < m.size(); ++y) {
        if (yCoordTracker.find(y) != yCoordTracker.end())
            continue;

        for (int x = 0; x < m[0].size(); ++x) {
            if (m[y][x] == 0) {
                xCoordTracker.insert(x);
                yCoordTracker.insert(y);
                break;
            }
        }
    }

    for (int y = 0; y < m.size(); ++y) {
        for (int x = 0; x < m[0].size(); ++x) {
            if (xCoordTracker.find(x) != xCoordTracker.end() || yCoordTracker.find(y) != yCoordTracker.end()) {
                m[y][x] = 0;
            }
        }
    }
}

inline void printMatrix(matrix& m) 
{
    for (int y = 0; y < m.size(); ++y) {
        for (int x = 0; x < m[0].size(); ++x) {
            cout << m[y][x] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    matrix test1 = {
        {0,1,1,1},
        {1,1,1,1},
        {1,1,0,1},
        {1,1,1,1},
        {1,1,1,1}
    };

    printMatrix(test1);

    zero(test1);

    cout << endl;
    printMatrix(test1);
}