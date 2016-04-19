/*
	���˿�����������5���ƣ��ж��ǲ���һ��˳�ӡ�
	2-10Ϊ���ֱ���AΪ1,JΪ11��QΪ12��KΪ13����С��Ϊ������ 
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
/*
	ͨ��ͳ������������ÿ�������ּ�Ĳ�ֵ
	�Ƿ����ͨ����С���ֲ� 
*/
bool isContinue(vector<int> nums){
	int zeroCount=0;
	int gap=0;
	sort(nums.begin(),nums.end());
	for(auto i:nums){
		if(i==0)
			++zeroCount;
		else 
			break;
	}
	int small=zeroCount;
	int big=zeroCount+1;
	while(big<nums.size()){
		if(nums[small]==nums[big])
			return false;
		gap+=nums[big]-nums[small]-1;
		small=big++;	
	}
	return gap<=zeroCount;	
}
/*
	���������������
	[100,4,200,1,2,3]->1,2,3,4==4 
*/
int longestConsecutive(vector<int> &nums){
	unordered_set<int> order(nums.begin(),nums.end());
	int res=1;
	for(auto i:nums){
		order.erase(i);
		int pre=i-1,next=i+1;
		while(order.find(pre)!=order.end()) order.erase(pre--);
		while(order.find(next)!=order.end()) order.erase(next++);
		res=max(res,next-pre-1);
	}
	return res;
}
int main(){
	vector<int> seq={
		1,2,3,4,5
	};
	vector<int> seq1={
		1,2,0,4,5
	};
	vector<int> nSeq={
		1,3,3,5
	};
	vector<int> nSeq1={
		1,2,0,4,8
	};
	cout<<isContinue(seq)<<endl;
	cout<<isContinue(seq1)<<endl;
	cout<<isContinue(nSeq)<<endl;
	cout<<isContinue(nSeq1)<<endl;
	cout<<longestConsecutive(nSeq1)<<endl;
}