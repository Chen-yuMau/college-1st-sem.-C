#include <stdlib.h>
#include <stdio.h>
#define kinds 4
int d[kinds]={50,10,5,1};
typedef struct stack{
	int top;
	int stk[100];
}stack;
stack ss;
void test()
{
     int i=0;
     for(i=0;i<200;i++)
     {
     if(ss.stk[i]!=0)
     {
     printf("   %d",ss.stk[i]);
     }
     }
}
void push(int i)
{
ss.stk[ss.top]=i;
printf("i=%d pushed!\n",i);//
test();
ss.top++;
}
int pop()
{
int w;
w=ss.stk[ss.top-1];
printf("w=%d popped!\n",w);//
test();
ss.stk[ss.top-1]=0;

ss.top--;
return(w);
}

int prin()
{
	int i=0,c=0;
	int fuck=0;
	for(i=0;i<kinds;i++)
	{
        for(fuck=0;fuck<200;fuck++)
	    {
		
		     if(ss.stk[fuck]==d[i])
		     {
             c++;
             }
		     
	     }
         if(c>99)
		{
		printf(" %d ",c);
		}
		else if(c>9)
		{
		printf(" %d  ",c);
		}
		else
		{
		printf(" %d   ",c);
		}
	     c=0;
    }
	printf("\n");
    //test();
	return(1);
    
}
void facevalue(int k)
{
	int i;
	for(i=0;i<kinds;i++)
	{
		if(d[i]>99)
		{
		printf("$%d ",d[i]);
		}
		else if(d[i]>9)
		{
		printf("$%d  ",d[i]);
		}
		else
		{
		printf("$%d   ",d[i]);
		}
		
	}
	printf("\n");
}
int cc(int m,int k)
{
    
	int i=0;
    if(m==0)
	{
    //printf("      e answer found coins lefts m:%d d:%d\n",m,d[k]);
	
	return(prin());
	
	}
	if(m>=d[k])
	{
                   push(d[k]);
                   printf("       b\n");
                   m=m-d[k];
    }
	if((m-d[k])>0)
	              {
                  i=i+cc(m,k);
                  }
    else if((m-d[k])<0)
                  {
                  i=i+cc(m,k+1);
                  }
    if(k+1<kinds)
    {
    m=m+pop();
    i=i+cc(m,k+1);
    printf("        c\n");
    }
	return(i);
}
void ui()
{
printf("enter amount of money:  ");
//printf("a start\n");

int money;
scanf("%d",&money);
facevalue(4);
printf("There are %d ways to make change\n\n",cc(money,0));
ui();
}
int main()
{
    ss.top=0;
     int i=0;
     for(i=0;i<200;i++)
     {
     ss.stk[i]=0;
     }
	ui();
	return(0);
}
