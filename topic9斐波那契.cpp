/*
 	写一个函数实现斐波那契数列
	 f(n)=0 n=0
	 f(n)=1 n=1
	 f(n-1)+f(n-2) n>1 
*/
#include <iostream>
using namespace std;
/*
	递归开支较大，转为迭代
	同时注意使用类型 long long保存数据 
*/
long long fibo(unsigned int n){
	long long result;
	if(n<2)
		return n;	
	int cur=1;
	int pre=0;
	for(int i=2;i<=n;++i){
		result=pre+cur;
		pre=cur;
		cur=result;
	}
	return result;
	
}
int main(){
	cout<<fibo(5)<<endl;
}