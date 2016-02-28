/*
	把一个数组最开始的若干个元素搬到末尾称为旋转。
	输入一个递增的数组的旋转，输出最小元素
	例如 {3,4,5,1,2}为{1,2,3,4,5}旋转，最小为1 
*/
#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;
/*
	函数说明：
		 使用二分查找，寻找最小值
		 两种情况
		 1.mid在正常的递增区间，mid<end，缩小mid
		 2.mid在旋转区间，mid>end,递增beg 
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
	扩展，如果允许重复数字呢 
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
	扩展，这里只是查找最小值。
	如果查找的是任意值，且不一定存在呢？
	任意值，可以在min的基础上，先找到min
	然后将min所在的位置作为偏移量
	接着进行二分查找 
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
	上面的问题，没有考虑有重复数字的问题，如果有呢？
	如果一样，只能从左到右一个一个遍历退化为O（n） 
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
