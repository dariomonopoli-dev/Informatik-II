/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 7 - Task 2                                                      *
 *                                                                          *
 * @author <Dario Alberto Monopoli>                                                      *
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
	unsigned int capacity;
	int* items;
  	int top;
} Stack;

//(a)
void create(Stack *stack)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1; //initial state of the stack

}
//(b) very wrong
void delete(Stack *stack){
    if (stack->top == NULL)
    {
        printf("Cannot delete an empty stack\n");
    }
    else{
    free(stack);
    }
}
//(c) correct
int is_empty(Stack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
//(d) correct
int is_full(Stack *stack)
{
    if (stack->top == s->items - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
//(e): 100% wrong-> TODO
int get_capacity(Stack stack){
    if (stack->top==NULL)
    {
        printf("This stack has no capacity");
    }
    else
    {
    printf("The capacity of the stack is: %i", stack.capacity);
    }
}
//(f) to test 
int num_items(Stack stack){
    int counter = 0;
    while(stack!=NULL)
    {
      counter++;
    }
   

    return counter;
}
//(g) correct
void push(Stack *stack, int val) {
   if(is_full(stack)){
   printf("Stack Overflow (stack is full), cannot push %d to the stack", val);
   }
   else {
        stack->top++;
        stack->items[stack->top] = val;
   }
}
//(h) correct but not cheggt
void pop(Stack *stack) {
   if(is_empty(stack)){
   printf("no elements are in the stack, pop operation not possible to execute");
   }
   else {
        printf("%d is the popped item",stack->items[stack->top]);
        stack->top--;
   }
}
//(i) to test (probably wrong)
int peek(Stack *stack)
{
   
        return stack->items[stack->top]; //this one returns the last lmao
}

//(j) (probably wrong)
void print(Stack *stack)
{
    int i;
    if(is_empty(stack))
    {
        printf("No elements are in the stack, the stack is empty\n");
    }
    else
    {
    printf("stack is: \n");
    for(i = num_items(stack); i>=0; i--)
        {
        printf("%d ", stack[i]);
        }
    }
}
//(k)

//(l)
void reverse(Stack *stack)
{
}
   
int main() {
  return 0;
}
