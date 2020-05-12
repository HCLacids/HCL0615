#include <stdio.h> 
#include <string.h>

typedef	 struct staff{
	char name[10];
	long id;
}Staff;

void sort(Staff staff[]){
	for(int i = 0; i < 9; i++){
		for(int j = i;j < 10; j++){
			if(staff[j].id > staff[j + 1].id){
				Staff temp;
				strcpy(temp.name,staff[j].name);
				temp.id = staff[j].id;
				strcpy(staff[j].name,staff[j + 1].name);
				staff[j].id = staff[j + 1].id;
				strcpy(staff[j + 1].name,temp.name);
				staff[j + 1].id = temp.id;
			}
		}
	}
}

void find_out(Staff staff[], long id){
	for(int i = 0; i <10; i++){
		if(id === staff[i].id)
		puts(staff.name);
	}
}

int main(){
	Staff staff[10];
	for(int i = 0; i < 10; i++){
		puts("请输入职工号:");
		scanf("%ld",&staff[i].id);
		puts("\n请输入姓名:");
		gets(staff[i].name);
		putchar('\n');
	}
	sort(staff);
	puts("请输入查找的员工职工号:\n");
	long id;
	scanf("%ld",&id);
	find_out(staff,id);
	return 0;
}