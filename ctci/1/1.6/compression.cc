#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

string compress(string str)
{
    // Use 2 iterators
    // it1 = it2 = str.begin
    // for each char in it1
    //   append char1 to return string
    //   move it2 forwards until we find a char that's not the same as it1
    //   get distance between it1 and it2 and append to return string
    //   set it1 = it2

    stringstream ret;
    string::iterator it1 = str.begin();
    string::iterator it2 = it1 + 1;

    while (it1 != str.end()) {
        ret << *it1;

        while (*it2 == *it1) ++it2;
        
        ret << distance(it1, it2);
        it1 = it2;
        ++it2;
    }

    return ret.str().length() < str.length() ? ret.str() : str;
}

#define COMPRESS(str) cout << str << " compressed = " << compress(str) << endl

int main(int argc, char* argv[])
{
    COMPRESS("ccchrrrrrriissss");
    COMPRESS("chris");
    COMPRESS("cchris");
    COMPRESS("ccchris");
    COMPRESS("cchhrriiss");
    COMPRESS("ccchhrriiss");

    return 0;
}