/*
	����һ��Ӣ�ľ��� ��ת���е��ʵ�˳�򣬵������ַ�˳�򲻱�
	i am a student --->student a am i 
*/
/*
	׷�� �ַ������������ǰ��ַ���ǰ��������ַ��Ƶ�β����
	����abcdefg,2��������cdefgab 
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std; 
/*
	�����巴ת
	Ȼ����ݿո񻮷֣���תÿһ������ 
*/
void reverseWords(string &s) {
       
        reverse(s.begin(),s.end());
        size_t start=0;
        size_t end=0;
        int i=0;
        while(s[0]==' ')
            s=s.erase(0,1);
        //�����Կո�Ϊ�ֽ��� Ϊ��ͳһ���� β׺����һ���ո� 
        s+=' ';
        for(int i=0;i<s.size();++i){
            if(s[i]!=' ')
                end++;
        //�����ո����� 
            while(s[i]==' '&&i<s.size()-1&&s[i+1]==' ')
                s.erase(i,1);
            if(s[i]==' '){
                if(end>start){
                    reverse(s.begin()+start,s.begin()+end);
                    start=++end;
                }
            }
        }
        s.erase(s.size()-1,1);
}
/*
	�����Ҫ��in-place ������stringstream 
*/
void reverseAgain(string &s){
	istringstream is(s);
	string tmp="";
	string res="";
	while(is>>tmp){
		tmp+=" ";
		tmp+=res;
		res=tmp;
	}
	s=res.erase(res.size()-1,1);
}
/*
	���stl�е�rotate 
*/
void leftRotate(string & s,int n){
	int size=s.size();
	int begin=0;
	for(;n=n%size;size-=n,begin+=n){
		for(int i=0;i<n;++i)
			swap(s[begin+i],s[begin+size-n+i]);
			cout<<s<<endl;
	}
}
int main(){
	string str="i am student";
	cout<<str.size()<<endl;
	reverseWords(str);
	cout<<str<<endl;
	reverseAgain(str);
	cout<<str<<endl;
	string rot="abcdefg";
	leftRotate(rot,3);
	cout<<str<<endl;
}