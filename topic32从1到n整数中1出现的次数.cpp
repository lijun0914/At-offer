/*
	����һ������n,���1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ���
	��������12,1��12�а���1��������1,10,11,12.1����5�� 
*/
#include <iostream>
using namespace std;
/*
	����ⷨ�ᳬʱ 
*/
long long int countOne(long long int num){
	long long int count=0;
	int lowerNum=0;
	int curNum=0;
	int highNum=0;
	int factor=1;
	while(num/factor!=0){
		lowerNum=num-num/factor*factor;
		curNum=(num/factor)%10;
		highNum=num/(factor*10);
		if(curNum==0)
			count+=highNum*factor;
		else if(curNum==1)
			count+=highNum*factor+lowerNum+1;
		else
			count+=(highNum+1)*factor;
		factor*=10;
	}
	return count;
}
/*
	��������ַ�Ϊ������ ����������
	�ֱ���pre suf��ʾ 
	ͬʱ�������һλ��Ϊ>1 =1 <1�������
	>1 �Ļ� ǰ��Ĳ���Ϊ1��pre+1
	(a/10+1)*m 
	=1 �Ļ� 
	(a/10*m)+(b+1) 
*/
int count(int n){
	int ones=0;
	for(long long m=1;m<=n;m*=10){
		int a=n/m,b=n%m;
		//ones += a/10 * m; 
		//if (a%10 > 1) ones += m; if (a%10 == 1) ones += b+1; 
		ones+=(a+8)/10*m+(a%10==1)*(b+1);
	}
	return ones;
}
int main(){
	long long int i;
	while(cin>>i){
		cout<<countOne(i)<<endl;
		cout<<count(i)<<endl;
	}
	//cout<<countOne(13)<<endl;
}