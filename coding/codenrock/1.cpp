#include <iostream>
#include <string>

int transform(char c)
{
    int symbol;
    if (c != ' ')
    {
        if (c < 'a')
        {
            c = c - 'A' + 'a';
        }
        symbol = c - 'a' + 1;        
        return symbol;
    }
    else
    {
        return 0;
    }
    
}

int main() 
{
    for (std::string line; std::getline(std::cin, line);) 
    { // get the line
        //here your code
        char c;
        int symbol;
        for (int i = 0; i < line.size() - 1; i++)
        {
            symbol = transform(line[i]);
            if (symbol > 0)
            {
                std::cout << symbol << ",";
            }
        }
        symbol = transform(line[line.size() - 1] );
        if (symbol > 0)
        {
            std::cout << symbol;
        }
        std::cout << "\n";
        // std::cout << line << std::endl; // print the answer as stdout
    }
    return 0;
}