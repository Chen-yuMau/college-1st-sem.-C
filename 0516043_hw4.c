#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
	while(1)
	{
	int m=1,n=1,i=0,j=0;
	
	printf("Please input two numbers:\n");
	scanf("%d%d",&m,&n);
	char a[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]='.';
			
		}
	}
	srand(time(NULL));
	
	int letter= 65;
	int cx=0,cy=0;
	a[cx][cy]=letter;
	while(letter<90)
	{	
		int x= rand()%2;
		int y= rand()%2;
		if(x==0&&y==0&&a[cx][cy-1]=='.'&&cy-1>=0)
		{
		cy--;
		letter++;
		a[cx][cy]=letter;
		}
		if(x==1&&y==0&&a[cx+1][cy]=='.'&&cy+1<=m)
		{cx++;
		letter++;
		a[cx][cy]=letter;
		}
		if(x==0&&y==1&&a[cx-1][cy]=='.'&&cx-1>=0)
		{cx--;
		letter++;
		a[cx][cy]=letter;
		}
		if(x==1&&y==1&&a[cx][cy+1]=='.'&&cy-1<=n)
		{cy++;
		letter++;
		a[cx][cy]=letter;
		}
	 	else if((a[cx][cy+1]!='.'||cy+1>n)&&(a[cx+1][cy]!='.'||cx+1>m)&&(a[cx-1][cy+1]!='.'||cx-1<0)&&(a[cx][cy-1]!='.'||cy-1<0))
		{
			printf("Trapped!\n");
			break;
		}
		}
		
		for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	}
	
    
	system("pause");
	return(0);
}
