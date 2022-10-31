#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// si c sigusr1 c 0
// si c sigusr2 c 1
// transformer les 0 et 1 en byte
// traduire le byte en char 

int nbr;
int count;

count = 0;
nbr = 0;

void handlerSIGUSR1(int signum)
{
    char letter;
    nbr = 1  + (2 * nbr);
    printf(" SUGUSR1 value of nbr is %i\n",nbr);
    
    count++;
    
    printf("value of count is %i\n", count);
    if (count == 7)
    {
        printf("im here\n");
        printf("value of letter is %i\n", nbr);
        letter = nbr;
        write(1,&letter,1);
        count = 0;
        nbr = 0;
     
    }
}

void handlerSIGUSR2(int signum)
{

    char letter;
    
    nbr = 0  + (2 * nbr);

    printf("SUGUSR2 value of nbr is %i\n",nbr);
    
    count++;
    printf("value of count is %i\n", count);
    if (count == 7)
    {
        printf("im here\n");
        printf("value of letter is %i\n", nbr);
        letter = nbr;
        write(1,&letter,1);
        count = 0;
        nbr = 0;
    }
}
int main(int argc, char*argv[])
{
    int pid;
    struct sigaction action1;
    struct sigaction action2;
    sigset_t sigmask;

    sigemptyset(&sigmask);
    action1.sa_handler = handlerSIGUSR1;
    action1.sa_flags = 0;
    action1.sa_mask = sigmask;
    
    action2.sa_handler = handlerSIGUSR2;
    action2.sa_flags = 0;
    action2.sa_mask = sigmask;

    pid = getpid();
    printf("%i\n", pid);
    sigaction(SIGUSR1, &action1,NULL);
    sigaction(SIGUSR2, &action2,NULL);
    while (1)
    {
        pause();
    }
}