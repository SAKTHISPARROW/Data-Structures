#include<stdio.h>
#include<stdlib.h>
#define max 10
struct node
{
    int data;
    struct node* link;
};
struct node* head;
int top;

void push(int data)
{
    if(top==max-1)
    {
        printf(" Stack Overflow\n");
        return;
    }
    struct node* newnode=malloc(sizeof(newnode));
    newnode->data=data;
    newnode->link=head;
    if(top==-1)
    {
        head=newnode;
        top++;
        return;
    }
    head=newnode;
    top++;
}

void pop()
{
    if(top==-1)
    {
        printf(" Stack Underflow\n");
        return;
    }
    struct node* temp=head; 
    printf(" Poped data :%d\n",temp->data);
    head=head->link;
    free(temp);
}

void peek()
{
    if(top==-1)
    {
        printf(" Stack Underflow\n");
        return;       
    }
    printf(" Topmost data :%d\n",head->data);
}
void display()
{
    if(top==-1)
    {
        printf(" Stack Underflow\n");
        return;       
    }
    struct node* temp=head;
    while (temp!=NULL)
    {
        printf(" Stack elements :%d\n",temp->data);
        temp=temp->link;
    }
        
}
int main()
{
    head=NULL;
    top=-1;
    int choice;
    do
    {
        printf(" 1.Push\n 2.Pop\n 3.Peek\n 4.Display\n 5.Quit\n ");
        printf("Enter your choice :",choice);
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            int data;
            printf(" Enter the data to be pushed : ",data);
            scanf("%d",&data);
            printf(" %d is pushed\n",data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf(" Please Enter valid choice");
            break;
        }
    } while (choice!=5);
    return 0;
}
