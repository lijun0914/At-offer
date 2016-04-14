/*
	输入一个整形数组，数组里有正有负。求所有字数组的和的最大值 
*/
#include <vector>
#include <iostream>
using namespace std;
/*
	考察的是最基本的动态规划知识
	编程珠玑中有一章对这个问题有详细的描述 
	公式 ： 
	maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i]; 
*/
int maxSub(vector<int> vc){
	int res=0;
	int max=0;
	for(int i=0;i<vc.size();++i){
		res+=vc[i];
		if(res>max){
			max=res;
		}
		if(res<0){
			res=0;
		}
	}
	return max;
}
/*
	这个写法比较清晰的解释思路
	pre和cur 
	
*/
int maxSubArr(vector<int>& nums){
	int pre=nums[0],cur=nums[0];
	for(int i=1;i<nums.size();++i){
		pre=max(nums[i],pre+nums[i]);
		cur=max(pre,cur);
	}
	return cur;
}
/*
	如果要求的是最大乘积呢？
	考虑到正负 
	这就需要保留两个前置结果了 
*/
 int maxProduct(vector<int>& nums) {
        int minPre=nums[0];
        int maxPre=nums[0];
        int maxRes=nums[0];
        for(int i=1;i<nums.size();++i){
            if(nums[i]>=0){
                minPre=min(minPre*nums[i],nums[i]);
                maxPre=max(maxPre*nums[i],nums[i]);
            }else{
                int temp=maxPre;
                maxPre=max(minPre*nums[i],nums[i]);
                minPre=min(temp*nums[i],nums[i]);
            }
            maxRes=max(maxRes,maxPre);
        }
        return maxRes;
    }
int main(){
	vector<int> test={
		1,-2,3,10,-4,7,2,-5
	};
	cout<<maxSub(test)<<endl;
	cout<<maxSubArr(test)<<endl;
	cout<<maxProduct(test)<<endl;
}