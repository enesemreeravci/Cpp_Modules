#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    if(argc >= 2)
    {
        for(int i = 1; i < argc; ++i)
        {
            for(int j = 0; argv[i][j] != '\0'; ++j)
            {
                std::cout << (char)toupper((unsigned char)argv[i][j]);
            }
        }  
        std::cout << "\n";
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
    }
}
