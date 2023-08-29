#include <stdio.h>
#include <string.h>
struct student
{
    char name[100];
    int r;
    int marks;
};
int n;
struct student s[100];

int main()
{

    for (;;)
    {

        void accept();
        void display(struct student s[]);
        void bubblesort(struct student s[], int n);
        void insertionsort(struct student s[], int n);
        void selectionSort(struct student s[], int n);
        void shellSort(struct student s[], int n);

        printf("Enter How many students marks you have to enter:");
        scanf("%d", &n);
        accept();

        display(s);
        shellSort(s, n);
        printf("\n\nAfter using Shell sort:\n");
        display(s);
        bubblesort(s, n);
        printf("\n\nAfter using Bubble sort:\n");
        display(s);
        insertionsort(s, n);
        printf("\n\nAfter using Insertion sort:\n");
        display(s);
        selectionSort(s, n);
        printf("\n\nAfter using Selection sort:\n");
        display(s);
        shellSort(s, n);
        printf("\n\nAfter using Shell sort:\n");
        display(s);

        return 0;
    }
}
void accept()
{

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf(" Enter %d  Student Information:\n", i + 1);
        printf("Enter Student Name:");
        scanf("%s", &s[i].name);
        printf("Enter Student Roll Number:");
        scanf("%d", &s[i].r);

        printf("Enter Student Marks:");
        scanf("%d", &s[i].marks);
        printf("\n");
        printf("You Complete The Information of %d Student\n\n\n", i + 1);
    }
}
void display(struct student s[])
{
    printf("\n");
    printf("SR NO.\t\tSTUDENT NAME\t\t\tROLL NO.\t\t\tMARKS");
    printf("\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d.\t\t%s\t\t\t\t%d\t\t\t\t%d\t\t\t\n", i + 1, s[i].name, s[i].r, s[i].marks);
    }
}
void bubblesort(struct student s[], int n)
{
    struct student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (s[j].r > s[j + 1].r)

            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void insertionsort(struct student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        struct student key;
        key = s[i];
        j = i - 1;
        while (j >= 0 && s[j].r > key.r)
        {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
}
void selectionSort(struct student s[], int n)
{
    int i, j, minIndex;
    struct student temp;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (s[j].r < s[minIndex].r)
                minIndex = j;
        }
        temp = s[minIndex];
        s[minIndex] = s[i];
        s[i] = temp;
    }
}

void shellSort(struct student s[], int n)
{
    int gap, i;
    struct student temp;
    for (gap = n / 2; gap > 0; gap / 2)
    {
        for (i = 0; i < n - gap; i++)
        {
            if (s[i].r > s[i + gap].r)
            {
                temp = s[i];
                s[i] = s[i + gap];
                s[i + gap] = temp;
            }
            else
            {
                break;
            }
        }
    }
}