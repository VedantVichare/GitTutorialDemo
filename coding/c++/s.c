printf("\nProcess\t\tArrival Time\tBurst Time\tCompletion Time\t\tTurn Around Time\tWaiting Time\n");
for (int i = 0; i < p; i++)
{
    printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", i, at[i], bt[i], ct[i], tat[i], wt[i]);
}
printf("\nAverage Of Total Around Time:%2.f\n", avgt);
printf("\nAverage Of Wating  Time:%2.f\n", avgwt);
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