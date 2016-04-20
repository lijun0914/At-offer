/*
	求1+2+3+...n,要求不能使用乘除法，for,while,if,else,
	switch,case等关键字以及条件判断语句A?B:C 
*/
#include <iostream>
using namespace std;
/*
	第一种方法
	使用构造函数以及静态变量 
*/
class temp{
	public:
		temp(){
			n++;
			sum+=n;
		}
		int value(){
			return sum;
		}
	private:
		static int n;
		static int sum;	
};
int temp::n=0;
int temp::sum=0;
int sum1(int n){
	temp a[n];
	return a[n-1].value();
}
/*
	使用递归 
*/
typedef int (*fcn)(int );
int soluTer(int n){
	return 0;
}
int sum2(int n){
	static fcn f[2]={
		soluTer,sum2
	};
	return n+f[!!n](n-1);
}
/*
	使用模板以及偏特化 
*/
template <unsigned int n>
struct sum3{
	enum value{
		N=sum3<n-1>::N+n
	};
};
template <>struct sum3<1>
{
	enum value{ N=1};
};
/*
	使用虚函数 
*/
class A;
A* array[2];
class A{
	public:
		virtual unsigned int sum(unsigned int n){
			return 0;
		}
};
class B:public A{
	public:
		virtual unsigned int sum(unsigned int n){
			return array[!!n]->sum(n-1)+n;
		}
};
unsigned int sum4(unsigned int n){
	A a;
	B b;
	array[0]=&a;
	array[1]=&b;
	unsigned int value=array[1]->sum(n);
	return value;
}
int main(){
	cout<<sum1(4)<<endl;
	cout<<sum2(4)<<endl;
	cout<<sum3<4>::N<<endl;	
	cout<<sum4(4)<<endl;
}