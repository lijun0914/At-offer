/*
 一个数组除了两个数字之外，其他数字都出现了两次。找出这两个数字 
*/
#include <vector>
#include <iostream>
using namespace std;
/*
	两个相同的数字异或为0
	其中不同的两个数字 必定有一位不同
	可以根据这一位将数字分成两组 
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
	for(auto i:res){
		cout<<i<<" ";
	}
}
