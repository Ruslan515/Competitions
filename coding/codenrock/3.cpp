#include <iostream>
#include <string>
#include <vector>

int main() 
{
/*     ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);    
 */

    std::string line;
    std::getline(std::cin, line);
    int count_barriers;
    count_barriers = line[line.size() - 1];
    std::vector<int> barriers(count_barriers);
    for (int i = 0; i < count_barriers; ++i)
    {
        barriers[i] = int(line[i * 2]);
    }
    std::cout << "yes";

    std::cout << line << "\n";

    return 0;
}