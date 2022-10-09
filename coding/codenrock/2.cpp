#include <iostream>
#include <string>

int rec_count(int count_soldiers)
{
    if (count_soldiers <= 0)
    {
        return 0;
    }
    else
    {
        int temp;
        temp = rec_count(count_soldiers - 2);
        int all_sum = 0;
        all_sum += count_soldiers + temp;
        return all_sum;
    }
}

int main() 
{
    int count_soldiers;
    std::cin >> count_soldiers;

    int new_sum;
    new_sum = rec_count(count_soldiers);
    std::cout << new_sum << "\n";
    return 0;
}