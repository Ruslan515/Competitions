#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string text;
    getline(cin, text);
    string ans;
    int start_first = 0, end_first = 0;
    int start_last = 0, end_last = 0;

    int i = 0;
    int j_ans = 0;
    int c;
    c = 'Я';
    for (int i = 'А'; i <= 'Я'; ++i)
        cout << i;
    while (i < text.size())   
    {
        if (('A' <= text[i]) && (text[i] >= 'Я'))
        {
            start_first = i;
            end_first = i + 1;
            while (('а' <= text[end_first]) && (text[start_last] >= 'я'))
            {
                ++end_first;
            }
            start_last = end_first + 1;
            while (text[start_last] == ' ')
            {
                ++start_last;
            }
            if (('A' <= text[start_last]) && (text[start_last] >= 'Я'))
            {
                end_last = start_last;
                while (('а' <= text[end_last]) && (text[end_last] >= 'я'))
                {
                    ++end_last;
                }
                int len_first = end_first - start_first;
                int len_last = end_last - start_last;
                for (int j = 0; j < len_first; ++j)
                {
                    ans[j] = text[start_last + j];
                }
                ans[ans.size()] = ',';
                for (int j = 0; j < len_last; ++j)
                {
                    ans[j] = text[start_last + j];
                }
                i = end_last + 1;

            }
        }
        
    }


    return 0;
}