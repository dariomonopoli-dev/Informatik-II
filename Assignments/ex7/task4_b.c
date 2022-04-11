// C++ implementation of above approach
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/****************************************************************************
 * Approach:                                                                 
 * we will start iterating on input array and storing its element one by    *
 * one in a stack and if top of our stack matches with an element in output * 
 * array we will pop that element from stack and compare next element of    *
 * output array with top of our stack if again it matches then again pop    *
 * until our stack isn’t empty.                                             *
 *                                                                          *
 * @author <Dario Alberto Monopoli>                                         *
 ****************************************************************************/
typedef struct Stack {
	unsigned int capacity;
	int* items;
  	int top;
} Stack;
Stack *create(unsigned int capacity) //only accepts capacities greather than 0
{
    Stack *stack = malloc(sizeof(Stack));
    stack->items = malloc(sizeof(int) * capacity);
    stack->capacity = capacity; //initial state of the stack
    stack->top = -1; //initial state of the stack (no elements)

}
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
void push(Stack *stack, int item) {
   if(is_full(stack)){
   printf("Stack Overflow (stack is full), cannot push %d to the stack\n", item);
   }
   else {
        stack->top++;
        stack->items[stack->top] = item;
   }       
}
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
        return stack->items[stack->top]; //returns the element at the top of the stack
   
}
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
// Function to check if second array can be achieved with a pop and push sequence of the first one
bool validateStackSequence(int In[], int Out[], int len){
    int i = 0;
	int j = 0;
    Stack *stack = create(len);
    //we iterate an element one by one in input array
    for(i = 0; i < len; i++)
    {
        //pushed an element from input array to stack
        push(stack, In[i]);
        
        // if our stack isn't empty and top matches with output array
        // then we will keep popping out from stack uptill top matches with
        // output array
        while(!is_empty(stack)&&peek(stack)==Out[j])
        {
            pop(stack);
            //incresing j so we can compare next element in output
            j++;
        }   
    }
    if(is_empty(stack)) //if the arrays
    {
        return true;
    }
    return  false;   
}



// Driver code
int main()
{
int In[] = {1, 2, 3, 4, 5};
int Out[] = {4,5,3,2,1};
int len = sizeof(In)/sizeof(In[0]); //the size of pushed and popped is equal

	
if (validateStackSequence(In, Out, len))
{
	printf("True");
}
else
{
	printf("False");
}
	
return 0;
}

