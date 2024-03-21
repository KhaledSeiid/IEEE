#include <stdio.h>
#include <stdlib.h>
struct student
{
    int id;
    char name[10];
    struct student *next;
};
struct student *head=NULL;

//////////////////////////

void add_node()
{
    struct student *new1;
    struct student *check;
    if(head==NULL)
    {
        new1=(struct student*)malloc(sizeof(struct student));
        head=new1;
    }
    else
    {
        check=head;
        while(check->next!=NULL)
        check=check->next;
         new1=(struct student*)malloc(sizeof(struct student));
         check->next=new1;
    }
    printf("ENTER STUDENT NAME : ");
    scanf("%s",&new1->name);
    printf("ENTER STUDENT ID : ");
    scanf("%d",&new1->id);
    new1->next=NULL;
}
 //////////////////////////

 void show_list()
{
   struct student *current=head;
   if(head==NULL)
        printf("EMPTY LIST.\n");
        while(current)
        {
            printf("NAME : %s \n",current->name);
            printf("ID : %d \n",current->id);
              printf("-=-=-=-=-=-=-=-=-=-\n");
            current=current->next;
        }
}
////////////////////////

void clear_list()
{
    struct student *current=head;
  if(head==NULL)
    printf("EMPTY LIST.\n");
  while(current)
        {
            struct student *temp=current;
            current =current->next;
            free(temp);
        }
        head=NULL;
}
/////////////

void clear_node( )
{
     int val ;
    printf("ENTER ID : ");
    scanf("%d",&val);
    if(head)
    {
        struct student *select=head;
         struct student *prev=NULL;
         while(select)
         {
             if(select->id==val)
             {
                 if(prev)
                 {
                     prev->next=select->next;
                 }
                 else
                 {
                     head=select->next;
                 }
                 free(select);

             }
             prev=select;
             select=select->next;
         }
    }
}
int main()
{
    int num;
   while(1)
   {
       printf("To add new node (1) ,\nTo show data of list (2) ,\nTo clear the list (3) ,\nTo remove node from list (4) .\n");
       scanf("%d",&num);
       switch(num)
       {
       case 1:
            add_node();
            break;
       case 2:
            show_list();
            break;
        case 3:
            clear_list();
            break;
       case 4:
            clear_node();
            break;
       default:
        printf("Enter valid num\n");
       }
   }

    return 0;
}
