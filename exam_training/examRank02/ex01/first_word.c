#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    i = 0;
    if (argc == 2)
    {
        printf("im here");
            while ((argv[0][i] == ' ') || (argv[0][i] == 9))
            {
                i++;
            }
            while ((argv[0][i] != ' ') || (argv[0][i] != 9))
            {
                write(1, &argv[0][i], 1);
                i++;
            }
            write(1, "\n", 1);
    }
    else
    {
        write(1, "\n", 1);
    }
    return(0);
}