/*
	���ַ������ҳ���һ��ֻ����һ�ε��ַ���������"abaccdeff"�����b 
*/
#include<map>
#include<string>
#include <iostream>
using namespace std;
/*
	�ռ任ʱ�� ��¼�����ͺ��� 
*/
void distinctChar(string str){
	if(str.empty())
		return;
	map<char,int> res;
	for(int i=0;i<str.size();++i){
		++res[str[i]];
	}
	for(auto i:str){
		if(res[i]==1){
			cout<<i<<endl;
			break;	
		}
		
	}
}
int main(){
	string str="aaccdeff";
	distinctChar(str);
}