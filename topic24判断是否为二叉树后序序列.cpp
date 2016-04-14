/*
	输入一个整数数组，判断该数组是不是二叉搜索树的后续遍历的结果。
	假设输入的数组的任意两个数字都不相同 
*/
#include <vector>
#include <iostream>
using namespace std;
/*
	二叉搜索树具有以下特性
	左子树数值小于根节点，右子树数值大于根节点
	后序遍历为左 右 中
	数组对应的区间为左子树，右子树，根 
	先根据数组最后一个值划分左右区间
	递归的判断数值是否符合 
*/
bool isPost(vector<int>::iterator tree,int length){
	int root=tree[length-1];
	int i=0;
	for(;i<length-1;++i){
		if(tree[i]>root)
			break;
	}
	int j=i;
	for(;j<length-1;++j){
		if(tree[j]<root)
			return false;
	}
	bool left=true;
	if(i>0)
		left=isPost(tree,i);
	bool right=true;
	if(i<length-1)
		right=isPost(tree+i,length-i-1);
	return (left&&right);
}
int main(){
	vector<int> post={
		5,7,6,9,11,10,8
	};
	vector<int> notPos={
		7,4,5,6
	};
	cout<<isPost(post.begin(),post.size())<<endl;
	cout<<isPost(notPos.begin(),notPos.size())<<endl;
}