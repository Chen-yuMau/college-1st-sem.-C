#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char c;
    struct Node *next;
}Node;


void append(Node *p_now, Node n[], int i, char str[])
{
    n[i].c=str[i]; //take a word from input and put it into the node
    (*p_now).next=&n[i+1]; //link the next node
}

//print reversely
void reverse(Node *p)
{
    if(p->next->c != NULL)
    {
        reverse((*p).next);
    }
    printf("%c",(*p).c);
}


int main()
{
    char str[100];
    Node n[100];
    int i;

    printf("Enter a string:\nbvcxz");
    scanf("%s",str);

    //append
    for(i=0 ; i<=strlen(str) ; i++)
    {
        append(&n[i], n, i, str);
    }

    //reverse
    reverse(&n[0]);

    return 0;
}
