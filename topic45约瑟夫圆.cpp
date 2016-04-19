/*
	0,1,2...n-1这n个数字排成一圈，从数字0开始从这个圈里删除第m个数字
	求剩下的最后一个数字 
*/
#include <list>
#include <iostream>
using namespace std;
int lastNum(int n,int m){
	list<int> nums;
	for(int i=0;i<n;++i)
		nums.push_back(i);
	auto cur=nums.begin();
	while(nums.size()>1){
		for(int i=1;i<m;++i){
			cur++;
			if(cur==nums.end())
				cur=nums.begin();
		}
		auto next=++cur;
		if(next==nums.end())
			next=nums.begin();
		--cur;
		nums.erase(cur);
		cur=next;
	}
	return *cur;
}
/*
	f(n,m)=[f(n-1,m)+m]%n
	被删除数字为K,k=(m-1)%n映射为0到n-2的序列 
	k+1 -> 0
	k+2 -> 1
	...
	n-1 -> n-k-2
	0   -> n-k-1
	...
	k-1-> n-2
	映射定义为p p=(x-k-1)%m
	该映射的逆映射为 p-1(x)=(x+k+1)%n
	f(n,m)=f'(n-1,m)=p-1[f(n-1,m)]=[f(n-1,m)+k+1]%n 
*/
int lastNumTwo(int n,int m){
	if(n<1||m<1)
		return -1;
	int last=0;
	for(int i=2;i<=n;i++){
		last=(last+m)%i;
	}
	return last;
}
int main(){
	cout<<lastNum(5,3)<<endl;
	cout<<lastNumTwo(5,3)<<endl;
}