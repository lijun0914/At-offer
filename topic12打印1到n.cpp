/*
	��������n,��˳���ӡ����1�����nλ��ʮ����������������3
	���ӡ��1,2,3.������999 
*/
#include <iostream>
using namespace std;
/*
	��ӡ��x000-��x001-��x002 
*/
void print(char *number,int len,int index){
	if(index==len-1){
		string s1=number;
		cout<<s1<<endl;
		return;
	}
	for(int i=0;i<10;++i){
		number[index+1]=i+'0';
		print(number,len,index+1);
	}
}
void printNum(int n){
	if(n<=0)
		return ;
	char *number=new char[n+1];
	number[n]='\0';
	for(int i=0;i<10;++i){
		number[0]=i+'0';
		print(number,n,0);
	}
	delete[]number;
}
int main(void){
	printNum(2);
}