#include <stdio.h>
#define  n 5
int arr[n];
int top = -1;
void push(int val)
{
	if(top==n-1)
	{
		printf("Overflow\n");
	}else{
		top+=1;
		arr[top]=val;
	}
}
int pop()
{
	if(top==-1)
	{
		printf("Underflow\n");
	}else{
	top-=1;
	}
}
int peek()
{
	if(top==-1)
	{
		printf("Stack is empty");
	}else{
		printf("Top element is: %d\n", arr[top]);
	}
}
int main()
{
	//stack underflow
	pop();
	//insertion of elements
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	//top element
	peek();
	//stack will overflow
	push(60);
	//remove top value
	pop();
	//display stack elements
	peek();
	return 0;
}
