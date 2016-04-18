/*
	输入一个递增排序的数组和一个数字s，在数组中查找两个数，
	使得它们的和正好是s.输出任意一对即可 
*/
/*
	追加:输入一个正整数s,打印出所有和为s的连续正数序列，至少
	含两个数 
*/
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm> 
using namespace std;
void sum(vector<int>& nums,int val){
	int small=0;
	int big=nums.size()-1;
	while(small<big){
		if((nums[small]+nums[big])>val)
			big--;
		else if((nums[small]+nums[big])<val)
			small++;
		else {
			cout<<nums[small]<<" "<<nums[big]<<endl;
			return;	
		}
				
	}
	cout<<"no such"<<endl;
	
}
/*
	问题一可以稍微变形一下
	找出a+b+c=0 
	等于 twoSum = -c 
*/
vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
    std::sort(num.begin(),num.end());
	for(int i=0;i<num.size();++i){
		
		int target=-num[i];
		int front=i+1;
		int rear=num.size()-1;
		while(front<rear){
			int sum=num[front]+num[rear];
			if(sum<target)
				front++;
			else if(sum>target)
				rear--;
			else{
				vector<int> temp(3,0);
				temp[0]=num[i];
				temp[1]=num[front];
				temp[2]=num[rear];
				res.push_back(temp);
			while(front<rear&&num[front]==temp[1]) ++front;
			while(front<rear&&num[rear]==temp[2]) rear--;
			
			}
			while(i<num.size()-1&&num[i+1]==num[i]) ++i;
		}
	}
    return res;
}
/*
	数组不递增呢 
*/
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector <int> result(2,-1);
        for(int i=0;i<nums.size();++i)
        {
            if(m.find(target-nums[i])==m.end())
                m[nums[i]]=i;
            else
            {
                result[0]=m[target-nums[i]];
                result[1]=i;
                return result;
            }
        }
}
/*
	四个数字呢？
	a + b + c + d = target 
*/
 vector<vector<int> > fourSum(vector<int> &num, int target) {

        vector<vector<int> > res;

        if (num.empty())
            return res;

        std::sort(num.begin(),num.end());

        for (int i = 0; i < num.size(); i++) {

            int target_3 = target - num[i];

            for (int j = i + 1; j < num.size(); j++) {

                int target_2 = target_3 - num[j];

                int front = j + 1;
                int back = num.size() - 1;

                while(front < back) {

                    int two_sum = num[front] + num[back];

                    if (two_sum < target_2) front++;

                    else if (two_sum > target_2) back--;

                    else {

                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);

                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;

                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;

                    }
                }

                // Processing the duplicates of number 2
                while(j + 1 < num.size() && num[j + 1] == num[j]) ++j;
            }

            // Processing the duplicates of number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) ++i;

        }

        return res;

}
void printSum(int down,int up){
	while(down<=up){
		cout<<down++<<" ";
	}
	cout<<endl;
	
}
void sequence(int sum){
	if(sum<3)
		return;
	int small=1;
	int big=2;
	int mid=(sum+1)/2;
	int cur=small+big;
	while(small<mid){
		if(cur==sum)
			printSum(small,big);
		while(cur>sum&&small<mid){
			cur-=small;
			small++;
			if(cur==sum)
				printSum(small,big);
		}
		big++;
		cur+=big;
	}
}
int main(){
	vector<int> test={
		1,2,4,7,11,15
	};
	sum(test,15);
	sequence(15);
	for(auto i:twoSum(test,9))
		cout<<i<<" ";
	cout<<endl;
	for(auto i:fourSum(test,23))
		for(auto j:i)
			cout<<j<<" ";
	cout<<endl;
}