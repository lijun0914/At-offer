/*
	用两个栈实现队列  
*/
#include <stack>
#include <iostream>
using namespace std;
/*
	函数说明：
		队列的特性为先入先出
		堆栈为先入后出，两者在出栈和出队的时候顺序相反 
		完成队列的出队入队功能
		
		使用两个堆栈，堆栈一负责入队操作，堆栈二负责出队 
		只要出队的时候能够完成堆栈的反向操作就可以
		堆栈一入队，出队时，先把一中的内容都弹出到二中
		这样就实现了堆栈反向 
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