/*
	输入n个整数，找出其中最小的K个数。
	例如输入4,5,1,6,2,7,3,8，怎最小4个为1,2,3,4 
*/
#include <vector>
#include <set>
#include <iostream>
#include <queue>
using namespace std;
/*
	stl中的优先级队列 默认是大根堆
	可以自定义比较规则
	priority_queue<int,vector<int>,greater<int>> 
*/
void findKMin(vector<int>& nums,int k){
	priority_queue<int> pq(nums.begin(),nums.end());
	for(int i=0;i<nums.size()-k;++i)
		pq.pop();
	while(!pq.empty()){
		cout<<pq.top()<<endl;
		pq.pop();
	}
}
/*
	使用可重复集合处理有重复数字的情况
	内部应该是红黑树
	使用大根堆的形式 堆顶为K位的最大数字 确保保存最小的K位数值 
*/
multiset<int,greater<int>> getLeaseNums(vector<int>& data,int k){
	multiset<int,greater<int>> mset;
	int n=data.size();
	for(int i=0;i<n;++i){
		if(mset.size()<k)
			mset.insert(data[i]);
		else{
			if(data[i]<*(mset.begin())){
				mset.erase(mset.begin());
				mset.insert(data[i]);	
			}	
		}
	}
	return mset;
}
int main(){
	vector<int> res={
		4,5,1,6,2,7,3,8
	};
	multiset<int,greater<int>> mult=getLeaseNums(res,4);
	for(auto i:mult)
		cout<<i<<" ";
	cout<<endl;
	findKMin(res,4);
}