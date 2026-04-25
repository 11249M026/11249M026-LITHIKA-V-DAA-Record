#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    if (n == 0)
        return -1;

    if (arr[n - 1] == key)
        return n - 1;

    return linearSearch(arr, n - 1, key);
}

int main()
{
    int arr[1000], n, key, i, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = linearSearch(arr, n, key);

    if (result == -1)
        printf("Element not found");
    else
        printf("Element found at index %d", result);

    return 0;
}
