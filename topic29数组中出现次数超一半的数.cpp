/*
	数组中有一个数字出现次数超过数组一半
	找出 
*/
#include<vector>
#include <iostream>
using namespace std;
/*
	因为有个数字超过一半
	所以区分数据就两种就可以了 和前面相同的 不同的
	不同的两个数字抵消 最后剩下的一定是超过一半的那个数字 
*/
int findNum(vector<int> &vc){
	int num=0;
	int res=vc[0];
	for(auto i:vc){
		if(res==i)
			num++;
		else
			num--;
		if(num==0){
			res=i;
			num++;	
		}
			
	}
	return res;
}
int main(){
	vector<int> res={
		1,2,3,2,3,3
	};
	cout<<findNum(res)<<endl;
}