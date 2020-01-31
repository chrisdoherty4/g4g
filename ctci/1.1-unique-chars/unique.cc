#include <iostream>
#include <cstring>

using namespace std;

#define LEGAL_CHARACTER_COUNT 26

// Assumptions:
// - Input strings are all lowercase
int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        cout << "Program accepts 1 argument" << endl;
        return 1;
    }

    int counts[LEGAL_CHARACTER_COUNT] = { 0 };

    for (int i = 0; i < strlen(argv[1]); i++) {
        if(++counts[argv[1][i] % 26] > 1) {
            cout << "not unique" << endl;
            return 0;
        }
    }

    cout << "unique" << endl;
    return 0;
}