/******************************************************************************

Program to reverse a Linked List using 3 variables and 2 variables

*******************************************************************************/
#include <iostream>
using namespace std;

typedef struct myList
{
    int data;
    myList *next;
}NODE, * NODEPTR;

NODEPTR createNode(int data)
{
    NODEPTR tempNode = new NODE;
    tempNode->data = data;
    tempNode->next = NULL;
    return tempNode;
}

void insert(NODEPTR * head, int data)
{
    NODEPTR tempNode = createNode(data);
    
    if(*head == NULL)
    {
        *head = tempNode;
    }
    else
        {
            NODEPTR iter = *head;
            while(iter -> next != NULL)
                iter = iter-> next;
            iter-> next = tempNode;
        }
}

void display(NODEPTR head)
{
    NODEPTR temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }   
    cout<<endl;
}

//Reverse using 3 temporary variables
void reverse_three_variables(NODEPTR * head)
{
    if(*head == NULL) return;
    
    NODEPTR left = *head;
    NODEPTR right = left->next;
    left->next = NULL;
         
    NODEPTR temp;
    while(right != NULL)
    {
        temp = right;
        right = right-> next;
        temp->next=left;
        left = temp;
    }

    *head = left;
}

//Reverse using 2 temporay variables
void reverse_two_variables(NODEPTR * head)
{
    if(*head == NULL || (*head)->next == NULL) return;
    
    NODEPTR prev = *head;
    NODEPTR curr = prev->next;
    prev->next = NULL;
         
    //NODEPTR temp;
    while(curr != NULL)
    {
        *head = prev;
        prev = curr;
        curr = curr-> next;
        prev->next = *head;
        *head = prev;
    }
}


//Reverse using 2 temporary variables - optimized code
void reverse_two_variables_optimized(NODEPTR * head)
{
    NODEPTR prev = NULL;
    NODEPTR current = *head;
    
    while(current != NULL)
    {
        *head = current;
         current = current->next;
         (*head)->next = prev;
         prev = *head;
    }
}


NODEPTR head;
int main()
{
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    cout<<"Before reversing linked list : ";
    display(head);
    
    cout<<"After reversing linked list  : ";
    reverse_two_variables_optimized(&head);
    display(head);
    
    cout<<"Original list after reversing list again  : ";
    reverse_two_variables_optimized(&head);
    display(head);
    return 0;
}
