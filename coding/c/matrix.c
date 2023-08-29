#include <stdio.h>
int main()
{
    for (int i = 0;; i++)
    {
        int a[3][3], i, j, b[3][3];
        int c[3][3];
        printf("Enter Array elements:");
        printf("\n");
        for (i = 0; i < 3; i++)

        {

            for (j = 0; j < 3; j++)

            {

                scanf("%d", &a[i][j]);
            }
        }
        printf("matrix A is");
        printf("\n");
        for (i = 0; i < 3; i++)

        {

            for (j = 0; j < 3; j++)

            {

                printf("%3d", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        printf("matrix B is");
        printf("\n");
        for (i = 0; i < 3; i++)

        {

            for (j = 0; j < 3; j++)

            {

                b[i][j] = a[j][i];
                printf("%3d", b[i][j]);
            }
            printf("\n");
        }

        printf("\n");
        printf("matrix c is");
        printf("\n");
        for (i = 0; i < 3; i++)

        {

            for (j = 0; j < 3; j++)

            {

                c[i][j] = a[i][j] * b[i][j];
                printf("%3d", c[i][j]);
            }
            printf("\n");
        }

        return 0;
    }
}