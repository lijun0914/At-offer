/*
	����n���������ҳ�������С��K������
	��������4,5,1,6,2,7,3,8������С4��Ϊ1,2,3,4 
*/
#include <vector>
#include <set>
#include <iostream>
#include <queue>
using namespace std;
/*
	stl�е����ȼ����� Ĭ���Ǵ����
	�����Զ���ȽϹ���
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
	ʹ�ÿ��ظ����ϴ������ظ����ֵ����
	�ڲ�Ӧ���Ǻ����
	ʹ�ô���ѵ���ʽ �Ѷ�ΪKλ��������� ȷ��������С��Kλ��ֵ 
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