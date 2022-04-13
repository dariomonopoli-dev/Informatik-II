
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Stack {
	unsigned int capacity; //size of the dinamically allocated array (how many int can it sotore)
	int* items; //pointer to dinamically allocated array of integers
  	int top; //tracks the number of elements in the stack
} Stack;
Stack *create(unsigned int capacity) //only accepts capacities greather than 0
{
    Stack *stack = malloc(sizeof(Stack));
    if(!stack)
    {
        return NULL;
    }
    stack->items = malloc(sizeof(int) * capacity);
    stack->capacity = capacity; //initial state of the stack
    stack->top = -1; //initial state of the stack (no elements)
    return stack;

}
void delete(Stack *stack)
{
    free(stack->items); //frees memory for dynamic allocated array
    free(stack); //frees memory for stack itself  
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
        
        stack->top--;
        int val = stack->items[stack->top + 1];
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

void get_span(int data[], int num_data, int* spans)
{
	//first span value is always 1
	spans[0] = 1;

	for (int i = 1; i < num_data; i++) {
		spans[i] = 1; // Initialize span value (is atleast 1)
		for (int j = 0; j<=i-1; j++)
        {
            if (data[j]<=data[i])
            {
		    spans[i]++;
            }
        }
	}
}
void get_span_better(int data[], int num_data, int* spans) //made by TAs
{
	Stack* helper_stack = create(num_data);
  for (int i = 0; i < num_data; i++) {
    while (!is_empty(helper_stack) && data[i] >= data[peek(helper_stack)]) {
      pop(helper_stack);
    }
    if (is_empty(helper_stack)) {
      spans[i] = i + 1;
    }
    else {
      spans[i] = i - peek(helper_stack);
    }
    push(helper_stack, i);
  }
  delete(helper_stack);

}
int main()
{
	int data[] = {6,3,4,5,2};
	int num_data= sizeof(data) / sizeof(data[0]);
	int spans[num_data];

	get_span_better(data, num_data, spans);
	for(int i = 0; i< num_data; i++)
    {
        printf("%d ",spans[i]);
	}
	return 0;
}
