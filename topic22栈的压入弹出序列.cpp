/*
	输入两个整数数列，第一个表示压入序列，第二个表示弹出，
	判断第二个是否为第一个数列的弹出，数字均不相等。
	如1,2,3,4,5压入，4,5，3，2,1为弹出。4,3,5,1,2不是。 
*/
#include <stack>
#include <iostream>
#include <vector>
using namespace std;
/*
	函数解释：
		设置临时堆栈，根据弹出的顺序入栈压入的元素
		如果压完也没找到 就退出
		找到后弹出这个临时堆栈里的元素 直到整个压入序列完成 
*/
bool isPop(vector<int>& push,vector<int>& pop){
		bool poss=false;
		int i=0;
		int j=0;
		stack<int> stk;
		while(i<pop.size()){
			while(stk.empty()||stk.top()!=pop[i])
			{
				if(j==push.size())
					break;
				stk.push(push[j]);
				++j;
			}
			if(stk.top()!=pop[i])
				break;
			stk.pop();
			++i;
		}
		if(stk.empty())
			poss=true;
		return poss;
}
int main(){
	vector<int> push{
		1,2,3,4,5
	};
	vector<int> pop{
		4,5,3,2,1
	};
	vector<int> pop2{
		4,3,5,1,2
	};
	cout<<isPop(push,pop)<<endl;	
	cout<<isPop(push,pop2)<<endl;
}
