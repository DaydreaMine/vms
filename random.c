#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
int main(){
    time_t t;
    time(&t);
    srand(t);
    int n=rand() %8;
    printf("%d\n",n);

    return 0;
}
*/

int main()
{
    int arr[8];
    int i;
    int r;
    int temp;
    time_t t;
    time(&t);
    srand(t);

    for (i = 0; i < 8; i++)
    {
        arr[i] = i;
    }
    for (i = 0; i < 8; i++)
    {
        r = rand() % 8;
        temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
    }

    for (i = 1; i <= 8; i++)
    {
        printf("%2d ", arr[i - 1]);
    }
    printf("\n");
}
