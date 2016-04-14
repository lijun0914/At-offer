/*
	���������������У���һ����ʾѹ�����У��ڶ�����ʾ������
	�жϵڶ����Ƿ�Ϊ��һ�����еĵ��������־�����ȡ�
	��1,2,3,4,5ѹ�룬4,5��3��2,1Ϊ������4,3,5,1,2���ǡ� 
*/
#include <stack>
#include <iostream>
#include <vector>
using namespace std;
/*
	�������ͣ�
		������ʱ��ջ�����ݵ�����˳����ջѹ���Ԫ��
		���ѹ��Ҳû�ҵ� ���˳�
		�ҵ��󵯳������ʱ��ջ���Ԫ�� ֱ������ѹ��������� 
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
