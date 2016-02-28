/*
	��һ����ά�����ÿһ�ж��������ҵ���
	ÿһ�д��ϵ��µ�����ʵ��һ�������������ά���飬��һ��������
	�ж��Ƿ��и����� 
*/
#include <vector>
#include <iostream>
using namespace std;

/*
	����˵����
		�����Ͻǿ�ʼ���ң���������ң����ϵ��µ�·����֧��ѡ�� 
*/
bool findNum(vector<vector<int>> mat,int number){
	bool find=false;
	int row=mat.size();
	int col=mat[0].size();
	int i=0;
	int j=col-1;
	while(i<row&&j>=0){
		if(mat[i][j]==number)
			return true;
		else if(mat[i][j]>number)
			--j;
		else
			++i;
	}
	return find;
}
int main(void){
	vector<vector<int>> a={
		{
			1,2,8,9
		},
		{
			2,4,9,12		
		},
		{
			4,7,10,13
		},{
			6,8,11,15
		}
	};
	cout<<(findNum(a,88))<<endl;
}