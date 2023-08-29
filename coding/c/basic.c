#include <stdio.h>
#include <stdlib.h>
int main()
{
    while (1)
    {
        int *p, *a, *e;
        printf("\n 1=%d", sizeof(&p));
        p = (int *)malloc(5 * sizeof(int));
        printf("\n 2=%d", sizeof(&p));

        for (int i = 1; i < 5; i++)
        {
            printf("%d.", i);
            printf("%d", *(p + i));
            printf("\n");
        }
        printf("\n realloc");
        printf("\n");
        a = (int *)realloc(p, 7 * sizeof(int));
        for (int i = 1; i < 7; i++)
        {
            printf("%d.", i);
            printf("%d", *(a + i));
            printf("\n");
        }
        printf("\n calloc");
        e = (int *)calloc(8, sizeof(int));

        for (int i = 1; i < 8; i++)
        {
            printf("%d.", i);
            printf("%d", *(e + i));
            printf("\n");
        }
        printf("\n array");
        int s[50];
        for (int i = 0; i < 60; i++)
        {
            printf("\n%d.", i);
            printf("%d", &s[i]);
        }

        return 0;
    }
}
