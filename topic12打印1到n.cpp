/*
	输入数字n,按顺序打印出从1到最大n位的十进制数，比如输入3
	则打印出1,2,3.。。。999 
*/
#include <iostream>
using namespace std;
/*
	打印从x000-》x001-》x002 
*/
void printWithString(string s,int index){
    if(index==s.size()-1){
	int zero = 0;
	while(s[zero]=='0'&&s[zero]!='\0')
            zero++;
        cout<<s<<endl;
        return;
    }else{
        for(int i=0;i<10;++i){
            s[index+1]=i+'0';
            printWithString(s,index+1);
        }
    }
}
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
