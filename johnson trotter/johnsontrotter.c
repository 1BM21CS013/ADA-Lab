#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int getMobile(int *a, int *d, int n)
{
    int mobileIndex = -1;
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            if (d[a[i] - 1])
            {
                // check right
                if (i != n - 1 && a[i] > a[i + 1])
                {
                    mobileIndex = i;
                    max = a[i];
                }
            }
            else
            {
                // check left
                if (i != 0 && a[i] > a[i - 1])
                {
                    mobileIndex = i;
                    max = a[i];
                }
            }
        }
    }

    return mobileIndex;
}

void printOne(int *a, int *d, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    int mobileIndex = getMobile(a, d, n);

    if (mobileIndex == -1)
        return;

    int mobileElement = a[mobileIndex];
    // printf("Mobile : %d\n", a[mobileIndex]);

    if (d[a[mobileIndex] - 1])
        // swap right
        swap(&a[mobileIndex], &a[mobileIndex + 1]);
    else
        // swap left
        swap(&a[mobileIndex], &a[mobileIndex - 1]);

    for (int i = 0; i < n; i++)
        if (a[i] > mobileElement)
            d[a[i] - 1] = !d[a[i] - 1];
}

int fact(int n)
{
    int prod = 1;
    for (int i = 1; i <= n; i++)
        prod *= i;
    return prod;
}

void printPermutations(int n)
{
    int a[n];
    int d[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        d[i] = 0;
    }
    int factorial = fact(n);

    for (int i = 0; i < factorial; i++)
        printOne(a, d, n);
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printPermutations(n);
    return 0;
}