#include <stdio.h>
#include <stdlib.h>
void insert();
void delete();
void display();
struct node
{
    int info;
    struct node *next;
};
struct node *front=0, *rear=0;
int main()
{
    int ch, p=1;
    do
    {
        printf("\n1- Insertion \n2- Delete \n3- Display \n4- Exit\nEnter option:\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nEnter valid choice");
        }
        printf("\nDo you want to continue?\n1- Yes\t0- No\n");
        scanf("%d", &p);
    }while(p==1);
}
void insert()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter value to node: ");
    scanf("%d", &ptr->info);
    if (front==0)
    {
        front=ptr;
        rear=ptr;
        ptr->next=front;
    }
    else
    {
        rear->next=ptr;
        rear=ptr;
        rear->next=front;
    }
}
void delete()
{
    struct node *x, *y;
    if (rear==0)
        printf("\nEmpty list");
    else
    {
        x=rear;
        y=rear;
        while(x->next!=rear)
        {
            x=x->next;
        }
        x->next
        =front;
        free(y);
        printf("\nSuccessfully Deleted!\n");
    }
}
void display()
{
    struct node *x, *p;
    if (rear==0)
    {
        printf("\nEmpty list\n");
    }
    else
    {
        x=front;
        while (x->next!=front)
        {
            printf("\n%d", x->info);
            x=x->next;
        }
        printf("\n%d", x->info);
    }
}
