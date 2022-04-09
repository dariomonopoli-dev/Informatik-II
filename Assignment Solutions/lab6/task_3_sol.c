/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 6 - Task 3 (b, c): Sample Solution                              *
 *                                                                          *
 * @date 2022-04-04                                                         *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node {
  char data;
  struct Node *next;
};

void displayList(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    if (current->next != NULL) {
      printf(" %c ->", current->data);
    } else {
      printf(" %c", current->data);
      printf("\n");
    }
    current = current->next;
  }
}

struct Node *insertList(struct Node *head, char data) {
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


void swap_nodes(struct Node *prev, struct Node *cur) {
  // before swap: prev->cur->ne->temp
  // after swap: prev->ne->cur->temp
  struct Node * ne = cur->next;
  struct Node * temp = ne->next;
  prev->next = ne;
  ne->next = cur;
  cur->next = temp;
  return;
}

/* Bubble sort the given linked list */
struct Node * bubbleSort(struct Node *head) {

  /* early termination */
  if (head == NULL || head->next == NULL) return head;

  struct Node *dummy = malloc(sizeof(struct Node));
  dummy->next = head;
  struct Node *last = NULL;

  while(dummy->next != last){
    struct Node * prev = dummy;
    struct Node * cur = prev->next;
    while(cur->next != last) {
      if(cur->data > cur->next->data) {
        swap_nodes(prev, cur); // after swap, j = j->next;
      } else {
        cur = cur->next;
      }
      prev = prev->next;
    }
    last = cur; // elements from last are sorted.
  }
  head = dummy->next;
  free(dummy); // delete dummy node 
  return head;
}

void isAnagram(struct Node *s1, struct Node *s2) {
  struct Node *s1_cur = s1;
  struct Node *s2_cur = s2;
  while (s1_cur != NULL) {
    if (s1_cur->data != s2_cur->data) {
      printf("letter in s1 '%c' is not the same as in s2 '%c'.\n", s1_cur->data,
             s2_cur->data);
      printf("Not Anagram!\n");
      return;
    }
    s2_cur = s2_cur->next;
    s1_cur = s1_cur->next;
  }
  printf("Anagram!\n");
}

int main() {
  char ch;
  struct Node *s1_head = NULL;
  struct Node *s2_head = NULL;

  printf("Enter the first string s1 \n");
  while ((ch = getchar()) != '\n') {
    s1_head = insertList(s1_head, ch);
  }
  printf("Enter the second string s2 \n");
  while ((ch = getchar()) != '\n') {
    s2_head = insertList(s2_head, ch);
  }
  s1_head = bubbleSort(s1_head);
  s2_head = bubbleSort(s2_head);
  isAnagram(s1_head, s2_head);
  displayList(s1_head);
  displayList(s2_head);
}