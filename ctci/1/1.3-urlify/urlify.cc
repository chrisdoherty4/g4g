#include <string>
#include <iostream>

using namespace std;

class mystring : public string
{
public:
    mystring(const char* init) : string(init) {}

    void replace(string needle, string replacement)
    {
        while (true) {
            auto found = find(needle);
            
            if (found == string::npos) break;

            insert(found+1, replacement);
            erase(found, 1);
        }
    }

    void replace(char needle, string replacement)
    {
        replace(string(&needle), replacement);
    }
};

int main(int argc, char* argv[])
{
    mystring testString = "This string has spaces";

    cout << "Test string: " << testString << endl;

    testString.replace(' ', "%20");

    cout << "Test string after: " << testString << endl;

    cout << "Hi my name is AJ" << endl;

    return 0;
}