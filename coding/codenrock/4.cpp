#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() 
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); ++i)
    {
        mp[s[i]] += 1;
    }

    map<char, int> :: iterator it = mp.begin();
    // for (int i = 0; it != mp.end(); it++, i++)
    for (int i = 0; i < mp.size() - 1; ++i, ++it)
    {
        cout << it->second << it->first << ',';
    }
    // it++;
    cout << it->second << it->first;


    return 0;
}