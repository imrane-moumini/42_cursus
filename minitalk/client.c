#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// transformer ce que jecris en binaire 0 et 1 
// si le caractere c 0 envoyer sigusr1
// si le caractere c 1 envoyer sigusr1
int count;

void send_data(int pid, char c)
{
    int i;
    i = 0;
    printf("%c\n",c);
    while (i < 8)
    {
        if (c & 1 == 1)
        {
            kill(pid,SIGUSR1);
            printf("SUGUSR1\n");
        }
        else if (c & 1 == 0)
        {
            kill(pid,SIGUSR2);
            printf("SUGUSR2\n");
        }
        c = c << 1;
        count++;
        i++;
    }
    printf("count is %i\n", count);
}

int main(int argc, char*argv[])
{
    int pid;
    int i;

    i = 0;
    pid = atoi(argv[1]);
    while (argv[2][i] != '\0')
    {
        send_data(pid,argv[2][i]);
        i++;
    }
}