#include <stdio.h>
#include<cstdlib>

typedef struct BiLink{
    struct BiLink *prior;
    struct BiLink *next;
    int data;
}Link;

Link* init(){
    Link *head;
    head = (Link*)malloc(sizeof(Link));
    head->prior=NULL;
    head->next=NULL;
    head->data=1;
    Link * list=head;
    for (int i=2; i<=3; i++) {
        Link * body=(Link*)malloc(sizeof(Link));
        body->prior=NULL;
        body->next=NULL;
        body->data=i;
        list->next=body;
        body->prior=list;
        list=list->next;
    }
    return head;
}

int get_length(Link* node){
    int length=0;
    Link*p = node->next;
    while(p)
    {
        length++;
        p=p->next;
    }
    return length;
}

int get(Link* h,int i)  {
    Link* p=h;
    int j=0;
    while(p&&(j<i)){
        p=p->next;
        j++;
    }
    return p->data;
}

int main(){
    Link *node;
    node = init();
    printf("%d\n",get_length(node));
    printf("%d\n",get(node,1));
    return 0;
}