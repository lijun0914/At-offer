/*
	ʵ�ֺ���double power(double base,int exponent)
	�����Ǵ������� 
*/
#include <iostream>
using namespace std;
bool equal(double base){
	return (base>-0.000001&&base<0.000001);
}
/*
	����˵����
		ʵ�����м������ǵ�����
		1.����ָ��������
		2.����ʹ�� Xn=Xn/2*Xn/2 (xΪż��)
		           Xn=Xn/2*Xn/2*base (xΪ����)
		  ����ѭ������    	 
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
	�ݹ�ʵ�� 
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