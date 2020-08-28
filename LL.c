#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
int data;
struct Node*link;
}Node;

Node* A= NULL;
int len;

void insert();
void addatbeg();
void addatend();
void length();
void display();
void deletenum();

int main()
{int a=1;
     while(a)
     {printf("\nEnter a digit from the following options;\n0-quit, 1-insert at a position, 2-add at beginning, 3-append/add at end, 4-length of list, 5-display list, 6-delete at a position\n");
     scanf("%d",&a);
     switch(a){
     case 1: insert(); break;
     case 2: addatbeg(); break;
     case 3: addatend(); break;
     case 4: length(); break;
     case 5: display(); break;
     case 6: deletenum(); break;
     default: printf("Invalid number");
     }
}
}


void insert(){
    int b,count=1;
    Node*temp=( Node*)malloc(sizeof( Node));
    printf("Enter number to insert\n");
    scanf("%d",&temp->data);
    printf("Enter position to insert\n");
    scanf("%d",&b);
    temp->link=NULL;

    Node*p=A;
    if(b==1){
            temp->link=A;
            A=temp;
    }
    else{
            while(1){
        if(++count==b){
            temp->link=p->link;;
            p->link=temp;
            break;
        }
        else
        p=p->link;
    }}}




void addatbeg()
{
    int b;
    Node*temp=(Node*)malloc(sizeof(Node));
    printf("Print the number you would like to add at the beginning.");
    scanf("%d",&b);
    temp->data=b;
    temp->link=NULL;

    if(A==NULL){
        A=temp;
    }
    else{
       temp->link=A;
    }A=temp;
}


void addatend()
{
   Node*temp=(Node*)malloc(sizeof(Node));
    printf("Print the number you would like to append.");
    scanf("%d",&temp->data);
    temp->link=NULL;

    Node *p=A;

    if(A==NULL){A=temp; return;}

    while(p->link!=NULL)
    {
        p=p->link;
    }p->link=temp;

}

void length()
{
   int count=0;
   Node*temp=A;

   while(temp!=NULL)
   {
       temp=temp->link;
       count++;
   }

   printf("Length of list is %d.\n",count);
}


void display(){
    printf("List is ");
Node *p=A;
while(p!=NULL){
        printf("%d-->",p->data);
        p=p->link;
        }
        printf("\n");
}


void deletenum()
{
    int count=1,b;
    printf("Print the position you would like to delete.\n");
    scanf("%d",&b);

    Node *p=A;

    if(b==1){
        A=p->link;
        free(p);
    }
    else{
    while(1)
    {
        if(++count==b){
            Node *temp=p->link;
            p->link=temp->link;
            free(temp);
        }
        else p=p->link;
    }}
    printf("Your current list is: ");
    display();
}
