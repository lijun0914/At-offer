/*
	����һ���������飬�жϸ������ǲ��Ƕ����������ĺ��������Ľ����
	�������������������������ֶ�����ͬ 
*/
#include <vector>
#include <iostream>
using namespace std;
/*
	����������������������
	��������ֵС�ڸ��ڵ㣬��������ֵ���ڸ��ڵ�
	�������Ϊ�� �� ��
	�����Ӧ������Ϊ������������������ 
	�ȸ����������һ��ֵ������������
	�ݹ���ж���ֵ�Ƿ���� 
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