/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 7 - Task 2                                                      *
 *                                                                          *
 * @author <Dario Alberto Monopoli>                                                      *
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h> //to use malloc and free functions
#include <stdbool.h>
typedef struct Stack {
	unsigned int capacity; //size of the dinamically allocated array (how many int can it sotore)
	int* items; //pointer to dinamically allocated array of integers
  	int top; //tracks the number of elements in the stack
} Stack;

//(a) correct
Stack *create(unsigned int capacity) //only accepts capacities greather than 0
{
    Stack *stack = malloc(sizeof(Stack));
    stack->items = malloc(sizeof(int) * capacity);
    stack->capacity = capacity; //initial state of the stack
    stack->top = -1; //initial state of the stack (no elements)
    return stack;

}
//(b) correct
void delete(Stack *stack)
{
    free(stack->items); //frees memory for dynamic allocated array
    free(stack); //frees memory for stack itself  
}
//(c) correct
bool is_empty(Stack *stack)
{
    if (stack->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//(d) correct
bool is_full(Stack *stack)
{
    if (stack->capacity == stack->top)
    {
        return true;
    }
    else
    {
        return false;
    }

}
//(e): correct
int get_capacity(Stack *stack){
     if (stack->top == -1)
     {
        printf("This stack has no capacity");
     }
     else
     {
     printf("The capacity of the stack is: %u", stack->capacity);
     }
 }
//(f) works
int num_items(Stack *stack){
    int counter = 0; 
    for(int i = stack->top; i>=0; i--)
        {
        counter++;
        }
    return counter;
}
//(g) correct
void push(Stack *stack, int item) {
   if(is_full(stack)){
   printf("Stack Overflow (stack is full), cannot push %d to the stack\n", item);
   }
   else {
        stack->top++;
        stack->items[stack->top] = item;
   }       
}
//(h) correct 
int pop(Stack *stack) {
   if(is_empty(stack)){
   printf("no elements are in the stack, pop operation not possible to execute\n");
   }
   else {
        
        int val = stack->items[stack->top];
        stack->top--;
        return val;   
   }
}
//(i) works
int peek(Stack *stack)
{
   if (!is_empty(stack)){
        return stack->items[stack->top]; //this one returns the last lmao
   }
}
//(j) correct
void print(Stack *stack)
{
    int i;
    if(is_empty(stack))
    {
        printf("No elements are in the stack, the stack is empty\n");
    }
    else
    {
    printf("Stack: \n");
    for(i = 0; i<=stack->top; i++)
    {
        printf("%d ",stack->items[i]);
    }
    }
}
//(k) correct
bool is_equal(Stack *stack1, Stack *stack2)
{
    bool flag = true;
    if (num_items(stack1)!=num_items(stack2)) //two stacks can't be equal if they don't have the same amount of elements
    {
        flag = false;
        return flag;
    }
    Stack *stack1_copy = stack1;
    Stack *stack2_copy = stack2;
        while (!is_empty(stack1)) // makes no difference if i choose stack2 or stack1 (since they have the same size)
        {
            if (peek(stack1_copy)==peek(stack2_copy))
            {
                pop(stack1_copy);
                pop(stack2_copy);
            }
            else{
                flag = false;
                break;;
            }
        }
    return flag;
}
//(l)
void reverse(Stack *stack)
{
    int length = stack->top;
    Stack *copy_stack = create(stack->capacity);

    for(int i = stack->top; i>=0; i--) //pushing elements from the original task to a provisory stack (so to not lose the elements)
    {
        push(copy_stack,stack->items[i]);
    }
    for(int i = 0; i<=length; i++) //removing elements from original stack
    {
        pop(stack);
    }

   for(int i = 0; i<=copy_stack->top  ; i++) //pushing the elements (that are in reversed order) from the provisory stack to the original stack
   {
       push(stack,copy_stack->items[i]);
   }
   print(stack);
}
   
int main() {
    Stack *stack = create(5);
    push(stack, 2);
    push(stack, 7);
    push(stack, 4);
    push(stack, 9);
    print(stack);
    printf("\n The stack has %d items\n", num_items(stack));
    printf("\n the popped element is %d\n", pop(stack));
    printf("\nReversed ");
    printf("\n The stack has %d items\n", num_items(stack));
    reverse(stack); 
  return 0;
}
