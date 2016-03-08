/*
	����һ��ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��
	��СԪ�ص�min�������ڸ�ջ��,min,push,pop��ʱ�临�Ӷȶ���o(1) 
*/
#include <stack>
#include <iostream>
using namespace std;
/*
	����˵����
		ʹ��������ջ������һ����ջ����ԭʼ����
		��һ�����浱ǰ��С����ֵ
		��ջ��ʱ�򱣴浱ǰ��ջֵ����ԭջ����ֵ
		��ջһ����� 
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