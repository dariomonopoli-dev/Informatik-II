//Task 3C
#include <stdio.h>
#include <stdlib.h> //needed for memory allocation

// Structure for a node
struct Node{
    int data;
    struct Node* next;
};
struct Node*head;

// Function to sort the list
void bubbleSort(struct Node** head, int length)
{
	struct Node** h;
	int i, j, temp;

	for (i = length - 1; i > 1; i--) {

		h = head;

		for (j = 1; j <= i; j++) {

			struct Node* p1 = *h;
			struct Node* p2 = p1->next;

			if (p2->data < p1->data ) {

				struct Node* temp = p2->next;
                p2->next = p1;
                p1->next = temp;

				*h = p2;
			}

			h = &(*h)->next;
		
	}
}
}
//From Task 2
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


int checkAnagram(struct Node** head1, struct Node** head2, int s_length)
{

	// Sort the linked list
	bubbleSort(head1, s_length);
	bubbleSort(head2, s_length);

	struct Node* p1 = *head1;
	struct Node* p2 = *head2;
	int flag = 0;
	while (p1 != NULL) {
		if (p1->data == p2->data)
        {
			p1 = p1->next;
			p2 = p2->next;
		}
		else 
        {
			return 0;
		}
	}
    // If one of the linked list
    // doesn't end
    if (!p1 && !p2) {
        return 1;
    }
  
    return 0;

}


// Function to create linked lists
// from the strings
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

// Driver Code
int main()
{
	char s1[] = "albero";
	char s2[] = "caraff";

	int s_length;  //we assume that the two linked lists have the same length
    for (s_length = 0; s1[s_length] != '\0'; ++s_length); //to calculate the length of the first string
    

	// start with empty linked list
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;


    // Create linked list from the array s2 (Task 3b)
    for (int i = 0; i < s_length; i++) {
        InsertList(&head1, s1[i]);
    }
  
    // Create linked list from the array s2 (Task 3b)
    for (int j = 0; j < s_length; j++) {
        InsertList(&head2, s2[j]);
    }

    //we sort the two linked lists
    bubbleSort(&head1, s_length);
    bubbleSort(&head2, s_length);

	if (checkAnagram(&head1, &head2, s_length))
		printf("Yes");
	else
		printf("No");

	return 0;
}
