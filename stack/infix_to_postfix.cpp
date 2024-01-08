#include <stdio.h>
#include <ctype.h>
//Global Variables
char stack[200];
int top = -1;

void push(char x)
{
	stack[++top] = x;
}

char pop()
{
	if(top==-1)
	{
		return 0;
	}else{
		return stack[top--];
	}
}

int pr(char x)
{
	if(x=='(')
	{
		return 0;
	}
	if(x=='+'||x=='-')
	{
		return 1;
	}
	if(x=='*'||x=='/')
	{
		return 2;
	}
	return 0;
}

int main()
{
	char exp[200];
	char *e, x;
	scanf("%s", exp);
	e = exp;
	while(*e!='\0')
	{
		if(isalnum(*e))
		{
			printf("%c", *e);
		}
		else if(*e=='(')
		{
			push(*e);
		}
		else if(*e==')')
		{
			while((x=pop())!='(')
			{
				printf("%c", x);
			}
		}
		else{
			while((pr(stack[top]))>=(pr(*e)))
			{
				printf("%c", pop());
			}
			push(*e);
		}
		e++;
	}
	while(top!=-1)
	{
		printf("%c", pop());
	}
}
