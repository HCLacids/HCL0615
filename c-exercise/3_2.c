#include <stdio.h>
float math (double n, float rate,float principal){
	float p ;
	p = principal*(1 + n* rate);
	return p;
}
int main(){
	float P[5] = {1000,1000,1000,1000,1000};//本息和初始化
	double n[5] = {1.00,2.00,3.00,5.00,0.25};//年份
	float interest_rate[5] = {0.0414,0.0468,0.054,0.0585,0.0072};//分别为1年2年3年5年活期利息
	//第一种存法一次5年
	P[0] = math(n[3],interest_rate[3],P[0]);
	//第二种
	P[1] = math(n[1],interest_rate[1],P[1]);
	P[1] = math(n[2],interest_rate[2],P[1]);
	//第三种
	P[2]= math(n[2],interest_rate[2],P[2]);
	P[2] = math(n[1],interest_rate[1],P[2]);
	//第四种
	for (int i = 0; i < 5; i++){
		P[3]= math(n[0],interest_rate[0],P[3]);
	}
	//第五种
	for (int i = 0; i < 20; i++){
		P[4] = math(n[4],interest_rate[4],P[4]);
	}
	for (int i = 0; i < 5; i++){
		printf("%f\n",P[i]-1000);
	}
	return 0;
}
