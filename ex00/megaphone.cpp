#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (i < argc)
        {
            j = 0;
            while (argv[i][j])
            {
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                    std::cout << char(std::toupper(argv[i][j]));
                else
                    std::cout << argv[i][j];
                j++;
            }
            i++;
        }
    }
    std::cout << "\n";
    return (0);
}
