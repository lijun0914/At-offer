/*
	������ջʵ�ֶ���  
*/
#include <stack>
#include <iostream>
using namespace std;
/*
	����˵����
		���е�����Ϊ�����ȳ�
		��ջΪ�������������ڳ�ջ�ͳ��ӵ�ʱ��˳���෴ 
		��ɶ��еĳ�����ӹ���
		
		ʹ��������ջ����ջһ������Ӳ�������ջ��������� 
		ֻҪ���ӵ�ʱ���ܹ���ɶ�ջ�ķ�������Ϳ���
		��ջһ��ӣ�����ʱ���Ȱ�һ�е����ݶ�����������
		������ʵ���˶�ջ���� 
*/
template<typename T> class CQueue{
	public:
		CQueue(){
			
		};
		~CQueue(){
			
		};
		void appendTail(const T& node);
		T deleteHead();
	private:
		stack<T> stack1;
		stack<T> stack2;
};
template<typename T>
void CQueue<T>::appendTail(const T& node){
	stack1.push(node);
}
template<typename T>
 T CQueue<T>::deleteHead(){
	if(stack2.empty()){
		while(!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	T res=stack2.top();
	stack2.pop();
	return res;
}
int main(){
	CQueue<int> myQueue;
	myQueue.appendTail(5);
	myQueue.appendTail(10);
	cout<<myQueue.deleteHead()<<endl;
	cout<<myQueue.deleteHead()<<endl;
}