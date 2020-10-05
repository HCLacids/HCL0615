#include <stdio.h>
#include <stdlib.h>
#define n 5
#define maxSize 10

//???洢 

void insert(int a[],int number){
	int i, j;
	for(i = 0; i < n; i++){
		if(a[i] <= number && a[i + 1] >= number){
			for(j = n - 1; j > i + 1; j--){
				a[j] = a[j-1];
			}
			a[i + 1] = number;
			break;
		}
	}
} 

//????洢

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

void insert_link(List *node, int x){
	List *i;
	while (node->next !=NULL && x >= node->data){
		node = node->next;
	}
	i = (List *)malloc(sizeof(List));
	i->data = x;
	i->next = node->next;
	node->next = i;
}


int main(){
	//???洢  ???迪??????? 
	int a[n] = {1,2,5,6},i;
	int x;
//	scanf("%d",&x);
	insert(a,4);
	for(i = 0;i < n; i++){
		printf("%d",a[i]);
	}
	puts("\n");
	//????洢
	List *node;
	node = create();
	insert_link(node,5);
	print(node);
	return 0;
} 
