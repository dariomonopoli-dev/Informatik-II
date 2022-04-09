// C++ implementation of above approach
#include <stdio.h>
#include <task2.c>
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
typedef struct Stack {
	unsigned int capacity;
	int* items;
  	int top;
} Stack;

// Function to check validity of stack sequence
int validateStackSequence(int pushed[], int popped[], int len){
	
	// maintain count of popped elements
	int j = 0;
	
	// an empty stack
	Stack *stack;
	for(int i = 0; i < len; i++){
		stack.push(pushed[i]);
		
		// check if appended value is next to be popped out
		while (!stack.isEmpty() && j < len && st.top() == popped[j]){
			st.pop();
			j++;
		}
	}
	
	return j == len;
}

// Driver code
int main()
{
int pushed[] = {1, 2, 3, 4, 5};
int popped[] = {4, 5, 3, 2, 1};
int len = sizeof(pushed)/sizeof(pushed[0]);
	
cout << (validateStackSequence(pushed, popped, len) ? "True" : "False");
	
return 0;
}

// This code is contributed by Rituraj Jain
