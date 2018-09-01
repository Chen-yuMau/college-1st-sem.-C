#include<stdio.h>
#include<stdlib.h>
char pic[100][100]={0};
char pico[100][100]={0};
char buf[100]={0};

int reverse()
{

    int i;//
    int j;
    for(i =0;i<80;i++)
    {
        for(j=0;j<80;j++)
        {
        pic[i][j]= pico[i][80-j];
		}
        	
	}//
    
   
    return 0;
}
int printimage()
{
	int i;
	int j;
	for(i =0;i<40;i++)
    {
    	for(j=0;j<100;j++)
    	{
		printf("%c",pic[i][j]);
		}    	
	}
	return(0);
}
int main()
{



    FILE *fp;
	int r;
	char go[50];
	scanf("%s",&go);
	fp = fopen(go,"r");
    for(r=0;fgets(pico[r], 100, fp) != NULL;r++)
    {
    
    }

	reverse();
	printimage();
	
	
	
	fclose(fp);
}
	
