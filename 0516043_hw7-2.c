#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int n;
    struct Node *next;
}node;
node b[200];
int bi = 0;
void in(node* fr, int k) {
    b[bi].n = k;
    b[bi].next = NULL;
    node *n = b[bi++];
    n->next = fr->next;
    fr->next = n;
    fr = n;
}
void swap(node* i) {
    node *n1 = i->next;
    node *n2 = n1->next;
    node *n3 = n2->next;
    // i -> n1 -> n2 -> n3

    i->next = n2;
    n2->next = n1;
    n1->next = n3;
    // i -> n2 -> n1 -> n3
}
void prin(node *b) {
    while (b != NULL) {
        printf("%d ",b->n);
        b = b->next;
    }
}
int main() {
    b[bi].n = -1;
    b[bi].next = NULL;
    node *head = b[bi++];
    node *tail = head;
    int a=48;
    char c;
    while (scanf("%d", &a) == 1)
        in(tail, a);
    scanf("%c", &c);
    printf("Output:");
    for (node *j = head->next ; j != NULL ; j = j->next)
        for(node *i = head ; i->next->next != NULL ; i = i->next)
            if (i->next->n < i->next->next->n)
                swap(i);
    prin(head->next);
    printf("\n");
        system("pause");
    return 0;
}
