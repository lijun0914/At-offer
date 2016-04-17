/*
	输入一个正整数数组，把数组中所有数字拼接起来，打印出拼接的最小的一个
	例如{3,32,321}，则打印 321323 
*/
#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>
using namespace std;
/*
	使用sort 
	自定义排序的规则 
*/
 string largestNumber(vector<int>& nums) {
        vector<string> comp;
        string res;
        for(int i=0;i<nums.size();++i){
            comp.push_back(to_string(nums[i]));
        }
        sort(comp.begin(),comp.end(),[](string &a,string &b){return a+b<b+a;});
        for(auto it=comp.begin();it!=comp.end();++it)
            res+=*it;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return res;
}
int main(){
	vector<int> test{
		3,32,321
	};
	cout<<largestNumber(test)<<endl;
}