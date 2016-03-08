/*
	定义一个栈的数据结构，请在该类型中实现一个能够得到栈的
	最小元素的min函数，在该栈中,min,push,pop的时间复杂度都是o(1) 
*/
#include <stack>
#include <iostream>
using namespace std;
/*
	函数说明：
		使用两个堆栈，其中一个堆栈保存原始数据
		另一个保存当前最小的数值
		入栈的时候保存当前入栈值或者原栈顶数值
		出栈一起除出 
*/
class myStack{
	public:
		myStack(){
			
		}
		void pop(){
			if(!minVal.empty()){
				minVal.pop();
				origin.pop();			
			}
			
		}
		void push(int val){
			origin.push(val);
			if(minVal.empty()||val<minVal.top())
				minVal.push(val);
			else
				minVal.push(minVal.top());		
		}
		int min(){
			return minVal.top();		
		}
		
	private:
		stack<int> origin;
		stack<int> minVal;
};
int main(){
	myStack test;
	test.push(4);
	test.push(3);
	test.push(1);
	test.push(2);
	cout<<test.min()<<endl;
	test.pop();
	cout<<test.min()<<endl;
	test.pop();
	cout<<test.min()<<endl;
}