/*
	不使用+-/*完成加法操作 
*/
#include <iostream>
using namespace std;
/*
	先异或完成二进制的加法操作
	然后产生进位 
*/
int sum(int a,int b){
	int res,carry;
	do{
		res=a^b;
		carry=(a&b)<<1;
		a=res;
		b=carry;
	}while(b!=0);
	return a;
}
int main(){
	cout<<sum(4,5)<<endl;
}