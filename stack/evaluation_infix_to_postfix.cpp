#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int numbers[50], tn=-1, to=-1;
char op[50];
void push_num(int n)
{
	numbers[++tn] = n;
}
void push_op(char c)
{
	op[++to]=c;
}
int pop_num()
{
	return numbers[tn--];
}
int pop_op()
{
	return op[to--];
}
int pr(char c)
{
	switch(c)
	{
		case '+':
			return  1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
	}
	return -1;
}
int is_operator(char c)
{
	return (c=='+' || c=='-' || c=='*' || c=='/');
}
int infix_eval(int numbers[50], char op[50])
{
	int x, y;
	char ope;
	x = pop_num();
	y = pop_num();
	
	ope = pop_op();
	
	switch(ope)
	{
		case '+':
			return x+y;
		case '-':
			return x-y;
		case '*':
			return x*y;
		case '/':
			return y/x;
	}
	return 0;
}
int eval(char exp[50]) {
    int i, num, output, r;
    char c;
    for (i = 0; exp[i] != '\0'; i++) {
        c = exp[i];
        if (isdigit(c) != 0) {
            num = 0;
            while (isdigit(c)) {
                num = num * 10 + (c - '0');
                i++;
                if (i < strlen(exp)) {
                    c = exp[i];
                } else {
                    break;
                }
            }
            i--;
            push_num(num);
        } else if (c == '(') {
            push_op(c);
        } else if (c == ')') {
            while (op[to] != '(') {
                r = infix_eval(numbers, op);
                push_num(r);
            }
            pop_op();
        } else if (is_operator(c)) {
            while (to != -1 && pr(c) <= pr(op[to])) {
                output = infix_eval(numbers, op);
                push_num(output);
            }
            push_op(c);
        }
    }
    while (to != -1) {
        output = infix_eval(numbers, op);
        push_num(output);
    }
    return pop_num();
}

int main()
{
	char exp[50];
	printf("Enter Expression: \n");
	scanf("%s", exp);
	printf("%d", eval(exp));
}
