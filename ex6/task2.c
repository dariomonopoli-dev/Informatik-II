#include <stdio.h>
#include <stdlib.h> //needed for memory allocation

struct Node{
    int data;
    struct Node* next;
};
struct Node*head;

void InsertList(struct Node** head, int val)
{

//create a new node
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

     //if head is NULL, it is an empty list
    if(*head == NULL)
    {
        *head = newNode; //i create a node
    }

    //Otherwise, find the last node and add the newNode
    else
    {
        struct Node *lastNode = *head;
        

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
      

    }

}
struct Node *groupingLinkedList(struct Node* head)
{
        //Initialize first nodes of even and odd lists
    struct Node *odd = head; //odd numbers have to be at beginning
    struct Node *even = head->next; //after all the odd elememnts i insert the even ones

    // Remember the first node of even list so
    // that we can connect the even list at the
    // end of odd list.
    struct Node *evenFirst = even;
    
    while (1)
    {
        

        // Connecting odd nodes
        odd->next = even->next;
        odd = even->next;

        // If there are no more nodes, then connect
        // first node of even list to the last node
        // of odd list
        if (odd->next == NULL)
        {
            even->next = NULL;
            odd->next = evenFirst;
            break;
        }

        // Connecting even nodes
        even->next = odd->next;
        even = odd->next;

    }
 
    return head;
    //Θ(n) Time Complexity: the running time increases linearly with the size of the input (goes through each element)
    //O(n) Space Complexity: the amount of data stored increases linearly with the number of nodes in the list.


    
}
void displayList(struct Node *head)
{

    struct Node *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}
int main()
{
    struct Node *head = NULL;
    InsertList(&head,1);
    InsertList(&head,10);
    InsertList(&head,17);
    InsertList(&head,2);
    InsertList(&head,15);

    groupingLinkedList(head);
    displayList(head);
    

    return  0;
}