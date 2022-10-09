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
    int start_char_big, end_char_big;
    int start_char_small, end_char_small;
    start_char_big = 'А';
    end_char_big = 'Я';
    start_char_small = 'а';
    end_char_small = 'я';
    while (i < text.size())   
    {
        int symbol = text[i];
        if ((start_char_big <= symbol) && (symbol >= end_char_big))
        {
            start_first = i;
            end_first = i + 1;
            int symbol = text[end_first];
            while ((start_char_small <= symbol) && (text[start_last] >= end_char_small))
            {
                ++end_first;
                symbol = text[end_first];
            }
            start_last = end_first + 1;
            symbol = text[start_last];
            while (int(text[start_last]) == ' ')
            {
                ++start_last;
                symbol = text[start_last];
            }
            if ((start_char_big <= int(text[start_last])) && (int(text[start_last]) >= end_char_big))
            {
                end_last = start_last;
                while ((start_char_small <= int(text[end_last])) && (int(text[end_last]) >= end_char_small))
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
        else
        {
            ++i;
        }
        
    }

    cout << ans;

    return 0;
}