/*
	���ǰ�ֻ��������2,3,5������Ϊ�������󰴴�С�����˳��
	�ĵ�1500������������6,8���ǳ�����14���ǡ���1��Ϊ��һ��
	���� 
*/
#include <iostream>
#include <vector>
using namespace std;
/*
	��ʼΪ1 
	k[1]=min( k[0]x2, k[0]x3, k[0]x5);
	�ƶ�2��ָ��++
	k[2] = min( k[1]x2, k[0]x3, k[0]x5)
	����2���������ʱ�򣬱���6����Ҫ�ƶ�2��3��ָ�� 
*/
int uglyNum(int n){
	int t2=0,t3=0,t5=0;
	if(n<=0) return 0;
	if(n==1) return 1;
	int k[n];
	k[0]=1;
	for(int i=1;i<n;++i){
		k[i]=min(2*k[t2],min(3*k[t3],5*k[t5]));
		if(k[i]==2*k[t2]) t2++;
		if(k[i]==3*k[t3]) t3++;
		if(k[i]==5*k[t5]) t5++;
	}
	return k[n-1];
}
/*
	�����ж�һ���Ƿ�Ϊ���� 
*/
bool isUgly(int num){
	if(num==0)
		return false;
	if(num==1)
		return true;
	while(num%5==0)
		num/=5;
	while(num%3==0)
		num/=3;
	while(num%2==0)
		num/=2;
	return num==1;		
}
/*
	�������������Ϊ����������
	 
*/
int nthSuperUglyNumber(int n, vector<int>& primes) {
	vector<int> index(primes.size(),0),ugly(n,INT_MAX);
	ugly[0] = 1;
	for(int i=1;i<n;i++){
		for(int j=0;j<primes.size();++j)
			ugly[i]=min(ugly[i],ugly[index[j]]*primes[j]);
		for(int j=0;j<primes.size();++j)
			index[j]+=(ugly[i]==ugly[index[j]]*primes[j]);
	}	        
	return ugly[n-1];
}
int main(){
	for(int i=0;i<20;++i)
		cout<<(uglyNum(i))<<endl;
	int testNum=uglyNum(2);
		cout<<isUgly(testNum)<<endl;
	cout<<"Now is the super ugly"<<endl;
	vector<int> primes={
		2, 7, 13, 19
	};
	//1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32
	cout<<nthSuperUglyNumber(5,primes)<<endl;
}