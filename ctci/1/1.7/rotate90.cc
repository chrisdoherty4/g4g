#include <iostream>
#include <vector>
#include <cstdint>
#include <cassert>
#include <array>

using namespace std;

typedef vector<vector<uint32_t>> matrix;
typedef pair<uint16_t, uint16_t> coords;

/**
 * Calculate coordinates of a point in a matrix after rotating closwise 90d.
 * 
 * Using the top right coordinates of the matrix we can calculate where any
 * other coordinate should be in the grid. The Y coordinate in this case
 * is always 0 so we only need the X reference coordinate.
 * 
 * We negate the y from max(x)-1 because a y coordinate increment represents a
 * drop in the row of the matrix.
 */
inline coords rot90Coords(uint16_t x, uint16_t y, matrix& arr)
{
    return make_pair(arr[0].size() - 1 - y, 0 + x);
}

inline coords rot90Coords(coords pos, matrix& arr)
{
    return rot90Coords(pos.first, pos.second, arr);
}

inline uint32_t& get(coords p, matrix& arr)
{
    return arr[p.second][p.first];
}

void print(matrix& arr)
{
    for (uint16_t y = 0; y < arr.size(); y++) {
        for (uint16_t x = 0; x < arr[0].size(); x++) {
            cout << arr[y][x] << " ";
        }
        cout << endl;
    }
}

void rotate90(matrix& arr)
{
    // Make sure we're lower than y.length / 2 because we only want to iterate over
    // the top cells in each row up until the centre of the ring.
    /**
     * U U U U E    U U U E    U U E    U E
     * E U U E E    E U E E    E E E    E E
     * E E E E E    E E E E    E E E
     * E E E E E    E E E E
     * E E E E E        
     * 
     * U U U U U U U U E        U = Used
     * E U U U U U U E E        E = Excluded
     * E E U U U U E E E 
     * E E E U U E E E E
     * E E E E E E E E E
     * E E E E E E E E E
     * E E E E E E E E E
     * E E E E E E E E E
     * E E E E E E E E E
     */    
    for (uint16_t y = 0; y < (uint16_t) (arr.size() / 2); y++) {
        for (uint16_t x = y; x < arr[0].size() - y * 2 - 1; x++) {
            coords topLeft = make_pair(x, y);
            coords topRight = rot90Coords(topLeft, arr);
            coords bottomRight = rot90Coords(topRight, arr);
            coords bottomLeft = rot90Coords(bottomRight, arr);

            uint32_t temp = get(topLeft, arr);
            get(topLeft, arr) = get(bottomLeft, arr);
            get(bottomLeft, arr) = get(bottomRight, arr);
            get(bottomRight, arr) = get(topRight, arr);
            get(topRight, arr) = temp;
        }
    }
}

int main(void)
{ 
    matrix test1Input = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44}
    };

    matrix test2Input = {
        {11, 12, 13, 14, 15},
        {21, 22, 23, 24, 25},
        {31, 32, 33, 34, 35},
        {41, 42, 43, 44, 45},
        {51, 52, 53, 54, 55}
    };

    matrix test3Input = {
        {11, 12, 13, 14, 15, 16, 17, 18},
        {21, 22, 23, 24, 25, 26, 27, 28},
        {31, 32, 33, 34, 35, 36, 37, 38},
        {41, 42, 43, 44, 45, 46, 47, 48},
        {51, 52, 53, 54, 55, 56, 57, 58},
        {61, 62, 63, 64, 65, 66, 67, 68},
        {71, 72, 73, 74, 75, 76, 77, 78},
        {81, 82, 83, 84, 85, 86, 87, 88}
    };

    // matrix test1Output = {
    //     {41, 31, 21, 11},
    //     {42, 32, 22, 12},
    //     {43, 33, 23, 13},
    //     {44, 34, 24, 14},
    // };
    
    rotate90(test1Input);
    print(test1Input);

    rotate90(test2Input);
    print(test2Input);
    
    rotate90(test3Input);
    print(test3Input);

    
    //assert(test1Input == test1Output);

    return 0;
}