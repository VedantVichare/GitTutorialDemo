#include <stdio.h>
void compact(int a[100][100], int m, int n, int d[100][100]);
void transpose(int a[100][100], int m, int n, int e[100][100], int d[100][100]);
int a[100][100], m, n, c, b, d[100][100], e[100][100], f[100][100];
int k = 1;
int main()
{

    while (1)
    {
        k = 1;
        c = 0;
        b = 0;
        printf("\nEnter No. of rows:");
        scanf("%d", &m);
        printf("\n");
        printf("Enter No. of colums:");
        scanf("%d", &n);
        printf("\n");
        printf("Enter Array elements:");
        printf("\n");
        for (int i = 0; i < m; i++)

        {

            for (int j = 0; j < n; j++)

            {

                scanf("%d", &a[i][j]);
            }
        }
        printf("matrix A is");
        printf("\n");
        for (int i = 0; i < m; i++)

        {

            for (int j = 0; j < n; j++)

            {

                printf("%3d", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for (int i = 0; i < m; i++)

        {

            for (int j = 0; j < n; j++)

            {

                if (a[i][j] > 0)
                {
                    b++;
                }
                else
                {
                    c++;
                }
            }
        }
        printf("\nc=%d\nb=%d\n", c, b);
        printf("\n");
        if (c > b)
        {
            printf("\nMatrix is  a sparse matrix\n");
            compact(a, m, n, d);
            printf("\n\n");
            printf("matrix A compact matrix is");
            printf("\n");
            printf("________________________________________________\n");
            printf("|\tCol 0\t||\tCol1\t||\tCol2\t|\n");

            for (int i = 0; i < b + 1; i++)

            {
                printf("________________________________________________\n");
                for (int j = 0; j < 3; j++)

                {

                    printf("|%9d\t|", d[i][j]);
                }
                printf("\n");
            }
            printf("________________________________________________\n");
            printf("\n");
            transpose(a, m, n, e, d);
        }
        else
        {
            printf("\nMatrix is not a sparse matrix\n\n\n");
        }
    }

    return 0;
}
void compact(int a[100][100], int m, int n, int d[100][100])
{

    d[0][0] = m;
    d[0][1] = n;
    for (int i = 0; i < m; i++)

    {

        for (int j = 0; j < n; j++)

        {

            if (a[i][j] != 0)
            {
                d[k][0] = i;
                d[k][1] = j;
                d[k][2] = a[i][j];
                k++;
            }
        }
    }
    d[0][2] = k - 1;
}

void transpose(int a[100][100], int m, int n, int e[100][100], int d[100][100])
{
    int x;

    int tot[100], index[100];
    index[0] = 1;
    for (int j = 0; j < n; j++)
    {
        x = 0;
        for (int i = 0; i < m; i++)
        {
            if (a[i][j] != 0)
            {
                x++;
            }
        }
        tot[j] = x;
    }
    for (int i = 1; i < n + 1; i++)
    {
        index[i] = index[i - 1] + tot[i - 1];

        printf("\n%d\t\t\t%d", tot[i - 1], index[i - 1]);
    }
    f[0][0] = n;
    f[0][1] = m;
    int y = 1;
    for (int i = 0; i < m; i++)

    {

        for (int j = 0; j < n; j++)

        {

            if (a[i][j] != 0)
            {
                f[y][0] = j;
                f[y][1] = i;
                f[y][2] = a[i][j];
                y++;
            }
        }
    }
    f[0][2] = y - 1;
    printf("\n\n");
    for (int i = 0; i < b + 1; i++)

    {

        for (int j = 0; j < 3; j++)

        {

            printf("%10d", f[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    int z = 0;
    e[0][0] = n;
    e[0][1] = m;
    e[0][2] = y - 1;
    int p;
    for (int i = 1; i < b + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            f[i][0] = z;

            e[index[z]][j] = f[i][j];
        }
        ++index[z];
    }
    printf("\n\n");
    printf("Transpose of compact matrix is:");
    printf("\n");
    printf("________________________________________________\n");
    printf("|\tCol 0\t||\tCol1\t||\tCol2\t|\n");

    for (int i = 0; i < b + 1; i++)

    {
        printf("________________________________________________\n");
        for (int j = 0; j < 3; j++)

        {

            printf("|%9d\t|", e[i][j]);
        }
        printf("\n");
    }
    printf("________________________________________________\n");
    printf("\n");
}