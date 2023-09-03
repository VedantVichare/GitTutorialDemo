

#include<stdio.h>
struct student
 {
   int r;
   char name[20];
   float marks;
 };

  void accept(struct student s[10],int n);
  void display(struct student s[10],int n);
  void linearsearch(struct student s[10],int data,int n);
  void selectionSort(struct student s[10], int n);
  int data;
 int main()
{ 
 
 struct student s[10];
 int n;
 printf("Enter no. of records:");
 scanf("%d",&n);
 accept(s,n);
 display(s,n);
 linearsearch(s,data,n);
 selectionSort(s,n);
 printf("After using slection sort:");
 display(s,n);
 return 0;
  }
 void accept(struct student s[10],int n)
 {
    int i;
    
    printf("\nEnter roll no,name,marks");
    for(i=0;i<n;i++)
   {     
          printf("\n\nEnter the information %d student:\n\n",i+1);
          scanf("%d",&s[i].r);
          scanf("%s",s[i].name);
          scanf("%f",&s[i].marks);
   }
 }

 void display(struct student s[10],int n)
 {   
     printf("\n STUDENT INFORMATION\n:");
     printf("\n");
     printf("SR NO.\t\t\tROLL NO.\t\tSTUDENT NAME\t\t\tMARKS");
     printf("\n");
     for (int i = 0; i < n; i++)
       {

        printf("\n%d.\t\t\t%d\t\t\t%s\t\t\t\t%2f\n", i+1,s[i].r, s[i].name,s[i].marks);
       }
      
  
  }
 
 void linearsearch(struct student s[10],int data,int n)
 {
    printf("\nEnter roll no you have to search:");
    scanf("%d",&data);
    for(int i=0;i<n;i++)
      {
         if(data=s[i].r)
           {
            printf ("\n %d  %s  %f\n",s[i].r,s[i].name,s[i].marks);
            break;
           }
            if(i=n)
           {
            printf("data is not found\n");
            break;
           }
       
      }
 }
 
 void selectionSort(struct student s[10], int n)
{
    int i, j, minIndex;
    struct student temp;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (s[j].r < s[minIndex].r)
            {
                minIndex = j;
          
               temp = s[minIndex];
               s[minIndex] = s[i];
               s[i] = temp;
               
            }
 printf(" Value change in %d pass:\n ",i+1);
               printf("\n%d.\t\t\t%d\t\t\t%s\t\t\t\t%2f\n", i+1,s[i].r, s[i].name,s[i].marks);
               printf("\n%d.\t\t\t%d\t\t\t%s\t\t\t\t%2f\n", i+2,s[i+1].r, s[i+1].name,s[i+1].marks);
               printf("\n%d.\t\t\t%d\t\t\t%s\t\t\t\t%2f\n", i+3,s[i+2].r, s[i+2].name,s[i+2].marks);
            
           
            
            
        }
         
        
        
     }
             
      
}
