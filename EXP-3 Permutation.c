#include <stdio.h>

void perm(int arr[], int start, int stop)
{
    int temp, i;

    if (start == stop)
    {
        for (i = 0; i < stop; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else
    {
        for (i = start; i < stop; i++)
        {
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;

            perm(arr, start + 1, stop);

            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int n, i, a[10];

    printf("Enter total number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    perm(a, 0, n);

    return 0;
}
