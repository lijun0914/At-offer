/*
	把n个骰子扔在地上，所有骰子朝上一面的点数和为s.输入n。打印出s的所有
	可能的值出现的概率 
*/
#include <ext/numeric>
#include <iostream>
#include <string.h>
 #define N 50
 int num1[N] , num2[N] ;
using namespace __gnu_cxx;
using namespace std;
int f(int n,int s){
	if(s<n||s>6*n) return 0;
	if(n==1) return 1;
	else 
		return f(n-1,s-6)+f(n-1,s-5)+f(n-1,s-4)+f(n-1,s-3)+
		f(n-1,s-2)+f(n-1,s-1);
}
void listProb(int n){
	for(int i=n;i<=6*n;++i){
		cout<<"prob= :"<<f(n,i)<<"\""<<power(6,n)<<endl; 
	}
}
 void Show(int n){
     memset(num1,0,N*sizeof(int));
     memset(num2,0,N*sizeof(int));
    for(int i = 1 ; i <= 6 ; i++) num1[i] = 1 ;
     int i , j , k ;
     for(i = 2 ; i <= n ; i++){
         for(j = i ; j <= 6*i ; j++){
             k = j-6 ;
             if(k < i)   k = i-1 ;
             for( ; k < j ; k++)  num2[j] += num1[k];
         }
        memset(num1,0,N*sizeof(int));
         for(int m = i ; m <= 6*i ; m++) num1[m] = num2[m];
         memset(num2,0,N*sizeof(int));
     }
     cout<<"The probability distribution of "<<n<<" dices"<<endl<<endl;
     cout<<"Point: \t"<<"Probability:"<<endl;;
     for(int kkk = n ; kkk <= 6*n ;  kkk++){
         cout<<kkk<<": \t"<<num1[kkk]<<"/"<<(power(6.0,n))<<endl;
     }
 }
int main(){
	listProb(4);
	Show(4);
}