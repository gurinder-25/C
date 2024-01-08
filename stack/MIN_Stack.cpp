#include <stdio.h>
#define max_size  200

int stack[max_size], minStack[max_size], top=-1, mtop=-1;

int push(int value)
{
	if(top==max_size -1)
	{
		printf("Overflow\n");
	}
	top++;
	stack[top] = value;
	if(mtop == -1 || value <= minStack[mtop])
	{
		mtop++;
		minStack[mtop] = value;
	}
}

int pop()
{
	if(top==-1)
	{
		printf("Underflow\n");
	}
	int popped_value = stack[top--];
	if(popped_value==minStack[mtop])
	{
		mtop--;
	}
	return popped_value;
}

int getMin()
{
	if(mtop==-1)
	{
		printf("Stack Empty\n");
	}
	return minStack[mtop];
}

int main()
{
	push(10);
	printf("Minimum value is: %d\n", getMin());
	push(5);
	printf("Minimum value is: %d\n", getMin());
	push(3);
	printf("Minimum value is: %d\n", getMin());
	push(16);
	printf("Minimum value is: %d\n", getMin());
	pop();
	printf("Minimum value is: %d\n", getMin());
	pop();
	printf("Minimum value is: %d\n", getMin());
}
