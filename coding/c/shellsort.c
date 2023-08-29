#include <stdio.h>
void shellSort(int s[], int n);
void swap();

int s[100];
int n;
int main()
{

    printf("\nEnter number of array elements:");
    scanf("%d", &n);
    printf("\n Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        printf("\n");
    }
    printf("\n Array element is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", s[i]);
        printf("\n");
    }
    printf("\n After using shell sort :\n");
    shellSort(s, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", s[i]);
        printf("\n");
    }
    return 0;
}

void shellSort(int s[], int n)
{

    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i += 1)
        {
            temp = s[i];
            for (j = i; j >= gap && s[j - gap] > temp; j -= gap)
            {
                s[j] = s[j - gap];
            }
            s[j] = temp;
        }
    }
}
