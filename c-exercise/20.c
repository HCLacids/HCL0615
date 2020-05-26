#include <stdio.h>
#include <stdlib.h>
#define max 10
int main(int argc, char *argv[]) {
	char str[]={'A','1','2','3','x','4','5','6',' ','1','7','9','6','0','?','3','0','2','t','a','5','8','7','6','\0'};
	char z;
	int transnum=0;
	int flag=0; 
	int j=0;
	int a[20];
	int i=0;
	char *st=&str[0];
	while((z=*(st+i))!='\0') 
	{
	
		if(z>='0'&&z<='9')  
		{
			    
			transnum=transnum*10+(z-'0'); 
			flag=1;	
		} 
		else
		
		{
			if(flag==1)   
			{
				a[j++]=transnum;
				transnum=0;   
			
			}
			flag=0;				
		}
		i++;  
	}
	if(flag==1)
	{
		a[j++]=transnum;
	}	
	a[j]='\0'; 
	int *ast=a; 
	printf("there are %d numbers in this line ,they are \n",j); 
	i=0; 
	while(*(ast+i)!='\0')
	{
	  	
		printf("%d ",*(ast+i));  
		i++;  
	}
	
	
	return 0;
	}