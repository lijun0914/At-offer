/*
	����һ�����������飬����������������ƴ����������ӡ��ƴ�ӵ���С��һ��
	����{3,32,321}�����ӡ 321323 
*/
#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>
using namespace std;
/*
	ʹ��sort 
	�Զ�������Ĺ��� 
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