#include<stdio.h>

//fwd is x*3+1
void fwd(unsigned long int *x);
//bwd is x:2
void bwd(unsigned long int *x);
//search max value hailstone number
void srchMax (unsigned long int *x);
//logic Collatz
void Collatz (unsigned long int *x);

static unsigned long int max = 0;

int main()
{
	unsigned long int x;
	unsigned long int *p;

	printf("%s", "input x: ");
	scanf("%lu", &x);

	p=&x;
	
	Collatz(p);
	
	printf("max value: %lu\n", max);
	printf("%s\n", "The end...");
}

void fwd(unsigned long int *x)
{
	*x = *x * 3 + 1;
}

void bwd(unsigned long int *x)
{
	*x = *x / 2;
}

void srchMax (unsigned long int *x)
{
	if(*x > max)
	{
		max = *x;
	}
}

void Collatz(unsigned long int *x)
{
	unsigned long int i = 0;
	while(1)
	{
		if(*x == 1)
		{
			printf("finale step %lu\n", i);
			break;
		}
		else if(*x  % 2 == 0)
		{
			printf("%lu. Number is even: %lu\n",i,*x);
			bwd(x);
		}
		else
		{
			printf("%lu. Number is odd: %lu\n",i,*x);
			fwd(x);
		}
		
		srchMax(x);

		i = i + 1;
	}	
}
