/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 6 - Task 2 (b): Sample Solution                                 *
 *                                                                          *
 * @date 2022-02-28                                                         *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void displayList(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    if (current->next != NULL) {
      printf(" %d ->", current->data);
    } else {
      printf(" %d", current->data);
      printf("\n");
    }
    current = current->next;
  }
}

struct Node* insertList(struct Node *head, int data) {
  if (head == NULL) {
    head = malloc(sizeof(struct Node));
    head->data = data;
    head->next = NULL;
    return head;
  } else {
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *current = head;
    newNode->data = data;
    newNode->next = NULL;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
    return head;
  }
}

struct Node* groupingLinkedList(struct Node *head) {
  struct Node *odd = NULL;
  struct Node *even = NULL;
  struct Node *groupedList = NULL;
  struct Node *current = head;

  while (current != NULL) {
    if (current->data % 2 == 0) {
      even = insertList(even, current->data);
    } else {
      odd = insertList(odd, current->data);
    }
    current = current->next;
  }
  groupedList = odd;
  current = groupedList;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = even;
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
