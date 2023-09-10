#include <stdio.h>
int main()
{
    int p, at[100], bt[100], st[100], ct[100], tat[100], wt[100];
    float t = 0;
    float w = 0;
    printf("\nEnter the number of process: ");
    scanf("%d", &p);
    printf("\nEnter the arrival time of each process:\n");
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &at[i]);
    }
    printf("\nEnter the Burst time of each process:\n");
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &bt[i]);
    }
    st[0] = at[0];
    for (int i = 0; i < p; i++)
    {

        ct[i] = bt[i] + st[i];
        st[i + 1] = ct[i];
    }

    for (int i = 0; i < p; i++)
    {
        if (ct[i] < at[i + 1])
        {

            ct[i + 1] = at[i + 1] + bt[i + 1];
        }
        ct[i + 2] = bt[i + 2] + ct[i + 1];
    }

    for (int i = 0; i < p; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        w += wt[i];
        t += tat[i];
    }
    float avgwt = w / p;
    float avgt = t / p;
    printf("\nGantt Chart:\n ");
    for (int i = 0; i < p; i++)
    {
        printf("_________________");
    }

    printf("\n");
    for (int i = 0; i < p; i++)
    {
        printf("|\t");
        printf("P%d\t", i + 1);
    }
    printf("|");

    printf("\n");
    for (int i = 0; i < p; i++)
    {
        printf("-----------------");
    }

    printf("\n");
    printf("\t\t");
    for (int i = 0; i < p; i++)
    {
        printf("%d\t\t", ct[i]);
    }

    printf("\n");
    printf("\nProcess\t\tArrival Time\tBurst Time\tCompletion Time\t\tTurn Around Time\tWaiting Time\n");
    for (int i = 0; i < p; i++)
    {
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", i, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Of Total Around Time:%f\n", avgt);
    printf("\nAverage Of Wating  Time:%f\n", avgwt);

    return 0;
}
