
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char c;
    struct node *next;
}node;


void append(node *a, node n[], int i, char str[])
{
    n[i].c=str[i]; 
    a->next=&n[i+1]; 
}
/*

void reverse(node *b)
{
    if(b->next->c != NULL)
    {
        reverse(b->next);
    }
    printf("%c",b->c);
}//
*/

node* reverse(struct node *b){
	if ( b == NULL ){
		return (b);
	}
	else if ( b->next == NULL ){
		return (b);
	}
	node* c= reverse(b->next);

	b->next->next=b;
	b->next=NULL;

	return c;
}



int main()
{
    char c[200];
    node n[100];
    scanf("%s",c);
    node *head=n;
    node *cur;
    int i;
    for(i=0 ; i<=strlen(c) ; i++)
    {
        cur=&n[i];
        append(cur, n, i,c);
    }
    reverse(head);
    system("pause");
    return 0;
}
