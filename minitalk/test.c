#include <stdio.h>

int main(void)
{
   int ok;
    ok = 0;
    printf("t1 : %i\n", !ok);
    if (!ok)
        printf("t2\n");
}