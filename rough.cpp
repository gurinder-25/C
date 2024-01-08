#include<stdio.h>


#define n 50

int stack[n], minStack[n], top = -1, mtop = -1;

int push(int value)
{
	if(top==n-1)
	{
		printf("Overflow\n");
	}
	top++;
	stack[top] = value;
	if(mtop=-1 || value<=minStack[mtop])
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
	if(popped_value == minStack[mtop])
	{
		mtop--;
	}
	return popped_value;
}

int getMin()
{
	if(top==-1)
	{
		printf("Stack Empty\n");
	}
	return minStack[mtop]; 
}

int main()
{
	push(10);
	printf("Minimun value: %d\n", getMin());
	push(5);
	printf("Minimun value: %d\n", getMin());
	push(3);
	printf("Minimun value: %d\n", getMin());
	push(16);
	printf("Minimun value: %d\n", getMin());
	pop();
	printf("Minimun value: %d\n", getMin());
}
