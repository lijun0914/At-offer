/*
	��������һ�����ֳ��ִ�����������һ��
	�ҳ� 
*/
#include<vector>
#include <iostream>
using namespace std;
/*
	��Ϊ�и����ֳ���һ��
	�����������ݾ����־Ϳ����� ��ǰ����ͬ�� ��ͬ��
	��ͬ���������ֵ��� ���ʣ�µ�һ���ǳ���һ����Ǹ����� 
*/
int findNum(vector<int> &vc){
	int num=0;
	int res=vc[0];
	for(auto i:vc){
		if(res==i)
			num++;
		else
			num--;
		if(num==0){
			res=i;
			num++;	
		}
			
	}
	return res;
}
int main(){
	vector<int> res={
		1,2,3,2,3,3
	};
	cout<<findNum(res)<<endl;
}