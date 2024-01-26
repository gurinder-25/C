#include <iostream>
using namespace std;
/* 
       pattern 1 2 1 3 2 5 3 7 5 11 8 .......
       input = 0
       output = 1
       give the nth value in this pattern
*/
int fib(int t)
{
	int n = t/2;
	int a = 1, b = 1;
	int c;
	if(n==0 || n==1)
	{
		return 1;
	}
	for(int i=2;i<=n;i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

bool isPrime(int num)
{
	if(num<=1)
	{
		return 0;
	}
	for(int i=2;i*i<=num;i++)
	{
		if(num%i==0)
		{
			return 0;
		}
	}
	return 1;
}

int findPrime(int t)
{
	int n = (t+1)/2;
	int count = 0;
	int num = 1;
	while(count<n)
	{
		num++;
		if(isPrime(num))
		{
			count++;
		}
	}
	return num;
}

int main()
{
	int n;
	cin>>n;
	if(n%2==0)
	{
		cout<<fib(n);
	}
	else{
		cout<<findPrime(n);
	}
}
