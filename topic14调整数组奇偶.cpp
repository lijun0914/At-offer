/*
	输入一个整数数组，实现一个函数调整数组奇数在前半部，
	偶数在后半部分 
*/
#include <vector>
#include <iostream>
using namespace std;
/*
	函数说明：
		双指针的应用，一个从前往后，一个从后往前
		交换数据直到相遇 
*/
void adjust(vector<int>& vc){
	int beg=0;
	int end=vc.size()-1;
	while(beg<end){
		while((vc[beg]&0x1)==1)
			beg++;
		while((vc[end]&0x1)==0)
			end--;
		if(end<=beg)
			break;
		swap(vc[beg],vc[end]);
	}	
}
int main(void){
	vector<int> vc={
		1,2,3,4,5,6
	};
	adjust(vc);
	for(auto i:vc){
		cout<<i<<" ";
	}	
}
