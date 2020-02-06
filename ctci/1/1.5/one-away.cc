#include <iostream>
#include <string>
#include <cstdint>
#include <cstdlib>

using namespace std;

bool oneAway(string str1, string str2)
{
    // What do we do in all cases when next char is null terminator?
    
    // Keep track of edit count; for each char eval check number of edits.
    // 

    // Tests:
    //  chrisz chris

    // Remove a char
    //  chriz chris
    //  chzris  chris
    //  str1[i + 1] == str2[i]

    // Insert a char
    //  chis chris
    //  str1[i] == str2[i + 1]

    // Replace a char
    //  chdis chris
    //  str1[i + 1] == str2[i + 1]

    // foreach char   
    //   (elseif block)
    //   str1[i + 1] != end and str1[i + 1] == str2[i] str1.remove(i)
    //   str2[i + 1] != end and st1[i + 1] == str2[i + 1] str1.insert(i, c)
    //   str1[i + 1] == str2[i + 1] str1.replace(i, str2[i])
    //
    //   if changes > 1 return false
    //   increment iterators

    // We can only insert or remove 1 char so if the size delta is > 1 it's 
    // not one away.
    if (abs((int16_t) str1.size() - (int16_t) str2.size()) > 1)
        return false;

    uint8_t changeCount = 0;

    string::iterator str1_it = str1.begin();
    string::iterator str2_it = str2.begin();

    while (str1_it != str1.end() && str2_it != str2.end()) {
        // Check if the 2 chars are the same
        if (*str1_it != *str2_it) {
            if (changeCount > 0)
                return false;
                
            // Can we remove a char?
            if (str1_it + 1 != str1.end() && *(str1_it + 1) == *str2_it) {
                ++str1_it;
                ++changeCount;
            }
            // Can we insert a char?
            else if (str2_it + 1 != str2.end() && *str1_it == *(str2_it + 1)) {
                --str1_it;
                ++changeCount;
            }
            // Can we replace a char?
            else if (*(str1_it + 1) == *(str2_it + 1)) {
                ++changeCount;
            } else {
                return false;
            }
        }

        ++str1_it;
        ++str2_it;
    }

    return true;
}

#define CHECK_ONE_AWAY(str1, str2) \
if(oneAway(str1, str2)) { \
    cout << "PASS: " << str1 << " is one away from " << str2 << endl; \
} else { \
    cout << "FAIL: " << str1 << " is more than one away from " << str2 << endl; \
}

int main(int argc, char* argv[])
{
    // Both the same
    CHECK_ONE_AWAY("chris", "chris")

    // Remove char
    CHECK_ONE_AWAY("chzris", "chris")
    
    // Insert char
    CHECK_ONE_AWAY("cris", "chris")

    // Replace char
    CHECK_ONE_AWAY("czris", "chris")
    
    // 2 away
    CHECK_ONE_AWAY("zhrs", "chris")
    
    // 3 away
    CHECK_ONE_AWAY("sgcad", "chris")

    // Different lengths
    CHECK_ONE_AWAY("adfhgjahghg", "a")
    

    return 0;
}