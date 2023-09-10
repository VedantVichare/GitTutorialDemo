#include <stdio.h>
#include <stdlib.h>
int n, a[100], v;
void quicksort(int a[], int lb, int ub);
int partition(int a[], int lb, int ub);
void insertionsort(int a[], int v);
int main()
{

    printf("\nEnter number of array elements:");
    scanf("%d", &n);
    printf("\n Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        printf("\n");
    }
    printf("\n Array element is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        printf("\n");
    }
    printf("\n After using Quicksort sort :\n");
    quicksort(a, 0, n - 1);
    printf("\n Array element is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        printf("\n");
    }

    printf("\nEnter number of array elements:");
    scanf("%d", &v);
    printf("\n Enter array elements:\n");
    for (int i = 0; i < v; i++)
    {
        scanf("%d", &a[i]);
        printf("\n");
    }
    printf("\n Array element is:\n");
    for (int i = 0; i < v; i++)
    {
        printf("%d", a[i]);
        printf("\n");
    }
    printf("\n After using insertionsort sort :\n");
    quicksort(a, 0, v - 1);
    printf("\n Array element is:\n");
    for (int i = 0; i < v; i++)
    {
        printf("%d", a[i]);
        printf("\n");
    }

    return 0;
}
void quicksort(int a[], int lb, int ub)
{

    int loc;
    if (lb < ub)
    {
        loc = partition(a, lb, ub);

        quicksort(a, lb, loc - 1);
        quicksort(a, loc + 1, ub);
    }
}
int partition(int a[], int lb, int ub)
{

    int i, j, pivot, temp, t;
    pivot = a[lb];
    i = lb;
    j = ub;
    while (i < j)
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (pivot < a[j])
        {
            j--;
        }
        if (i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    t = a[j];
    a[j] = a[lb];
    a[lb] = t;

    return j;
}
void insertionsort(int a[], int n)
{
    for (int i = 0; i < v; i++)
    {
        int j;
        int key;
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            printf("\n Array element is:\n");
            for (int i = 0; i < v; i++)
            {
                printf("%d", a[i]);
                printf("\n");
            }

            j = j - 1;
        }
        a[j + 1] = key;
    }
}