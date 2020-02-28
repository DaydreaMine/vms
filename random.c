#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int arr[8];
    int i;
    int r;
    srand(time(NULL));
    for (i = 0; i < 8; i++)
    {
        arr[i] = i;
    }
    for (i = 0; i < 8; i++)
    {  r=rand()%8;
       swap(&arr[r],&arr[i]);
    }

    for (i = 1; i <= 8; i++)
    {
        printf("%2d ", arr[i - 1]);
    }
    printf("\n");
}
