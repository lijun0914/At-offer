/*
 һ�����������������֮�⣬�������ֶ����������Ρ��ҳ����������� 
*/
#include <vector>
#include <iostream>
using namespace std;
/*
	������ͬ���������Ϊ0
	���в�ͬ���������� �ض���һλ��ͬ
	���Ը�����һλ�����ֳַ����� 
*/
vector<int> singleNum(vector<int>& nums){
	int temp=0;
	for(auto i:nums){
		temp^=i;
	}
	int num=0;
	while((temp&1)==0){
		temp>>=1;
		num++;
	}
	int first=0;
	int second=0;
	for(auto i:nums){
		if((1<<num&i)==0)
			first^=i;
		else 
			second^=i;
	}
	vector<int> res;
	res.push_back(first);
	res.push_back(second);
	return res;
}
int main(){
	vector<int> test={
		1,1,2,2,3,3,4,5,6,6
	};
	vector<int> res=singleNum(test);
	for(i:res){
		cout<<i<<" ";
	}
}
