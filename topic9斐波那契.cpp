/*
 	дһ������ʵ��쳲���������
	 f(n)=0 n=0
	 f(n)=1 n=1
	 f(n-1)+f(n-2) n>1 
*/
#include <iostream>
using namespace std;
/*
	�ݹ鿪֧�ϴ�תΪ����
	ͬʱע��ʹ������ long long�������� 
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