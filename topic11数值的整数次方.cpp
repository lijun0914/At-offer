/*
	实现函数double power(double base,int exponent)
	不考虑大数问题 
*/
#include <iostream>
using namespace std;
bool equal(double base){
	return (base>-0.000001&&base<0.000001);
}
/*
	函数说明：
		实现上有几个考虑的因素
		1.考虑指数的正负
		2.可以使用 Xn=Xn/2*Xn/2 (x为偶数)
		           Xn=Xn/2*Xn/2*base (x为奇数)
		  减少循环次数    	 
*/ 
double Power(double base,int exponent){
	double result=1.0;
	bool nage=false;
	if(equal(base))
		return 0.0;
	if(exponent==0)
		return 1;
	else if(exponent<0){
		nage=true;
		exponent=-exponent;
	}
	result=base;
	if((exponent&0x1)==0){
		for(int i=1;i<exponent;i=i*2){
			result*=result;
		}
	}else{
		for(int i=1;i<exponent;i=i*2+1){
			result=result*result*base;
		}
	}
	if(nage)
		return 1/result;
	else
		return result;
	
}
/*
	递归实现 
*/
double Power2(double x,int n){
	if(n==0)
		return 1;
	if(n<0){
		n=-n;
		x=1/x;
	}
	return (n%2==0)?Power2(x*x,n/2):x*Power2(x*x,n/2);
}
int main(){
	cout<<Power(10,4)<<endl;
	cout<<Power2(10,4)<<endl; 
	cout<<Power(10,-3)<<endl;
}