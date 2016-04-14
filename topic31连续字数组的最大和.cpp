/*
	����һ���������飬�����������и���������������ĺ͵����ֵ 
*/
#include <vector>
#include <iostream>
using namespace std;
/*
	�������������Ķ�̬�滮֪ʶ
	�����������һ�¶������������ϸ������ 
	��ʽ �� 
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
	���д���Ƚ������Ľ���˼·
	pre��cur 
	
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
	���Ҫ��������˻��أ�
	���ǵ����� 
	�����Ҫ��������ǰ�ý���� 
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