#include <iostream>
#include <cstring>

using namespace std;

#define MAX_CHAR_COUNT 26

#define PERMUTATION_MSG(s1, s2, msg) cout << s1 << msg << s2 << endl
#define IS_PERMUTATION(s1, s2) PERMUTATION_MSG(s1, s2, " is a permutation of ")
#define NOT_PERMUTATION(s1, s2) PERMUTATION_MSG(s1, s2, " is not a permutation of ")

// Assumptions:
// - strings are lower case characters only.
int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "Expects 2 arguments; got " << argc << endl;
    }

    if (strlen(argv[1]) != strlen(argv[2])) {
        NOT_PERMUTATION(argv[1], argv[2]);
        return 0;
    }

    int s1_count[MAX_CHAR_COUNT] = {0};
    int s2_count[MAX_CHAR_COUNT] = {0};

    for (int i = 0; i < strlen(argv[1]); i++) {
        s1_count[argv[1][i] % MAX_CHAR_COUNT]++;
        s2_count[argv[2][i] % MAX_CHAR_COUNT]++;
    }

    for (int i = 0; i < MAX_CHAR_COUNT; i++) {
        if (s1_count[i] != s2_count[i]) {
            NOT_PERMUTATION(argv[1], argv[2]);
            return 0;
        }
    }

    IS_PERMUTATION(argv[1], argv[2]);

    return 0;
}