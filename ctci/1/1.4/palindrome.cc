#include <iostream>
#include <cstdint>
#include <cstring>

using namespace std;

bool palindromePermutation(char* str, size_t sz)
{
    // Solution 1
    // Discount spaces
    // Check how many times each character appears
    // Odd char count;
    //   Check each char for mod 2 = 0 and allow 1 char where charCount mod 2 = 1
    // Even char count:
    //   Every char should be charCount mod 2 = 0

    // Allocate array and assume we have an ascii string with lower case alphabet chars only
    uint8_t charCounts[26] = { 0 };

    // Run up a char count.
    for (int16_t i = 0; i < sz; i++) {
        charCounts[str[i] - 'a']++;
    }

    uint16_t oddCount = 0;

    for (int16_t i = 0; i < sz; i++) {
        if (charCounts[i] % 2 != 0) {
            oddCount++;
        }
    } 

    return oddCount <= 1;
}


int main(int argc, char* argv[])
{

    #define BUFFER_SZ 25
    char testSuccess[BUFFER_SZ] = "acbed abdc";
    char testFailure[BUFFER_SZ] = "not a palindrome";

    #define IS_PERM(str) cout << str << " is palindrome permutation" << endl
    #define NOT_PERM(str) cout << str << " is not a palindrome permutation" << endl;

    if (palindromePermutation(testSuccess, BUFFER_SZ)) {
        IS_PERM(testSuccess);
    } else {
        NOT_PERM(testSuccess)
    }

    if (palindromePermutation(testFailure, BUFFER_SZ)) {
        NOT_PERM(testFailure);
    } else {
        IS_PERM(testFailure);
    }


    return 0;
}