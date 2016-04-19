/*
	从扑克牌中随机抽出5张牌，判断是不是一个顺子。
	2-10为数字本身，A为1,J为11，Q为12，K为13，大小王为任意数 
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
/*
	通过统计排序后的数组每两个数字间的差值
	是否可以通过大小王弥补 
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
	查找最长的连续序列
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