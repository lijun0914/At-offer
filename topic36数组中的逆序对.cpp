/*
	�������е������������ǰ��һ�����ں�������֣����������������
	һ������ԣ�����һ�����飬���������������Ե������� 
*/
#include <iostream>
#include<vector>
using namespace std;
/*
	�鲢����nlog(n)
	��һ��������temp�ռ� ������������������ֵ 
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
	����һ���鲢�Ĺ���
	�Ȱ�����ָ���������
	�ȼ��������������� Ȼ������  
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