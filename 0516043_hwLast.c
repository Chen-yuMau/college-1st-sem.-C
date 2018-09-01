#include <stdio.h>
#include <stdlib.h>
typedef struct data
{
char placename[100];
int date[3];
int amount;
char unit[10];
}data;
data d[1000]={0};
int readfile()
{
	char temp[50];
	FILE *fp;
	int r;
	int k=0;
	fp = fopen("PM2.5.csv","r");
    for(r=1;fgets(temp, 100, fp) != NULL;r++)
    {
    	int i;
    	int j1=0;
    	int j2=0;
    	for(i=0;temp[i]!=',';i++)
    	{
    		d[r-1].placename[i]=temp[i];
    	}
    	for(i=i+1;temp[i]!=',';i++)
    	{
            if(temp[i]!='/')
            {
    		  for(i=i;(temp[i]!='/'&&temp[i]<58&&temp[i]>47)||temp[i]==32;i++)
    		  {
	 		    if(temp[i]!=32)
	 		    {
    			     j1=10*j1+(temp[i]-48);
    			}
    			if(temp[i]==',')
    			{
                     break;
                }
    		  }
    		  d[r-1].date[j2]=j1;
    		  j1=0;
    		  j2++;
            }
    	}
    	for(i=i+1;temp[i]!=',';i++)
    	{
    		k=10*k+(temp[i]-48);
    	}
    	d[r-1].amount=k;
    	for(i=i+1;temp[i]!=NULL;i++)
    	{
    		d[r-1].unit[i]=temp[i];
    	}
    	//printf("%s",temp);
    }
return(0);
}
int main()
{
	readfile();
int i;
for (i=0;i<1001;i++)
{
	printf("%s , %d/%d/%d , %d , %s , %d\n",d[i].placename,d[i].date[0],d[i].date[1],d[i].date[2],d[i].amount,d[i].unit,i+1);
}
system("pause");
return(0);
}
	
