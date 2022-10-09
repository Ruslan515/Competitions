#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string s;
    cin >> s;    
    int count = 0;
    for (int i = 0; i < s.size() - 1; ++i)    
    {        
        if (s[i] != s[i + 1])
        {
            ++count;
            cout << count << s[i] << ',';
            count = 0;
        }
        else
        {
            ++count;

        }
    }
    if (s[s.size() - 2] != s[s.size() - 1])
    {
        ++count;
        cout << count << s[s.size() - 1];
    }    
    return 0;
}