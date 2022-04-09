#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};


struct Node* insertList(struct Node *head, int data) {
	//what if the list is empty!? --> list is empty if head pointer == NULL
	
	if (head == NULL){
		//dynamic memory allocation with malloc
		//specify how many bytes we "need", and malloc reserves this and returns a pointer to it
		//after reserving memory, we know WHERE to store the struct
		head = malloc(sizeof(struct Node));
		
		//head is a pointer, so we have to dereference it (follow the pointer!) and then access the elements
		head -> data = data;
		head -> next = NULL;
		return head;
	}else{
		struct Node *newNode = malloc(sizeof(struct Node));
		
		//add the data to the new pointer
		newNode -> data = data;
		//we create a temporary pointer called "current" which we can move through the whole list
		
		struct Node *current = head; //WE don't ned to allocate memory for the current pointer, because we don't need it
		//after function finishes (i.e., no malloc)
		
		//since we insert newNode at the end, it must point to NULL
		newNode -> next = NULL;

		//loop through the linked list, until we reach the end
		while(current -> next != NULL){
			current = current -> next; //"moving the pointer to the next element"
		}
		current -> next = newNode; //we make the previously last element point to the new last element (=newNode)
		return head;
	}
}


//idea --> loop through the list until we reach null pointer

void displayList(struct Node *head){
	//again, create a temporary pointer!
	struct Node *current = head;
	while(current != NULL){
		if (current -> next != NULL){ //so we check if were not at the LAST element of the linked list
			printf(" %d ->", current->data);
		}else{
			printf(" %d \n", current->data); //othterwise, print the last element without an arrow
		}
		current = current -> next; //change where current points to, i.e., change the pointer
	}
}


struct Node* groupingLinkedList(struct Node *head) {
	//initialize 2 struct Node pointers (our two new lists)
	//grouped list pointer --> which is the list we will return
  struct Node *odd = NULL;
  struct Node *even = NULL;
  
  struct Node *groupedList = NULL;
  struct Node *current = head;

  while (current != NULL) { //loop through the original list
    if (current->data % 2 == 0) { //if data even (current node)
      even = insertList(even, current->data); //as arguments, head of even list, and the even data,  fct will return head to even list again
    } else {
      odd = insertList(odd, current->data);
    }
    current = current->next; //move through original list
  }
  
  groupedList = odd; //since first come the odd elements!
  current = groupedList;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = even; //make the END of the odd list, point to the even list (connect even and odd list!!)
  return groupedList;
}



int main() {
  int n, x, i;
  struct node *l;
  struct Node *head = NULL;
  printf("Input the number of nodes: ");
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    printf("Input the data of the node %d:  ",i);
    scanf("%d", &x);
    head = insertList(head, x);
  }
  printf("Before Grouping:");
  displayList(head);
  struct Node *gList = groupingLinkedList(head);
  printf("After Grouping:");
  displayList(gList);
  return 0;
}
