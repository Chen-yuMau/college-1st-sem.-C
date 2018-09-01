#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{

long long int num;// original number
long long int n;// copy of number
long long int fact[100];
int i,j,k;
for(i=0;i<100;i++)
{
        fact[i]=0;
}
	while(1)
	{
        for( i=0;i<100;i++)
		{
        fact[i]=0;
        }
        int c=0;
		printf("Enter an unsigned integer >=2:");
		scanf("%lld",&num);
		n = num ;
		for(i=2;i<(sqrt(num)+1);i++)
		{
			if(n%i==0)
			{
				fact[2*c]=i;
				while(n%i==0)
				{
					n/=i;
					fact[2*c+1]=fact[2*c+1]+1;
				}
				c++;
			}
			else
            {
            }
		}
		if(n!=1)
		{
		fact[2*c]=n;
		fact[2*c+1]=1;
        }
	printf("prime factorization of %lld =",num);
	for(i=0;fact[2*i]!=0;i++)
	{
		if(fact[2*i+2]!=0)
		{
			printf("%lld ^ %lld * ",fact[2*i],fact[2*i+1]);
		}
		else
		{
			printf("%lld ^ %lld\n",fact[2*i],fact[2*i+1]);
		}
	}
	int divnum=1;//number of divisers
   for(i=0;fact[2*i+1]!=0;i++)
   {
   	divnum=divnum*(fact[2*i+1]+1);
   }
   printf("Number of divisors: %d\n",divnum);

   long long int timesprod=1;

   for(i=0;fact[2*i]!=0;i++)
   {
   	long long int addprod=1;
   	for( j=1;j<=fact[2*i+1];j++)
   	{
        int numpow=1;
        for(k=0;k<j;k++)
        {
               numpow=numpow*fact[2*i];
        }
   		addprod=addprod+numpow;
   	}
   	timesprod=timesprod*addprod;
   }
   printf("Sum of divisors : %lld\n",timesprod);
   long long int divpro;
if(divnum%2==0)
{
	for(k=0;k<(divnum/2);k++)
        {
        	n=n*num;
        }
        divpro=n;
}
else
{
	for(k=0;k<((divnum-1)/2);k++)
        {
        	n=n*num;
        }
	    divpro=n;
    divpro=divpro*(int)sqrt(num);
}
if(divpro>2147483647)
{
	printf("Product of divisors overflow!\n");
}
else
{
	printf("Product of divisors = %d\n\n",divpro);
}

	}
	system ("pause");
	return(0);
}
