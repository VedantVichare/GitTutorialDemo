
#include <stdio.h>
#include <string.h>
struct student
{

    char name[100];
    int div;
    int marks;
};
int n, temp, a[100];
struct student s[100];
int main()
{

    for (;;)
    {

        void accept();
        void display();
        void bubblesort();

        printf("Enter How many students marks you have to enter:");
        scanf("%d", &n);
        accept();

        display();
        bubblesort();
        printf("\n\nAfter using Bubble sort\n");
        display();

        return 0;
    }
}
void accept()
{

    for (int i = 0; i < n; i++)
    {
        printf("\n\n\n");
        printf("Start Entering New Student Information:\n");
        printf("Enter Student Name:");
        scanf("%s", &s[i].name);
        printf("Enter Student Roll Number:");
        scanf("%d", &a[i]);

        printf("Enter Student Div:");
        scanf("%d", &s[i].div);

        printf("Enter Student Marks:");
        scanf("%d", &s[i].marks);
        printf("\n");
        printf("You Complete The Information of %d Student\n\n\n", i + 1);
    }
}
void display()
{
    printf("\n");
    printf("SR NO.\t\tSTUDENT NAME\t\t\tROLL NO.\t\t\tDIV\t\t\tMARKS");
    printf("\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d.\t\t%s\t\t\t\t%d\t\t\t\t%d\t\t\t%d\t\t\t\n", i + 1, s[i].name, a[i], s[i].div, s[i].marks);
    }
}
void bubblesort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])

            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                temp = s[i].name;
                s[i].name = s[i+1].name;
                s[i + 1].name = temp;
                temp = s[i].div;
                s[i].div = s[i+1].div;
                s[i + 1].div = temp;

            }
        }
    }
}
