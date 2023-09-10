#include <stdio.h>
#include <stdlib.h>
int n, a[100];
void mergesort(int a[], int lb, int ub);
void merge(int a[], int mid, int lb, int ub);
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
    printf("\n After using Mergesort sort :\n");
    mergesort(a, 0, n - 1);
    printf("\n Array element is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        printf("\n");
    }

    return 0;
}

void mergesort(int a[], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, mid, lb, ub);
    }
}
void merge(int a[], int mid, int lb, int ub)
{

    int i, j, k, b[100];
    i = lb;
    j = mid + 1;
    k = lb;
    while (i <= mid && j <= ub)
    {

        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= ub)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = lb; i <= ub; i++)
    {
        a[i] = b[i];
    }
}
