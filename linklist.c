#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char c;
    struct Node *next;
}node;


void append(node *saver, int i, char temp[])
{
    saver->next=NULL;
    saver->c=temp[i];  
}


void reverse(node *head)
{
    if(head->next->c != NULL)
    {
        reverse(head->next);
    }
    printf("%c",head->c);
}


int main()
{
    char temp[100];
    int i;
    node *saver;
    node *head;
    saver=head;
    scanf("%s",&temp);
    saver = malloc(sizeof(node)*strlen(temp));
    for(i=0 ; i<=strlen(temp) ; i++)
    {
        append(saver+i,i,temp);
    }

    reverse(head);

    return 0;
}
