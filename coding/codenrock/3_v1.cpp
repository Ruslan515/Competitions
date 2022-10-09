#include <iostream>
#include <string>
#include <vector>

int main() 
{
/*     ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);    
 */

    std::vector<int> barriers;
    int len_b;
    char op;
    int count;
    while (std::cin >> len_b)
    {
        std::cin >> op;
        if (!std::cin) 
        {
            count = len_b;
            break;
        }
        barriers.push_back(len_b);
    }
    
    std::string ans(count, '0');
    
    for (int i = 0; i < barriers.size(); ++i)
    {
        int position;
        position = barriers[i] - 1;
        ans[position] = 'X';
    }
    if (barriers[barriers.size() - 1] != count)
    {
        ans[count - 1] = 'X';
    }
    
    // std::vector<std::string> key(4);
    for (int i = 0; i < 3; ++i)
    {
        std::cout << ans << "\n";
    }
    std::string end(count, 'X');
    std::cout << end << "\n";    

    return 0;
}