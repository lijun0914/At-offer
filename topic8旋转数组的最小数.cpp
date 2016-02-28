/*
	��һ�������ʼ�����ɸ�Ԫ�ذᵽĩβ��Ϊ��ת��
	����һ���������������ת�������СԪ��
	���� {3,4,5,1,2}Ϊ{1,2,3,4,5}��ת����СΪ1 
*/
#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;
/*
	����˵����
		 ʹ�ö��ֲ��ң�Ѱ����Сֵ
		 �������
		 1.mid�������ĵ������䣬mid<end����Сmid
		 2.mid����ת���䣬mid>end,����beg 
*/
int minNum(const vector<int>& vc){
	if(vc.empty())
		return -1;
	int beg=0;
	int end=vc.size()-1;
	int mid;
	while(beg<end){
 		mid=beg+(end-beg)/2;
		if(vc[mid]>vc[end]){
			beg=mid+1;
		}else {
			end=mid;
		}
	}	
	return vc[beg];
}
/*
	��չ����������ظ������� 
*/
int minNumDup(const vector<int>& vc){
	if(vc.empty())
		return -1;
	int beg=0;
	int end=vc.size()-1;
	int mid;
	while(beg<end){
 		mid=beg+(end-beg)/2;
		if(vc[mid]>vc[end]){
			beg=mid+1;
		}else if(vc[mid]<vc[end]){
			end=mid;
		}else
			end--;
	}	
	return vc[beg];
}
/*
	��չ������ֻ�ǲ�����Сֵ��
	������ҵ�������ֵ���Ҳ�һ�������أ�
	����ֵ��������min�Ļ����ϣ����ҵ�min
	Ȼ��min���ڵ�λ����Ϊƫ����
	���Ž��ж��ֲ��� 
*/
int search(vector<int> &arr,int target){
	int beg=0,end=arr.size()-1;
	int mid;
	while(beg<end){
		mid=beg+(end-beg)/2;
		if(arr[mid]>arr[end]){
			beg=mid+1;
		}else{
			end=mid;
		}
	}
	cout<<"the min "<<beg<<":"<<arr[beg]<<endl;
	int rot=beg;
	beg=0,end=arr.size()-1;
	while(beg<=end){
 		mid=beg+(end-beg)/2;
 		int realmid=(mid+rot)%(arr.size());
 		if(arr[realmid]==target) return realmid;
 		if(arr[realmid]<target) beg=mid+1;
 		else end=mid-1;
	}
	return -1; 
} 
/*
	��������⣬û�п������ظ����ֵ����⣬������أ�
	���һ����ֻ�ܴ�����һ��һ�������˻�ΪO��n�� 
*/
int searchAgain(vector<int> &arr,int target){
	int beg=0,end=arr.size()-1;
	while(beg<=end){
		int mid=beg+(end-beg)/2;
		if(arr[mid]==target) return mid;
		if(arr[beg]<arr[mid]){//left half is sorted
			if(arr[beg]<=target&&target<arr[mid])
				end=mid-1;
			else
				beg=mid+1;
		}else if(arr[beg]>arr[mid]){//right half is sorted
			if(arr[mid]<target&&target<=arr[end])
				beg=mid+1;
			else
				end=mid-1;
		}else
			beg++;
		
	}
	return -1;
} 
int main(){
	vector<int> test1={
		3,4,5,1,2
	};
	vector<int> test2={
		1,2,3,4,5
	};
	vector<int> test3={
		1,1,1,5,1
	};
	vector<int> test4={
		2,5,5,1,1
	};
	cout<<(minNum(test1))<<endl;
	cout<<(minNum(test2))<<endl;
	cout<<(search(test1,2))<<endl;	
	cout<<(searchAgain(test1,2))<<endl;
	assert(searchAgain(test1,2)==4);
	cout<<(searchAgain(test2,5))<<endl;
	assert(searchAgain(test2,5)==4);
	cout<<(searchAgain(test3,5))<<endl;
	assert(searchAgain(test3,5)==3);
	cout<<(minNumDup(test4))<<endl;
}
