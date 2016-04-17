/*
	在数组中的两个数字如果前面一个大于后面的数字，则这两个数字组成
	一个逆序对，输入一个数组，求出这个数组的逆序对的总数。 
*/
#include <iostream>
#include<vector>
using namespace std;
/*
	归并过程nlog(n)
	有一个辅助的temp空间 来保存排序过后的数组值 
*/
long long mergeCount(vector<int>& vc,int left,int mid,int right,vector<int>& temp){
	int i=left;
	int j=mid+1;
	int k=left;
	long long count=0;
	while(i<=mid&&j<=right){
		if(vc[i]<=vc[j]){
			temp[k++]=vc[i++];
		}else{
			temp[k++]=vc[j++];
			count+=mid-i+1;	
		}
	}
	while(i<=mid) temp[k++]=vc[i++];
	while(j<=right) temp[k++]=vc[j++];
	for(i=left;i<=right;++i){
		vc[i]=temp[i];
	}
	return count;
} 
/*
	这是一个归并的过程
	先把数组分隔成子数组
	先计算子数组的逆序对 然后排序  
*/
long long mergeSort(vector<int>& vc,int left,int right,vector<int>& temp){
	if(left>=right) return 0;
	int mid=left+(right-left)/2;
	long long leftCount=mergeSort(vc,left,mid,temp);
	long long rightCount=mergeSort(vc,mid+1,right,temp);
	long long count=mergeCount(vc,left,mid,right,temp);
	return leftCount+rightCount+count;
}
int main(){
	vector<int> test={
		7,5,6,4
	};
	vector<int> temp(test.begin(),test.end());
	cout<<mergeSort(test,0,test.size()-1,temp)<<endl;
}