#include <stdio.h>
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
	node = (List *)malloc(sizeof(List));
	node->data = 9;
 	end->next = node;
 	end = node;
 	end->next = NULL;
} 
void print(List *node){
	while(node->next!=NULL){
		printf("%d",node->data);
		node->next = node;
	}
}


int main(){
	//???洢  ???迪??????? 
	int a[n] = {1,2,5,6},i;
	int x;
	scanf("%d",&x);
	insert(a,x);
	for(i = 0;i < n; i++){
		printf("%d",a[i]);
	}
	puts("\n");
	//????洢
	List *node;
	node = create();
	print(node);
	return 0;
} 