#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node *next;
} List;

List *create(){
	List *head,*node,*end;
	end = head = (List *)malloc(sizeof(List));
	for(int i = 0; i < 5; i++){
		node = (List *)malloc(sizeof(List));
		node->data = i;
 		end->next = node;
 		end = node;
	}
	node->next = NULL;
	return head;
} 
void print(List *node){
	int i;
	while (node->next != NULL){
		node = node->next;
		printf("%d",node->data);
	}

}

void delete_elem(List *node, int x){
    while (node->next != NULL && node->next->data != x){
		node = node->next;
	}
   List *p = node,*q = node->next;
    p->next = q->next;
    free(q);
}

int main(){
    List *node;
    int x;
	node = create();
    scanf("%d",&x);
    delete_elem(node,x);
    print(node);
    return 0;
}
