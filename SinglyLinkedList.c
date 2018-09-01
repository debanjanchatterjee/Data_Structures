#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
   int data;
   struct Node* next;
};

struct Node* head = NULL;

//display the list
void printList()
{
   struct Node* temp = head;
   printf("Liked List : \n");
	
   //start from the beginning
   while(temp != NULL)
   {
      printf("%d ",temp->data);
      temp = temp->next;
   }
	
 }

//insert at beginning
void insertFirst(int data) 
{
   
   struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = data;
	//point it to old first node
   temp->next = head;
	//point first to new first node
   head = temp;
}

//delete first item
struct Node* deleteFirst()
{
   struct Node *temp = head;
   head = head->next;
   return temp;
}


//is list empty
bool isEmpty()
{
   return head == NULL;
}

void main() 
{
    int ch;
    int f=1;
    int x;
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Print\n");
    
    do 
    {
        printf("Enter choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter data value:");
                    scanf("%d",&x);
                    insertFirst(x);
                    break;
            case 2:if(!isEmpty())
                    {
                        struct Node *temp = deleteFirst();
                        printf("\nDeleted value:");
                        printf("%d ",temp->data);
                    }
                    else
                        printf("List is Empty");
                    break;
            case 3:if(!isEmpty())
			printList();
	           else
			printf("List is Empty.");
                   break;
            default: printf("Invalid choice!!");
        }
        printf("Enter 1 to continue, 0 to terminate :");
        scanf("%d",&f);
   