/*
	在字符串中找出第一个只出现一次的字符，如输入"abaccdeff"则输出b 
*/
#include<map>
#include<string>
#include <iostream>
using namespace std;
/*
	空间换时间 记录下来就好了 
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