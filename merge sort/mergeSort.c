#include <stdio.h>

void merge(int *a, int start, int mid, int end)
{
    int n = (end - start + 1);
    int copy[n];
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
        copy[k++] = a[i] <= a[j] ? a[i++] : a[j++];
    while (i <= mid)
        copy[k++] = a[i++];
    while (j <= end)
        copy[k++] = a[j++];

    for (k = 0; k < n; k++)
        a[start + k] = copy[k];
}

void mergeSort(int *a, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);
    merge(a, start, mid, end);
    return;
}

int main()
{
    printf("Enter n: ");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Before Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    mergeSort(a, 0, n - 1);
    printf("After Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
