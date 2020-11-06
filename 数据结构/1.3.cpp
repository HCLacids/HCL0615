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

void sort(List *node,int x){
    int n = 0;
    while (node->next){
        if (node->data == x ){
            n++;
            if(n == 0) free(node);
        }
        
    }
    
}
