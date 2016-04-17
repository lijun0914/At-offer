/*
	统计一个数字在排序数组中出现的次数。例如输入{1,2，3,3,3,3,4,5}
	由于3出现4次，因此输出4 
*/
#include <vector>
#include <iostream>
using namespace std;
/*
	对于左半部分 
If A[mid] < target, then the range must begins on the right of mid (hence i = mid+1 for the next iteration)
If A[mid] > target, it means the range must begins on the left of mid (j = mid-1)
If A[mid] = target, then the range must begins on the left of or at mid (j= mid)
	对于右半部分
	
If A[mid] > target, then the range must begins on the left of mid (j = mid-1)
If A[mid] < target, then the range must begins on the right of mid (hence i = mid+1 for the next iteration)
If A[mid] = target, then the range must begins on the right of or at mid (i= mid) 
*/
int count(vector<int>& vc,int val){
	int low=0;
	int high=vc.size()-1;
	int begin;
	int end;
	 // Search for the left one
	while(low<high){
		int mid=low+(high-low)/2;
		if(vc[mid]<val){
			low=mid+1;
		}else{
			high=mid;
		}
	}
	begin=low;
	cout<<"the index of left bound is"<<begin<<endl;
	high=vc.size()-1;
	// Search for the right one
	while(low<high){
		// Make mid biased to the right
		int mid=(low+high)/2+1;
		if(vc[mid]>val){
			high=mid-1;
		}else{
			low=mid;
		}
	}
	end=high;
	cout<<"the index of right bound is"<<end<<endl;
	return end-begin+1;
}
int main(){
	vector<int> test={
		1,2,3,3,3,3,4
	};
	cout<<count(test,3)<<endl;
}
